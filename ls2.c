#include <stdio.h>
typedef struct{
  int eid;
  char fn[10];
  char mn[10];
  char ln[10];
  int sal;
}e;
e* eptr[10];
int n,i;
void read(int n){
  for(i=0;i<n;i++){
    printf("Eid name sal: ");
    scanf("%d %s %s %s %d",&(eptr[i])->eid,(eptr[i])->fn,(eptr[i])->mn,(eptr[i])->ln,&(eptr[i])->sal);
  }
}
void display(){
  for(i=0;i<n;i++){
    printf("Eid name sal: ");
    printf("%d %s %s %s %d",(eptr[i])->eid,(eptr[i])->fn,(eptr[i])->mn,(eptr[i])->ln,(eptr[i])->sal);
 }
}
void main(){
  for(i=0;i<n;i++){
    eptr[i]=(e*)malloc(sizeof(e));
  }
  
  int ch;
  do{
    printf("CHOOSE:\n1.Input\n2.Search\nEnter ur choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        printf("Enter no of inputs : ");
        scanf("%d",&n);
        read(n);
        display();
      }
    }
  }
  while(ch<=2);
}