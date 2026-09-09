#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
  /**
    * Adds a new value to the back of the list
    *   - MUST RUN in O(1)
  */
  void ULListStr::push_back(const std::string& val) {
    // if tail is NULL
    if (tail_ == nullptr) {
      Item* newItem = new Item();
      newItem->val[0] = val;
      newItem->first = 0;
      newItem->last = 1;
      head_ = tail_ = newItem;
    }

    // if tail has room
    else if (tail_->last < ARRSIZE) {
      tail_->val[tail_->last] = val;
      tail_->last ++;
    }
    
    // if no room, add new item
    else {
      Item* newItem = new Item();
      newItem->val[0] = val;
      newItem->first = 0;
      newItem->last = 1;
      newItem->prev = tail_;
      tail_->next = newItem;
      tail_ = newItem;
    }

    size_ ++;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
  */
  void ULListStr::pop_back() {
    size_ --;
    tail_->last --;

    // if item is empty, we deallocate it
    if (tail_->last == tail_->first) {
      Item* tmp = tail_->prev;
      delete tail_;
      tail_ = tmp;
      if (tail_ != nullptr) {
        tail_->next = nullptr;
      } else {
        head_ = nullptr;
      }
    }
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
  */
  void ULListStr::push_front(const std::string& val) {
    // if head is null
    if (head_ == nullptr) {
      Item* newItem = new Item();
      newItem->first = 0;
      newItem->last = 1;
      newItem->val[0] = val;
      head_ = newItem;
      tail_ = newItem;
    }

    // else if there is room before the 'first' val
    else if (head_->first != 0) {
      head_->first --;
      head_->val[head_->first] = val;
    }

    // else (there is no room)
    else {
      Item* newItem = new Item();
      newItem->first = 0;
      newItem->last = 1;
      newItem->val[0] = val;
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
    }
    
    size_ ++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
  */
  void ULListStr::pop_front() {
    size_ --;
    head_->first ++;
    
    // if empty item, deallocate
    if (head_->first == head_->last) {
      Item* tmp = head_->next;
      delete head_;
      head_ = tmp;
      if (head_ != nullptr) {
        head_->prev = nullptr;
      } else {
        tail_ = nullptr;
      }
    }
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
  */
  std::string const & ULListStr::back() const {
    return tail_->val[tail_->last - 1]; 
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
  */
  std::string const & ULListStr::front() const {
    return head_->val[head_->first];
  }

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
  */
  std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size_) {
      return NULL;
    }

    Item* curr = head_;
    while (curr != nullptr) {
      size_t range = curr->last - curr->first;
      if (loc < range) {
        return &curr->val[curr->first + loc];
      }
      else {
        loc -= range;
        curr = curr->next;
      }
    }

    return NULL;
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