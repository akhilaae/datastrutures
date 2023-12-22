#include <stdio.h>
#include <string.h>
int top=-1,max=30,i,l,x,y,z,len;
char stack[30],a[30],c,b[30],s[30];
void push(char ch){
  if(top==max-1){
    printf("overflow");
    return;
  }
  else{
    top++;
    stack[top]=ch;
  }
}
char pop(){
  if(top==-1){
    printf("under");
    return;
  }
  else{
    c=stack[top];
    top--;
    return c;
  }
}
int priority(char ch){
  if(ch=='('||ch==')')
    return 0;
  if(ch=='^')
    return 3;
  if (ch=='*'||ch=='/')
    return 2;
  if(ch=='+'||ch=='-')
    return 1;
}
void topost(){
  push('(');
  for(i=0;i<=l;i++){
    if(a[i]=='^'||a[i]=='*'||a[i]=='/'||a[i]=='+'||a[i]=='-'){
      if (priority(a[i])<priority(stack[top])){
        x=pop();
        printf("%c",x);
        push(a[i]);
      }
      else{
        push(a[i]);
      }
    }
    else if(a[i]=='('){
      push(a[i]);
    }
    else if(a[i]==')'){
      while (stack[top]!='('){
        x=pop();
        printf("%c",x);
      }
      pop();
    }
    else{
      printf("%c",a[i]);
    }
  }
}
void evaluate(){
  for(i=0;i<len;i++){
    if(b[i]=='^'||b[i]=='*'||b[i]=='/'||b[i]=='+'||b[i]=='-'){
      x=pop();
      printf("%d\n",x);
      y=pop();
      printf("%d\n",y);
      switch(b[i]){
        case '^':{
          z=y^x;
          push(z);
          break;
        }
        case '*':{
          z=y*x;
          push(z);
          break;
        }
        case '%':{
          z=y%x;
          push(z);
          break;
        }
        case '+':{
          z=(y)+(x);
          push(z);
          printf("%d\n",stack[top]);
          break;
        }
        case '-':{
          z=y-x;
          push(z);
          break;
        }
      }
    }
    else{
      push(b[i]);
    }
  }
}
void main(){
  scanf("%s",a);
  l=strlen(a);
  a[l]=')';
  a[l+1]='\0';
  topost();
  scanf("%s",b);
  len=strlen(b);
  b[l]=')';
  b[l+1]='\0';
  evaluate();
  printf("%d",stack[top]);
}