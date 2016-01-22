#ifndef SR_H
#define SR_H

#include <stddef.h>

#define SR_RESULT_LIMIT 25
#define SR_STRING_LIMIT 64 
#define SR_URL_PREFIX "http://reddit.com/r/"
#define SR_URL_SUFFIX "/new.json?sort=new&limit="

size_t function_pt(void *ptr, size_t size, size_t nmemb, void *stream);
int sr_geturl(char* url);
int sr_getsubreddit(char* subreddit, int limit);

#endif /* SR_H */
