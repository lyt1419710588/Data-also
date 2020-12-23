struct list
{
	int nval;
	list *pNext;
};


list* ReList(list* head)
{
	if (!head || !head->pNext)
	{
		return head;
	}

	list *s = nullptr;
	while (head)
	{
		list* node = head;
		head = head->pNext;
		list *hnext = head->pNext;
		node->pNext = s;
		head->pNext = node;
		s = head;
		head = hnext;
	}
	head = s;
	return s;
}

int main()
{
	list* head = nullptr;
	list* node = nullptr;
	for (size_t i = 0; i < 6; i++)
	{
		if (!head)
		{
			head = node = new list;
			node->nval = i + 1;
			node->pNext = nullptr;
		}
		else
		{
			node->pNext = new list;
			node->pNext->nval = i + 1;
			node->pNext->pNext = nullptr;
			node = node->pNext;
		}
	}

	list *rList = ReList(head);
}