#include <stdio.h>
typedef struct{
 struct node* lchild;
 int data;
 struct node* rchild;
}node;
node* head,*temp,*ptr,*lc,*rc;

void create(node* ptr,int num){
  int x,ch1;
  if(ptr!=NULL){
    ptr->data=num;
    printf("Push to L of %d(1/0)?",num);
    scanf("%d",&ch1);
    if(ch1==1){
      lc=(node*)malloc(sizeof(node));
      ptr->lchild=lc;
      printf("data for lc : ");
      scanf("%d",&x);
      create(lc,x);
      printf("%d",ptr->data);
    }
    else{
      //lc=(node*)malloc(sizeof(node));
      //lc=NULL;
      //ptr->lchild=NULL;
      //create(ptr->lchild,NULL)
      return NULL;
    }
    printf("push r for %d(1/0):",num);
    scanf("%d",ch1);
    if(ch1==1){
      rc=(node*)malloc(sizeof(node));
      ptr->rchild=rc;
      printf("data for r : ");
      scanf("%d",&x);
      create(rc,x);
    }
    else{
      //rc=(node*)malloc(sizeof(node));
      //rc=NULL;
      //ptr->rchild=NULL;
      
      //create(ptr->rchild,NULL);
      return NULL;
    }
  }
}
void inorder(node *temp){
  if (temp!=NULL){
    inorder(temp->lchild);
    printf("%d",temp->data);
    inorder(temp->rchild);
  }
}



void main(){
  int ch,item;
  do{
    printf("CHOOSE:\n1.Insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\nchoice =");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        head=(node*)malloc(sizeof(node));
        printf("data : ");
        scanf("%d",&item);
        create(head,item);
        break;
      }
      case 2:{
        temp=head;
        inorder(temp);
        break;
      }
    }
  }
  while(ch<=2);
}