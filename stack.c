#include <stdio.h>
void enque(int n);
void deque();
void display();
int front=0,rear=-1,Q[50],max;
void main(){
    int ch;
    printf("Enter max size : ");
    scanf("%d",&max);
do{
    int n;
    printf("Choose :\n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    if (ch==1){
        printf("Enter no to be inserted : ");
        scanf("%d",&n);
        enque(n);
    }
    if (ch==2)
        deque();
    if (ch==3)
        display();
}  
while (ch!=4);
}
void enque(int n){
    if (rear==max-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
    rear+=1;
    Q[rear]=n;
    display();}
}
void deque(){
    if ((front==0 && rear==-1) || (front>rear)){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int y=Q[front];
        printf("Deleted element : %d\n",y);
        front+=1;
        display();
    }
}
void display(){
    if (front==-1) return;
    else{
    printf("QUEUE : \n");
    for (int i=front;i<=rear;i++)
        printf("%d\t",Q[i]);
    printf("\n");
    }
}
