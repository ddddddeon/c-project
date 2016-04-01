#include <hiredis/hiredis.h>
#include <hk/log.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#define NAMESPACE "todo:tasks"

int main(int argc, char *argv[])
{
    redisContext *c = redisConnect("127.0.0.1", 6379);
    if (c != NULL && c->err) {
        hk_fatal("failed to connect to redis: %s\n", c->errstr);
        return HK_NOK;
    }

    const char *short_opts = "laird";
    const struct option long_opts[] = {
        {"list",   0, NULL, 'l'},
        {"add",    0, NULL, 'a'},
        {"insert", 0, NULL, 'i'},
        {"remove", 0, NULL, 'r'},
        {"delete", 0, NULL, 'd'},
        { NULL,    0, NULL,  0 }
    };

    char key_string[1024];

    if (argv[2]) {
        strncpy(key_string, argv[2], sizeof(key_string));
    }

    redisReply *reply;
    int next;
    int index;

    do {
        next = getopt_long(argc, argv, short_opts, long_opts, NULL);
        switch (next) {

        case 'a':
        case 'i':
            if (!argv[2]) {
                hk_err("must provide an entry to add\n");
                return HK_NOK;
            }

            reply = redisCommand(c, "LPUSH " NAMESPACE " %s", key_string);
            freeReplyObject(reply);
            break;

        case 'd':
        case 'r':
            if (!argv[2]) {
                hk_err("must provide an entry number to remove\n");
                return HK_NOK;
            }

            index = atoi(key_string);
            if (index == 0) {
                hk_err("invalid index!");
            }

            redisReply *numTasks;
            numTasks = redisCommand(c, "LLEN " NAMESPACE);
            if (index > numTasks->integer) {
                hk_err("no entry at index %d\n", index);
                return HK_NOK;
            }
            freeReplyObject(numTasks);

            redisReply *entry;
            entry = redisCommand(c, "LINDEX " NAMESPACE " %d", index - 1);
            reply = redisCommand(c, "LREM " NAMESPACE " 1 %s", entry->str);
            freeReplyObject(entry);
            freeReplyObject(reply);
            break;
        }
    } while (next != -1);

    reply = redisCommand(c, "LRANGE " NAMESPACE " 0 -1");

    int i;
    for (i = 0; i < reply->elements; i++) {
        printf("%d) %s\n", i + 1, reply->element[i]->str);
    }

    freeReplyObject(reply);
    redisFree(c);
    return HK_OK;
}
