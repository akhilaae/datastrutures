#include <stdio.h>
typedef struct{
  int eid;
  char fn[10];
  char mn[10];
  char ln[10];
  int sal;
}e;
e* eptr;
int n,i,key;
void read(int n){
  printf("Eid name sal: ");
  for(i=0;i<n;i++){
    scanf("%d %s %s %s %d",&(eptr+i)->eid,(eptr+i)->fn,(eptr+i)->mn,(eptr+i)->ln,&(eptr+i)->sal);
  }
}
void display(){
  printf("Eid name sal: ");
  for(i=0;i<n;i++){
    printf("%d %s %s %s %d\n",(eptr+i)->eid,(eptr+i)->fn,(eptr+i)->mn,(eptr+i)->ln,(eptr+i)->sal);
 }
}
void ls(int item){
  int f=0;
  for(i=0;i<n;i++){
    if ((eptr+i)->eid==key){
      f=1;
      break;
    }
  }
  if (f==1){
    printf("present\n");
  }
  else("absent\n");
}


void main(){
  eptr=(e*)malloc(sizeof(e));
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
        break;
      }
      case 2:{
        printf("to searvh : ");
        scanf("%d",&key);
        ls(key);
        break;
      }
    }
  }
  while(ch<=2);
}