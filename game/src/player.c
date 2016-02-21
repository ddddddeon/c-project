#include "player.h"

#include <malloc.h>
#include <string.h>

player *new_player(char name[32], unsigned int age, char gender[32]) {
    player *new = malloc(sizeof(player));
    
    if (strlen(name)   > 32   ||
        strlen(gender) > 32   ||
	age            == 0   ||
	new            == NULL)  {

        return NULL;
    }
    
    new->name = strdup(name);
    new->age = age;
    new->gender = new_gender(gender);
    new->hp = 100;
    new->money = 100;
    new->level = 1;

    return new;
}

gender *new_gender(char g[32]) {
    if (strlen(g) > 32) {
        return NULL;
    }
    
    gender *new = malloc(sizeof(gender));
    pronouns *p = malloc(sizeof(pronouns));
    gender_type gender = str_to_gender_type(g);

    if (gender == F) {
        *p = (pronouns) { 
            "she", 
            "her", 
            "her" 
        };

    } else if (gender == M) {
        *p = (pronouns) { 
            "he", 
            "him", 
            "his" 
        };

    } else {
        *p = (pronouns) { 
            "they", 
            "them", 
            "their" 
        };
    }

    new->pronouns = p;
    new->gender = gender;
    new->name = g;

    return new;
}

gender_type str_to_gender_type(char g[32]) {
    gender_type gender;

    if (strcmp(g, "female") == 0  || 
        strcmp(g, "woman")  == 0  ||
        strcmp(g, "f")      == 0  ||
        strcmp(g, "F")      == 0  ||
        strcmp(g, "girl")   == 0  || 
        strstr(g, "ess") != NULL  )  {

        gender = F;
    
    } else if (strcmp(g, "male") == 0  || 
               strcmp(g, "man")  == 0  ||
               strcmp(g, "m")    == 0  || 
               strcmp(g, "M")    == 0  ||
               strcmp(g, "boy")  == 0  )  {

        gender = M;

    } else {

        gender = NB;
    }

    return gender;
}

void destroy_player(player *p) {
    free(p->gender->pronouns);
    free(p->gender);
    free(p->name);
    free(p);
}
