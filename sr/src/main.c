#include "sr.h"

#include <hk/log.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* subreddit;
    int limit;
    int res;
    
    if (argc < 2) {
	hkerr("no subreddit specified D:\n");
	return SR_NOK;
    }
    
    if (argc < 3) {
	limit = SR_RESULT_LIMIT;
    } else {
	limit = atoi(argv[2]);
    }
    
    if (strlen(argv[1]) > SR_STRING_LIMIT) {
	hkerr("subreddit name too long, must be < %d\n", SR_STRING_LIMIT);
	return SR_NOK;
    } 
    
    subreddit = argv[1];
    
#ifdef DEBUG
    hkdebug("subreddit: %s, limit: %d\n", subreddit, limit);
#endif
    
    if ((res = sr_getsubreddit(subreddit, limit)) > SR_OK) {
	hkerr("could not get url, curl return code %d\n", res);    
	return SR_NOK;
    }
    
#ifdef DEBUG
    hkdebug("curl return code: %d\n", res);
#endif
    
    return SR_OK;
}
