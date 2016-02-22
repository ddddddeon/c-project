#include "lib/player.h"
#include "lib/item.h"
#include "lib/util.h"
#include "screens/screens.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    player *p = player_create();

    p->hp--;
    printf("HP: %d \n", p->hp);
    
    /* item test */
    inventory *inv = new_inventory();
    item *potion = new_item("potion", 5);
    if (add_item(potion, inv) < 0) {
        printf("inventory full!\n");
    }
    
    unsigned int idx = inv->latest - 1;
    printf("%s: $%d \n", inv->items[idx].name,
           inv->items[idx].price);

    /* free memory */
    remove_item(potion, inv);
    destroy_inventory(inv);
    destroy_player(p);

    return 0;
}
