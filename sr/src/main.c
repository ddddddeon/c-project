#include "sr.h"
#include "lib/hklog.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char* subreddit;
  int limit;

  if (argc < 2) {
    hklog(HK_ERR, "no subreddit specified D:");
    return 1;
  }
  
  if (argc < 3) {
    limit = SR_RESULT_LIMIT;
  } else {
    limit = atoi(argv[2]);
  }

  if (strlen(argv[1]) > SR_STRING_LIMIT) {
    hklog(HK_ERR,"subreddit name too long, must be < %d", SR_STRING_LIMIT);
    return 1;
  } 
    
  subreddit = argv[1];

#ifdef DEBUG
  hklog(HK_DEBUG, "subreddit: %s, limit: %d\n", subreddit, limit);
#endif

  sr_getsubreddit(subreddit, limit);

  return 0;
}
