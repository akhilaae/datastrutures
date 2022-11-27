#include <stdio.h>
#include <string.h>

void main(){
int ch,top=-1;
do{
int cho, stack[50],no,max=50;
printf("Choose option : \n1.Push\n2.Pop\n3.Display\n");
scanf("%d",&cho);
if (cho==1){

if (top==max-1)
printf("overflow");
else
{printf("Enter the number to be pushed : ");
scanf("%d",&no);
top+=1;
stack[top]=no;}
printf("Stack : \n");
for(int i=top;i>=0;i--)
printf("%d\n",stack[i]);

}
if (cho==2){
if(top==-1)
printf("underflow");
else
{printf("Popped element : %d\n",stack[top]);
top-=1;
printf("Stack : \n");
for(int i=top;i>=0;i--)
printf("%d\n",stack[i]);}

}
if (cho==3){
printf("Stack : \n");
for(int i=top;i>=0;i--)
printf("%d\n",stack[i]);
}
printf("Do you wish to continue(1/0)? : ");
scanf("%d",&ch);
}
while (ch==1);
}
