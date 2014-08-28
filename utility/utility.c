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
struct node* merge(struct node* , struct node* );
void frontbacksplit(struct node*,struct node**,struct node**);
void movenode(struct node**,struct node **);
/********************************testing*****************************************************************************************/

struct node *reverse(struct node *head,int k)
{
	struct node *prev=NULL;
	struct node *curr=head;
	struct node *next;
	int i;
	while(curr!=NULL && i<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		i++;
	}
	if(next != NULL)
	head->next = reverse(next,k) ;

return prev;}
/********************************utility function********************************************************************************/
void removeloop(struct node *loop_node,struct node *head)
{
	struct node *ptr = loop_node;
	struct node *ptr2= loop_node;
	int k=0;
	while(ptr -> next != ptr2)
	{
		ptr=ptr->next;
		k++;
	}
	ptr=head;
	ptr2=head;
	while(k--)
	ptr2=ptr2->next;
	while(ptr != ptr2)
	{
		ptr= ptr->next;
		ptr2= ptr2->next;
	}
	ptr2= ptr2->next;
	while(ptr2->next != ptr)
	ptr2 = ptr2->next;
	
	ptr2->next =NULL;
}
bool detect_remove(struct node *head)
{
	struct node *slow=head;
 	struct node *fast=head;
	while(fast && slow && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow == fast)
		{
			removeloop(slow,head);
			return 1;
		}
	}
	return 0;
	
}

struct node *merge_sorted_ll(struct node *a,struct node *b)
{
	struct node *result =NULL;
	struct node **tail = &result;
	while(1)
	{
	
	if(a == NULL)
	{
		*tail = b;
		break;
	}
	else if(b == NULL)
	{	
		*tail = a;
		break;
	}
	if(a->data <= b->data)
	{
		movenode(tail,&a);
	}
	else
	{
		movenode(tail,&b);
	}
	tail = &((*tail) -> next);
   }
	return result;
}


void altsplit(struct node *head,struct node **aref,struct node **bref)
{
	struct node *a=NULL;
	struct node *b=NULL;
	while(head != NULL)
	{
		movenode(&a,&head);
		if(head != NULL)
			movenode(&b,&head); 	
	
	}
 *aref = a;
 *bref = b;
} 
void movenode(struct node **dest,struct node **source)
{
	if((*source) == NULL)
		return;
	struct node *a=*source;
	
	*source=a->next;
	a->next = *dest;
	*dest = a;
	
	
}

void deletealt(struct node *head)
{

	if(head == NULL)
		return;
	struct node *prev = head;
 	struct node *node = head -> next;
	while(prev != NULL && prev ->next != NULL)
	{
		prev -> next = node -> next;
		free(node);
		prev = prev ->next;
		if(prev)
			node = prev -> next;
		
		
	}

}

//quick sort
struct node *gettail(struct node *head)
{
	if(head != NULL )
	{
		while (head -> next != NULL )
		{	
			head = head -> next;
		}
	}
	return head;
}
struct node *partition(struct node *head,struct node *end, struct node **newhead ,struct node **newend)
{
	

	struct node *pivot = end;
	struct node *prev = NULL;
	struct node *cur = head , *tail = pivot;
	while( cur != pivot)
	{
		if(cur -> data < pivot -> data)
		{
			if((*newhead) == NULL)
			(*newhead) = cur;
			prev = cur;
			cur = cur -> next;
		}
		else
		{
			if(prev)
				prev -> next = cur -> next;
			struct node *tmp = cur -> next;
			cur -> next = NULL;
			tail -> next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if((*newhead) == NULL)
		(*newhead) = pivot;
	(*newend) = tail;
	return pivot;

}
struct node *quicksortrecur(struct node *head ,struct node *end)
{
	if(head == NULL || head == end )
	return head;
	struct node *newhead = NULL , *newend = NULL;
	struct node *pivot = partition(head , end ,&newhead , &newend);
	if(newhead != pivot)
		{
			struct node *tmp = newhead;
			while(tmp -> next != pivot)
				tmp =tmp -> next;
			tmp -> next = NULL;
			newhead = quicksortrecur(newhead , tmp);
			tmp = gettail(newhead);
			tmp -> next = pivot;
		}
	pivot ->next = quicksortrecur(pivot -> next, newend);
	return newhead;
}
void quicksort(struct node **headref )
{
	(*headref) = quicksortrecur(*headref , gettail(*headref));
	return;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

void swap_ll(struct node *head)
{
	while(head != NULL && head->next != NULL)
	{
		swap(&head->data,&head->next->data);
		head=head->next->next;
	}
}


void del_dup(struct node *head)
{
	struct node *next=NULL;
	if(head == NULL)
		return;
	while( head -> next != NULL)
	{
		if(head->data == head->next->data)
		{
			next=head->next->next;
			free(head->next);
			head->next=next;		
		}
		else
			head=head->next;
	}
}

//print reverse
void print_rev(struct node *head)
{
	if(head == NULL)
		return;
	print_rev(head->next);
	printf("%d ",head->data);
}

//intersecting  point two ll
int _get_intersecting(int ,struct node*,struct node*);
int getcount(struct node *head)
{
	int cont = 0;
	while(head!=NULL)
	{
		cont++;
		head=head->next;
	}
return cont;
}
int get_intersecting(struct node *head1,struct node *head2)
{
	int c1=getcount(head1);
	int c2=getcount(head2);
	int d;
	
	if(c1>c2)
	{
		d=c1-c2;
		 return _get_intersecting(d,head1,head2);
	}
	else
	{
		d=c2-c1;
		 return _get_intersecting(d,head2,head1);
		
	}

}
int _get_intersecting(int d,struct node *head1,struct node *head2)
{
	int i;
	for(i=0;i<d;i++)
	{
		if(head1 == NULL)
			return -1;
		head1=head1->next;
	}
//printf("%d %d",head1->data,head2->data);
	while(head1!= NULL && head2 != NULL)
	{
		if(head1== head2)
		return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
return -1;
}

void insert_sort(struct node **head,int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next= NULL;
	if(*head == NULL)
	{
		*head=newnode;
		return;

	}
	else if((*head)->data>=data)
	{
		newnode->next=(*head);
		(*head)=newnode;
	}
	else
	{
		struct node *ref=*head;
		while(ref ->next !=NULL && ref->next->data < data )
		{
			ref=ref->next;

		}
		newnode->next=ref->next;
		ref->next=newnode;
	}

}


void merge_sort(struct node **headref)
{
	struct node *head=*headref;
	struct node *a= NULL;
	struct node *b = NULL;
	
	if(head == NULL || head -> next == NULL)
	{
		return;
	}
	frontbacksplit(head,&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	*headref = merge(a , b);

	
	
}
void frontbacksplit(struct node *head,struct node **a,struct node **b)
{
	if( head == NULL || head -> next == NULL)
	{
		*a = head;
		*b = NULL;

	}
	else
	{
		struct node *fast;
		struct node *slow;
		slow = head;
    		fast = head->next;
		while(fast != NULL)
		{
			fast = fast -> next;
			if(fast != NULL)
			{
				slow = slow -> next;
				fast = fast -> next;


			}
		}
		*a = head;
		*b = slow -> next;
		slow -> next = NULL;
	}
}

struct node* merge(struct node *a,struct node *b)
{
	struct node *result = NULL;
	if(a==NULL) return b;
	if(b==NULL) return a;
	if(a->data <= b->data)
	{
		result = a;
		result->next = merge(a->next , b);
	}
	else
	{
		result = b;
		result -> next = merge(a, b->next);
	}
	return result;
}


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
	printf("%d l\n",detect_loop(head));
		printf("%d l\n",ispallindrom(&head));
	struct node *head2=NULL;
	push_ll(&head2,5);
	push_ll(&head2,3);
	print_ll(head2);
	print_rev(head);
	head->next->next=head2;
	printf("%d l\n",get_intersecting(head,head2));
	merge_sort(&head);
	print_ll(head);
	insert_sort(&head,4);
	insert_sort(&head,4);
	insert_sort(&head,4);
	print_ll(head);
	del_dup(head);
	swap_ll(head);*/
	quicksort(&head);
	struct node *aref=NULL;
	struct node *bref=NULL;
	altsplit(head,&aref,&bref);
	//deletealt(head);
	struct node *head2=merge_sorted_ll(aref,bref);
		print_ll(head2);
	struct node *ptr=reverse(head2,2);
		print_ll(ptr);

return 0;
}
