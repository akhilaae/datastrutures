#include <stdio.h>
int p[10][2],i,j,k,t1,t2,*af,*al,*bf,*bl;
void readPoly(){
  printf("size1:");
  scanf("%d",t1);
  printf("size2 : ");
  scanf("%d",t2);
  *af=p[0][1];
  for (i=0;i<t1;i++)
    scanf("%d %d",&p[i][0],&p[i][1]);
  *al=p[i-1][1];
  *bf=p[i][1];
  for (j=i;j<t2+t1;j++)
    scanf("%d %d",&p[j][0],&p[j][1]);
  *bl=p[j-1][1];
}
void sumPoly(){
  /*int large=p[0][1];
  for (k=1;k<t1+t2;k++){
    if (p[k][1]>large)
      large=p[k][1];
  }
  for (k=0;k<t1+t2;k++){
    if
  }*/
  for (k=0;k)
}
void main{
  readPoly();
  sumPoly();
  displayPoly();
}