/*! \file */ 

/*
Simple C variable size vector, a simple variable size vector written in C
    Copyright (C) 2016-2017 Francisco Anderson Bezerra Rodrigues

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef VECTOR_H
#define VECTOR_H

/*!
	\brief The vector data structre.
	
	
*/
struct vector
{
	void *elements;					/**< Pointer to the elements. */
	unsigned long int elementSize;	/**< The size of one element of the vector. Informed in the vector creation. */
	int numberOfElements;			/**< Hold the information of how many elements are in use at the moment. */
	int capacity;					/**< Tells the actual reserved size of the vector. */
};
typedef struct vector Vector;

/*!
	\fn Vector* NewVector(unsigned long int elementSize)
	\param elementSize The size of one element of the vector.
	\return A new vector wich each element have size elementSize.
	\brief Create a new vector
	
	A new vector is created, the size of each element is elementSize.<br>
	If the Vector allocation fails, NULL is returned. <br>
	The best way is to use with sizeof, like: \code Vector *vec= NewVector( sizeof ( int ) ); \endcode
*/

Vector* NewVector(unsigned long int elementSize);

/*!
	\fn int VectorAppendCopy(Vector *vec, void* element)
	\param *vec A pointer to the vector.
	\param *element A pointer to the element wich value will be copied to the vector.
	\return Returns the the position of the value passed as argument, with the new element at the end of the vector.
	\brief Inserts a new element at the end of the vector.
	
	Inserts a new element at the end of the vector, expanding the vector size if necessary.<br>
	If the allocation fails, an error message is send to stderr and exit is called.<br>
	
	Example:
	\code int newElementPosition= VectorAppendCopy( vec, &value ); \endcode
	The example above inserts an element at the end of the vector and assigns to newElementPosition its position.
*/
int VectorAppendCopy(Vector *vec, void *element);

/*!
	\fn int VectorAllocateOne(Vector *vec)
	\param *vec A pointer to the vector.
	\return Returns the position in the vector allocated. May be used with VectorGetElement.
	\brief Allocates space for at least one more element.
	
	Allocate space in the vector for at least one more element, expanding the vector size if necessary. The allocated position is uninitialized.<br>
	If the allocation fails, an error message is send to stderr and exit is called.<br>
	Its return value may be used with VectorGetElement.<br>
	Example: \code 
			Vector *vec= new Vector(sizeof(int));
			*( (int*) VectorGetElement(vec, VectorAllocateOne(vec) ) = 2; 
		\endcode
	The example above assigns 2 to the first position of the vector. The vector holds elements of type "int".
*/
int VectorAllocateOne(Vector *vec);

/*!
	\fn void* VectorGetElement(Vector *vec, int position)
	\param *vec A pointer to the vector.
	\param position The wanted vector position
	\return Returns a pointer to the element of the vector at the position informed.
	\brief Gets the element at informed position.
	
	Its return value may be used with VectorGetElement.<br>
	Since the pointer to the position is returned, you may assign new values to the position using the returned pointer.<br>
	Example 1: \code 
			Vector *vec= new Vector(sizeof(int));
			*( (int*) VectorGetElement(vec, VectorAllocateOne(vec) ) = 2; 
		\endcode
	The example above assigns 2 to the first position of the vector. The vector holds elements of type "int".<br>
	To assign values you may deference the pointer and then assign. Or use memcpy, declared at string.h.
*/
void* VectorGetElement(Vector *vec, int position);

/*!
	\fn Vector* DeleteVector(Vector* vec)
	\param *vec A pointer to the vector.
	\return NULL is returned
	\brief Delete the vector and its elements.
	
	Deletes the vector and its elements, deallocating both.
	Example : \code 
			Vector *vec= new Vector(sizeof(int));
			DeleteVector(vec);
		\endcode
*/
Vector* DeleteVector(Vector* vec);
#endif
