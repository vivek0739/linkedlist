#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
void insert_after(struct node **prev,int data)
{
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	if(prev==NULL)
	{
	printf("errror in input");
	return;
	}
	newnode->next=(*prev)->next;
	*prev=newnode;
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

	4b:5f:36:3b:7b:c0:e6:e4:81:7e:ad:f3:8b:ec:3f:91 vivek0739@gmail.com
	Agent pid 12302
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
int main()
{
	struct node *head=NULL;
	push_ll(&head,5);
	insert_after(&head->next,9);
	print_ll(head);
	insert_end(&head,7);
	print_ll(head);

return 0;
}
