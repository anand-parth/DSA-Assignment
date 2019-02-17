#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void add(Node **head_ref, int x) 
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
void traverse(Node *head_ref)
{
	Node* tmp = head_ref;
	while(tmp->next != head_ref)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
}
Node *search(Node *head_ref, int k,int l)
{
	int ct = 0;
	Node *tmp = head_ref;
	while(tmp->next != head_ref)
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
int main()
{
	Node* head = NULL;
	add(&head,10);
	add(&head,20);
	add(&head,30);
	add(&head,40);
	traverse(head);
	Node *tmp = search(head, 2, 4);
	printf("%d\n", tmp->data);
	return 0;
}