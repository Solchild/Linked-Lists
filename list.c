// list/list.c
// 
// Implementation for linked list.
//
// Alexander Rodgers

#include <stdio.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *newList;
  newList = malloc(sizeof(list));
  newList->head = NULL;
  return newList; 
}

void list_free(list_t *l) {
  if(l == NULL){
    return;
  }
  node_t *curr_node = l -> head;
  node_t *next_node = NULL;
  while (curr_node != NULL){
      next_node = curr -> next;
      free(curr_node);
      curr_node = next_node;
  }
  l->head = NULL
  free(list);
}

void list_print(list_t *l) {
  node_t *curr_node = l -> head;
  node_t *next_node = NULL;
  printf("Starting list_print\n");
  while (curr_node->next != NULL){
    printf("%d -> ", curr_node -> value);
    next_node = curr_node -> next;
    curr_node = next_node;
  }
  printf("%d", curr_node -> value)
  printf("Ended list_print\n");
  return;
}

int list_length(list_t *l) {
  int number = 0;
  while(l->next != NULL){
    number++;
    *l = l->next;
  }
  return number;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  node_t *curr_node = l->head;
  while(curr_node->next != NULL){
    curr_node = curr_node->next;
  }
  curr_node->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  int i = 1;
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  node_t *curr_node = l->head;
  node_t *next_node = NULL;
  while(curr_node != NULL && i < index){
    i++;
    next_node = curr_node->next;
    curr_node = next_node;
  }
  next_node = curr_node->next;
  curr_node->next = new_node;
  new_node->next = next_node;
}

elem list_remove_from_back(list_t *l) { 
  node_t *prev_node = l->head;
  node_t *curr_node = prev_node->next;
  if(l->head == NULL){
    return -1;
  }
  while(curr_node->next != NULL){
    prev_node = curr_node;
      curr_node = curr_node->next;
  }
  prev_node->next = NULL;
  elem value = curr_node->value;
  free(curr_node);
  return value;
}

elem list_remove_from_front(list_t *l) { 
  if(l->head == NULL){
    return -1;
  }
  node_t *curr_node = l->head;
  l->head = curr_node->next;
  elem value = curr_node->value;
  free(curr_node);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  int i = 0;
  node_t *prev_node = l->head;
  node_t *curr_node = prev_node->next;
  while(curr_node->next != NULL){
    i++;
    prev_node = curr_node;
    curr_node = curr_node->next;
  }
  if(i < index){
    return -1;
  }
  node_t *temp = curr_node;
  prev_node->next = curr_node->next;
  elem value = temp->value;
  free(temp);
  return value;
}

bool list_is_in(list_t *l, elem value) { 
  if(l->head == NULL){
    return false; 
  }
  bool is_there = false;
  node_t *curr_node = l->head;
  while(curr_node->next != NULL && !is_there){
    if(curr_node->value == value){
      is_there = true;
    }
    curr_node = curr_node->next;
  }
  return is_there;
}

elem list_get_elem_at(list_t *l, int index) { 
  int i = 0;
  elem value = 0;
  node_t *curr_node = l->head;
  while(i < index){
    i++;
    if(curr_node->next == NULL){
      return -1;
    }
    curr_node = curr_node->next;
  }
  value = curr_node->value;
  return value;
}
int list_get_index_of(list_t *l, elem value) {
  int i = 0;
  node_t * curr_node = l->head;
  while(curr_node->next != NULL){
    if (curr_node->value == value){
			return i;
		}
    i++;
    if(curr_node->next == NULL){
      return -1;
    }
		curr_node = curr_node->next;
  }
  return i;  
}
