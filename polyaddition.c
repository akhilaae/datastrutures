#include <stdio.h>
struct poly{
  int coef;
  int expo;
}p1[10],p2[10],p3[10];
int i,j,k,t1,t2,p;
void readPoly(){
  printf("Enter no of terms in poly1 : ");
  scanf("%d",&t1);
  printf("Enter no of terms in poly2 : ");
  scanf("%d",&t2);
  printf("Enter coef and expo poly1 : \n");
  for (i=0;i<t1;i++){
    scanf("%d %d",&p1[i].coef,&p1[i].expo);
  }
   printf("Enter coef and expo poly2 : \n");
  for (i=0;i<t2;i++){
    scanf("%d %d",&p2[i].coef,&p2[i].expo);
  }
}
void sumPoly(){
  i=0;j=0;k=0;
  while(i<t1&&j<t2)
  {
    if (p1[i].expo==p2[j].expo){
      p3[k].coef=p1[i].coef+p2[j].coef;
      p3[k].expo=p1[i].expo;
      i++;j++;k++;
    }
    else if (p1[i].expo>p2[j].expo){
      p3[k].coef=p1[i].coef;
      p3[k].expo=p1[i].expo;
      i++;k++;
    }
    else if (p1[i].expo<p2[j].expo){
      p3[k].coef=p2[j].coef;
      p3[k].expo=p2[j].expo;
      j++;k++;
    }
  }
  while(i<t1){
    p3[k].coef=p1[i].coef;
      p3[k].expo=p1[i].expo;
      i++;k++;
  }
  while (j<t2){
    p3[k].coef=p2[j].coef;
      p3[k].expo=p2[j].expo;
      j++;k++;
  }
}
void displayPoly(struct poly P[10],int n){
  for (i=0;i<n;i++){
    printf("%dx^%d",P[i].coef,P[i].expo);
    if (i!=n-1)
    printf("+");
  }
  printf("\n");
}
void main(){
  readPoly();
  sumPoly();
  printf("Poly1 : \n");
  displayPoly(p1,t1);
  printf("Poly2 : \n");
  displayPoly(p2,t2);
  printf("Sum : \n");
  displayPoly(p3,k);
}
