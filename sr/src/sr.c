#include "sr.h"
#include "json.h"

#include <hk/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t sr_write_callback(void *buf, size_t size, size_t nmemb, void *p) {
  sr_response_t *response = (sr_response_t *) p;
  
  if (response->offset + (size * nmemb) >= SR_BUFFER_SIZE -1) {
    hklog(HK_ERR, "buffer too small!\n");
    return 0;
  }

  memcpy(response->data + response->offset, buf, size * nmemb);
  response->offset += size * nmemb;

  #ifdef DEBUG
  hklog(HK_DEBUG, "response data buffer offset: %d\n", response->offset);
  #endif  

  return (size_t) ((size *nmemb));
}

int sr_geturl(char *url, void *p) {
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  if ((curl = curl_easy_init()) != NULL) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, sr_write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, p);

    if ((res = curl_easy_perform(curl)) > SR_OK) {
      return (int) res;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return SR_OK;
  } else {
    hklog(HK_ERR, "unknown curl init error\n");
    return SR_NOK;
  }
}

int sr_getsubreddit(char *subreddit, int limit) {
  char *prefix = SR_URL_PREFIX;
  char *suffix = SR_URL_SUFFIX;
  int url_size = strlen(prefix) + SR_STRING_LIMIT + strlen(suffix);
  char url[url_size];
  int res;

  sprintf(url, "%s%s%s%d", prefix, subreddit, suffix, limit);
  #ifdef DEBUG
  hklog(HK_DEBUG, "constructed url: %s\n", url);
  #endif

  char* buffer = malloc(SR_BUFFER_SIZE);
  if (!buffer) {
    hklog(HK_FATAL, "error allocating %d bytes!\n", SR_BUFFER_SIZE);
    return SR_NOK;
  }
  
  sr_response_t response = {
    .data = buffer,
    .offset = 0
  }; 
  
  if ((res = sr_geturl(url, &response)) > SR_OK) {
    return (int) res;
  }

  response.data[response.offset] = '\0';

  #ifdef DEBUG
  hklog(HK_DEBUG, "%s\n", response.data);
  #endif

  sr_parse_json(response.data);
  
  free(buffer);
  return SR_OK;
}
