#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
struct node
{
	int data;
	struct node *left,*right;
};
struct node* newNode(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}
void mirror(struct node *root)
{
	if(root==NULL) return;
	struct node *temp;
	mirror(root->left);
	mirror(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}
void printpath(struct node *root,int arr[],int pathlength)
{
	int i;
	if(root == NULL)
	{
		for(i=0;i<pathlength;i++)
			printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	arr[pathlength++]=root->data;
	printpath(root->left,arr,pathlength);
	printpath(root->right,arr,pathlength);
	

}
int height(struct node *root)
{
	if(root == NULL)
	return;
	return(1+max(height(root->left),height(root->right)));
}
void delete(struct node *root)
{
	if(root == NULL) return;
	delete(root->left);
	delete(root->right);
	printf("%d ",root->data);
	free(root);
}
int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    //printf("Hight of tree is %d\n", height(root));
    //delete(root);
	int arr[50]={0};
	int pathlength=0;
	printpath(root,arr,pathlength);
    getchar();
    return 0;
}
