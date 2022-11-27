#include <stdio.h>
int CQ[100],max=3,f=-1,r=-1,i;
void display(){
	printf("CQ : \n");
	if(r!=-1)
	{
		for (i=f;i!=r;i=(i+1)%max)
			printf("%d\t",CQ[i]);
		printf("%d\t",CQ[r]);
	}
	else 
		printf("%d\t",CQ[r]);
	printf("\n");
}
	
void enque(){
	int n;
	printf("Enter no to be inserted : ");
	scanf("%d",&n);
	if ((r==max-1 && f==0) ||f-r==1)
		{printf("OVERFLOW\n");
		return;}
	else if (f==-1 && r==-1)
		{f=0;r=0;}
	else 
		r=(r+1)%max;

	CQ[r]=n;     
	display();
}
void deque(){
	int c;
	if (f==-1) 
		{printf("UNDERFLOW\n");
		return;}
	else if (f==r){
		f=r=-1;
		c=CQ[f];
	}
	else {c=CQ[f]; f=(f+1)%max;}
	printf("Deleted element : %d\n",c);
	display();
}
void main(){
	int ch,n,x;
	do{
	printf("CHOOSE : \n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
	scanf("%d",&ch);
	if (ch==1){
		enque();
	}
	else if (ch==2){
		deque();
	}
	else if (ch==3){
		display();
	}
	}
	while (ch!=4);
}
