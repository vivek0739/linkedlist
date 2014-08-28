#include<bits/stdc++.h>
class node_t
{
	int data;
	node_t *next;
	create_newnode(data);	
};
class tree
{
	node_t root;
	printtree(root);
	createtree(&root);
	inorder(root);
	preorde(root);
	postorder(root);
	level(root);
	
};
int main()
{
	
}
