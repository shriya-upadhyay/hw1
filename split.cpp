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
  //checks if the input node is null before trying to dereference it
  if (in == NULL) {
    return;
  }
  //creates a temp pointer for the next item after in
  Node* temp = in -> next;

  //checks if input value is even
  if ((in -> value ) %2 == 0) {
    //checks if evens list is null already and sets it equal to in, if so, sets the next pointer to NULL since it is the only item in the evens list
    if (evens == NULL) {
      evens = in;
      evens -> next = NULL;
    }
    //checks if evens list has numbers in it already, if so, uses the recursive function to find the tail and then adds the number to the end of the list
    else {
      Node* evens_tail = evens;
      parse_linked_list(evens_tail);
      evens_tail -> next = in;
      evens_tail -> next -> next = NULL;
    }
  }
  
  //checks if input value is odd
  else if (in -> value %2 != 0) {
    //checks if odds list is null already and sets it equal to in, if so, sets the next pointer to NULL since it is the only item in the odds list 
    if (odds == NULL) {
      odds = in;
      odds -> next = NULL;
    }

  //checks if odds list has numbers in it already, if so, uses the recursive function to find the tail and then adds the number to the end of the list
  else {
    Node* odds_tail = odds;
    parse_linked_list(odds_tail);
    odds_tail -> next = in;
    odds_tail -> next -> next = NULL;
    }

  }

  //sets input pointer to next number in input list
  in = temp;
  
  //calls split function again
  split(in, odds, evens);
  /* Add code here */
// WRITE YOUR CODE HERE
}


//recursive function to find tail of a linked list
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
