#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char n[36]={0};
    int i,b,a=0;
    scanf("%s %d",n,&b);
    for(i=0;i<strlen(n);i++){
        if(n[i]>='A'&&n[i]<='z'){
            a+=(n[i]-55)*pow(b,strlen(n)-i-1);
        }
        else{
            a+=(n[i]-48)*pow(b,strlen(n)-i-1);
        }
    }
    printf("%d",a);
    return 0;
}