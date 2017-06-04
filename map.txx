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
		while(elem != NULL)
		{
			HashMapElemType* tmp = elem;
			elem = elem->link;
			free(tmp);
		}
	}
	free(ht);
}
	
template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	// ToDo
	// find (k, v) by k where (k, v) is HashMapElemType
	unsigned int hashvalue = hashfunction(k);
	HashMapElemType* elem = ht[hashvalue]; // init

	while(elem != NULL)
	{
		// until exact key
		if( elem->key != k)
		{
			elem = elem->link;
		}
		else
		{
			break;
		}
	}

	return elem;
}
	
template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	// ToDo
	unsigned int hashvalue = hashfunction(k);
	HashMapElemType* newelem = new HashMapElemType; // correct grammar???
	newelem->key = k;
	newelem->val = v;
	newelem->link = NULL;
	if (ht[hashvalue] != NULL)
	{
		if(ht[hashvalue]->key == k)
		{ // overwrite
			newelem->link = ht[hashvalue]->link;
			ht[hashvalue] = newelem;	
		}
		else
		{ // chaining
			HashMapElemType* elem = ht[hashvalue];
 			while(elem->link != NULL)
			{
				if( elem->key == k )
				{
					elem->val = v;
					//ht[hashvalue] = elem;
					// change only value
					break;
				}
				elem = elem->link;
			}
			// after repeatition, elem become last node
			if( elem-> key == k )
			{ // Do Nothing
			}
			else
			{ // connect new element to last node where node have same hashvalue
				elem->link = newelem;
				mapsize += 1;
			}
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
	if(ht[hashvalue] == NULL) { return false; }

	// find exact matching and need to control linked list for consistency
	HashMapElemType* target = ht[hashvalue];
	HashMapElemType* prev;
	while(target->key != k)
	{
		prev = target;
		target = target->link;
	}
	prev->link = target->link;
	free(target);
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
	HashMapElemType* listed[mapsize];
	int pt = 0;
	// hashmap to list so that can sort
	for(int i = 0; i < capacity; i++)
	{
		HashMapElemType* elem = ht[i];
		while(elem != NULL)
		{
			listed[pt] = elem;
			pt++;
			elem = elem->link;
		}
	}

	// listed to be sorted
	for(int i = 0; i < mapsize-1; i++)
	{
		for(int j = i+1; j < mapsize; j++)
		{
			if( listed[i]->val < listed[j]->val )
			{
				HashMapElemType* tmp = listed[i];
				listed[i] = listed[j];
				listed[j] = tmp;
			}
		}
	}
	// print out
	for(int i = 0; i < mapsize; i++)
	{
		std::cout << listed[i]->key << ":" << listed[i]->val << std::endl;	
	}
}




