/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	node *var = new node;
	node *s = front;
	(*var).priority = priority;
	(*var).data = item;
	(*var).link = nullptr; 
	if(front == nullptr){
		front = var;
	}
	else if((*front).priority > priority) {
		(*var).link = front;
		front = var;
	}
	else {
		node *temp = s;
		while ((*temp).link != nullptr) {
			temp = (*temp).link;
		}
		while ((*s).link != nullptr && (*(*s).link).priority <= priority) {
			s = (*s).link;
		}
		(*var).link = (*s).link;
		(*s).link = var;        
	}

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if(front == nullptr){
		return nullptr;
	}
	return (*front).data;
	/* Your code here */
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	if(front == nullptr){
		return;
	}
	front = (*front).link;
	/* Your code here */
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	
	/* Use the following out command for the data */
	node *var = front;
	while(var != nullptr){
	std::cout<<var->priority<<" "<<(char*)var->data<<std::endl;
	var = (*var).link;

	}
}
	
