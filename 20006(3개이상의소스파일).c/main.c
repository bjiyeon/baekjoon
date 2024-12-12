#include <stdio.h>
#include "room.h"

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    while (p--) {
        Player pl;
        scanf("%d %s", &pl.l, pl.n);
        add_player_to_room(pl, m);
    }
    print_rooms(m);
    return 0;
}