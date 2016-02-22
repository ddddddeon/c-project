#ifndef PLAYER_H
#define PLAYER_H

typedef enum {
    M,
    F,
    NB
} gender_type;

typedef struct {
    char *nominative;
    char *oblique;
    char *possessive;
} pronouns;

typedef struct {
    gender_type gender;
    pronouns *pronouns;
    char* name;
} gender;

typedef struct {
    char *name;
    unsigned int age;
    gender *gender;
    int hp;
    int money;
    int level;

} player;

player *new_player(char name[32], unsigned int age, char gender[32]);
gender *new_gender(char g[32]);
gender_type str_to_gender_type(char g[32]);
void destroy_player(player *p);
#endif
