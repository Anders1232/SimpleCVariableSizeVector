#ifndef VECTOR_H
#define VECTOR_H

struct vector
{
	void *elements;
	int elementSize;
	int numberOfElements;
	int capacity;
};
typedef struct vector Vector;

Vector* NewVector(int elementSize);
int VectorAppendCopy(Vector *vec, void* element);
int VectorAllocateOne(Vector *vec);
void* VectorGetElement(Vector *vec, int position);
Vector* DeleteVector(Vector* vec);
#endif
