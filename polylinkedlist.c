#include <stdio.h>
int i,j,k,n1,n2,n3,n4,coef,pow;
typedef struct{
  int coef;
  int power;
  struct poly* link;
}poly;
poly *Aheader,*Bheader,*Sheader,*Mheader;

void getheader(){
  Aheader=(poly*)malloc(sizeof(poly));
  Aheader->link=NULL;
  Bheader=(poly*)malloc(sizeof(poly));
  Bheader->link!=NULL;
  Sheader=(poly*)malloc(sizeof(poly));
  Sheader->link!=NULL;
  Mheader=(poly*)malloc(sizeof(poly));
  Mheader->link!=NULL;
}
void insert(poly* header, int coef, int pow){
  poly *new,*ptr;
  new=(poly*)malloc(sizeof(poly));
  new->coef=coef;
  new->power=pow;
  new->link=NULL;
  ptr=header;
  while(ptr->link!=NULL){
    ptr=ptr->link;
  }
  ptr->link=new;
}
void sum(){
  poly *ptr1=Aheader->link,*ptr2=Bheader->link,*ptr3=Sheader;
  while(ptr1!=NULL && ptr2!=NULL){
    if (ptr1->power==ptr2->power){
      insert(Sheader,ptr1->coef+ptr2->coef,ptr1->power);
      ptr1=ptr1->link;
      ptr2=ptr2->link;
    }
    else if (ptr1->power>ptr2->power){
      insert(Sheader,ptr1->coef,ptr1->power);
      ptr1=ptr1->link;
    }
    else if (ptr1->power<ptr2->power){
      insert(Sheader,ptr2->coef,ptr2->power);
      ptr2=ptr2->link;
    }
  }
  while(ptr1!=NULL){
    insert(Sheader,ptr1->coef,ptr1->power);
    ptr1=ptr1->link;
  }
  while(ptr2!=NULL){
    insert(Sheader,ptr2->coef,ptr2->power);
    ptr2=ptr2->link;
  }
}
void product(){
  poly *ptr1=Aheader->link,*ptr2=Bheader->link,*ptr3=Mheader;
  while(ptr1!=NULL){
    ptr2=Bheader->link;
    while(ptr2!=NULL){
      insert(Mheader,ptr1->coef*ptr2->coef,ptr1->power+ptr2->power);
      ptr2=ptr2->link;
    }
    ptr1=ptr1->link;
  }
  poly *ptr4,*ptr5=Mheader->link,*ptr6,*ptr0;
  while(ptr5!=NULL){
    ptr6=ptr5->link;
      while(ptr6!=NULL){
       ptr4=ptr6;
        if (ptr6->power==ptr5->power){
          ptr5->coef+=ptr6->coef;
          ptr4->link=ptr6->link;
          ptr0=ptr6;
          ptr6=ptr6->link;
          free(ptr0);
          ptr0=NULL;
        }
        else{
          ptr6=ptr6->link;
        }
      }
      ptr5=ptr5->link;
    }
}
void display(poly* header){
  poly *ptr=header;
  while(ptr->link!=NULL){
    ptr=ptr->link;
    printf("%d %d\n",ptr->coef,ptr->power);
  }
}
void main(){
  getheader();
  int ch; 
  do{
    printf("CHOOSE:\n1.Read poly A\n2.Read B\n3.Sum of poly\n4.Product\n5.Display\nEnter your choice");    
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        printf("Enter A coef and pow: ");
        scanf("%d %d",&coef,&pow);
        insert(Aheader,coef,pow);
        break;
      }
      case 2:{
        printf("Enter B coef and pow: ");
        scanf("%d %d",&coef,&pow);
        insert(Bheader,coef,pow);
        break;
      }
      case 3:{
        sum();
        display(Sheader);
        break;
      }
      case 4:{
        product();
        display(Mheader);
        break;
      }
      case 5:{
        printf("A : \n");
        display(Aheader);
        printf("B : \n");
        display(Bheader);
        break;
      }
    }
  }
  while(ch<=5);
}