
#include "wordfrequency.h"
 
using namespace std;

int main()
{
	WordFrequency freqChecker;
	
	freqChecker.ReadText("steve_jobs.txt");//"cat_in_the_hat.txt");
	/*
	cout << "# of occurence of word 'hello' : " << freqChecker.GetFrequency("hello") << endl;
	cout << "# of occurence of word 'hi' : " << freqChecker.GetFrequency("hi") << endl;
	cout << "# of occurence of word 'hey' : " << freqChecker.GetFrequency("hey") << endl;
	*/
	
	cout << "# of occurence of word 'you' : " << freqChecker.GetFrequency("you") << endl;
	
	cout << "Print all result" << endl;
	freqChecker.PrintAllFrequency();
	return 0;
}
