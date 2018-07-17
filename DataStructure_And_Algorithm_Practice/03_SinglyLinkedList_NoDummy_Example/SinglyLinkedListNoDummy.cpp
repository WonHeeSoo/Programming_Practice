#include "SinglyLinkedListNoDummy.h"

SinglyLinkedListNoDummy::SinglyLinkedListNoDummy()
{
}

SinglyLinkedListNoDummy::~SinglyLinkedListNoDummy()
{
}

bool SinglyLinkedListNoDummy::Insert(int data, int pos)
{
	if (pos < 0)
	{
		return false;
	}

	if (nodeCnt == 0)
	{
		head = new Node(data);
		nodeCnt++;
		return true;
	}

	if (nodeCnt != 0 && pos == 0)
	{
		Node *nextNode = head;
		Node *node = new Node(data);
		head = node;
		head->next = nextNode;
		return true;
	}

	Node *prevNode = head;
	Node *nextNode = head->next;
	for (int i = 0; i <= __min(pos, nodeCnt); i++)
	{
		prevNode = prevNode->next;
		nextNode = nextNode->next;
	}
	Node *newNode = new Node(data);
	prevNode->next = newNode;
	newNode->next = nextNode;
	return true;
}

bool SinglyLinkedListNoDummy::Remove()
{
	Node *del = head;
	while (del->next != NULL)
	{
		del = head->next;
	}
	delete del;
	return true;
}

bool SinglyLinkedListNoDummy::Remove(int pos)
{
	if (pos < 0)
	{
		return false;
	}

	Node *delNode = head;
	if (pos == 0)
	{
		head = head->next;
		delete delNode;
	}
	
	Node *prevNode = head;
	delNode = delNode->next;
	Node *nextNode = delNode->next;
	for (int i = 1; i < __min(pos, nodeCnt); i++)
	{
		prevNode = prevNode->next;
		delNode = delNode->next;
		nextNode = nextNode->next;
	}
	prevNode->next = nextNode;
	delete delNode;
	return true;
}

void SinglyLinkedListNoDummy::TestAllList()
{
	Node *testNode = head;
	while (testNode != NULL)
	{
		printf("%d ,", testNode->data);
	}
	printf("\n");
}