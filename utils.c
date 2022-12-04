#include "utils.h"




pointer createNode(Disk value){
    pointer newNode = (pointer)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}





/* 
push an element to the stack after checking if 
the first constraint (the new disk should be smaller than the top of the stack) is verified
*/
void push(pointer* head,Disk value){
    if(*head){
        if(getDiskSize(value) > getDiskSize(peek(*head))){
           printf("Constraint violated !\n");
           return;
        }
    }
    pointer newNode = createNode(value);
    if(*head != NULL){
         newNode->next = *head;
         *head = newNode;
    }else *head = newNode;
}
/*
 remove an element from the stack and returning it's value
*/
Disk pop(pointer* head){
    Disk tmp = (*head)->value;
    *head = (*head)->next;
    return tmp;
}

/*
get the value of the top element of the stack
without removing it
*/

Disk peek(pointer head){
    return head->value;
}

void displayList(pointer head){
    while(head){
        if(head->next){
            printf("%d --> " , head->value.size);
        }
        else printf("%d" , head->value.size);
        head = head->next;
    }
    printf("\n");
}
int listSize(pointer head){
    int size = 0;
    while(head){
        size++;
        head = head->next;
    }
    return size;
}



int getTheTemporaryPiquetNumber(int piquet1 , int piquet2){
        if((piquet1 == 1 && piquet2 == 2) || (piquet1 == 2 && piquet2 == 1))
            return 3;
        else if((piquet1 == 1 && piquet2 == 3) || (piquet1 == 3 && piquet2 == 1))
            return 2;
        else if((piquet1 == 2 && piquet2 == 3) || ((piquet1 == 3 && piquet2 == 2)))
            return 1;
        return 0;
}

char* getPiquetTitle(int piquetNumber){
    switch(piquetNumber){
        case 1:
            return "PIQUET 1";
            break;
        case 2:
            return "PIQUET 2";
            break;
        case 3:
            return "PIQUET 3";
            break;
        default : return "ERROR";
    }
}


