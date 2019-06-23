//https://www.programcreek.com/2014/08/leetcode-plus-one-linked-list-java/

ListNode* sum1(ListNode* node)
{
	if (node == NULL)
		return NULL;
	stack<ListNode*> s;
	ListNode *t = node;
	
	while (t != NULL)
	{
		s.push(t);
		t = t->next;
	}

	int carry = 1, sum;
	while (s.empty() == false)
	{
		t = s.top();
		s.pop();

		sum = t->val + carry;
		t->val = sum % 10;
		carry = sum / 10;

		if (carry == 0)
			break;
	}

	if (carry == 0)
		return node;

	t = new ListNode(carry);
	t->next = node;

	return t;
}

ListNode* plusOne(ListNode *head)
{
	if (head == NULL)
		return NULL;
	return sum1(head);
}
