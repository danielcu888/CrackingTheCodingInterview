/*
 * Node.c
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"

enum BOOL partition(Node **head, int x)
{
	if(!*head) return FALSE; //if empty list
	if(!(*head)->next) return FALSE; //if single member list

	Node *tmp = *head;
	while(tmp->next)
	{
		if(tmp->next->data >= x)
			tmp = tmp->next;
		else
		{
			Node *tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp2->next = *head;
			*head = tmp2;
		}
	}
	return TRUE;
}

