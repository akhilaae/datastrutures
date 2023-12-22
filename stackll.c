#include <stdio.h>
int item;
typedef struct{
  int data;
  struct node* link;
}node;
node *shead;
void getheader(){
  shead=(node*)malloc(sizeof(node));
  shead->link=NULL;
}
void push(int item){
  //insertatend
  node *ptr=shead;
  node *new=(node*)malloc(sizeof(node));
  while(ptr->link!=NULL){
    ptr=ptr->link;
  }
  ptr->link=new;
  new->link=NULL;
  new->data=item;
}
void pop(){
  //deleteatend
  node *ptr=shead,*ptr0;
  node *new=(node*)malloc(sizeof(node));
  while(ptr->link!=NULL){
    ptr0=ptr;
    ptr=ptr->link;
  }
  ptr0->link=NULL;
  free(ptr);
}
void display(){
  node *ptr=shead->link;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
  }
  printf("\n");
}
void main(){
  getheader();
  int ch;
  do{
    printf("CHOOSE : \n1.Push\n2.Pop\nEnter ch : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        printf("item: ");
        scanf("%d",&item);
        push(item);
        display();
        break;
      }
      case 2:{
        pop();
        display();
        break;
      }
    }
  }
  while(ch<=2);
}