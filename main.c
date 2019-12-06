#include <stdio.h>

#include "list.h"
int main() {
  printf("Tests for linked list implementation\n");
  
	list_t *myList = list_alloc();
  
	list_add_to_front(myList,4);
  printf("Add %d to the front: ", 4);
  list_print(myList);
    
  list_add_to_back(myList,3);
  printf("Add %d to the back: ", 3);
  list_print(myList);
  
	list_add_to_front(myList,1);
  printf("Add %d to the front: ", 1);
  list_print(myList);
    
	list_add_to_back(myList,4);
  printf("Add %d to the back: ", 4);
  list_print(myList);
    
	list_add_at_index(myList,6,4);
  printf("Add %d at index %d: ", 6,4);
  list_print(myList);
    
  list_add_to_front(myList,6);
  printf("Add %d to the front: ", 6);
  list_print(myList);
  
	list_add_to_back(myList,9);
  printf("Add %d to the back: ", 9);
  list_print(myList);
   
	list_add_at_index(myList,9,2);
  printf("Add %d at index %d: ", 9,2);
  list_print(myList);
    
	elem e1 = list_remove_from_front(myList);
  printf("\nRemoved %d from the front: ", e1);
  list_print(myList);
    
	elem e2 = list_remove_at_index(myList, 4);
  printf("Removed %d from the index, %d: ", e2, 3);
  list_print(myList);
    
	elem e3 = list_remove_from_back(myList);
  printf("Removed %d from the back: ", e3);
	list_print(myList);
	
	int length = list_length(myList);
	printf("\nLength of the list is: %d.\n", length);
	
	elem item = 10;
	bool exist = list_is_in(myList, item);
	if (exist){
		printf("%d is in the list.\n", item);
	} else {
		printf("%d is not in the list.\n", item);
	}
	
	int index1 = 2;
	elem e4 = list_get_elem_at(myList, index1);
	printf("Element at index %d is: %d. \n", index1, e4);
	
	elem e5 = 2;
	int index2 = list_get_index_of(myList,e5);
	printf("Element %d is at index: %d. \n", e5, index2);
	
	list_free(myList);
	return 0;
}
