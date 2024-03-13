#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node{
    char  nom[50];
    char address[50];
    struct Node *next ;
    int isTail;
};

void appendClient(struct Node *head,char* name, char* address,int *initialized,struct Node *previous,struct Node *current){
    
    if(*initialized == 0){
        strcpy(head->nom ,name);
        strcpy(head->address , address);
        head->next = NULL;
        head->isTail = 1;
        *initialized = 1;
    }else{   
        current = head;
        previous=head->next;
        while(previous != NULL){
            current = previous;
           previous = previous->next;

        }
        struct Node *toAppend = malloc(sizeof(struct Node));

        strcpy(toAppend->nom,name);
        strcpy(toAppend->address,address);
        toAppend->next = NULL;
        toAppend->isTail = 1;
        current->next= toAppend;

       
    }
    return;
}

void findClient(char* name, int *initialized,struct Node *head){
    if(*initialized == 0){
        printf( "No Data \n");
    }else{
        struct Node *previous = malloc(sizeof(struct Node));
        previous = head;
        while(previous !=NULL){
            if(strcmp(previous->nom, name) == 0){
                printf("Name: %s - Address: %s \n",previous->nom,previous->address);
            }
            previous = previous->next;
            
        }
    }
    return ;
}

void listClients( int *initialized,struct Node *head){
    if(*initialized == 0){
        printf( "No Data \n");
    }else{
        struct Node *previous = malloc(sizeof(struct Node));
        previous = head;
        while(previous !=NULL){
            printf("Name: %s - Address: %s \n",previous->nom,previous->address);
            
            previous = previous->next;
            
        }
    }
    return ;
}

int main (){

   struct Node *headNode = NULL; 
   headNode = malloc(sizeof(struct Node));
   int initialized = 0;
        
    struct Node *previous = malloc(sizeof(struct Node));
    previous->next = NULL;
    
    struct Node *current= NULL;
    previous = malloc(sizeof(struct Node));
    char answer ='n';
    char choice =0;
    char choiceSecond=0;

    char name[50];
    char address[50];
    char clientToFind[50];
        printf("What do you want to do? \n 1 Enter a client \n 2 Search for a Client\n 3 List all clients\n 4 Exit");
        scanf("%c",&choice);
        while(choice !='4'){ 
            while(choice == '1'){
                printf("Name please. \n");
                scanf("%s",name);
                if(strcmp(name,"exit")==0){
                    break;
                }
                printf("Address please.\n" );
                scanf("%s",address);

                appendClient(headNode,name,address,&initialized,previous,current);
                
                
                

            }
            if(choice == '2'){
                printf("Enter Client's name.\n");
                scanf("%s", clientToFind);
                findClient(clientToFind, &initialized,headNode);
            }
            if(choice == '3'){
                listClients(&initialized,headNode);
            }
            if(choice == 4){
                break;
            }
            printf("What do you want to do? \n 1 Enter a client \n2 Search for a Client\n 3 List all clients\n 4 Exit");
            scanf("%c",&choice);
        }
    return 0;   
}
