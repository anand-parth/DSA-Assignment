#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
void push(Node** head_ref, int x) 
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
int main()
{
	Node *head = NULL;
	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	Node *tmp = search(head, 2, 4);
	printf("%d", tmp->data);
	return 0;
}
