#pragma once
#include <string>
#include "doublyLinkedList.h"
using namespace std;


class PigLatin : public doublyLinkedList<char>
{
private:
	doublyLinkedList<char> List;
	int length;


public:
	//Constructor
	PigLatin();

	PigLatin(string word);
	
	//Destructor
	~PigLatin();

	//A function to break string into linked list
	void ToList(string word);

	//A function to check vowels
	bool checkVowels();

	//function to manipulate linked list
	void manipulateList();


};

PigLatin::PigLatin()
{
	List.initializeList();
}

PigLatin::~PigLatin()
{
	List.destroy();
}



void PigLatin::ToList(string word)
{
	for (int i = 0; i < length; i++)
	{
		List.insert(word[i]);
	}

	
}

bool PigLatin::checkVowels()
{
	nodeType<char>* current = new nodeType<char>; //current pointer
	current = first;

	char vowels[6] = {'a','e','i','o','u'};
	while (!List.isEmptyList())
	{
		for (int i = 0; i < 6; i++)
		{
			if (tolower(current->info) == vowels[i])
			{
				return true;
			}
		}
	}


	return false;
}
