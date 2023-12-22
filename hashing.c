#include <stdio.h>
int b[10],k,max,i,j;
typedef struct{
  int data;
  struct node* link;
}node;
node* a[10],*temp;
void insert1(int x){
  node* new=(node*)malloc(sizeof(node));
  new->data=x;
  new->link=NULL;
  k=x%7;
  if(a[k]->link==NULL){
    a[k]->link=new;
  }
  else{
    temp=a[k];
    while(temp->link!=NULL){
      temp=temp->link;
    }
    temp->link=new;
  }
}
void insert2(int x){
  k=x%7;
  if(b[k]==-1){
    b[k]=x;
  }
  else{
    for(j=k+1;j<7;j++){
      if(b[j]==-1){
        b[j]=x;
        return;
      }
    }
    for(j=0;j<k;j++){
      if(b[j]==-1){
        b[j]=x;
        return;
      }
    }
  }
}
void display2(){
  for(i=0;i<7;i++){
    printf("%d %d\n",i,b[i]);
  }
}
void display1(){
  for(i=0;i<7;i++){
    printf("%d: ",i);
    temp=a[i];
    while(temp->link!=NULL){
      temp=temp->link;
      printf("%d ",temp->data);
    }
    printf("\n");
  }
}
void main(){
  int item;
  printf("enter no of input : ");
  scanf("%d",&max);
  for (i=0;i<7;i++){
    a[i]=(node*)malloc(sizeof(node));
    b[i]=-1;
  }
  for (i=0;i<max;i++){
    printf("data : ");
    scanf("%d",&item);
    insert1(item);
    insert2(item);
  }
  display1();
  display2();
}