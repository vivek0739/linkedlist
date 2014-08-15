#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
/********************************utility function********************************************************************************/
void del_ll(struct node **head,int key)
{
	struct node *ptr=*head,*prev;;
	if(ptr == NULL)
	{
	printf("ll not exist\n");
	return;
	}
	else if(ptr->data == key)
	{
		*head = ptr->next;
		free(ptr);
		return;
	}
	while(ptr->next != NULL && ptr->next->data != key)
		ptr=ptr->next;
	if(ptr->next == NULL)
	{
		printf("item not found\n");
		return;
	}
	else
	{
		ptr->next=ptr->next->next;
		free(ptr->next);
	}

}
void insert_after(struct node **prev,int data)
{
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	if((*prev)==NULL)
	{
	printf("errror in input");
	return;
	}
	newnode->next=(*prev)->next;
	(*prev)->next=newnode;
} 
void push_ll(struct node **head,int data)
{
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=(*head);
	(*head)=newnode;


}
void insert_end(struct node **head,int data)
{
	struct node *ptr=*head;
	struct node *newnode;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	if(ptr == NULL)
	{
		newnode->next=(*head);
		(*head)=newnode;
		return;
	}
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;

	
}
void print_ll(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
/***************************************Drier function***************************************************************************/
int main()
{
	struct node *head=NULL;
	push_ll(&head,5);
	push_ll(&head,3);
	push_ll(&head,2);
	push_ll(&head,6);
	print_ll(head);
	insert_after(&(head->next),9);
	print_ll(head);
	del_ll(&head,5);
	print_ll(head);
	insert_end(&head,7);
	print_ll(head);

return 0;
}
