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
	T->size = 0;
	return T;
}

HeapNode *copy_tree(HeapNode *copy, HeapNode *original)
{
	copy->key = original->key;
	copy->degree = original->degree;
	copy->child = original->child;
	return copy;
}


	
int size_of_heap(HeapNode * node)
{	
	int size = 0; // can be initialised to any value so if you want 0, place it to zero
	
	if (node != NULL)
	{	if (node->key != 0)
		{
			size++;
		}
		else return size;
	
	}
	else 
	{
		return size;
	}
	//printf (" PRE he current node and size is %d %d \n", node->key, size);
    size =  size + size_of_heap(node->child) + size_of_heap(node->sibling);
   // printf (" Post he current node and size is %d %d \n \n", node->key, size);
	return size;
}
	
	
	







BinomialHeap *createHeap(int f,int g,int h, int i, int j)
{ // this function creates a binomial heap-based priority queue
	BinomialHeap *heap = newHeap();
	HeapNode *a = newHeapNode (f, NULL,NULL,0, NULL);
	HeapNode *b = newHeapNode (g, NULL,NULL,0, NULL);
	HeapNode *c = newHeapNode (h, NULL,NULL,0, NULL);
	HeapNode *d = newHeapNode (i, NULL,NULL,0, NULL);
	HeapNode *e = newHeapNode (j, NULL,NULL,0, NULL);
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
	HeapNode * cp1, *cp2 , *cp3, *temp_pointer;
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
		{	 cp3 = copy_tree(cp3, cp1);
			 cp1 = cp1->sibling;
		}
		// case 2 , cp2 is smaller
		else
		{    // duplicate cp1 content into cp3
			// * cp2
			 cp3 = copy_tree(cp3,cp2);
			 cp2 = cp2->sibling;
		}
		//cp3 = cp3 ++; // already know memory or realloction
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;

	}
	while (cp1!= NULL)
	{
		cp3 = copy_tree(cp3,cp1);
		cp1 = cp1->sibling;
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;
		
	}

	while (cp2!= NULL)
	{
		cp3 = copy_tree(cp3,cp2);
		cp2 = cp2->sibling;
		cp3->sibling =  newHeapNode (0, NULL,NULL,0, NULL);
		cp3 = cp3->sibling;
	}
	
	free(temp_pointer);
	return myheap;
}



// Ask about complete trees ?
// Link two trees of same degree
HeapNode *link_heap_node(*HeapNode y, *HeapNode z)
{	
	if (y->key < z->key)
	{
		y->parent = z;
		y->sibling = z->child;
		z->child = y;
		z->degree ++;
		return z;
		
	}
	
	else 
	{   
		z->parent = y;
		z->sibling = y->child;
		y->child = z;
		y->degree ++;
		return y;
	}
	
}




BinomialHeap *union_heap(*BinomialHeap H1, *BinomialHeap H2)
{
	HeapNode *newHeap = newHeap();
	newHeap = merge_heaps(H1, H2);
	HeapNode *prev_x;
    HeapNode *next_x;
    HeapNode *x, *temp_p  *temp_p2  ;
    // case when merged heap is empty
    if (newHeap->Head == NULL)
    {
    	return newHeap;
    }
    x = newHeap->head;
    next_x = x->sibling;
    prev_x = NULL;   // initially the first root
    //  Binomial Heap has at most one root of given degree, if there are 2 roots then they would form a new Tree with degree + 1
    // hence the merge will have at most 2 trees of same degree
    // If same degree then they are adjacent, ask why, I think because all in increasing order, hence if same then next to each other
	
	while (next_x != NULL) 
	{
		// case 2
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)
                && (next_x->sibling)->degree == x->degree) && (x->degree == next_x->degree)) 
        {
            prev_x = x;
            x = next_x;
        } 
        else if (x->degree == next_x->degree) // ASK
        {	// case 3
        		temp_p2 = prev_x;
                temp_p = next_x->sibling;
                
                x = link_heap_node(next_x, x);
                x->sibling = temp_p;
         
            	if (temp_p2 == NULL)
        		 {
            		x->prev_x = temp_p2;
            		newHeap->head = x;
    			 }
            
            	else if (temp_p2 != NULL)
            	{
            		x->prev_x = temp_p2;
            	}
 
         }
        
        next_x = x->sibling;
    }
    return newHeap;
}
	
// Ask why only key taken	
BinomialHeap *insert_node(BinomialHeap *H, HeapNode *x)
{
   BinomialHeap *newHeap = newHeap();
   int key = x->key
   HeapNode *new_node = newHeapNode (key, NULL,NULL,0, NULL);
   newHeap->head = new_node;
   H = union_heap(H,H1);
   return H;
}	
	
	

















int main() //sample main for testing
{
	BinomialHeap * heap, *heap2, *combheap;
	heap = createHeap(10,1,12,25,18);
	heap->size = 5;
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap->head->key, heap->head->sibling->key,
	heap->head->sibling->child->key, heap->head->sibling->child->sibling ->key,heap->head->sibling->child->child ->key);*/
	heap2 = createHeap(15,8,20,26,30);
	heap2->size = 5;
	/*printf("first is %d, second is %d third is %d fourth is %d fifth is %d \n", heap2->head->key, heap2->head->sibling->key,
	heap2->head->sibling->child->key, heap2->head->sibling->child->sibling ->key,heap2->head->sibling->child->child ->key);*/
	combheap = merge_heaps(heap, heap2); // works
	combheap->size = 10;
	printf("size is %d \n", size_of_heap(combheap->head));

	free(heap);
	free (heap2);
    free (combheap);
	return 0;
}
