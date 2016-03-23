#include "red.h"

#include <hk/log.h>
#include <hiredis/hiredis.h>

#define ___LIMIT 100000
#define SET_FOO_N "SET foo %d"
#define INCR_FOO "INCR foo"

int main(int argc, char* argv[]) {
    hk_init("red");

    redisContext *c = redisConnect("127.0.0.1", 6379);
    if (c != NULL && c->err) {
        hk_err("error: %s\n", c->errstr);
        return HK_NOK;
    }

    redisReply *reply;
    int i = 0;

    reply = redisCommand(c, SET_FOO_N, i);
    hk_info(SET_FOO_N ": %s\n", i, reply->str);
    freeReplyObject(reply);

    for (/* void */; i < ___LIMIT; i++) {
        reply = redisCommand(c, INCR_FOO);
        hk_info(INCR_FOO ": %d\n", reply->integer);
        freeReplyObject(reply);
    }

    redisFree(c);
    hk_info("redis disconnected and memory freed\n");

    return HK_OK;
}                       
