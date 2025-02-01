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
void ULListStr::push_back(const std::string& val)
{
  if(empty())
  {
    head_ = tail_ = new Item();
    head_->next = nullptr;
    head_->prev = nullptr;
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
    size_++;
    return;
  }

  if(tail_->last == ARRSIZE)
  {
    Item* newTail = new Item();
    tail_->next = newTail;
    newTail->next = nullptr;
    newTail->prev = tail_;
    newTail->val[0] = val;
    newTail->first = 0;
    newTail->last = 1;
    size_++;
    tail_ = newTail;

    return;
  }

  if(tail_->last < ARRSIZE)
  {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;

    return;
  }

}

void ULListStr::push_front(const std::string& val)
{
  if(empty())
  {
    head_ = tail_ = new Item;
    head_->next = nullptr;
    head_->prev = nullptr;
    head_->val[ARRSIZE-1] = val;
    size_++;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;

    return;
  }

  if(head_->first == 0)
  {
    Item* newHead = new Item;
    head_->prev = newHead;
    newHead->val[ARRSIZE-1] = val;
    newHead->next = head_;
    newHead->prev = nullptr;
    newHead->first = ARRSIZE-1;
    newHead->last = ARRSIZE;
    size_++;
    head_ = newHead;

    return;
  }

  if(head_->first > 0)
  {
    head_->val[head_->first - 1] = val;
    head_->first = head_->first - 1;
    size_++;
    
    return;
  }

}


void ULListStr::pop_back()
{
  if(empty())
  {
    return;
  }

  if(tail_->last == 1)
  {
    Item* newTail = tail_->prev;
    if(newTail == nullptr)
    {
      delete tail_;
      head_ = tail_ = nullptr;
      size_ = 0;

      return;
    }
    newTail->next = nullptr;
    
    delete tail_;
    tail_ = newTail;
    size_--;

    return;
  }

  if(tail_->last > 1)
  {
    tail_->last = tail_->last - 1;
    size_--;

    return;
  }
}



void ULListStr::pop_front()
{  
  head_->first += 1;  
  if(head_->first == head_->last)  
  {    
    Item* temp = head_;

    head_ = head_->next;   

    if(head_ != nullptr)    
    {      
      head_->prev = nullptr;    
    }    
    else    
    {      
      tail_ = nullptr;   
    }   
    delete temp;  
  }  
  size_--;
}

std::string const & ULListStr::back() const
{

  return tail_->val[tail_->last-1];
}


std::string const & ULListStr::front() const
{

  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_)
  {
    return nullptr;
  }

  size_t numNode = (loc + head_->first) / ARRSIZE;
  size_t index = (loc + head_->first) % ARRSIZE;
  Item* curr = head_;

  for (size_t i = 0; i < numNode; i++) 
  {
    curr = curr->next;
  }

  
  return &curr->val[index];
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
