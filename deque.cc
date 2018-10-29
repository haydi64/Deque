/****************************************************
 * File Name: deque.cc
 * Author: Hayden Ivatts
 * Course: CSCI 132
 * Purpose: Implementation of deque class
 *****************************************************/

#include "deque.h"

Deque::Deque() {
    //Post: The Deque is initialized to be empty.
    count = 0;
    rear = maxqueue - 1;
    front = 0;
} //Default constructor

Error_code Deque::append_rear(const Queue_entry &item) 
/*
  Pre: The item being appended is a valid Queue_entry item and the deque has 
  been correctly initialized.
  Post: item is added to the rear of the Deque. If the Deque is full
  return an Error_code of overflow and leave the Deque unchanged.
*/
{
    Queue::append(item);
} //append rear

Error_code Deque::append_front(const Queue_entry &item)
/*
  Pre: The item being appended is a valid Queue_entry item and the deque has 
  been correctly initialized.
  Post: item is added to the front of the Deque. If the Deque is full
  return an Error_code of overflow and leave the Deque unchanged.
*/
{
    if(count >= maxqueue) {
        return overflow;
    }
    count++;
    if(front ==0) {
        front = maxqueue - 1;
    } else {
        front--;
    }
    entry[front] = item;
    return success;
} //append front

Error_code Deque::serve_front()
/*
  Pre: The deque has been initialized correctly.
  Post: The front of the Deque is removed. If the Deque
  is empty return an Error_code of underflow.
*/
{
    Queue::serve();
} //serve front

Error_code Deque::serve_rear()
/*
  Pre: The deque has been initialized correctly.
  Post: The rear of the Deque is removed. If the Deque
  is empty return an Error_code of underflow.
*/
{
    if(count <= 0) {
        return underflow;
    }
    count--;
    if(rear - 1 < 0) {
        rear = maxqueue - 1;
    } else {
        rear--;
    }
    return success;
} //serve rear

Error_code Deque::retrieve_front(Queue_entry &item) const
/*
  Pre: The output parameter item is a valid Queue_entry variable and the 
  deque has been correctly initialized.
  Post: The front of the Deque is retrieved to the output
  parameter item. If the Deque is empty return an Error_code of underflow.
*/
{
    Queue::retrieve(item);
} //retrieve front

Error_code Deque::retrieve_rear(Queue_entry &item) const
/*
  Pre: The output parameter item is a valid Queue_entry variable and the 
  deque has been correctly initialized.
  Post: The rear of the Deque is retrieved to the output
  parameter item. If the Deque is empty return an Error_code of underflow.
*/
{
    if(count <= 0) {
        return underflow;
    }
    item = entry[rear];
    return success;
} //retrieve rear


    
