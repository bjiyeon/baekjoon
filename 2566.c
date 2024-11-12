#include<stdio.h>
int main(){
    int a,i,j,x,y;
    int max=-1;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            scanf("%d",&a);
            if(max<=a){
                max=a;
                x=i;
                y=j;
            }
        }
    }
    printf("%d \n%d %d",max,x,y);
    return 0;
}