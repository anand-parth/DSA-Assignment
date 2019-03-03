#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
-void insertAtEndSLL(Node** head_ref, int x)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data=x;
	tmp->next= NULL;
	if(*head_ref == NULL)
		*head_ref=tmp;
	else
	{
		Node *last = *head_ref;
		while(last->next != NULL)
			last = last->next;
		last->next = tmp;
	}
}
void pushDLL(Node** head_ref, int x) 
{ 
    Node *tmp = (Node *)malloc(sizeof(struct Node)); 
    Node *last = *head_ref; 
    tmp->data = x; 
    tmp->next = NULL; 
    if (*head_ref == NULL) 
    { 
        tmp->prev = NULL; 
        *head_ref = tmp; 
    }
    else
    {  
    	while (last->next != NULL) 
        	last = last->next; 
	    last->next = tmp; 
	    tmp->prev = last; 
	}
}
void addCLL(Node **head_ref, int x) 
{	
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = x;
	if(*head_ref == NULL)
	{
		*head_ref = tmp;
		tmp->next = tmp;
	}
	else
	{
		Node *last = *head_ref;	
		while(last->next != *head_ref)
			last = last->next;
		last->next = tmp;
		tmp->next = *head_ref;
    }
} 
Node *search(Node *head_ref, int k,int l)
{
	int ct = 0;
	Node *tmp = head_ref;
	while(tmp != NULL)
	{
		ct++;
		if(ct == l-k+1)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
void traverse(Node *head_ref)
{
	Node *tmp = head_ref;
	while(tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
int main()
{
	Node* head = NULL;
	int ip,ct =0;
	while(1)
	{
		scanf("%d", &ip);
		if(ip == -1)
			break;
		else
		{
			insertAtEndSLL(&head, ip);
			ct++;
		}
	}
	traverse(head);
	Node *tmp1 = search(head, 2, ct);
	printf("%d\n", tmp1->data);

	// for(int i=1;i<=5;i++)
	// 	insertAtEndSLL(&head, 10*i);
	// Node *tmp = search(head, 2, 5);
	// printf("%d\n", tmp->data);
	// traverse(head);

	// Node *head1 = NULL;
	// for(int i=1;i<=5;i++)
	// 	pushDLL(&head1, 10*i);
	// Node *tmp1 = search(head1, 2, 5);
	// printf("%d\n", tmp1->data);
	// traverse(head1);

	// Node* head2 = NULL;
	// for(int i=1;i<=5;i++)
	// 	addCLL(&head2, 10*i);
	// Node *tmp2 = search(head2, 1, 5);
	// printf("%d\n", tmp2->data);
	return 0;
}
