#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
	int data;
	struct node *left,*right;

};
struct node *newnode(int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp ->left = temp ->right = NULL;
	return temp;
}
int isbst(struct node *node,int min,int max)
{
	if(node == NULL)
		return 1;
	if(node->data<min || node->data>max)
		return 0;
	
	
	if(!isbst(node->left,min,node->data)||!isbst(node->right,node->data,max))
			return 0;
	return 1;
}
void insert(struct node **root1,int data)
{
	if((*root1) == NULL)
	{
		(*root1)=newnode(data);
		return ;
	}
	struct node *root=*root1;
	struct node *prev=NULL;
	while(root != NULL)
	{

		
		prev=root;
		if(root->data>data)
		root=root->left;
		else
		root=root->right;
	}
		if(data<=prev->data)
			prev->left=newnode(data);
		else
			prev->right=newnode(data);
}
struct node *lca(struct node *root,int n1,int n2)
{
	if(root == NULL ) return NULL;
	if(root->data<n1 && root->data <n2)
		return lca(root->left,n1,n2);
	if(root->data>n1 && root->data>n2)
		return lca(root->right,n1,n2);
	return root;
}
print_sort(struct node *root)
{
	if(root!=NULL)
	{
		print_sort(root->left);
		printf("%d ",root->data);
		print_sort(root->right);
	}
}
struct node *inorder_successor(struct node *root,struct node *n)
{
	struct node *succ=NULL;
	if(n->right != NULL)
	{
		succ=n->right;
		while(succ->left!=NULL)
			succ = succ->left;
	}
	else
	{
		while(root != NULL)
		{
			if(n->data<root->data)
			{
				succ=root;
				root=root->left;

			}
			else if(n->data >root->data)
			{
				root=root->right;
			}
			else
				break;
		}
	}
	return succ;
}
int main()
{
	struct node* root = NULL,*temp;
    insert(&root, 20);
   insert(&root, 8);
   insert(&root, 22);
   insert(&root, 4);
  insert(&root, 12);
   insert(&root, 10);  
   insert(&root, 14);    
   root->left->right->right;
	struct node *succ=inorder_successor(root,temp);
	//printf("%d\n",isbst(root,INT_MIN,INT_MAX)); 
print_sort(root);
	if(succ !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);    
  else
    printf("\n Inorder Successor doesn't exit");

}
