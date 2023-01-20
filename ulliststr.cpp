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
  //checks if list is empty and allocated a new item if necessary
  if(empty()) {
    //fills in features of the new item such as the value in the array, the first value, the last value, and then the prev and next values, as well as the head and tail while increasing the size
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
  //checks if the item we're trying to add to is already full
  else if (tail_ -> last==ARRSIZE) {
    //allocates a new item to hold the new value
    //fills in features of the new item such as the value in the array, the first value, the last value, and then the prev and next values, as well as the head and tail while increasing the size
    Item* temp = new Item;
    temp -> val[0] = val;
    temp -> first = 0;
    temp -> last = 1;
    temp -> prev = tail_;
    tail_ -> next = temp;
    tail_ = temp;
    size_++;
  }
  //if the above conditions aren't met the new value is simply added to the last item's array
  else {
  tail_ -> last++;
  tail_ -> val[tail_ -> last - 1] = val;
  size_++;
  }
}

void ULListStr::push_front(const std::string& val) {
  //checks if list is empty and allocated a new item if necessary
  if (empty()) {
    //fills in features of the new item such as the value in the array, the first value, the last value, and then the prev and next values, as well as the head and tail while increasing the size
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
  //checks if the item we're trying to add to is already full
  else if (head_ -> first == 0) {
    //allocates a new item to hold the new value
    //fills in features of the new item such as the value in the array, the first value, the last value, and then the prev and next values, as well as the head and tail while increasing the size
    Item* temp = new Item;
    temp -> val[ARRSIZE - 1] = val;
    temp -> first = ARRSIZE - 1;
    temp -> last = ARRSIZE;
    temp -> next = head_;
    head_ -> prev = temp;
    head_ = temp; 
    size_++; 
  }
    //if the above conditions aren't met the new value is simply added to the first item's array
  else {
    head_ -> first--;
    head_ -> val[head_ -> first] = val;
    size_++;
  }
}

void ULListStr::pop_back() {
  //returns if list is empty
  if (empty()) {
    return;
  }
  //deletes last element from last tail's array
  //changes tail's last variable value as necessary
  //changes size as necessary
  tail_ -> val[ tail_ -> last -1] = "";
  (tail_ -> last)--;
  (size_)--;

  //deallocates item if the none of the item's array elements are used
  if ((tail_ -> last) - (tail_ -> first) == 0) {
    Item* temp = tail_;
    if(tail_ -> prev != NULL) {
    tail_ -> prev -> next = NULL;
    tail_ = tail_ -> prev;
    }
  //if last (singular) item in array, sets head to NULL
  else {
    head_ = NULL; 
  }
  delete temp;
}
}

void ULListStr::pop_front() {
  //returns if list is empty
  if (empty()) {
    return;
  }
  //deletes first element from head's array
  //changes head's first variable value as necessary
  //changes size as necessary
  head_ -> val[head_ -> first] = "";
  head_ -> first++;
  (size_)--; 
  //deallocates item if the none of the item's array elements are used
  if ((head_ -> last) - (head_ -> first) == 0) {
    Item* temp = head_;
    if (head_ -> next != NULL) {
      head_ -> next -> prev = NULL;
      head_ = head_ -> next;
    }
  //if last singular item in array, sets head to NULL
  else {
    head_ = NULL;
  }
  delete temp;
  }   
}

//return last element of tail's array
std::string const & ULListStr:: back() const {
  return tail_ -> val[tail_ -> last -1];
}

//return first element of head's array
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

  //initalize counter and innerArrayValue
  //counter will keep track of our position in the linked list (in terms of all of the arrays)
  //innerArrayValue will keep track of our position in the array of one singular item
  size_t counter = 0;
  Item* temp = head_;
  unsigned int innerArrayValue = temp->first;


  while(counter < loc) {
    //if we can incremeent innerArrayValue, increase it it
    if (innerArrayValue < (temp -> last - 1)) {
      innerArrayValue++;
    }

    //otherwise move to the next item and iterate through its array
    else {
      temp = temp -> next;
      innerArrayValue = temp -> first;
    }
    //increase the total counter value
    counter++;
  }
  return &(temp -> val[innerArrayValue]);
}

