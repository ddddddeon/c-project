#include "json.h"
#include "sr.h"

#include <hk/log.h>
#include <string.h>

/*
 * the following is a state machine that goes through
 * a tokenized set of strings from a subreddit's json object
 * and transitions between SCANNING, FOUND_COLON and FOUND_URL_VALUE states.
 *
 * 0: SCANNING is the default state. when the state is SCANNING and the string
 * "url" appears in the present token, transition to the next state.
 *
 * 1: FOUND_URL_KEY means the present token is a colon because the "url" string was
 * present in the previous token. transition automatically to the next state 
 * to find the url value.
 *
 * 2: FOUND_COLON is the state in which the token contains the url value,
 * which always follows the colon after a "url" key. indicate that we have found
 * the right url by setting already_found_url to true, and continue scanning
 * by transitioning back to SCANNING.
 */
int sr_parse_json(char* sr_blob) {
  int state = SCANNING;
  int already_found_url = true;

  char* token = strtok(sr_blob, SR_DELIM);
  while (token != NULL) {

    /* 
     *  we know this is the start of a new object if the 
     *  '"kind": ...' key/value appears in the token, as 
     *  this is a top-level property. reset "already_found_url"
     *  to false, and continue scanning tokens.
     */
    if (strstr(token, "kind") != NULL &&
	(strstr(token, "_") == NULL)) {
      already_found_url = false;
    } else


    /*
     *  we found a colon after finding the "url" key, so 
     *  we are now at the "url" key's value.
     *  if the url is not a thumbnail or otherwise unneeded,
     *  assuming we have not already found the url in this object,
     *  log the url, and set already_found_url to true.
     *  transition back to state SCANNING;
     */
    if (state == FOUND_COLON) {
      if ((strstr(token, "redditmedia") == NULL) && 
           strstr(token, "http") != NULL) {
        if (already_found_url == 0) { 
	  hklog(HK_INFO, "%s\n", token);
	  already_found_url = true;
       	}
      }
      state = SCANNING;
    } else


    /* 
     *  if the "url" key in the object has been found, then
     *  we are at a ":" token, so skip to the next token by
     *  transitioning to the next state, FOUND_COLON.
     */
    if (state == FOUND_URL_KEY) {
      state++;
    } else


    /*  we found a "url" key that doesn't contain an "_",
     *  so transition to the next state, FOUND_URL_KEY.
     */
    if ((strstr(token, "url") != NULL) && 
	strstr(token, "_") == NULL) {
      state++;
    }

    token = strtok(NULL, SR_DELIM);
  }
  return SR_OK;
}
