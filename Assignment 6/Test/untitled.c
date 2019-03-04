void merge(Node *head_ref1, Node* head_ref2)
{
	Node *tmp1 = head_ref1;
	Node *tmp2 = head_ref2;
	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1->data <= tmp2->data)
		{
			Node temp = tmp1->next;
			tmp1->next = tmp2;
			tmp2->next = temp;
			// insertAtEndSLL(&head, tmp1->data);
			tmp1 = tmp1->next;
		}
		else
		{
			Node temp = tmp2->next;
			tmp2->next = tmp1;
			tmp1->next = temp;
			// insertAtEndSLL(&head, tmp2->data);
			tmp2 = tmp2->next;
		}
	}
	while(tmp1!= NULL)
	{
		insertAtEndSLL(&head, tmp1->data);
		tmp1 = tmp1->next;
	}
	while(tmp2!= NULL)
	{
		insertAtEndSLL(&head, tmp2->data);
		tmp2 = tmp2->next;
	}
}