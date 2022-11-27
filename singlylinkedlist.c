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
void insert_beg(int item){
    ptr=header;
    node* new=(node*)malloc(sizeof(node));
    if (new==NULL){
        printf("Insufficient memory");
    }
    else{
        new->data=item;
        new->link=header->link;
        header->link=new;
        ptr=ptr->link;
    }
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
void insert_any(int item,int pos){
    node* new=(node*)malloc(sizeof(node));
    ptr=header;
    while(ptr->link!=NULL && ptr->data!=pos){
        ptr=ptr->link;
    }
    new->link=ptr->link;
    ptr->link=new;
    new->data=item;
}
void delete_beg(){
    ptr=header->link;
    if(ptr==NULL){ 
        printf("NO LIST\n");
    }
    else{
        header->link=ptr->link;
        free(ptr);
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
void delete_any(int pos){
    ptr=header;
    node* ptr1=ptr->link;
    if(ptr==NULL){ 
        printf("NO LIST\n");
    }
    else{
        while(ptr->link!=NULL && ptr->data!=pos){
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=ptr->link;
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
        printf("CHOOSE : \n1.Insert at Beginning\n2.Insert at End\n3.Insert at a Specified Position\n4.Delete from a Specified Position\n5.Delete from Beginning\n6.Delete from End\n7.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1 :{
                printf("Enter item to be inserted : ");
                scanf("%d",&item);
                insert_beg(item);
                display();
                break;
            }
            case 2 :{
                printf("Enter item to be inserted : ");
                scanf("%d",&item);
                insert_end(item);
                display();
                break;
            }
            case 3 :{
                printf("Enter item to be inserted : ");
                scanf("%d",&item);
                printf("Enter data after which you wish to insert : ");
                scanf("%d",&pos);
                insert_any(item,pos);
                display();
                break;
            }
            case 4 :{
                printf("Enter the data to be deleted : ");
                scanf("%d",&pos);
                delete_any(pos);
                display();
                break;
            }
            case 5 :{
                delete_beg();
                display();
                break;
            }
            case 6 :{
                delete_end();
                display();
                break;
            }
        }
    }
    while(ch<7);
}