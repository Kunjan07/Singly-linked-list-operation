#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *info;
};

void iatb(struct node **head_ref,  int data1){

    struct node *new node = (struct node)*malloc(sizeof(struct node));
    new node ->data=data1;
    new node->info=(*head_ref);
    *head_ref=new node;

}

void printlist(struct node *n){

    while(n!=NULL){
        printf("%d\n",n->data);
        n=n->info;
    }

}


int main(){

    struct node *one ;
    struct node *two ;
    struct node *three ;
    struct node *head ;

    
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one ->data=53321;
    two -> data=9020;
    three ->data=98989;

    one ->info=two;
    two -> info=three;
    three-> info =NULL;
    head=one;
    iatb(&head,88);
    printlist(head);

    return 0;
}