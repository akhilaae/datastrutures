  
/*Write a  program to read two matrices in normal representation . Do the following operations 
        as menu driven , implemented with  separate functions:
    a) Convert two matrices to tuple form and display it.
b) Find the transposes of a matrix represented in tuple form and display them in tuple form.
c) Find the sum of the two matrices in tuple form and display the sum in tuple form.
*/
#include <stdio.h>
int A[10][10],B[10][10],i,j,k=1,m,n,p,q,t;
struct tuple{
    int row;
    int col;
    int val;
}tup1[10],tup2[10],trans[10],sum[10];
void read(int M[10][10],int m,int n){
    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&M[i][j]);
}
void convert(int M[10][10],int m,int n,struct tuple tup[10]){
    int k=1,t=0;
    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(M[i][j]!=0)
                t+=1;
    tup[0].row=m;tup[0].col=n;tup[0].val=t;
    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(M[i][j]!=0)
                {tup[k].row=i;tup[k].col=j;tup[k].val=M[i][j];k++;}
}
void display(struct tuple tup[10]){
    for(i=0;i<=tup[0].val;i++)
        printf("%d %d %d\n",tup[i].row,tup[i].col,tup[i].val);
    printf("\n");
}
void transpose(struct tuple tup[10]){
    int p=1;
    trans[0].row=tup[0].row;trans[0].col=tup[0].col;trans[0].val=tup[0].val;
    for(i=0;i<tup[0].col;i++)
        for(j=1;j<=tup[0].val;j++)
            if(tup[j].col==i){
                trans[p].row=tup[j].row;
                trans[p].col=tup[j].col;
                trans[p].val=tup[j].val;
                p++;
            }
}
void add(struct tuple t1[10],struct tuple t2[10]){
    int r1=t1[0].row,c1=t1[0].col,r2=t2[0].row,c2=t2[0].col,m=1,n=1,s=1;
    if(r1!=r2 || c1!=c2){
        return;
    }
    else{
    sum[0].row=r1;sum[0].col=c1;
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            if (t1[m].row==i && t1[m].col==j && t2[n].row==i && t2[n].col==j){
                sum[s].row=t1[m].row;
                sum[s].col=t1[m].col;
                sum[s].val=t1[m].val+t2[n].val;
                m++;n++;s++;
            }
            else if (t1[m].row==i && t1[m].col==j){
                sum[s].row=t1[m].row;
                sum[s].col=t1[m].col;
                sum[s].val=t1[m].val;
                m++;s++;
            }
            else if (t2[n].row==i && t2[n].col==j){
                sum[s].row=t2[n].row;
                sum[s].col=t2[n].col;
                sum[s].val=t2[n].val;
                n++;s++;
            }
    sum[0].val=s-1;
    }
}
void main(){
    int ch;
    do{
    printf("CHOOSE :\n1.Read two matrices\n2.Convert to tuple form\n3.Matrix transpose in tuple form\n4.Matrix sum in tuple form\n5.Exit\nEnter your choice : ");
    scanf("%d",&ch);
    if (ch==1){
        printf("Enter rows and columns of first matrix : ");
        scanf("%d %d",&m,&n);
        printf("Enter values : \n");
        read(A,m,n);
        printf("Enter rows and columns of second matrix : ");
        scanf("%d %d",&p,&q);
        printf("Enter values : \n");
        read(B,p,q);
    }
    else if (ch==2){
        convert(A,m,n,tup1);
        convert(B,p,q,tup2);
        printf("TUPLE 1 : \n");
        display(tup1);
        printf("TUPLE 2 : \n");
        display(tup2);
    }
    else if (ch==3){
        transpose(tup1);
        printf ("TRANSPOSE of TUPLE 1 : \n");
        display(trans);
        transpose(tup2);        
        printf ("TRANSPOSE of TUPLE 2 : \n");
        display(trans);
    }
    else if (ch==4){
        add(tup1,tup2);
        printf("SUM : \n");
        display(sum);
    }
    }
    while(ch!=5);
}
