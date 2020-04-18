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
BinomialHeap *merge_heaps(BinomialHeap H1, inomialHeap H2)
{
	





	
}




// put the time complexity analysis for Insert() here    
void Insert(BinomialHeap *T, int k)
{ 
}

// put your time complexity for RemoveMin() here
HeapNode *RemoveMin(BinomialHeap *T)
{
 // put your code here
}

int Min(BinomialHeap *T)
{
  // put your code here
}




int main() //sample main for testing 
{
	BinomialHeap * heap, *heap2;
	heap = createHeap(10,1,12,25,18);
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap->head->key, heap->head->sibling->key,  
	heap->head->sibling->child->key, heap->head->sibling->child->sibling ->key,heap->head->sibling->child->child ->key);*/
	heap2 = createHeap(15,8,20,26,30);
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap2->head->key, heap2->head->sibling->key,  
	heap2->head->sibling->child->key, heap2->head->sibling->child->sibling ->key,heap2->head->sibling->child->child ->key);*/
	
	
	
	
	return 0; 
}
