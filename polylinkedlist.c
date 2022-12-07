#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int power;
    struct node* link;
}node;
node* Pheader,*Qheader,*Mheader,*Sheader;
void getheader(){
    Pheader=(node*)malloc(sizeof(node));
    Pheader->link=NULL;
    Qheader=(node*)malloc(sizeof(node));
    Qheader->link=NULL;
    Mheader=(node*)malloc(sizeof(node));
    Mheader->link=NULL;
    Sheader=(node*)malloc(sizeof(node));
    Sheader->link=NULL;
}
void insert(node* header,int pow, int coef){
    node *new,*ptr;
    ptr=header;
    new=(node*)malloc(sizeof(node));
    if (new==NULL)
    {
        printf("Insufficient memory");
    }
    else
    {
        while(ptr->link!=NULL)
        {
          ptr=ptr->link;
        }
        ptr->link=new;
        new->link=NULL;
        new->coeff=coef;
        new->power=pow;
    }
}
void product(){
    node *Pptr=Pheader->link,*Qptr=Qheader->link,*Mptr=Mheader;
    if(Pptr==NULL || Qptr==NULL){
        return;
    }
    else{
        while(Pptr!=NULL){
            Qptr=Qheader->link;
            while(Qptr!=NULL){
                node* new=(node*)malloc(sizeof(node));
                while(Mptr->link!=NULL){
                    Mptr=Mptr->link;
                }
                Mptr->link=new;
                new->coeff=(Pptr->coeff)*(Qptr->coeff);
                if (Pptr->power==0){
                    new->power=Qptr->power;
                }
                else if (Qptr->power==0){
                    new->power=Pptr->power;
                }
                else if(Pptr->power==0 && Qptr->power==0){
                    new->power=Pptr->power;
                }
                else{
                    new->power=(Pptr->power)+(Qptr->power);
                }
                new->link=NULL;
                Qptr=Qptr->link;
            }
            Pptr=Pptr->link;
        }
    }
}
void sum(){
    node *Pptr=Pheader->link,*Qptr=Qheader->link,*Sptr=Sheader;
    if(Pptr==NULL || Qptr==NULL){
        return;
    }
    else{
        while(Pptr!=NULL && Qptr!=NULL){
            if (Pptr->power==Qptr->power){
                node* new=(node*)malloc(sizeof(node));
                while(Sptr->link!=NULL){
                    Sptr=Sptr->link;
                }
                Sptr->link=new;
                new->coeff=(Pptr->coeff)+(Qptr->coeff);
                new->power=Pptr->power;
                new->link=NULL;
                Pptr=Pptr->link;
                Qptr=Qptr->link;
            }
            else if (Pptr->power>Qptr->power){
                node* new=(node*)malloc(sizeof(node));
                while(Sptr->link!=NULL){
                    Sptr=Sptr->link;
                }
                Sptr->link=new;
                new->coeff=Pptr->coeff;
                new->power=Pptr->power;
                new->link=NULL;
                Pptr=Pptr->link;
            }           
            else if (Pptr->power<Qptr->power){
                node* new=(node*)malloc(sizeof(node));
                while(Sptr->link!=NULL){
                    Sptr=Sptr->link;
                }
                Sptr->link=new;
                new->coeff=Qptr->coeff;
                new->power=Qptr->power;
                new->link=NULL;
                Qptr=Qptr->link;
            }
        }
        while(Pptr!=NULL){
            node* new=(node*)malloc(sizeof(node));
                while(Sptr->link!=NULL){
                    Sptr=Sptr->link;
                }
                Sptr->link=new;
                new->coeff=Pptr->coeff;
                new->power=Pptr->power;
                new->link=NULL;
                Pptr=Pptr->link;
        }
        while (Qptr!=NULL){
            node* new=(node*)malloc(sizeof(node));
                while(Sptr->link!=NULL){
                    Sptr=Sptr->link;
                }
                Sptr->link=new;
                new->coeff=Qptr->coeff;
                new->power=Qptr->power;
                new->link=NULL;
                Qptr=Qptr->link;
        }
    }
}
void display(node* header)
{
    node* ptr=header;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        printf("%d %d\n",ptr->coeff,ptr->power);
    }
}
void main(){
    int ch,ppow,pcoef;
    getheader();
    do{
        printf("CHOOSE : \n1.Input P\n2.Input Q\n3.Product of two polynomials\n4.Sum of two polynomiaols\n5.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1 :{
                printf("Enter poly P (coef pow) : ");
                scanf("%d %d",&pcoef,&ppow);
                insert(Pheader,ppow,pcoef);
                display(Pheader);
                break;
            }
            case 2 : {
                int qpow,qcoef;
                printf("Enter poly Q (coef pow) : ");
                scanf("%d %d",&qcoef,&qpow);
                insert(Qheader,qpow,qcoef);
                display(Qheader);
                break;
            }
           case 3 :{
                product();
                printf("Polynomial P : \n");
                display(Pheader);
                printf("Polynomial Q : \n");
                display(Qheader);
                printf("Product : \n");
                display(Mheader);
                break;
            }
            case 4 :{
                sum();
                printf("Polynomial P : \n");
                display(Pheader);
                printf("Polynomial Q : \n");
                display(Qheader);
                printf("Sum : \n");
                display(Sheader);
                break;
            }
        }
    }
    while(ch<5);
}
