


struct Node
{
	Node() {}
	Node(bool blive, Node* next,int val)
	{
		isAlive = blive;
		pnext = next;
		nval = val;
	}
	bool isAlive;
	int nval;
	Node* pnext;
};

int   sYsf(Node* node, int del,int Num)
{
	Node* ndel = node;
	int i = 0;
	int n = 0;

	while (n < Num - 1)
	{
		if (del == i)
		{
			i = 0;
			ndel->isAlive = false;
			n++;
		}
		else if(ndel->isAlive)
		{
			i++;
		}
		ndel = ndel->pnext;
	}

	while (ndel)
	{
		if (ndel->isAlive)
		{
			break;
		}
		ndel = ndel->pnext;
	}
	return ndel->nval;
}

int main()
{
	Node *head = nullptr;
	Node *ptemp = nullptr;
	for (int i = 0; i < 6; i++)
	{
		if (!head)
		{
			head = ptemp = new Node(true, nullptr,i + 1);
		}
		else
		{
			ptemp->pnext = new Node(true, nullptr,i + 1);
			ptemp = ptemp->pnext;
		}
	}
	ptemp->pnext = head;

	int rel = sYsf(head, 5, 6);
	return 0;
}