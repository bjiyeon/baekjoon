#include <string.h>
#include "room.h"

int compare_players(const void *a, const void *b) {
    return strcmp(((Player *)a)->n, ((Player *)b)->n);
}