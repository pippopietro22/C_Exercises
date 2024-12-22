#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR(A){perror(A);exit(1);}

typedef struct capit{
    char *s;
    double lat,lon;
    struct capit *dx,*sx;
}Capitali;

void stampa(Capitali *c);
void stampa_capitali(Capitali *root);
Capitali *capitale_crea(char *s, double lat, double lon);
void capitale_distruggi(Capitali *a);
Capitali *capitaliLeggi(FILE *f);
Capitali *abr_inserisci(Capitali *root, Capitali *c);
Capitali *crea_abr(FILE *f);

int main(){
    FILE *fin=fopen("capitali.txt","r");
    if(!fin)ERROR("Errore Apertura");
    Capitali *root = crea_abr(fin);
    fclose(fin);

    stampa_capitali(root);
    capitale_distruggi(root);
    return 0;
}

void stampa_capitali(Capitali *root){
    if(root != NULL){
        stampa_capitali(root->sx);
        stampa(root);
        stampa_capitali(root->dx);
    }
}

void stampa(Capitali *c){
    printf("%s %lf %lf \n",c->s,c->lat,c->lon);
}

Capitali *capitale_crea(char *s, double lat, double lon){
  Capitali *a  = (Capitali*)malloc(sizeof(*a));
  a->lat = lat;
  a->lon = lon;
  a->s = strdup(s);
  a->sx = a->dx = NULL;
  return a;
}

void capitale_distruggi(Capitali *a){
    if(a != NULL){  
        Capitali *current = a;
        Capitali *nextD = a->dx;
        Capitali *nextS = a->sx;

        free(current->s);
        free(nextD);
        free(nextS);
    }
}

Capitali *capitaliLeggi(FILE *f){
    if(!f) exit(1);
    char *name;
    double lat,lon;
    int e = fscanf(f,"%ms %lf %lf",&name, &lat, &lon);
    if(e!=3){
        if(e == EOF){ 
            return NULL;
        }else{
            printf("Formato file sbagliato!\n");
            return NULL;
        }
    }

    Capitali *res = capitale_crea(name,lat,lon);
    free(name);

    return res;
}


Capitali *abr_inserisci(Capitali *root, Capitali *c){
    if(!c) return root;
    if(!root) return c;
    int conf = strcmp(root->s,c->s);

    if(conf == 0){
        printf("Capitale già inserita\n");
    }else if(conf < 0){
        root->dx=abr_inserisci(root->dx,c);
    }else{
        root->sx=abr_inserisci(root->sx,c);
    }

    return root;
}

Capitali *crea_abr(FILE *f){
    Capitali *root=NULL;
    Capitali *c=NULL;
    while(1){
        c=capitaliLeggi(f);
        if(!c) break;
        root = abr_inserisci(root,c);
    }
    free(c);
    return root;
}