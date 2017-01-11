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

struct vector
{
	void *elements;
	unsigned long int elementSize;
	int numberOfElements;
	int capacity;
};
typedef struct vector Vector;

Vector* NewVector(unsigned long int elementSize);
int VectorAppendCopy(Vector *vec, void* element);
int VectorAllocateOne(Vector *vec);
void* VectorGetElement(Vector *vec, int position);
Vector* DeleteVector(Vector* vec);
#endif
