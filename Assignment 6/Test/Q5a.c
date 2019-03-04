#include<stdio.h>
#include<stdlib.h>
#define scan(a) scanf("%d",&a)
#define print(a) printf("%d\n", a);
#define loop(i,n) for(int i=0;i<n;i++)
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void insertAtEndSLL(Node** head_ref, int x)
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
void merge(Node *head_ref1, Node* head_ref2, Node *head)
{
	Node *tmp1 = head_ref1;
	Node *tmp2 = head_ref2;
	Node *temp;
	temp = head;
	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1->data <= tmp2->data)
		{
			temp->next = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			temp->next = tmp2;
			tmp2 = tmp2->next;
		}
		temp = temp->next;
	}
	while(tmp1!= NULL)
	{
		temp->next = tmp1;
		tmp1 = tmp1->next;
		temp = temp -> next;
	}
	while(tmp2!= NULL)
	{
		temp->next = tmp2;
		tmp2 = tmp2->next;
		temp = temp -> next;
	}
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
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *head = (Node *)malloc(sizeof(Node));
	int n1;
	scan(n1);
	loop(i,n1)
	{
		int u;
		scan(u);
		insertAtEndSLL(&head1, u);
	}
	int n2;
	scan(n2);
	loop(i,n2)
	{
		int u;
		scan(u);
		insertAtEndSLL(&head2, u);
	}
	merge(head1,head2,head);
	traverse(head->next);
	return 0;
}