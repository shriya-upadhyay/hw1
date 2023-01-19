/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* evens = NULL;
  Node* odds = NULL;
  Node* in = new Node(0, new Node(6, new Node(8, new Node(10, new Node (3, new Node (11, NULL))))));
  split(in, odds, evens);

  Node *temp = odds;
  Node *temp2 = evens;

  cout << "Odds: " << endl;
  while(temp != NULL) {
    cout << temp -> value << " ";
    temp = temp -> next;
  }
  cout << endl;

  cout << "Evens: " << endl;
  while(temp2 != NULL) {
    cout << temp2 -> value << " ";
    temp2 = temp2 -> next;
  }
  cout << endl;

  while(odds != NULL){
    Node* temp = odds->next;
    delete odds;
    odds = temp;
  }

  while(evens != NULL){
    Node* temp = evens->next;
    delete evens;
    evens = temp;
  } 

}
