/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == NULL) {
    return;
  }
  Node* temp = in -> next;

  if ((in -> value ) %2 == 0) {
    if (evens == NULL) {
      evens = in;
      evens -> next = NULL;
    }
    else {
      Node* evens_tail = evens;
      parse_linked_list(evens_tail);
      evens_tail -> next = in;
      evens_tail -> next -> next = NULL;
    }
  }
  

  else if (in -> value %2 != 0) {
    if (odds == NULL) {
      odds = in;
      odds -> next = NULL;
    }

    else {
      Node* odds_tail = odds;
      parse_linked_list(odds_tail);
      odds_tail -> next = in;
      odds_tail -> next -> next = NULL;
    }

  }

  in = temp;
  
  split(in, odds, evens);
  /* Add code here */
// WRITE YOUR CODE HERE
}

void parse_linked_list(Node*& tail) {
  if (tail -> next == NULL ) {
    return;
  }
  else {
    tail = tail -> next;
    parse_linked_list(tail); 
  }
}

/* If you needed a helper function, write it here */
