#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if(empty()) {
    Item *temp = new Item;
    temp -> val[0] = val;
    temp -> first = 0;
    temp -> last = 1;
    temp -> prev = NULL;
    temp -> next = NULL;
    head_ = temp;
    tail_ = temp;
    size_++;
  }
  else if (tail_ -> last==ARRSIZE) {
    Item* temp = new Item;
    temp -> val[0] = val;
    temp -> first = 0;
    temp -> last = 1;
    temp -> prev = tail_;
    tail_ -> next = temp;
    tail_ = temp;
    size_++;
  }
  else {
  tail_ -> last++;
  tail_ -> val[tail_ -> last - 1] = val;
  size_++;
  }
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) {
    Item* temp = new Item;
    temp -> val[ARRSIZE - 1] = val;
    temp -> first = ARRSIZE - 1;
    temp -> last = ARRSIZE;
    temp -> prev = NULL;
    temp -> next = NULL;
    head_ = temp;
    tail_ = temp;
    size_++;
  }
  else if (head_ -> first == 0) {
    Item* temp = new Item;
    temp -> val[ARRSIZE - 1] = val;
    temp -> first = ARRSIZE - 1;
    temp -> last = ARRSIZE;
    temp -> next = head_;
    head_ -> prev = temp;
    head_ = temp; 
    size_++; 
  }
  else {
    head_ -> first--;
    head_ -> val[head_ -> first] = val;
    size_++;
  }
}

void ULListStr::pop_back() {
  if (empty()) {
    return;
  }
    tail_ -> val[ tail_ -> last -1] = "";
    (tail_ -> last)--;
    (size_)--; 
  if ((tail_ -> last) - (tail_ -> first) == 0) {
    Item* temp = tail_;
    if (tail_ -> prev != NULL) {
    tail_ -> prev -> next = NULL;
    tail_ = tail_ -> prev;
      delete temp;
     }
    }
 }

void ULListStr::pop_front() {
  if (empty()) {
    return;
  }
    head_ -> val[head_ -> first] = "";
    head_ -> first++;
    (size_)--;
    if ((head_ -> last) - (head_ -> first) == 0) {
      Item* temp = head_;
      if (head_ -> next != NULL) {
      head_ -> next -> prev = NULL;
      head_ = head_ -> next;
      delete temp;
      }
    }
}


std::string const & ULListStr:: back() const {
  return tail_ -> val[tail_ -> last -1];
}

std::string const & ULListStr::front() const {
  return head_ -> val[head_ -> first];
}





void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  //make sure loc is valid 
  if (loc > size_ || loc < 0) {
    return NULL;
  }

  //initalize
  size_t counter = 0;
  Item* temp = head_;
  unsigned int innerArrayValue = temp->first;


  //counter += (temp -> last) - (temp -> first);
  while(counter < loc) {
    //if we can incremeent innerArrayValue increase it
      if (innerArrayValue < (temp -> last - 1)) {
        innerArrayValue++;
      }
      else {
        temp = temp -> next;
        innerArrayValue = temp -> first;
      }
    //else go to next item and set innerArrayValue = temp->first;
    counter++;
  }
  return &(temp -> val[innerArrayValue]);
}

