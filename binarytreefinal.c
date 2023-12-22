#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int data;
  struct node* l;
  struct node* r;
}node;
node* root,*ptr,*temp;
int item,key,ch;
void getroot(){
  root=(node*)malloc(sizeof(node));
  root->l=NULL;
  root->r=NULL;
  root=NULL;
}
node* searchnode(node* p,int key){
  node* p1=NULL;
  if(p->data!=key){
    if(p->l!=NULL){
      //ptr=ptr->l;
      p1=searchnode(ptr->l,key);
      if(p1!=NULL){
        return(p1);
      }
    }
    else if(p->r!=NULL){
      //ptr=ptr->r;
      p1=searchnode(p->r,key);
      if(p1!=NULL){
        return (p1);
      }
    }
   }
   else{
     return(p);
   }
}
void insert(int x){
  node* new=(node*)malloc(sizeof(node));
  new->data=x;
  new->l=NULL;
  new->r=NULL;
  if(root==NULL){
    root=new;
  }
  else{
    printf("key:");
    scanf("%d",&key);
    ptr=searchnode(root,key);
    if(ptr==root){
      printf("l/r?");
      scanf("%d",&ch);
      if (ch==1){
        root->l=new;
        return;
      }
      else{
        root->r=new;
        return;
      }
    }  
    if(ptr->l!=NULL || ptr->r!=NULL){
    printf("l/r?");
    scanf("%d",&ch);
    if (ch==1){
      if(ptr->l==NULL){
        ptr->l=new;
      }
      else{
        printf("no");
      }
    }
    else{
      if(ptr->r==NULL){
        ptr->r=new;
      }
      else{
        printf("no");
      }
    }}
  }
}
void inorder(node* ptr){
  if(ptr!=NULL){
    inorder(ptr->l);
    printf("%d",ptr->data);
    inorder(ptr->r);
  }
}
void preorder(node* ptr){
  if(ptr!=NULL){
    printf("%d",ptr->data);
    preorder(ptr->l);
    
    preorder(ptr->r);
  }
}
void postorder(node* ptr){
  if(ptr!=NULL){
    postorder(ptr->l);
    
    postorder(ptr->r);
    printf("%d",ptr->data);
  }
}
node* del(node* ptr,int item){
  if(ptr!=NULL){
    ptr->l=del(ptr->l,item);
    ptr->r=del(ptr->r,item);
    if(ptr->l==NULL && ptr->r==NULL && ptr->data==item){
      temp=ptr;
      free(temp);
      temp=NULL;
      ptr=NULL;
      return NULL;
    }
    return ptr;
  }
  else{return NULL;}
}
void main(){
  getroot();
  int ch;
  do{
    printf("1.insert2.in2.pre3.post4.del5.dis");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        printf("data:");
        scanf("%d",&item);
        insert(item);
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
        printf("todel:");
        scanf("%d",&item);
        del(root,item);
        break;
      }
    }
  }
  while(ch<=5);
}