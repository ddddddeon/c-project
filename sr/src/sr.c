#include "sr.h"

#include <hk.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int sr_geturl(char *url) {
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  if ((curl = curl_easy_init()) != NULL) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    if ((res = curl_easy_perform(curl)) > 0) {
      return (int) res;
    }

    printf("\n");
    curl_easy_cleanup(curl);
    return 0;
  } else {
    hklog(HK_ERR, "unknown curl init error\n");
    return 1;
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
  
  if ((res = sr_geturl(url)) > 0) {
    return (int) res;
  }
  return 0;
}
