#ifndef ITEM_H
#define ITEM_H

#define INVENTORY_LIMIT 1024

typedef struct {
    char *name;
    unsigned int price;
} item;

typedef struct {
    item *items;
    unsigned int latest;
} inventory;

inventory *new_inventory();
item *new_item(char *name, unsigned int price);
int add_item(item *i, inventory *inv);
int remove_item(item *i, inventory *inv);
void destroy_inventory(inventory *inv);

#endif
