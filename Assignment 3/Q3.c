#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node *head2 = NULL;
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
void buildLL(Node *head_ref,int val,Node **head2)
{
	Node *tmp = head_ref;
	while(tmp!=NULL)
	{
		if(tmp->data == val)
			insertAtEndSLL(head2,val);
		tmp = tmp->next;
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
	Node *head = NULL;
	int k;
	scanf("%d ",&k);
	int a[100];
	int ct = 0;
	while(1)
	{
		int v;
		scanf("%d",&v);
		if(v==-1)
			break;
		else
			a[ct++] = v;
	}
	for(int i=0;i<ct;i++)
	{
		insertAtEndSLL(&head,a[i]);
	}
	for(int i=0;i<ct*k;i++)
	{
		if((i+1)%k==0)
		{
			buildLL(head,a[i],&head2);
			a[i] = -1;
		}
	}
	for(int i=ct-1;i>=0;i--)
	{
		if(a[i]!=-1)
			buildLL(head,a[i],&head2);
	}
	traverse(head2);


	return 0;
}