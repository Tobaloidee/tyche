/*
* GNU General Public License Version 3.0, 29 June 2007
* Header file of list.
* Copyright (C) 2018  David Petrosyan
* Email: david.petrosyan11100@gmail.com
* For full notice please see https://github.com/amirkhaniansev/tyche/tree/master/LICENSE.
*/


//#include "../include/queue.h"
#include "queue.h"

/**
* queue_create - creates queue
*
* @data_size - data size
* @is_primitive_type - boolean value indicating whether
*			queue holds data of primitive type.
*		Primitive types are considered:
*			int
*			short int
*			double
*			float
*			char
*			unsigned char
*			long
*			unsigned int
etc.
* @comparator - pointer to function which will be used to compare data.
* @assigner - pointer to function which will be used to assign data.
* @finalizer - pointer to function which will be used to finalize object.
* @copy_func - pointer to function which will be used to copy data.
*
* Must be called with valid arguments, otherwise the result will be NULL.
*/
queue * queue_create(int* error_code, unsigned int data_size, bool is_primitive_type, int(*comparator)(const void *, const void *), int(*assigner)(void *, void *), int(*finalizer)(void *), void *(copy_func)(void *))
{
	list* list_ = list_create(error_code, data_size, is_primitive_type, &comparator, &assigner, &finalizer, &copy_func);

	return list_;
}

/**
* queue_front - gets the first element of queue
* @queue - queue
* May be called with non-null argument.
*/
void * queue_front(queue * queue)
{
	return list_front(queue);
}

/**
* queue_back - gets the last element of queue
* @queue - queue
* May be called with non-null argument
*/
void * queue_back(queue * queue)
{
	return list_back(queue);
}

/**
* queue_push - pushes element to queue
*
* @queue - queue
* @data - data that will be pushed to queue
*
* Errors
* QUEUE_IS_NULL				 		(0x121)					if queue is NULL
* QUEUE_NODE_ALLOCATION_ERROR			(0x123)					if queue's node allocation cannot be realized
* INVALID_DATA							(0x125)					if data is NULL
*
*/
int queue_push(queue * queue, void * data)
{
	return list_push_back(queue, data);
}

/**
* queue_pop - pops element from the queue
*
* @queue - queue
* @data - data that will be popped.
*
* Errors
* QUEUE_IS_NULL				 		(0x121)				if queue is NULL
* QUEUE_IS_EMPTY						(0x122)				if queue is empty
*
*/
int queue_pop(queue * queue)
{
	return list_pop_front(queue);
}

/**
* queue_is_empty - checks if the given queue is empty
* @queue - queue
*/
bool queue_is_empty(queue * queue)
{
	return list_is_empty(queue);
}

/**
* destroy_queue - destroys queue
* @queue - queue
*/
int queue_destroy(queue * queue)
{
	return list_destroy(queue);
}
