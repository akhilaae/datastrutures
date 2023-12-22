#include <stdio.h>
int n,largest,A[10],I[10],S[10],l,r,q[10],m[10],g[10],h[10],lf,r,mid,p,i,j,k,temp,small;
void insertion(){
  copy(I);
  for(i=1;i<n;i++){
    temp=I[i];
    for(j=i-1;j>=0;j--){
      if(I[j]>temp){
        I[j+1]=I[j];
        k=j;
      }
      else{break;}
    }
    I[k]=temp;
  }
}
void selection(){
  copy(S);
  for(i=0;i<n;i++){
    small=S[i];
    for(j=i+1;j<n;j++){
      if(S[j]<small){
        small=S[j];
        k=j;
      }
    }
    if(small<S[i]){
      temp=S[k];
      S[k]=S[i];
      S[i]=temp;
    }  
  }
}
void quick(int l,int r){
  //copy(q);
  if(l<r){
    p=partition(l,r);
    quick(l,p-1);
    quick(p+1,r);
  }
}
int partition(int l,int r){
  p=l;
  while(l<r){
    while(q[p]<=q[r] && p<r){
      r--;
    }
    if(q[p]>q[r]){
      temp=q[p];
      q[p]=q[r];
      q[r]=temp;
      l++;
      p=r;
    }
    while(q[p]>=q[l] && p>l){
      l++;
    }
    if(q[p]<q[l]){
      //swap(q[p],q[l]);
      temp=q[p];
      q[p]=q[l];
      q[l]=temp;
      r--;
      p=l;
    }
  }
  return p;
}
void mergesort(int m[10],int l,int h){
  if(l<h){
    int mid=(l+h)/2;
    mergesort(m,l,mid);
    mergesort(m,mid+1,h);
    merge(m,l,mid,h);
  }
}
void merge(int m[10],int l,int mid,int h){
  lf=l;
  r=mid+1;
  k=l;
  while(lf<=mid && r<=h){
    if(m[lf]<=m[r]){
      g[k]=m[lf];
      k++;lf++;
    }
    else{
      g[k]=m[r];
      k++;r++;
    }
  }
  if(lf<=mid){
    while(lf<=mid){
      g[k]=m[lf];
      k++;lf++;
    }
  }
  else{
  while(r<=h){
    g[k]=m[r];
    k++;r++;
  }}
  for(i=0;i<k;i++){
    m[i]=g[i];
  }
}
void heapsort(int h[10],int n){
  for(i=(n/2)-1;i>=0;i--){
    heapify(h,n,i);
  }
  for(i=n-1;i>=0;i--){
    temp=h[i];
    h[i]=h[0];
    h[0]=temp;
    heapify(h,i,0);
  }
}
void heapify(int h[10],int n,int i){
  largest=i;
  l=2*i+1;
  r=2*i+2;
  if(l<n && h[largest]<h[l]){
    largest=l;
  }
  if(r<n && h[largest]<h[r]){
    largest=r;
  }
  if(largest!=i){
    temp=h[largest];
    h[largest]=h[i];
    h[i]=temp;
    heapify(h,n,largest);
  }
}
void swap(int x, int y){
  temp=x;
  x=y;
  y=temp;
}
void copy(int X[10]){
  for(i=0;i<n;i++){
   X[i]=A[i];
  }
}
void display(int X[10]){
  for(i=0;i<n;i++){
    printf("%d ",X[i]);
  }
  printf("\n");
}
void main(){
  int ch;
  printf("enter max : ");
  scanf("%d",&n);
  printf("vskies...");
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  do{
    printf("1.Insertion\n2.selection\n3.quick\n4.merge\n5.heap\nenter choice");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
        insertion();
        display(I);
        break;
      }
      case 2:{
        selection();
        display(S);
        break;
      }
      case 3:{
        copy(q);
        quick(0,n-1);
        display(q);
        break;
      }
      case 4:{
        copy(m);
        mergesort(m,0,n-1);
        display(m);
        break;
      }
      case 5:{
        copy(h);
        heapsort(h,n);
        display(h);
        break;
      }
    }
  }
  while(ch<=5);
}