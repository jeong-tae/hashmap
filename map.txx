// Constructor
template <class HashMapElemType>
HashMap<HashMapElemType>::HashMap(unsigned int c) 
{
	// ToDo
	mapsize = 0;
	capacity = c;
	divisor = c - (1-c%2); // biggest odd number smaller than c
	ht = new HashMapElemType* [capacity];
	for(int i=0; i<capacity; i++) ht[i] = NULL;
}


// destructor
template <class HashMapElemType>
HashMap<HashMapElemType>::~HashMap() 
{
	// ToDo: Destructor
	// iteratively remove the alloacted memory
	for(int i = 0; i < capacity; i++)
	{
		HashMapElemType* elem = ht[i];
		HashMapElemType* tmp;
		while(elem->link != NULL)
		{
			tmp = elem;
			elem = elem->link;
			free(tmp)
		}
		free(elem)
	}
	free(ht)
}
	
template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	// ToDo
	// find (k, v) by k where (k, v) is HashMapElemType
	unsigned int hashvalue = hashfunction(k);
	HashMapElemType* elem = ht[hashvalue]; // init

	while(elem->key != k)
	{
		// until exact key
		elem = elem->link;
	}

	// exception handler, the case where hashvalue is in ht but no exact value.
	if(elem-> key != k)
	{
		elem = NULL;
	}

	return elem;
}
	
template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	// ToDo
	unsinged int hashvalue = hashfunction(k);
	HashMapElemType* newelem = new HashMapElemType(k, v); // correct grammar???
	if (ht[hashvalue] != NULL)
	{
		if(ht[hashvalue]->key == k)
		{ // overwrite
			ht[hashvalue] = newelem;	
		}
		else
		{ // chaining
			elem = ht[hashvalue]
			while(elem->link != NULL)
			{
				elem = elem->link
			}
			// after repeatition, elem become last node
			elem->link = newElem;
			// connect new element to last node where node have same hashvalue
			mapsize += 1;
		}
	}
	else
	{
		ht[hashvalue] = newelem;
		mapsize += 1;
	}
}
		
template <class HashMapElemType>
bool 
HashMap<HashMapElemType>::remove(const KeyType k) 
{
	// ToDo	
	unsigned int hashvalue = hashfunction(k);
	if(ht[hashvalue] == NULL) { return false }

	// find exact matching and need to control linked list for consistency
	HashMapElemType* target = ht[hashvale]
	HashMapElemType* prev;
	while(target->key != k)
	{
		prev = target;
		target = target->link;
	}
	prev->link = target->link;
	free(target)	
	mapsize -= 1;

	return true;
}
	
template <class HashMapElemType>
unsigned int 
HashMap<HashMapElemType>::hashfunction(const KeyType k)
{
	// ToDo
	unsigned int hashkey = 0;
	int i = 0;
	for(i = 0; k[i] != '\0'; ++i)
	{
		hashkey += (unsigned int)k[i];
	}
	hashkey = hashkey % divisor;
	return hashkey;
}

template <class HashMapElemType>
void 
HashMap<HashMapElemType>::print()
{
	// ToDo: Print all Key:value pair in decreasing order of value
	
	// get all elements
	HashMapElemType* listed = new HashMapElemType[mapsize];
	int pt = 0;
	for(int i = 0; i < capacity; i++)
	{
		HashMapElemType* elem = ht[i];
		while(elem != NULL)
		{
			listed[pt] = elem;
			pt++;
			elem->link = elem; // does not change the previous one? not sure
		}
	}

	// listed to be sorted
	

	// print out
}




