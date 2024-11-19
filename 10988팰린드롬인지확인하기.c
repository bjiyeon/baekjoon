#include<stdio.h>
#include<string.h>
int main(){
    int len,k=1;
    int i;
    char str[100];
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len/2;i++){
        if(str[i]!=str[len-1-i]){
            k=0;
            break;
        }
    }
    printf("%d",k);
    return 0;
}