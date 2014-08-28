#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	int lcount;
	struct node *left,*right;
};
struct node *newnode(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;
	temp->lcount=0;
	return temp;
}
struct node *insert_node(struct node *root,int data)
{
	struct node *temp=root,*prev=NULL;
	if(!root)
	{
		return newnode(data);
	}
	while(root)
	{
		prev=root;
		if(data<root->data)
		{
			root->lcount++;
			root=root->left;
		}
		else
		root=root->right;
	}
	if(data<prev->data)
		prev->left=newnode(data);
	else
		prev->right=newnode(data);
	
	return temp;
}
int small_kth(struct node *root,int k)
{
	int ret=-1;
	if(root)
	{
		struct node *prev=root;
		while(prev)
		{
			if((prev->lcount+1)==k)
				{
					ret=prev->data;
					break;
				}
			else if(k>(prev->lcount))
				{
					k-=(prev->lcount+1);
					prev=prev->right;
				}
			else
				{
				prev=prev->left;
				}
		}
	}
	return ret;
}
int main(void)
{
    
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    int i;
    struct node* root = NULL;
 
    
    for(i=0;i<7;i++)
	root= insert_node(root,ele[i]);
 
    
    for(i = 1; i <= 7; i++)
    {
        printf("\n kth smallest elment for k = %d is %d",
                 i, small_kth(root, i));
    }
 
    getchar();
    return 0;
}
