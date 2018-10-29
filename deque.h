/****************************************************
 * File Name: deque.h
 * Author: Hayden Ivatts
 * Course: CSCI 132
 * Date: 10-15-18
 * HW 3
 * Professor Kadady MWF 1 to 1:50
 * Purpose: Specification of Deque class
 *****************************************************/

#include "queue.h"

class Deque : private Queue  {
 public:
    Deque();
    Error_code append_front(const Queue_entry &item);
    Error_code append_rear(const Queue_entry &item);
    Error_code serve_front();
    Error_code serve_rear();
    Error_code retrieve_front(Queue_entry &item) const;
    Error_code retrieve_rear(Queue_entry &item) const;
};

    
