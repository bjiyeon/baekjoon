#include<stdio.h>
int main(){
    char input[1000000];
    int spell[26]={0,};
    int count=0;
    char num='?';
    int i,j;
    scanf("%s",input);
    for(i=0;input[i]!='\0';i++){
        if(input[i]>='a'){
            input[i]=input[i]-32;
        }
        spell[input[i]-65]++;
    }
    for(j=0;j<26;j++){
        if(spell[j]>count){
            count=spell[j];
            num=j;
        }
        else if(spell[j]==count){
            num='?';
        }
    }
    if(num!='?')printf("%c",num+65);
    else printf("?");
    return 0;
}