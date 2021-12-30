#include <stdio.h>
#include <stdlib.h>


int main(){
    char nextChar;
    while(scanf("%c",&nextChar) != EOF){
    printf("%c",nextChar);
    }
    ungetc(nextChar,stdin);
    ungetc('Q', stdin);
    scanf("%c", &nextChar);
    printf("%c",nextChar);


}