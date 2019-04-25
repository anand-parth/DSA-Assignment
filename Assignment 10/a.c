insertintoHeap(int num,int i, int j)
{
	a[size].val= num;
	a[size].id2= i;
	a[size].id1= j;
	size++;
	shiftUp(size-1);
}
void shiftUp(int id)
{
	int parent;
	if(id != 0)
	{
		parent = (id - 1) / 2;
		if(a[parent].val < a[id].val)
		{
			swap(&a[parent], &a[id]);
			shiftUp(parent);
		}
	}
}