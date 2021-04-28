#include <string.h>
#include <stdlib.h>
#include "hashtbl.h"
#include <math.h>

static item* new_item(const char* key, const char* value)
{
    item* i = malloc(sizeof(item));

    i->key = strdup(key);
    i->value = strdup(value);

    return i;
}

hashtbl* new()
{
    hashtbl* tbl = malloc(sizeof(hashtbl));

    tbl->size = 53;
    tbl->count = 0;
    tbl->items = calloc((size_t)tbl->size, sizeof(item*));

    return tbl;
}

static void delete_item(item* i)
{
    free(i->key);
    free(i->value);
    free(i);
}

void delete_tbl(hashtbl* ht)
{
    for (int i=0; i<ht->size; i++)
    {
        item* item = ht->items[i];
        if (item != NULL)
            delete_item(item);
    }

    free(ht->items);
    free(ht);
}

int hash(const char* s, const int a, const int m)
{
    long hash = 0;
    const int len_s = strlen(s);

    for (int i=0; i < len_s; i++)
    {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }

    return (int)hash;
}

int main()
{
    hashtbl* ht = new();
    delete_tbl(ht);
}