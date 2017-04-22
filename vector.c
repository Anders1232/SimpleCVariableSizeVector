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
#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Vector* NewVector(unsigned long int elementSize)
{
	Vector *ret= malloc(sizeof(Vector));
	if(NULL == ret)
	{
		fprintf(stderr, "[ERROR] Allocation Error at %s|%s:%d\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	ret->elementSize= elementSize;
	ret->numberOfElements=0;
	ret->capacity= 0;
	ret->elements= NULL;
	return ret;
}

static void Resize(Vector * vec)
{
	vec->capacity= 2 * (vec->capacity) + 1;
	vec->elements= realloc(vec->elements, (vec->capacity) * (vec->elementSize));
	if(NULL == vec-> elements)
	{
		fprintf(stderr, "[ERROR] Memory reallocation error at %s|%s:%d\n", __FILE__, __func__, __LINE__);
		exit(1);
	}
}

int VectorAllocateOne(Vector *vec)
{
	if(vec->numberOfElements == vec->capacity)
	{
		Resize(vec);
	}
	(vec->numberOfElements)++;
	return (vec->numberOfElements)-1;
}

int VectorAppendCopy(Vector *vec, void* element)
{
	VectorAllocateOne(vec);
	char* newElementArea= ( ( char*) vec->elements) + (vec->elementSize)*( (vec->numberOfElements)-1);
	memcpy(newElementArea, element, vec->elementSize);
	return (vec->numberOfElements)-1;
}

void* VectorGetElement(Vector *vec, int position)
{
/*	while(position > capacity)
	{
		Resize(vec);
	}
*/
	if( (vec->numberOfElements) <= position)
	{
		fprintf(stderr, "[ERROR] Bad element access at %s|%s:%d\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	return ((char*)vec->elements)+ ( position*(vec->elementSize) );
}

Vector* DeleteVector(Vector* vec)
{
	free(vec->elements);
	free(vec);
	return NULL;
}
