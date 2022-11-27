#include <stdio.h>
#include <stdlib.h>
struct Employee {
int EmpId;
char fname[50];
char mname[50];
char lname[50];
int salary;
}*ptr;
void ls(int eid,int n){
//struct Employee *ptr2;
int i,f=0;
for (i=0;i<n;++i){
if (((ptr+i)->EmpId)==eid)
{
printf("PRESENT\n%d %s %s %s %d\n",(ptr+i)->EmpId,(ptr+i)->fname,(ptr+i)->mname,(ptr+i)-
>lname,(ptr+i)->salary);
f=1;
break;
}
}
if (f==0) printf("NOT PRESENT");
}
void main()
{
int n,i,eid,f=0;
printf("Size : ");
scanf("%d",&n);
ptr=(struct Employee*)malloc(n*sizeof(struct Employee));
printf("Enter *EmpId Name Salary* : \n");
for (i=0;i<n;++i){
scanf("%d %s %s %s %d",&(ptr+i)->EmpId,(ptr+i)->fname,(ptr+i)->mname,(ptr+i)->lname,&(ptr+i)-
>salary);
}
printf("Enter EmpId to be searched : ");
scanf("%d",&eid);
ls(eid,n);
}
