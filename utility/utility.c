#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node 
{
	int data;
	struct node *next;
};
bool iscompare(struct node*,struct node*);
void reverse_ll(struct node**);
/********************************testing*****************************************************************************************/


/********************************utility function********************************************************************************/

bool ispallindrom(struct node **head)
{
	struct node *fast_ptr=*head,*slow =*head;
	struct node *prev=NULL,*second_half=NULL;
	struct node *middle=NULL;
	bool flag=true;
	if(*head != NULL)
	{
		while(fast_ptr!=NULL && fast_ptr->next != NULL)
		{
			fast_ptr=fast_ptr->next->next;
			prev=slow;
			slow=slow->next;
			
		}
		if(fast_ptr!= NULL)
		{
			middle=slow;
			slow=slow->next;
		}
		second_half=slow;
		prev->next=NULL;
		reverse_ll(&second_half);
		flag=iscompare(*head,second_half);
		reverse_ll(&second_half);
		if(middle!=NULL)
		{
			prev->next=middle;
			middle->next=second_half;
			
		}
		else 
			prev->next=second_half;
	}

return flag;	
}
bool iscompare(struct node* head1,struct node *head2)
{
	while(head1 && head2)
	{
		if(head1->data == head2->data)
			{
       				head1=head1->next;
				head2=head2->next;

			}
		else
			return 0;
	}
if (head1 == NULL && head2 == NULL)
        return 1;
return 0;
}


bool detect_loop(struct node *head)
{
	struct node *slow=head;
 	struct node *fast=head;
	while(fast && slow && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow == fast)
		{
			printf("found loop\n");
			return 1;
		}
	}
	return 0;
	
}

void reverse_ll(struct node **head)
{
	struct node *prev=NULL;
	struct node *curr=*head;
	struct node *next;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}

void nth_end(struct node *head,int n)
{
	struct node *main=head;
	struct node *ref=head;
	int count=0;
	if(head!=NULL)
	{
		while(count!=n && ref != NULL)
		{
			count++;
			ref=ref->next;
		}
		if(count == n)
		{
			while(ref!=NULL)
			{
				ref=ref->next;
				main=main->next;
			}
			printf("%d \n",main->data);
		}	
	}
	
	
}

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
	/*nth_end(head,3);
	insert_after(&(head->next),9);
	reverse_ll(&head);
	print_ll(head);
	print_middle(head);
	printf("%d \n",nth_node(head,3));
	del_ll(&head,9);
	print_ll(head);
	insert_end(&head,7);
	print_ll(head);
	printf("%d l\n",detect_loop(head));*/
		printf("%d l\n",ispallindrom(&head));

return 0;
}
