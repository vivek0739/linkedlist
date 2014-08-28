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
struct s_node
{
	struct t_node *t;
	struct s_node *next;
};
struct t_node* newnode(int data)
{
	struct t_node *temp;
	temp = (struct t_node *)malloc(sizeof(struct t_node));
	temp -> data =data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}
void push(struct s_node** top_ref ,struct t_node *t)
{
	struct s_node* new_tnode = (struct s_node*)malloc(sizeof(struct s_node));
	if(new_tnode == NULL)
	{
		printf("stack overflow\n");
		getchar();
		exit(0);
	}
	new_tnode -> t =t;
	new_tnode->next = (*top_ref);
	(*top_ref) = new_tnode;

}
bool isEmpty(struct s_node *top)
{
	return (top == NULL)?1:0;
}

struct t_node *pop(struct s_node** top_ref)
{
	struct t_node *res;
	struct s_node *top;
	if(isEmpty(*top_ref))
	{
		printf("stack Underflow\n");
		getchar();
		exit(0);

	}
	else
	{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
void postorder(struct t_node *root)
{
	struct t_node *current=root;
	struct s_node *s1=NULL;
	struct s_node *s2=NULL;
	if(current == NULL) return;
	push(&s1,current);
	while(!isEmpty(s1))
	{
		struct t_node *node;
		node=pop(&s1);
		push(&s2,node);
		if(node->left) push(&s1,node->left);
		if(node->right) push(&s1,node->right);

	}
	while(!isEmpty(s2))
	{
		printf("%d",pop(&s2)->data);
	}
	
}
int height(struct t_node *root)
{
	if(root == NULL)
	return;
	return(1+max(height(root->left),height(root->right)));
}
void givenlevelorder(struct t_node *root,int level)
{
	if(root == NULL )
		return;
	if(level == 1)
		printf("%d",root->data);
	else if(level>1)
		{
			givenlevelorder(root->left,level-1);
			givenlevelorder(root->right,level-1);
		}

	
}
void level_order(struct t_node *root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
		givenlevelorder(root,i);
}
void preorder(struct t_node *root)
{
	
	struct t_node *current=root;
	struct s_node *p=NULL;
	if(current == NULL)
	 return;
		
		push(&p,current);
		//printf("%d",is);
	while(!isEmpty(p))
	{
		
		current=pop(&p);
		printf("%d ",current->data);
		
		if(current->right)
		push(&p,current->right);
		if(current->left)
		push(&p,current->left);
	}

	
	
}
void inorder(struct t_node *root)
{
	struct t_node *current = root;
	struct s_node *s = NULL;
	bool done = 0;
	while(!done)
	{
		if(current != NULL)
		{
			push(&s,current);
			current = current -> left;	
		}
		else
		{
			if(!isEmpty(s))
			{
				current = pop(&s);
				printf("%d ",current -> data);
				current = current -> right;
			}
			else
				done =1;
		}
	}
}
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct t_node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
 
  inorder(root);
	printf("\n");
 	level_order(root);
  getchar();
  return 0;
}
