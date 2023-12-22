#include <stdio.h>
int btree[20],b[20],ch,k,i,j,temp,item,s;
void insert(int item){
      printf("l/r:");
      scanf("%d",&ch);
      if (ch==1){
        btree[2*i+1]=item;
      }
      else if(ch==0){
        btree[2*i+2]=item;
      }
      else{
        return;
      }
 }
void sort(){
  for(i=1;i<k;i++){
    temp=b[i];
    for(j=i-1;j>=0;j--){
      if (b[j]>temp){
        b[j+1]=temp;
        s=j;
      }
    }
    b[s]=temp;
  }
}
void display(){
  for(i=0;i<k;i++){
    printf("%d ",b[i]);
  }
}
void main(){
  for(i=0;i<20;i++){
    btree[i]=-1;
  }
  for(i=0;i<5;i++){
  printf("item:");
  scanf("%d",&item);
  insert(item);}
  k=0;
  for(i=0;i<20;i++){
    if(btree[i]!=-1)
      b[k]=btree[i];
      k++;
  }
  sort();
  display();
}