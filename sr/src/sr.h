#ifndef SR_H
#define SR_H

#include <stddef.h>

#define SR_OK 0
#define SR_NOK 1

#define SR_RESULT_LIMIT 25
#define SR_STRING_LIMIT 64 
#define SR_BUFFER_SIZE (256 * 1024)
#define SR_URL_PREFIX "http://reddit.com/r/"
#define SR_URL_SUFFIX "/new.json?sort=new&limit="

typedef struct {
  char* data;
  int offset;
} sr_response_t;

size_t sr_write_callback(void *buf, size_t size, size_t nmemb, void *p);
int sr_geturl(char* url, void *p);
int sr_getsubreddit(char* subreddit, int limit);

#endif /* !SR_H */
