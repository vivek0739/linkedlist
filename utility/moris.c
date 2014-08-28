#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(a,b) ((a)>(b)?(a):(b))
struct t_node
{
	int data;
	struct t_node *left;
	struct t_node *right;

};
void MorrisTraversal(struct t_node *root)
{
	struct t_node *current,*pre;
	if(root == NULL)
		return;
	while(current != NULL)
	{
		if(current ->left == NULL)
			{
				printf(" %d ",current-> data);
				current = current -> right;

			}
		else
		{
			pre = current -> left;
			while(pre->right != NULL)
			{
				pre->right = current;
				current = current -> left;
			}
		}
	}
}
int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    getchar();
    return 0;
}
