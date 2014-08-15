#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
/********************************utility function********************************************************************************/
void print_middle(struct node *head)
{
	struct node *fast_ptr=head;
	struct node *second =head;
	if(head!=NULL)
	{
		while(fast_ptr!=NULL && fast_ptr->next!=NULL)
		{
			fast_ptr=fast_ptr->next->next;
			second=second->next;
			
		}
		printf("middle=%d\n",second->data);
	}
}


int nth_node(struct node *head,int n)
{
	int count=0;
		while(head!=NULL)
		{
			count++;
			if(count == n)
				return head->data;
			
		  head=head->next;	
		}
		
			
}

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
	while(ptr != NULL && ptr->data != key)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	if(ptr == NULL)
	{
		printf("item not found\n");
		return;
	}
	else
	{
		prev->next=ptr->next;
		free(ptr);
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
	newnode->next=NULL;
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
	print_middle(head);
	printf("%d \n",nth_node(head,3));
	del_ll(&head,9);
	print_ll(head);
	insert_end(&head,7);
	print_ll(head);

return 0;
}
