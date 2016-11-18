#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Vector* NewVector(unsigned long int elementSize)
{
	Vector *ret= malloc(sizeof(Vector));
	if(NULL == ret)
	{
		fprintf(stderr, "[ERROR] Allocation Error\n");
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
		fprintf(stderr, "[ERROR] Memory reallocation error\n");
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
		fprintf(stderr, "[ERROR] Bad element access\n");
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
