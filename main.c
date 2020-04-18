#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// data type for heap nodes
typedef struct HeapNode {
	int key; //key of this task
    struct HeapNode * parent;
    struct HeapNode * sibling;
    int degree;
    struct HeapNode * child;
} HeapNode;

//data type for a priority queue (heap)
typedef struct BinomialHeap{ //this is heap header
	int  size;      // count of items in the heap
	HeapNode * head;
} BinomialHeap;

// create a new heap node to store an item (task)
HeapNode *newHeapNode(int k, HeapNode * parent, HeapNode * sibling, int degree, HeapNode * child)
{
	HeapNode *new;
	new = malloc(sizeof(HeapNode));
	assert(new != NULL);
	new->key = k;
	new->parent = parent;
	new->sibling = sibling;
	new->degree = degree;
	new->child = child;
	return new;
}

// create a new empty heap-based priority queue
BinomialHeap *newHeap()
{ // this function creates an empty binomial heap-based priority queue
	BinomialHeap *T;
	T = malloc(sizeof(BinomialHeap));
	assert (T != NULL);
	T->head = NULL;
	return T;
}

BinomialHeap *createHeap(int f,int g,int h, int i, int j)
{ // this function creates a binomial heap-based priority queue
	BinomialHeap *heap = newHeap();
	HeapNode *a = newHeapNode (f, NULL,NULL,0, NULL);
	HeapNode *b = newHeapNode (g, NULL,NULL,0, NULL);
	HeapNode *c = newHeapNode (h, NULL,NULL,0, NULL);
	HeapNode *d = newHeapNode (i, NULL,NULL,0, NULL);
	HeapNode *e = newHeapNode (j, NULL,NULL,0, NULL);

	// did I allocate memory ? ASK WHY THIS DOES NOT WORK
	/*keys for all nodes
	a->key = f;
	b->key = g;
	c->key = h;
	d->key = i;
	e->key = j; */
	// for a
	a->parent = heap->head;
	heap->head = a;
	a->sibling = b;
	a->degree = 0;
	// for b
	b->parent = a;
	b->child = c;
	b->degree = 2;
	// for c
	c->parent = b;
	c->sibling = d;
	c->child = e;
	c->degree = 1;
	// for d
	d->parent = b;
	d->degree = 0;
	// for e
	e->parent = c;
	e->degree = 0;
	// return heap head
	return heap;
}

// merge 2 heaps
BinomialHeap *merge_heaps(BinomialHeap *H1, BinomialHeap *H2)
{	BinomialHeap *myheap = newHeap();
	HeapNode * cp1, *cp2 , *cp3;
	cp1 = H1->head;
	cp2 = H2->head;
	myheap->head = newHeapNode (0, NULL,NULL,0, NULL);
	cp3 = myheap->head;

	//myheap = null, and then myheap->head --> error
	// no need to compare size, run till one is null then appendix other
	while (cp2!=NULL && cp1 !=NULL) // we dont know which one is shorter
	{	// case 1
		if (cp1->degree < cp2->degree)  // unequal sign for this assignment
		// contents of the address that is pointing to cp3
		{	 cp3->key =  cp1->key; // points to the first address
			 cp1 = cp1->sibling;
		}
		// case 2 , cp2 is smaller
		else
		{    // duplicate cp1 content into cp3
			// * cp2
			 cp3->key = cp2->key;
			 cp2 = cp2->sibling;
		}
		//cp3 = cp3 ++; // already know memory or realloc
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;
	}



	while (cp1!= NULL)
	{
		cp3->key = cp1->key;
		cp1 = cp1->sibling;
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;
	}

	while (cp2!= NULL)
	{
		cp3->key = cp2->key;
		cp2 = cp2->sibling;
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;
	}


	return myheap;
}








int main() //sample main for testing
{
	BinomialHeap * heap, *heap2, *myheap;
	heap = createHeap(10,1,12,25,18);
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap->head->key, heap->head->sibling->key,
	heap->head->sibling->child->key, heap->head->sibling->child->sibling ->key,heap->head->sibling->child->child ->key);*/
	heap2 = createHeap(15,8,20,26,30);
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap2->head->key, heap2->head->sibling->key,
	heap2->head->sibling->child->key, heap2->head->sibling->child->sibling ->key,heap2->head->sibling->child->child ->key);*/
	myheap = merge_heaps(heap, heap2);



	return 0;
}
