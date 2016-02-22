#include "../lib/player.h"
#include "../lib/item.h"
#include "../lib/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

player *player_create(void) {
    char player_name[32];
    char player_gender[32];
    char player_age_[4];

    printf("your name: ");
    fgets(player_name, 32, stdin);
    
    int len = (int) strlen(player_name) - 1;
    strip_newline(player_name, len);
    
    unsigned int player_age = 0;
    char ch;
    int i = 0;

    printf("your age: ");
    while (player_age == 0) {
        while ((ch = getchar()) != '\n' && ch != EOF)  {
            if (ch >= 48 && ch <= 58) {
                player_age_[i] = ch;
                i++;
            } else {
                flush_stdin();
                printf("your age: ");
            }
        }
        player_age_[i] = '\0';
        player_age = atoi(player_age_);
    }

    printf("your gender: ");
    fgets(player_gender, 32, stdin);

    len = (int) strlen(player_gender) - 1;
    strip_newline(player_gender, len);
    printf("\n");

    player *p = new_player(player_name, player_age, player_gender);
    if (p == NULL) {
        printf("could not create player\n");
        return NULL;
    }

    printf("%s, %u:\n  %s (%s, %s, %s)\n  HP: %d\n  $: %d\n  level %d\n",
           p->name,
           p->age,
           p->gender->name, 
           p->gender->pronouns->nominative,
           p->gender->pronouns->oblique,
           p->gender->pronouns->possessive,
           p->hp, 
           p->money, 
           p->level);

    return p;
}
