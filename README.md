# singly_linked_list
In this implementation of lists we use the assert.h library for carry out all the checks on the parameters passed to the functions. 
Furthermore, the list is formed by a sentinel node of type node_t which contains the *next pointer to the first real node in the list,
this one means that there is a fictitious first node (sentinel) that contains no value in the value field. To access the first real node,
dereference the *next field of the node sentinel. 
