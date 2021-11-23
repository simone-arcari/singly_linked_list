#include <stdio.h>
#include <stdbool.h>
#include "singly_linked_list.h"

/******************************** MAIN PROGRAM ********************************/
int main(void) {
	/* example code */
	node_t *list = NULL;	// the list is a pointer to the first node
	
	do {
		list = create_list();
	}while(list==NULL);	    // retry until the list is created
	
	/* populate my list */
	int value[10] = {2,5,7,1,6,9,4,8,3,0};	// array of auxiliaries
	popolate_list(list, value, 10);
		
	/* print list */
	printf("lista: ");
	print_list(list);

	/* get the value of the first node */
	printf("il primo nodo contiene: %d\n", get_value(head(list)));

	/* remove the last node */
	node_t *pos = tail(list);
	printf("\nrimuovo l'ultimo nodo:\n");
	pos = remove_node(list, pos);	// now pos points to the new last node

	/* print list */
	printf("lista: ");
	print_list(list);

	/* insert node */
	pos = prev(list, pos);	// now pos points to the penultimate node
	printf("\ninserisco 10 prima dell'ultimo nodo:\n");
	insert(pos, 10);

	/* print list */
	printf("lista: ");
	print_list(list);

	/* loads all zeros in the value field of the nodes starting from the head */
	pos = list; // now pos points to the sentinel knot
	int count = 1;
	printf("\ncarico tutti zeri nei nodi partendo dalla testa:\n");
	do {
		pos = next(pos);	// increment the pointed node
		set_value(pos, 0);
		printf("%d°-->", count);
		print_list(list);
		count++;

	}while(is_not_finish(pos));

	/* loads all 1s in the value field of the nodes starting from the queue */
	pos = tail(list); // now pos points to the last node
	count = 1;
	printf("\ncarico tutti uno nei nodi partendo dalla coda:\n");
	do {
		set_value(pos, 1);
		printf("%d°-->", count);
		print_list(list);
		count++;
		pos = prev(list, pos);	// decreases the pointed node

	}while(pos != list);	// until pos reaches the sentinel node

	/* delete list */
	list = delete_list(list);
	if(list==NULL)
		printf("\nho eliminato(deallocato) la lista\n");
	
	return 0;
}
/****************************** END MAIN PROGRAM ******************************/