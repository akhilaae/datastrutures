#include <stdio.h>
int front[100],rear[100],PQ[100][100],i,j,max;
void display(){
    for(i=0;i<max;i++)
        {for (j=0;j<max;j++)
            printf("%d\t",PQ[i][j]);
        printf("\n");}
}
void enque(int item,int pr){
    int c;
    if ((front[pr]==0 && rear[pr]==max-1)||front[pr]-rear[pr]==-1){
        printf("Overflow\n");
        return;
    }
    else if (rear[pr]==-1){
        front[pr]=0;
        rear[pr]=0;
        c=rear[pr];
    }
   else if (rear[pr]==max-1){
      rear[pr]=-1;
      c=rear[pr];
    }
    else{
        rear[pr]+= 1;
        c=rear[pr];
    }
    PQ[pr][c]=item;
    display();
}
void deque(){
    int f;
    for(i=0;i<max;i++)
        for (j=0;j<max;j++)
            if(PQ[i][j]!=NULL)
                {PQ[i][j]=NULL;
                f=1;
                display();
                return;}
            else if(PQ[i][j]==NULL)
                f=0;
    if (f==0){
        printf("UNDERFLOW\n");
        return;
    }
}
void main()
{
    int ch;
    printf("Enter max size : ");
    scanf("%d",&max);
    for(i=0;i<max;i++)
        for (j=0;j<max;j++)
            PQ[i][j]=NULL;
    for(i=0;i<max;i++){
        front[i]=-1;
        rear[i]=-1;}
    do{
       printf("Choose\n1. Enque\n2. Deque\n3. Display\n4. Exit\n");
       scanf("%d",&ch);
       int item,pr;
       if (ch==1){
           printf("Enter item to be inserted : ");
           scanf("%d",&item);
           printf("Enter it priority : ");
           scanf("%d",&pr);
           enque(item,pr);
           //display();
       }
       else if (ch==2){
           deque();
       }
       else if (ch==3){
           display();
       }
    }
    while(ch!=4);
}