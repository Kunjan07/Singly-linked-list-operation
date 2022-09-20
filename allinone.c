#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node * info;

};

void printlist(struct node *n){
    int i=0;
    while (n!=NULL){
        printf("NODE %d : %d\n",i,n->data);
        printf("INFO : %d\n",n->info);
        n=n->info;
        printf("\n");
        i++;
    }

}


void counter(struct node *n){
    int count=0;
    while (n!=NULL){

       count ++;
       n=n->info;
    }
    
    printf("NUMBER OF NODES IN THE LINKED LIST : %d\n",count);
}

void insertathead(struct node ** head , int ndata){

    struct node *temp;
    struct node *new_node;
    new_node=malloc(sizeof(struct node ));
    temp=*head;
    new_node->data=ndata;
    new_node->info=temp;
    *head=new_node;

}


void deletathead(struct node ** head){

    struct node *temp;
    struct node *new_node;
    temp=*head;
    new_node=temp->info;
    temp->info=NULL;
    *head=new_node;
}


void insertatend(struct node ** head , int ndata){

    struct node *temp;
    struct node *new_node;
    new_node=malloc(sizeof(struct node ));
    temp=*head;
    do {

        temp=temp->info;
        
    }while(temp->info!=NULL);
    

    new_node->data=ndata;
    new_node->info=NULL;
    temp->info=new_node;

}

void cyclemaker(struct node ** head){
    struct node *temp;
    struct node *new_node;
    temp=*head;
    do {

        temp=temp->info;
        
    }while(temp->info!=NULL);
    temp->info=*head;
}

void insertatany(struct node ** head , int n1data , int pos){

    struct node *temp;
    struct node *temp1;
    struct node *new_node;
    new_node=malloc(sizeof(struct node ));
    temp=malloc(sizeof(struct node ));
    temp=*head;

    for (int i = 1; i < pos; i++){

        temp=temp->info;
    }
    new_node->info=temp->info;
    temp->info=new_node;
    new_node->data=n1data;
    

}

void deleteatany(struct node ** head , int pos){

    struct node *temp;
    temp=malloc(sizeof(struct node ));
    temp=*head;

    for (int i = 1; i < pos; i++){

        temp=temp->info;
    }
    temp->info=temp->info->info; 
    temp->info->info=NULL;
    

}

int main(){


    struct node *one ;
    struct node *two;
    struct node *three;
    struct node *`head;

    one = malloc(sizeof(struct node)) ;
    two = malloc(sizeof(struct node)) ;
    three = malloc(sizeof(struct node)) ;

    one -> data=35;
    one ->info=two;

    two ->data=2352;
    two ->info=three;

    three->data=532;
    three->info=NULL;

    head=one;
    insertathead(&head, 32);
    insertathead(&head, 62);
    insertathead(&head, 2);
    insertatend(&head ,100);
    insertatany(&head,777,6);
    deleteatany(&head ,6);
    deleteatany(&head ,2);
    // cyclemaker(&head);
    // deletathead(&head);
    

    printlist(head);
    counter(head);

    return 0;
}
