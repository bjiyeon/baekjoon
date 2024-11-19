#include<stdio.h>
#include<string.h>
int main(){
    char n[10];
    char tmp;
    int i, j;
    scanf("%s",n);
    for(i=0;i<strlen(n)-1;i++){
        for(j=0;j<strlen(n);j++){
            if(n[j]<n[j+1]){
                tmp=n[j];
                n[j]=n[j+1];
                n[j+1]=tmp;
            }
        }
    }
    printf("%s",n);
    return 0;
}