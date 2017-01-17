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
	
	A new vector is created, the size of each element is elementSize.
	The best way is to use with sizeof, like \code Vector *vec= NewVector( sizeof ( int ) ); \endcode
*/

Vector* NewVector(unsigned long int elementSize);

int VectorAppendCopy(Vector *vec, void* element);

int VectorAllocateOne(Vector *vec);
void* VectorGetElement(Vector *vec, int position);
Vector* DeleteVector(Vector* vec);
#endif
