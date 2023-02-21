#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct elem{
    int number;
    struct elem *next;
}t_elem;


void inicjuj(t_elem *stos){
    stos = NULL;
}

t_elem* push(t_elem* stos,int data)
{
    t_elem* tmp = (t_elem*)malloc(sizeof(t_elem));
    tmp->number = data;
    tmp->next = stos;
    stos = tmp;
    return stos;
}


t_elem* pop(t_elem *stos, int *elem){
       t_elem *tmp = stos;
       *elem = stos->number;
       stos = stos->next;
       free(tmp);
       return stos;
}

int empty(t_elem *stos){
    return stos == NULL ? 1 : 0;
}

void print(t_elem *stos){
    
    t_elem *tmp;
    tmp = stos;
    if(tmp!= NULL)
    {
        do
        {
            printf("%d ",tmp->number);
            tmp = tmp->next;
        }
        while (tmp!= NULL);
        printf("\n");
    }

}


t_elem* dodaj(t_elem *stos){
    int a, b;
    a = stos -> number;
    stos = pop(stos,&stos->number);
    b = stos -> number;
    stos = pop(stos,&stos->number);
    stos = push(stos,a + b);

    return stos;
}

t_elem* odejmij(t_elem *stos){
    int a, b;
    a = stos -> number;
    stos = pop(stos,&stos->number);
    b = stos -> number;
    stos = pop(stos,&stos->number);
    stos = push(stos, b - a);

    return stos;
}





int main(){

    t_elem* stos = NULL, *spr = NULL;
    inicjuj(stos);
    inicjuj(spr);
    stos = push(stos,1);
    stos = push(stos,2);

    printf("Stos po inicjacji\n");
    print(stos);

    stos = dodaj(stos);

    printf("Stos po dodaniu\n ");
    print(stos);

    stos = push(stos,2);

    printf("Stos przed odejmowaniem\n");
    print(stos);


    stos = odejmij(stos);

    printf("Stos po odejmowaniu\n");
    print(stos);    

    return 0;
}