#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define ERROR(A){perror(A); exit(1);}

typedef struct{
    char titolo[N];
    char autore[N];
    int anno;
    int copie;
}Libro;

int cmp(const void *l1, const void *l2){
    Libro *ll1 = (Libro*)l1;
    Libro *ll2 = (Libro*)l2;
    if(ll1->anno != ll2->anno){
        return ll1->anno - ll2->anno;
    }else{
        return -strcmp(ll1->autore,ll2->autore);
    }
}

int main(){
    FILE *fin=fopen("prova.txt","r");
    if(!fin){
        ERROR("Apertura fallita: ");
    }

    Libro cat[N];
    char testo[N];
    int x;
    int n=0;

    while(fgets(testo,N-1,fin)){
        char *token= strtok(testo,",");
        strcpy(cat[n].titolo,token);
        token = strtok(NULL,",");
        strcpy(cat[n].autore,token);
        token = strtok(NULL,",");
        cat[n].anno = atoi(token);
        token = strtok(NULL,",");
        cat[n].copie = atoi(token);
        if(cat[n].copie == 0){
            n++;
        }
    }
    fclose(fin);
    qsort(cat,n,sizeof(Libro),cmp);

    for(int i = 0; i < n; i++){
        printf("%s, %s, %d\n", cat[i].titolo, cat[i].autore, cat[i].anno);
    }

    return 0;
}

