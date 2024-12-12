#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{ 
    int l; 
    char n[17]; 
} P;
typedef struct{ 
    int min, max, c; 
    P p[300]; 
} R;
R r[300];
int rc = 0;

int cmp(const void *a, const void *b) {
    return strcmp(((P *)a)->n, ((P *)b)->n);
}

void create_room(P pl){
    r[rc].min = pl.l - 10;
    r[rc].max = pl.l + 10;
    r[rc].c = 0; // 초기화
    r[rc].p[r[rc].c++] = pl;
    rc++;
}

void add_player_to_room(P pl, int m){
    for (int i = 0; i < rc; i++) {
        if (r[i].c < m && pl.l >= r[i].min && pl.l <= r[i].max) {
            r[i].p[r[i].c++] = pl;
            return;
        }
    }
    create_room(pl);
}

void print_room_status(R room, int m) {
    qsort(room.p, room.c, sizeof(P), cmp);
    printf("%s\n", room.c == m ? "Started!" : "Waiting!");
    for (int j = 0; j < room.c; j++) {
        printf("%d %s\n", room.p[j].l, room.p[j].n);
    }
}

void print_rooms(int m) {
    for (int i = 0; i < rc; i++) {
        print_room_status(r[i], m);
    }
}

int main() {
    int p, m;
    scanf("%d %d", &p, &m);
    while (p--) {
        P pl;
        scanf("%d %s", &pl.l, pl.n);
        add_player_to_room(pl, m);
    }
    print_rooms(m);
    return 0;
}