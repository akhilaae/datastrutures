#include <stdio.h>
typedef struct{
 struct node* lchild;
 int data;
 struct node* rchild;
}node;
node* root,*temp,*ptr,*ptr1,*lc,*rc;
int key,item;
node* create(){
  int x;
  node* new=(node*)malloc(sizeof(node));
  printf("data?(-1 if none):");
  scanf("%d",&x);
  if(x==-1){
    return NULL;
  }
  else{
    new->data=x;
    printf("l of %d:",x);
    new->lchild=create();
    printf("r of %d:",x);
    new->rchild=create();
    return new;
  }
}
void createroot(){
  root=(node*)malloc(sizeof(node));
  root=create();
}
node* searchlink(node* ptr0,int key){
  if(ptr0->data!=key){
    if(ptr0->lchild!=NULL){
      ptr1=searchlink(ptr0->lchild,key);
    }
    else {ptr1=NULL;}
    if(ptr1==NULL){
    if(ptr0->rchild!=NULL){
      ptr1=searchlink(ptr0->rchild,key);
    }
    else {return NULL;}}
  }
  else return ptr0;
}
void insert(int key,int item){
  int ch1;
  node* ptr=searchlink(root,key);
  if(ptr==NULL){
    printf("not found");
    return;
  }
  if(ptr->lchild==NULL || ptr->rchild==NULL){
  printf("L or R(1/0)");
  scanf("%d",&ch1);
  if(ch1==1){
    if(ptr->lchild==NULL){
      node *new=(node*)malloc(sizeof(node));
      ptr->lchild=new;
      new->lchild=new->rchild=NULL;
      new->data=item;
    }
    else{
      printf("no free lchild");
      return;
    }
  }
  if(ch1==0){
    if(ptr->rchild==NULL){
      node *new=(node*)malloc(sizeof(node));
      ptr->rchild=new;
      new->lchild=new->rchild=NULL;
      new->data=item;
    }
    else{
      printf("no free rchild");
      return;
    }
  }
  }
  else{
    printf("no free lc or rc");
    return;
  }
}
void inorder(node *temp){
  if (temp!=NULL){
    inorder(temp->lchild);
    printf("%d ",temp->data);
    inorder(temp->rchild);
  }
}

void preorder(node *temp){
  if (temp!=NULL){
    printf("%d ",temp->data);
    preorder(temp->lchild);
    preorder(temp->rchild);
  }
}
void postorder(node *temp){
  if (temp!=NULL){
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d ",temp->data);
  }
}
void main(){
  int ch,item;
  createroot();
  do{
    printf("CHOOSE:\n1.Insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\nchoice =");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        printf("entr item after ehich to be inserted");
        scanf("%d",&key);
        printf("entr data to insert:");
        scanf("%d",&item);
        insert(key,item);
        break;
      }
      case 2:{
        inorder(root);
        break;
      }
      case 3:{
        preorder(root);
        break;
      }
      case 4:{
        postorder(root);
        break;
      }
      case 5:{
        delete()
        break;
      }
    }
  }
  while(ch<=5);
}