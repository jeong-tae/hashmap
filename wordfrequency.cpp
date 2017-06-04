#include "wordfrequency.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

/** 
 * ***************************
 *
 * ****. **. **
 *
 */

WordFrequency::WordFrequency()
{
	// ToDo
}

WordFrequency::~WordFrequency()
{
	// ToDo
}

void WordFrequency::ReadText(const char* filename)
{
	std::ifstream fin(filename);
	std::string s;
	if ( fin.is_open() )
	{
		while(std::getline(fin, s))
		{
			std::istringstream iss(s);
			do
			{
				std::string word;
				iss >> word;
				std::transform(word.begin(), word.end(), word.begin(), ::tolower);
				IncreaseFrequency(word);
			} while(iss);
		}
	}
}

int WordFrequency::GetFrequency(const std::string word)
{
	WordFreqElem* elem = map.find(word);
	if( elem != NULL )
	{
		return elem->val;
	}	
	return 0;
}

void WordFrequency::IncreaseFrequency(const std::string word)
{
	WordFreqElem* elem = map.find(word);
        if( elem != NULL )
        {
		int val = elem->val + 1;
		map.insert(word, val);
	}
	else
	{
		map.insert(word, 1);
	}
}
