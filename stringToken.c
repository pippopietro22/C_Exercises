#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define lenMax (1000);

int main(){
    char str[] ="hello guys!!! heheheheh";
    const char delim[] = " !";
    char *token =  strtok(str,delim);

    while(token != NULL){
        printf("%s\n",token);
        token = strtok(NULL,delim);
    }

    return 0;
}