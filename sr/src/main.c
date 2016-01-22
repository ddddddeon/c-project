#include "sr.h"

#include <hk.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char* subreddit;
  int limit;
  int res;

  if (argc < 2) {
    hklog(HK_ERR, "no subreddit specified D:\n");
    return 1;
  }
  
  if (argc < 3) {
    limit = SR_RESULT_LIMIT;
  } else {
    limit = atoi(argv[2]);
  }

  if (strlen(argv[1]) > SR_STRING_LIMIT) {
    hklog(HK_ERR, "subreddit name too long, must be < %d\n", SR_STRING_LIMIT);
    return 1;
  } 
    
  subreddit = argv[1];

#ifdef DEBUG
  hklog(HK_DEBUG, "subreddit: %s, limit: %d\n", subreddit, limit);
#endif
  
  if ((res = sr_getsubreddit(subreddit, limit)) > 0) {
      hklog(HK_ERR, "could not get url, curl return code %d\n", res);    
    return 1;
  }

#ifdef DEBUG
  hklog(HK_DEBUG, "curl return code: %d\n", res);
#endif

  return 0;
}
