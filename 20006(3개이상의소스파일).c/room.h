#ifndef ROOM_H
#define ROOM_H

typedef struct {
    int l; 
    char n[17];
} Player;

typedef struct {
    int min, max, c;
    Player p[300];
} Room;

void create_room(Player pl);
void add_player_to_room(Player pl, int max_players);
void print_rooms(int max_players);
int compare_players(const void *a, const void *b);

#endif