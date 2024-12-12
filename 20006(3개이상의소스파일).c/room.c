#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

Room rooms[300];
int room_count = 0;

void create_room(Player pl) {
    rooms[room_count].min = pl.l - 10;
    rooms[room_count].max = pl.l + 10;
    rooms[room_count].c = 0;
    rooms[room_count].p[rooms[room_count].c++] = pl;
    room_count++;
}

void add_player_to_room(Player pl, int max_players) {
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].c < max_players && pl.l >= rooms[i].min && pl.l <= rooms[i].max) {
            rooms[i].p[rooms[i].c++] = pl;
            return;
        }
    }
    create_room(pl);
}

void print_rooms(int max_players) {
    for (int i = 0; i < room_count; i++) {
        qsort(rooms[i].p, rooms[i].c, sizeof(Player), compare_players);
        printf("%s\n", rooms[i].c == max_players ? "Started!" : "Waiting!");
        for (int j = 0; j < rooms[i].c; j++) {
            printf("%d %s\n", rooms[i].p[j].l, rooms[i].p[j].n);
        }
    }
}