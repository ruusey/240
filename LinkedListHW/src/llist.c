/*
 * Copyright 2018
 * Created on: Apr 25, 2018
 * Author: Robert Usey
 * CSCE212 HW06
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/alist.h"
#include "../include/llist.h"

// Helper methods
int contains(alist_t *lst, int val);
llist_t *create_link(int val, llist_t *parent);
llist_t *reverse(llist_t *lst);

llist_t *llalloc(int val) {
  // Allocate memory on the heap for a new linked list
  llist_t *new_list = malloc(sizeof(llist_t));
  new_list->val = val;

  new_list->next = NULL;

  return new_list;
}

llist_t *copy(llist_t *lst) {
  // Use our tort hare proof to find our where to insert our link
  proof_t *cycle = tort_hare(lst);
  int start_index = cycle->return_val;
  int times = 0;
  // Cur points to start of our list
  llist_t *cur = lst;
  // Allocate new list node starting value cur.val
  llist_t *new_list = llalloc(cur->val);
  // Keep track of the start of our new list so we can add the other nodes
  llist_t *start = new_list;
  // Next node in source list
  cur = cur->next;
  for (; cur->next != NULL; cur = cur->next) {
    // Allocate new list node with cur.val
    llist_t *nde = llalloc(cur->val);
    // New list.next = new node
    new_list->next = nde;
    // Move new_list to the next node
    new_list = new_list->next;

    if ((cur->val) == start_index)
      times++;
    // If weve seen the start of the loop twice
    if (times == 2)
      break;
  }
  // Set cur back to start of new list
  cur = start;
  while (start->val != start_index) {
    start = start->next;
  }
  new_list->next = start;
  // Return pointer to start of our list
  return cur;
}
llist_t *convert(unsigned int *arr, unsigned int size) {
  llist_t *first = NULL, *cur = NULL;
  for (int i = 0; i < size; i++) {
    // Creates node next to current with current.next pointing to this new node
    cur = create_link(arr[i], cur);
    if (first == NULL)
      first = cur;
  }

  return first;
}
proof_t *tort_hare(llist_t *lst) {
  // Allocate new proof_t on the heap
  proof_t *ret = malloc(sizeof(proof_t));
  // Two pointers, fast and slow, both start at the head
  llist_t *slow = lst, *fast = lst;

  while (slow != NULL && fast != NULL && fast->next != NULL) {
    // Slow moves by 1 node, fast by 2
    slow = slow->next;
    fast = fast->next->next;

    //If they meet then there is a loop
    if (slow == fast) {
      ret->proof = &slow->val;
      slow = lst;
      while (slow != fast) {
        // Move both by one until they meet
        slow = slow->next;
        fast = fast->next;
      }
      // When they meet this is the node where the loop begins
      ret->return_val = slow->val;
      return ret;
    }
  }
  // Loop was not foound!
  ret->return_val = -1;
  ret->proof = -1;
  return ret;
}

proof_t *rev_cycle(llist_t *lst, int num) {
  // Copy our list(deep) into temp;
  llist_t *tmp = copy(lst);
  // Create new proof_t on the heap
  proof_t *ret = malloc(sizeof(proof_t));
  // Create new int array to hold our steps on the heap;
  int *arr = malloc(sizeof(arr) * num);
  // Reverse the list copy
  llist_t *new_head = reverse(tmp);
  // Undo destructive reverse
  reverse(new_head);
  // If the heads are equal we have a loop
  if (new_head == tmp) {
    // Allocate an alist on heap - Will be used to map already visited values
    alist_t *array = alalloc();
    for (; new_head->next != NULL; new_head = new_head->next) {
      // For all the elements if the array already contains it
      if (contains(array, new_head->val) == 1) {
        // That is the start of our loop
        ret->return_val = new_head->val;
        break;
      } else {
        // Else add the value to the array
        push(array, (int *) new_head->val);
      }

    }
    // Grab the first num values from the array
    for (int i = 0; i < num; i++) {
      arr[i] = (array->arr[i]);
    }
    ret->proof = arr;
    // Free the memory used for the array
    free(array);
  } else {
    // No loop found
    ret->return_val = -1;
    ret->proof = arr;
  }
  // Free memory used to hold our temp array (mainy used to test copy function)
  free(tmp);

  return ret;
}
// Reverses a given llist - used for rev_cycle
llist_t *reverse(llist_t *head) {
  llist_t *prev = NULL;
  llist_t *curr = head;
  llist_t *next;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}
// Creates a node next to a given parent - used in push
llist_t *create_link(int val, llist_t *parent) {
  llist_t *node = llalloc(val);

  if (parent != NULL)
    parent->next = node;

  return node;
}
// Finds the index of the first occurance of a node within a list

// Returns 1 if val is contained within alist lst
int contains(alist_t *lst, int val) {
  for (int i = 0; i < lst->size; i++) {
    if (lst->arr[i] == val) {
      return 1;
    }
  }
  return 0;
}

