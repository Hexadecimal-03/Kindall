#include <iostream>
using namespace std;

class node
{
	/**
	 * node class for one node of the linked list
	 * value is for value stored in the node and next is pointer to next node
	 * an constructor can be called and initialized at the time of calling new function: [node* head = new node (value)]
	 */

public:
	int value;
	node *next;

	node(int d)
	{
		value = d;
		next = NULL;
	}
};

template <typename T>
class Node
{
	/**
	 * template class and hence can be typecast into any datatype at time of construction
	 * Node <int> * head;
	 * head = new Node <int> (num);
	 */

public:
	T value;
	Node *next;

	Node(T d)
	{
		value = d;
		next = NULL;
	}
};

void addatlast(int n, node *&head) // adds a new node with value n at the end of list
{
	if (head == NULL)
	{
		head = new node(n);
		return;
	}
	else
	{
		node *tail = head;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new node(n);
	}
	return;
}

node *merge(node *&a, node *&b)
{
	/**
	 * takes in two sorted arrays a and b, merges them into sorted array
	 * inputs heads of corresponding arrays and outputs the head of final sorted array
	 * inplace sorting with implementation of recursion
	 */

	node *c = NULL;
	if (a == NULL)
	{
		return b;
	}

	if (b == NULL)
	{
		return a;
	}

	if (a->value <= b->value)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

void print(node *head) // simple function for printing the list
{
	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

node *fromend(node *head, int k) // returns the head corresponding to k'th node from last of the list, as length of lists are not known generally
{
	node *slow = head;
	node *fast = head;
	int i;
	for (i = 1; i < k; ++i)
	{
		fast = fast->next;
	}

	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

void reverse(node *&head) // reverses whole list
{
	node *prev = NULL;
	node *curr = head;
	node *next;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	head = prev;
}

void kreverse(node *&head, int k)
{
	/**
	 * reverses k nodes at intervals of k nodes
	 * Example n = 3, k = 3, [9 4 1 7 8 3 2 6 5] -> [1 4 9 3 8 7 5 6 2]
	 * uses reverse function as helper function
	 */

	int i;
	node *prev = NULL;
	node *curr1 = head;
	node *curr2 = head;
	node *next = curr1;

	while (curr1 != NULL)
	{
		for (i = 1; i < k; ++i)
		{
			curr2 = curr2->next;
		}
		next = curr2->next;
		curr2->next = prev;
		prev = curr1;
		curr1 = next;
		curr2 = next;
	}

	head = prev;

	reverse(head);
}

node *recrev(node *head)	// Reverses list (inplace) using recursive function
{
	if (head->next == NULL || head == NULL)
	{
		return head;
	}

	node *shead = recrev(head->next);
	head->next->next = head;
	head->next = NULL;
	return shead;
}

void delathead(node *&head)		// Deletes the node at head
{
	if (head == NULL)
	{
		return;
	}

	node *temp = head->next;
	delete head;
	head = temp;

	return;
}

bool floydCycleRemoval(node *head)
{
	/**
	 * this function detects cyclic path present in the linked list
	 * if cyclic path is present -> function returns true and cycle is removed, else flase is returned
	 * uses two heads -> slow and fast to detect the cycle
	 */

	node *slow = head;
	node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			fast = head;

			while (slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
			slow->next = NULL;

			return 1;
		}
	}

	return 0;
}

node *intersectionOfTwoLinkedLists (node *l1, node *l2)
{
	/**
	 * This function gets two arguments - the head pointers of the two linked lists
	 * Return the node which is the intersection point of these linked lists
	 * It must be assured that the two lists intersect
	 */

	node *head1 = l1;
	node *head2 = l2;
	int a = 0, b = 0, c;
	while (head1 != NULL)
	{
		head1 = head1->next;
		a++;
	}
	while (head2 != NULL)
	{
		head2 = head2->next;
		b++;
	}
	if (a > b)
	{
		c = a - b;
		while (c > 0)
		{
			l1 = l1->next;
			c--;
		}
	}
	else
	{
		c = b - a;
		while (c > 0)
		{
			l2 = l2->next;
			c--;
		}
	}

	while (l1->next != NULL && l2->next != NULL)
	{
		if (l1->next == l2->next)
		{
			return l1->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return NULL;
}

int main()
{

	return 0;
}