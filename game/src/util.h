#ifndef UTIL_H
#define UTIL_H

#define strip_newline(_STR, _LEN) \
    if (_STR[_LEN] == '\n' || _STR[_LEN] == '\r') {\
	_STR[_LEN] = '\0';\
	if (_STR[_LEN-1] == '\n' || _STR[_LEN-1] == '\r') {\
	    _STR[_LEN] = '\0';\
	}\
    }\


#endif
