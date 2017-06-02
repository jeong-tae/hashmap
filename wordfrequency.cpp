#include "wordfrequency.h"
#include <iostream>
#include <fstream>

/** 
 * Assignment 6 for CSE231 Data Structures
 *
 * 2014. 1. 16
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
	// ToDo
	ifstream fin(filename);
	string s;
	if ( fin.is_open() )
	{
		
		fin >> s;
		istringstream iss(s);
		do
		{
			string sub;
			iss >> sub;
			std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
		} while(iss);
		
	}
}

int WordFrequency::GetFrequency(const std::string word)
{
	// ToDo
	
	return 0;
}

void WordFrequency::IncreaseFrequency(const std::string word)
{
	// ToDo
}
