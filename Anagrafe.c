#include<stdio.h>
#include<string.h>

typedef enum{
    dirigente,
    quadro,
    operaio,
    impiegato
}ruolo_t;

typedef struct{
    int cf;
    int age;
    float wage;
    int role;
}person;

int main(){
    char choice;
    char keepGoing = 'y';
    person mgm[6];
    int count = 0;
    float sum = 0.0;

    while(keepGoing == 'y'){
        while(1){
            printf("i/o ?\n");
            scanf(" %c", &choice);
            if(choice == 'i' || choice == 'o'){
                break;
            }else {
                printf("Not valid! Retry.\n");
            }
        }

        if(choice =='i'){
            char input = 'y';
            while(input != 'n' && count < 6){
                printf("cf> ");
                scanf("%d", &mgm[count].cf);
                printf("age> ");
                scanf("%d", &mgm[count].age);
                printf("wage> ");
                scanf("%f", &mgm[count].wage);
                printf("role(\n");
                printf(" 0) dirigente\n");
                printf(" 1) quadro\n");
                printf(" 2) operaio\n");
                printf(" 3) impiegato\n");
                printf(") > ");
                scanf("%d", &mgm[count].role);

                sum += mgm[count].wage;
                count++;
                printf("\n");
                printf("Inserire profilo? (y/n) ");
                scanf(" %c", &input);
            }
        }else{
            if(count == 0){
                printf("Nessun dato registrato!\n");
            }else{
                float ave = sum/(float)count;
                printf("Lavoratori con stipendio inferiore allo stipendio medio\n");
                for(int i = 0; i <= count; i++){
                    if(mgm[i].wage < ave){
                        switch (mgm[i].role){
                            case dirigente:
                                printf("%d %d Dirigente\n", mgm[i].cf, mgm[i].age);
                                break;
                            case quadro:
                                printf("%d %d Quadri\n", mgm[i].cf, mgm[i].age);
                                break;
                            case operaio:
                                printf("%d %d Operaio\n", mgm[i].cf, mgm[i].age);
                                break;
                            case impiegato:
                                printf("%d %d Impiegati\n", mgm[i].cf, mgm[i].age);
                                break;
                            default:
                            printf("Nessuno sotto lo stipendio medio");
                        }
                    }
                }
            }
        }
        while(1){
            printf("Effettuare altre operazioni? (y/n) ");
            scanf(" %c", &keepGoing);
            if(keepGoing == 'y' || keepGoing == 'n') break;
            printf("Comando non valido!");
        }
    }
    return 0;
}