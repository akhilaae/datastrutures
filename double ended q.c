#include <stdio.h>
int DQ[100],i,j,max,f=-1,r=-1;
void display(){
  
}
void front_enq(int item){
  int c;
  if (f==0&&r==max-1||f-r==1){
    printf("OVERFLOW\n");
    return;
  }
  else if (){
    
  }
  else
    
}
void rear_enq(int item){
  if (f==0&&r==max-1||f-r==1){
    printf("OVERFLOW\n");
    return;
  }
  else if(f==-1&&r==-1){
    f=0;r=0;
  }
  else if(r==max-1){
    r=0;
  }
  else 
    r+=1;
  DQ[r]=item;
  display();
}
void front_del(){
  int c;
  if (f==-1&&r==-1){
    printf("UNDERFLOW\n");
    return;
  }
  else if (f==max-1){
    c=DQ[f];
    f=r=0;
  }
  else if (r==f){
    c=DQ[f];
    f=r=-1;
  }
  else
    {c=DQ[f];
    f+=1;}
  printf("Deleted element : %d",c);
}
void rear_del(){
  if (f==-1&&r==-1){
    printf("UNDERFLOW\n");
    return;
  }
  else if (){
    
  else if (){
    
  }
  else
    {c=DQ[r];
    r-=1;}
  printf("Deleted element : %d",c);
}
void main()
{
  int ch;
  do{
    printf("Choose : \n1.Enque at front\n2.Enque at rear\n3.Deque at front\n4.Deque at rear\n5.Display\n6.Exit");
    scanf("%d",ch);
    if (ch==1){
      int item;
      printf("Enter item : ");
      scanf("%d",&item);
      front_enq(item);
    }
    else if(ch==2){
      int item;
      printf("Enter item : ");
      scanf("%d",&item);
      rear_enq(item);
    }
    else if(ch==3){
      front_del();
    }
    else if (ch==4){
      rear_del();
    }
    else if (ch==5){
      display();
    }
  }
  while (ch!=6):
}