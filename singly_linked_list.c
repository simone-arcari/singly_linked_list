/*
NOTA:   in this implementation of lists we use the assert.h library for 
    carry out all the checks on the parameters passed to the functions.
    Furthermore, the list is formed by a sentinel node of type node_t which
    contains the * next pointer to the first real node in the list, this one
    it means that there is a fictitious first node (sentinel) that contains 
    no value in the value field. To access the first real node, dereference 
    the * next field of the node sentinel. 
*/


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"


bool is_empty(node_t *list) {
/*******************************************************************************
 *
 * Description:
 *      true if the list is empty, false otherwise.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [out] return bool
 *
 ******************************************************************************/
	assert(list!=NULL);
	return (list->next==NULL);
}

bool is_not_finish(node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      true if it is not the last node, false otherwise.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [out] return bool
 *
 ******************************************************************************/
	assert(pos!=NULL);
	return (pos->next!=NULL); 
}

bool is_finish(node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      true if it is the last node, false otherwise.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [out] return bool
 *
 ******************************************************************************/
	assert(pos!=NULL);
	return (pos->next==NULL);
}

node_t *create_list(void) {
/*******************************************************************************
 *
 * Description:
 *      creates a list by allocating dynamic memory in the heap and returns
 *      the pointer to the allocated memory area.
 * 
 * Parameters:
 *      [out] return list: pointer to the sentinel node
 *
 ******************************************************************************/
	node_t *list = (node_t*)malloc(sizeof(node_t));
	list->next = NULL;

	return (list);
}

node_t *delete_list(node_t *list) {
/*******************************************************************************
 *
 * Description:
 *      it deletes a list by deallocating its memory from the heap but without 
 *      resetting the values of this memory area.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [out] return: NULL pointer 
 *
 ******************************************************************************/
	assert(list!=NULL);

	node_t *pos = list->next;	// pos points to the first node
	node_t *temp;
	
	/* deallocates all nodes in the list */
	while(pos!=NULL) {
		temp = pos->next;
		free(pos);

		pos = temp;	// increment the position to the next node
	}

	free(list);	// finally deallocates the sentinel node
	return NULL;
}

node_t *insert(node_t *pos, int value) {
/*******************************************************************************
 *
 * Description:
 *      inserts a node in succession at the given position with its relative 
 *      value. The inserted node is allocated on the heap.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [in] value: value to be included in the list
 *      [out] return new_node: pointer to the inseted node 
 *
 ******************************************************************************/
	assert(pos!=NULL);
	
	node_t *new_node = (node_t*)malloc(sizeof(node_t));
	new_node->value = value;	// the new node contains the entered value

	new_node->next = pos->next;	// insertion in list (first operation)
	pos->next = new_node;		// insertion in list (second operation)

	return (new_node);
}

node_t *remove_node(node_t *list, node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      removes the node pointed to by pos deallocating its memory area in the 
 *      heap and returns the position to the previous node.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [in] pos: pointer to node
 *      [out] return temp: pointer to the node preceding the one removed
 *
 ******************************************************************************/
	assert(list!=NULL);
	assert(pos!=NULL);

	node_t *temp = prev(list, pos);	// pointer to the previous node of pos
	temp->next = pos->next;
	free(pos);			// free the memory of the removed node
	return (temp);
}

node_t *next(node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      returns the next node to the given position.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [out] return next: pointer to next node
 *
 ******************************************************************************/
	assert(pos!=NULL);
	return (pos->next);
}

node_t *prev(node_t *list, node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      returns the previous node to the given position.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [in] pos: pointer to node
 *      [out] return next: pointer to previous node
 *
 ******************************************************************************/
	assert(list!=NULL);
	assert(pos!=NULL);
	
	node_t *temp = list;
	while(temp!=NULL && (temp->next)!=pos)
		temp = temp->next; // increment the position to the next node

	return (temp);
}

node_t *head(node_t *list) {
/*******************************************************************************
 *
 * Description:
 *      returns the first node to the list.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [out] return next: pointer to first node
 *
 ******************************************************************************/
	assert(list!=NULL);
	return (list->next);
}

node_t *tail(node_t *list) {
/*******************************************************************************
 *
 * Description:
 *      returns the last node to the list.
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [out] return pos: pointer to last node
 *
 ******************************************************************************/
	assert(list!=NULL);

	node_t *pos = list;
	while((pos->next)!=NULL)
		pos = pos->next;
		
	return (pos);
}

int get_value(node_t *pos) {
/*******************************************************************************
 *
 * Description:
 *      returns the value contained in the node.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [out] return value: value contained in the node
 *
 ******************************************************************************/
	assert(pos!=NULL);
	return (pos->value);
}

void set_value(node_t *pos, int value) {
/*******************************************************************************
 *
 * Description:
 *      sets the value provided in the node.
 * 
 * Parameters:
 *      [in] pos: pointer to node
 *      [in] value: value to be set
 *
 ******************************************************************************/
	assert(pos!=NULL);
	pos->value = value;
}

void popolate_list(node_t *list, int value[], int n) {
/*******************************************************************************
 *
 * Description:
 *      populates the empty list by creating the nodes relative to the values
 *      of the array value[]
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *      [in] value[]: array containing values to insert
 *      [in] n: array dimension
 *
 ******************************************************************************/
	assert(list!=NULL);
	assert(n>=0);

	node_t *pos = list;	// pos initially points to the sentinel node
	for(int i=0; i<n; i++) {
		pos = insert(pos, value[i]); // pos is incremented each time
	}
}

void print_list(node_t *list) {
/*******************************************************************************
 *
 * Description:
 *      print list
 * 
 * Parameters:
 *      [in] list: pointer to the sentinel node
 *
 ******************************************************************************/
	assert(list!=NULL);

	node_t *pos = list->next;	// pos point to first node

	printf("[ ");
	while(pos!=NULL) {
		printf("%d, ", pos->value);
		pos = pos->next;
	}
	printf("\b\b ]\n");
}
