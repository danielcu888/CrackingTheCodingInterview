/*
 * main.cc
 *
 *  Created on: Dec 29, 2011
 *      Author: danielcumberbatch
 */

enum BOOLEAN{FALSE, TRUE};

typedef struct Node
{
	void *data;
	struct Node *next;
} Node;


//Stack Implementation via a LinkedList

Node *stack;

bool createStack(Node **stack)
{
	*stack = 0;
	return true;
}

bool deleteStack(Node **stack)
{
	if(!*stack) return false;
	while(*stack)
	{
		Node *tmp = *stack;
		*stack = (*stack)->next;
		delete tmp;
	}
	return true;
}

bool StackEmpty(Node **stack)
{
	return *stack;
}

Node *StackTop(Node **stack) const
{
	return *stack;
}

void StackPush(Node **stack, void* data)
{
	Node *tmp = new Node();
	tmp->data = data;
	tmp->next = *stack;
	*stack = tmp;
}

bool StackPop(Node **stack)
{
	if(!*stack) return false;
	Node *tmp = *stack;
	*stack = (*stack)->next;
	delete tmp;
	return true;
}

//Queue implementation via a linkedlist

Node *qHead, *qTail;

bool createQueue(Node **qHead, Node **qTail)
{
	*qHead = *qTail = 0;
	return true;
}

bool deleteQueue(Node **qHead, Node **qTail)
{
	if(!*qHead) return false;
	while(*qHead)
	{
		Node *tmp = *qHead;
		*qHead = (*qHead)->next;
		delete tmp;
	}
	*qTail = *qHead;
	return true;
}

bool QueueEmpty(Node *qHead)
{
	return qHead;
}

int QueueSize(Node *qHead, Node *qTail)
{
	int ret = 0;
	while(qHead)
	{
		qHead = qHead->next;
		++ret;
	}
	return ret;
}

Node* QueueFront(Node *qHead, Node *qTail)
{
	return qHead;
}

Node* QueueBack(Node *qHead, Node *qTail)
{
	return qTail;
}

void QueuePush(Node **qHead, Node **qTail, void *data)
{
	Node *tmp = new Node();
	tmp->data = data;
	if(!*qHead) *qHead = *qTail = tmp;
	(*qTail)->next = tmp;
}

bool QueuePop(Node **qHead, Node **qTail)
{
	if(!*qHead) return false;
	Node *tmp = *qHead;
	*qHead = (*qHead)->next;
	delete tmp;
	return true;
}

int main(int argc, char** argv)
{
	return 0;
}
