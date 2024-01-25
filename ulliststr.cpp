#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  numOfNodes = 0;
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


void ULListStr::push_back(const std::string& val){
  if (tail_){
  
    // check if last item is full
    if(tail_->last == ARRSIZE){
      Item* newItem = new Item();
      numOfNodes++;
      tail_-> next = newItem;
      newItem->prev = tail_;
      tail_ = newItem;
      size_t last_ = newItem->last;

      newItem->val[last_] = val;
      newItem->last++;
      size_++;
    } else {
      size_t last_ = tail_->last;
      tail_->val[last_] = val;
      tail_->last++;
      size_++;
    }
    
  } else {
    head_ = new Item();
    numOfNodes++;
    tail_ = head_;
    head_->val[head_->last] = val;
    head_->last++;
    size_++;
  }
}

void ULListStr::pop_back(){
  if(tail_){
    (tail_->last)--;
    if(tail_->last < tail_->first){
      Item* temp = tail_;
      tail_ = tail_->prev;
      if(tail_){
      tail_->next = nullptr;
      }
      delete temp;
      numOfNodes--;

    }
    size_--;
  }
  
}

void ULListStr::push_front(const std::string& val){
  if (head_){
    if (head_->first == 0){
      Item* newItem = new Item();
      numOfNodes++;
      newItem->first = ARRSIZE - 1;
      newItem->last = ARRSIZE;

      newItem->val[ARRSIZE - 1] = val;
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;

      size_++;
    } else {
      head_->val[--(head_->first)] = val;
      size_++;
    }
  } else {
    head_ = new Item();
    tail_ = head_;
    numOfNodes++;
    head_->val[head_->last] = val;
    head_->last++;
    size_++;
  }
}

void ULListStr::pop_front(){
  if(head_){
    head_->first++;
    size_--;
    if (head_->first == head_->last){
      Item* temp = head_;
      if(head_ == tail_){
        tail_ = nullptr;
      }
      head_ = head_->next;
      delete temp;
      numOfNodes--;
    }
  }
}


// to Do
std::string const & ULListStr::back() const {
  if(tail_){
    return tail_->val[tail_->last - 1];
  } 

// to check
  // std::string test = "test";
  return tail_->val[tail_->last - 1];

}

std::string const & ULListStr::front() const {
  if(head_){
    return head_->val[head_->first];
  }
    return head_->val[head_->first];

}

// WRITE YOUR CODE HERE

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

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc < size_){
    int c = ((loc + head_->first) / 10);
    Item* currN = head_;
    for (int i = 0; i < c; i++){
      currN = currN->next;
    }

    return &(currN->val[(loc + head_->first) % 10]);
  } else {
    // std::cout << "EROROROROEROREOREORO" << std::endl;
    return &(head_->val[0]);
  }
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
