#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node;
node* header;
node* ptr;
void getheader(){
    header=(node*)malloc(sizeof(node));
    header->link=NULL;
}
void insert_end(int item){
    node* new=(node*)malloc(sizeof(node));
    ptr=header;
    if (new==NULL){
        printf("Insufficient memory");
    }
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=new;
        new->link=NULL;
        new->data=item;
    }
}
void delete_end(){
    ptr=header->link;
    node* ptr1=header;
    if(ptr==NULL){ 
        printf("NO LIST\n");
    }
    else{
        while(ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        free(ptr);
    }
}
void display(){
    node* ptr0=header;
    while(ptr0->link!=NULL){
        ptr0=ptr0->link;
        printf("%d ",ptr0->data);
    }
    printf("\n");
}
void main(){
    int ch,item,pos;
    getheader();
    do{
        printf("CHOOSE : \n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1 :{
                printf("Enter item to be inserted : ");
                scanf("%d",&item);
                insert_end(item);
                display();
                break;
            }
            case 2 :{
                delete_end();
                display();
                break;
            }
            case 3 :{
                display();
                break;
            }
        }
    }
    while(ch<4);
}