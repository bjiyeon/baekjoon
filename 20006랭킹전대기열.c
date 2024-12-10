#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{int l; char n[17];}P;
typedef struct{int min,max,c; P p[300];}R;
R r[300];
int rc;

int cmp(const void *a,const void *b){
    return strcmp(((P *)a)->n,((P *)b)->n);
}

int main(){
    int p,m,i,j;
    scanf("%d %d",&p,&m);
    while(p--){
        P pl;
        scanf("%d %s", &pl.l,&pl.n);
        for(i=0;i<rc;i++){
            if (r[i].c < m && pl.l >= r[i].min && pl.l <= r[i].max){
                r[i].p[r[i].c++] = pl; break; 
            }
        }
        if(i == rc){
            r[rc].min = pl.l - 10;
            r[rc].max = pl.l + 10;
            r[rc++].p[r[rc - 1].c++] = pl;
        }
    }
    for(i=0; i<rc; i++){
        qsort(r[i].p, r[i].c, sizeof(P), cmp);
        printf("%s\n", r[i].c == m ? "Started!" : "Waiting!");
        for(j=0; j<r[i].c; j++){
            printf("%d %s\n", r[i].p[j].l, r[i].p[j].n);
        }
    }
}