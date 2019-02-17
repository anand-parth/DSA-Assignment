#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void insertAtEnd(Node** head_ref, int x)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data=x;
	tmp->next= NULL;
	if(*head_ref == NULL)
		*head_ref=tmp;
	else
	{
		Node *lastNode = *head_ref;
		while(lastNode->next != NULL)
			lastNode = lastNode->next;
		lastNode->next = tmp;
	}
}
void search(Node *head_ref, int x)
{
	int ct=0;
	while(head_ref != NULL)
	{
		ct++;
		if(head_ref->data == x)
		{
			printf("%d ", ct);
		}
		head_ref = head_ref->next;
	}
}
void traverse(Node *head_ref)
{
	while(head_ref !=NULL)
	{
		printf("%d ", head_ref->data);
		head_ref = head_ref->next;
	}
	printf("\n");
}
void swap(Node **head_ref, int x)
{
	Node *prev = NULL;
	Node *target = *head_ref;
	while(target != NULL && target->data!=x)
	{
		prev = target;
		target = target->next;
	}
	if(target == NULL)
		printf("Element not present");
	if(prev == NULL)
	{
		Node *tmp = target->next;
		(*head_ref)->next = tmp->next;
		tmp->next = *head_ref;
		*head_ref = tmp;
	}
	else
	{
		Node *tmp = target->next;
		target->next = tmp->next;
		tmp->next = target;
		prev->next = tmp;
	}
			
}
void delete(Node **head_ref, int x)
{
	Node *tmp = *head_ref;
	Node *prev = NULL;
	int ct = 1;
	while(tmp != NULL)
	{
		if(tmp->data != x)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		else
		{
			if(ct == 1)
			{
				ct = 0;
				prev = tmp;
				tmp= tmp->next;
			}
			else
			{
				Node *deleted = tmp;
				prev->next = tmp->next;
				tmp = tmp->next;
				free(deleted);
			}
		}
	}
}
int main()
{
	Node* head = NULL;
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 30);
	insertAtEnd(&head, 50);
	insertAtEnd(&head, 40);
	insertAtEnd(&head, 50);
	insertAtEnd(&head, 60);
	insertAtEnd(&head, 50);
	// traverse(head);
	// search(head, 50);
	// swap(&head,50);
	traverse(head);
	delete(&head, 50);
	traverse(head);
	return 0;
}