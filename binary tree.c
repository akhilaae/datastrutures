#include <stdio.h> #include <stdlib.h> struct node{ int data;
struct node *left;
struct node *right;
};
//int keyFound=0;
struct node *create() { 
  struct node *newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  int x;
  printf("Enter the data(enter -1 if no data to be passed): ");
  scanf("%d",&x);
  if(x==-1) { 
    return NULL;}
  else{ 
    newNode->data=x;
    printf("Enter the left child of %d : ",x);
    newNode->left=create();
    printf("Enter the right child of %d : ",x);
    newNode->right=create();
    return newNode;
  } 
 } 
  struct node *linking(struct node *toAdd, struct node *root,int key) { char leftOrRight;
if(root==NULL) { return 0;
}else if(root->data==key && (root->right==NULL || root->left==NULL)){ printf("Do you want to add the element as the Right child or Left child?(Enter r for right and l for left):");
scanf(" %c",&leftOrRight);
if(leftOrRight=='r') { root->right=toAdd;
}else if(leftOrRight=='l'){ root->left=toAdd;
} }else{ linking(toAdd,root->left,key);
linking(toAdd,root->right,key);
} return root;
} struct node *addNode(struct node *root) { int key;
printf("Enter the node to which the element is to be added(key): ");
scanf("%d",&key);
struct node *added,*toAdd;
toAdd=create();
added=linking(toAdd,root,key);
return added;
} struct node *removeLink(struct node *root,int parent) { char choice;
if(root==NULL) { return 0;
}else if(root->data==parent) {
  printf("Do you want to delete the Left child or Right child of the parent element %d (l / r): ",&parent);
scanf(" %c",&choice);
if(choice=='r'){ root->right=NULL;
}else if(choice=='l'){ root->left=NULL;
} }else{ removeLink(root->left,parent);
removeLink(root->right,parent);
} return root;
} struct node *deleteNode(struct node *root) { int parent;
struct node *removed;
printf("Enter the Parent node(value of parent node) of the leaf node to be deleted: ");
scanf("%d",&parent);
removed=removeLink(root,parent);
return removed;
} void preorder(struct node *root){
  if(root==NULL) { return;
}else{ printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
} } void inorder(struct node *root) { if(root==NULL) { return;
}else{ inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
} } void postorder(struct node *root) { if(root==NULL) {
}
return;
}else{ postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
} } int main() { int selection=0;
printf("CREATE A TREE.\n");
struct node *root;
root=NULL;
root=create();
while(selection!=6) { printf("Enter one of the choices: \n1)Preorder\n2)Inorder\n3)Postorder\n4)Add Element\n5)Delete Element\n6)Exit\n");
scanf("%d",&selection);
switch(selection) { case 1:
preorder(root);
printf("\n");
108 break;
case 2:
inorder(root);
printf("\n");
break;
case 3:
postorder(root);
printf("\n");
break;
case 4:
root=addNode(root);
inorder(root);
printf("\n");
break;
case 5:
root=deleteNode(root);
inorder(root);
printf("\n");
break;
case 6:
//exit(1);
break;
default:
printf("\nEnter a valid option.\n");
} return 0;
}