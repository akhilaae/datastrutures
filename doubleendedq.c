//DOUBLE ENDED QUEUE
#include <stdio.h>
int DQ[100],i,j,max,f=-1,r=-1;
void display(){
printf("DQ : \n");
if(r!=-1)
{
for (i=f;i!=r;i=(i+1)%max)
printf("%d\t",DQ[i]);
printf("%d\t",DQ[r]);
}
else
printf("%d\t",DQ[r]);
printf("\n");
}
void front_enq(int item){
if ((r==max-1 && f==0)||f-r==1){
printf("OVERFLOW\n");
return;
}
else if (f==-1&&r==-1)
{f=0;r=0;}
else if (f==0)
f=max-1;
else f-=1;
DQ[f]=item;
display();
}
void rear_enq(int item){
if ((r==max-1 && f==0)||f-r==1){
printf("OVERFLOW\n");
return;
}
else if (f==-1&&r==-1)
{f=0;r=0;}
else if (r==max-1)
r=0;
else
r+=1;
DQ[r]=item;
display();
}
void front_deq(){
int c;
if(f==-1&&r==-1){
printf("UNDERFLOW\n");
return;
}
else if (f==max-1){
c=DQ[f];
f=0;
}
else if (r==f){
c=DQ[f];
f=r=-1;
}

else{
c=DQ[f];
f+=1;
}
printf("Deleted element : %d\n",c);
display();
}
void rear_deq(){
int c;
if(f==-1&&r==-1){
printf("UNDERFLOW\n");
return;}
else if (r==0){
c=DQ[r];
r=max-1;
}
else if (r==f){
c=DQ[r];
f=r=-1;
}
else{
c=DQ[r];
r-=1;
}
printf("Deleted element : %d\n",c);
display();
}
void main(){
int ch;
printf("Enter max : ");
scanf("%d",&max);
do{
printf("CHOOSE : \n1.Enque at front\n2.Enque at rear\n3.Deque at front\n4.Deque at
rear\n5.Display\n6.Exit\n");
scanf("%d",&ch);
int item;
if (ch==1){
printf("Enter item : ");
scanf("%d",&item);
front_enq(item);
}
if (ch==2){
printf("Enter item : ");
scanf("%d",&item);
rear_enq(item);
}
if (ch==3){
front_deq();
}
if (ch==4){
rear_deq();
}
else if(ch==5){
display();
}
}
while (ch!=6);

}
