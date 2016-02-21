#include "player.h"
#include "util.h"

#include <stdio.h>
#include <string.h>

int main(void) {
    char player_name[32];
    char player_gender[32];
    int len;

    printf("your name: ");
    fgets(player_name, 32, stdin);

    len = (int) strlen(player_name) - 1;
    strip_newline(player_name, len);

    printf("your gender: ");
    fgets(player_gender, 32, stdin);

    len = (int) strlen(player_gender) - 1;
    strip_newline(player_gender, len);

    player *p = new_player(player_name, player_gender);
    if (p == NULL) {
	printf("could not create player\n");
	return 1;
    }

    printf("%s:\n  %s (%s, %s, %s)\n  %dhp\n  $%d\n  level %d\n",
	   p->name, p->gender->name, 
	   p->gender->pronouns.nominative,
	   p->gender->pronouns.oblique,
	   p->gender->pronouns.possessive,
	   p->hp, p->money, p->level);

    return 0;
}
