#ifndef SR_JSON_H
#define SR_JSON_H

#define SR_DELIM "{}\","

#define true 1
#define false 0

enum json_states { SCANNING,
		   FOUND_URL_KEY,
		   FOUND_COLON };

int sr_parse_json(char* blob);

#endif /* !HK_JSON_H */
