#include <stdio.h>
#include <string.h>
struct strings{
	char string[50];
}data[50];
int i=0,j,n;
char key[100];
void bubblesort(){
	struct strings temp[50];
	for (i=0;i<n-1;i++)
		for (j=0;j<n-i-1;j++)
			if (strcasecmp(data[j].string,data[j+1].string)>0){
				strcpy(temp[j].string,data[j].string);
				strcpy(data[j].string,data[j+1].string);
				strcpy(data[j+1].string,temp[j].string);
		}
}
void binarysearch(char key[100]){
	int l=0,u=n,mid,f=0;
	for (i=l-1;i<=u;i++){
			mid=((l+u)/2);
			if (strcasecmp(key,data[mid].string)==0){
				printf("Found at position %d\n",mid+1);
				f=1;
				break;
			}
			else if(strcasecmp(key,data[mid].string)<0){
				u=mid;
			}
			else if (strcasecmp(key,data[mid].string)>0){
				l=mid;
			}
		}
		if (f==0){
			printf("NOT FOUND\n");
		}
}
void main()
{
	int k=0;
	FILE* fptr;
	fptr=fopen("Test.txt","r");
	while(!feof(fptr)){
		fscanf(fptr,"%s",data[k].string);
		k++;
	}
	n=k;
	bubblesort();
	for (i=0;i<n;i++){
		printf("%s\n",data[i].string);
	}
	printf("Enter string to be searched : ");
	scanf("%s",key);
	binarysearch(key);
	fclose(fptr);
	
}
