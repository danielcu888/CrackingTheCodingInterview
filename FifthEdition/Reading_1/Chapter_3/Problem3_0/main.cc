/*
 * main.cc
 *
 *  Created on: Jan 3, 2012
 *      Author: danielcumberbatch
 */

#include <stddef.h>

enum BOOLEAN {FALSE, TRUE};

typedef struct Node
{
	void *data;
	struct Node *next;
} Node;

BOOLEAN createStack(Node **headAddress)
{
	*headAddress = 0;
	return TRUE;
}

BOOLEAN deleteStack(Node **headAddress)
{
	if(!*headAddress) return FALSE;
 	while(*headAddress)
	{
		Node *tmp = *headAddress;
		*headAddress = (*headAddress)->next;
		delete tmp;
	}
 	return TRUE;
}

BOOLEAN emptyStack(Node *head)
{
	return *head ? FALSE : TRUE;
}
Node *topStack(Node *head)
{
	return head;
}

size_t sizeStack(Node *head)
{
	size_t ret = 0;
	while(head)
	{
		++ret;
		head = head->next;
	}
	return ret;
}

BOOLEAN pushStack(Node **headAddress, void *val)
{
	Node *tmp = new Node();
	if(!tmp) return FALSE;
	tmp->data = val;
	tmp->next = *headAddress;
	*headAddress = tmp;
	return TRUE;
}

BOOLEAN popStack(Node **headAddress)
{
	if(!*headAddress) return FALSE;
	Node *tmp = *headAddress;
	*headAddress = tmp->next;
	delete tmp;
	return TRUE;
}

BOOLEAN createQueue(Node **headAddress, Node **tailAddress)
{
	*headAddress = *tailAddress = 0;
	return TRUE;
}

BOOLEAN deleteQueue(Node **headAddress, Node **tailAddress)
{
	if(!*headAddress) return FALSE;
	while(*headAddress)
	{
		Node *tmp = *headAddress;
		*headAddress = tmp->next;
		delete tmp;
	}
	*tailAddress = 0;
	return TRUE;
}

BOOLEAN emptyQueue(Node *head)
{
	return head ? FALSE : TRUE;
}

Node *frontQueue(Node *head, Node *tail)
{
	return head;
}

Node *backQueue(Node *head, Node *tail)
{
	return tail;
}

size_t sizeQueue(Node *head)
{
	size_t ret = 0;
	while(head)
	{
		++ret;
		head = head->next;
	}
	return ret;
}

BOOLEAN pushQueue(Node **headAddress, Node **tailAddress, void *val)
{
	Node *tmp = new Node();
	if(!tmp) return FALSE;
	tmp->data = val;
	tmp->next = *tailAddress;
	*tailAddress = tmp;
	if(!*headAddress) *headAddress = *tailAddress;
	return TRUE;
}

BOOLEAN popQueue(Node **headAddress, Node **tailAddress)
{
	if(!*headAddress) return FALSE;
	Node *tmp = *headAddress;
	if(*tailAddress == tmp)
		*headAddress = *tailAddress = 0;
	else
		*headAddress = tmp->next;
	delete tmp;
	return TRUE;
}

int main(int argc, char **argv)
{
	return 0;
}
