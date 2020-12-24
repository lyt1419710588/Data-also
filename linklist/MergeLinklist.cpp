struct list
{
	int nval;
	list *pNext;
};

list* MergList(list* l1, list* l2)
{
	list* head = nullptr;
	list* node = nullptr;
	while (l1 && l2)
	{
		if (l1->nval <= l2->nval)
		{
			if (!head)
			{
				head = node = l1;
			}
			else
			{
				node->pNext = l1;
				node = node->pNext;
			}
			l1 = l1->pNext;
		}
		else
		{
			if (!head)
			{
				head = node = l2;
			}
			else
			{
				node->pNext = l2;
				node = node->pNext;
			}
			l2 = l2->pNext;
		}
	}

	if (l1)
	{
		node->pNext = l1;
	}
	if (l2)
	{
		node->pNext = l2;
	}
	return head;

}

bool hasCycl(list* head)
{
	if (!head || !head->pNext || !head->pNext->pNext)
	{
		return false;
	}

	list* p = head;
	list* q = head;

	while (p && q)
	{
		if (!p)
		{
			return false;
		}
		p = p->pNext;
		if (!q)
		{
			return false;
		}
		if (!q->pNext)
		{
			return false;
		}
		q = q->pNext->pNext;

		if (!q)
		{
			return false;
		}

		if (q == p)
		{
			return true;
		}
	}
	return false;
}

list* remove(list* head,int n)
{
	list* l1 = head;
	list* l2 = head;
	int iCount = 0;
	while (l2)
	{
		l2 = l2->pNext;
		if (++iCount > n + 1)
		{
			l1 = l1->pNext;
		}
	}
	if (n == iCount)
	{
		head = head->pNext;
		delete l1;
	}
	else
	{
		list* del = l1->pNext;
		l1->pNext = l1->pNext->pNext;
		delete del;
	}
	return head;
}
int main()
{
	list* head = nullptr;
	list* node = nullptr;

	list* head1 = nullptr;
	list* node1 = nullptr;
	for (size_t i = 0; i < 6; i++)
	{
		if (!head && !head1)
		{
			head = node = new list;
			node->nval = 2 * i;
			node->pNext = nullptr;

			head1 = node1 = new list;
			node1->nval = 2 * i + 1;
			node1->pNext = nullptr;
		}
		else
		{
			node->pNext = new list;
			node->pNext->nval = 2 * i;
			node->pNext->pNext = nullptr;
			node = node->pNext;

			node1->pNext = new list;
			node1->pNext->nval = 2 * i + 1;
			node1->pNext->pNext = nullptr;
			node1 = node1->pNext;
		}
	}

	//list *mlist = MergList(head, head1);

	//bool bret = hasCycl(head);
	//node1->pNext = head1;

	

	//bool bret1 = hasCycl(head1);


	list* l3 = remove(head1, 3);
}