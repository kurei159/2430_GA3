#pragma once
/*Author: Cheuk-Wang Chau
Pig Latin class inherits from unorderedLinkedList to translate string to pig latin
*/
#include <string>
#include "unorderedLinkedList.h"
using namespace std;


class PigLatin : public unorderedLinkedList<char>
{
private:

	int length;
	char vowels[6] = { 'a','e','i','o','u','y' };
	char hyphen = '-';
	char ay[2] = { 'a','y' };
	char way[3] = {'w','a','y' };

public:
	//Constructor
	PigLatin();

	PigLatin(string word);
	
	//Destructor
	~PigLatin();

	//A function to break string into linked list
	void ToList(string word);

	//A function to check if first character is a vowel
	bool checkVowels();

	//function to manipulate linked list
	bool manipulateList();


};


PigLatin::PigLatin()
{
	initializeList();
}

PigLatin::~PigLatin()
{
	destroyList();
}

PigLatin::PigLatin(string word)
{
	initializeList();
	length = word.length();
	ToList(word);
	manipulateList();
}



void PigLatin::ToList(string word)
{
	for (int i = 0; i < length; i++)
	{
		insertLast(word[i]);
	}

}

bool PigLatin::checkVowels()
{
	if(!isEmptyList())
		for (int i = 0; i < 6; i++)
		{
			if (tolower(first->info) == vowels[i]) //Switch to lowercase then compare
			{
				return true;
			}
		}

	return false;
}

bool PigLatin::manipulateList()
{
	nodeType<char>* trailcurrent = new nodeType<char>; //trailcurrent
	nodeType<char>* current = new nodeType<char>; //current pointer
	nodeType<char>* temp = new nodeType<char>;
	current = first;
	
	trailcurrent = first;
	//Check
	if (checkVowels())
	{
		insertLast(hyphen);
		for (int i = 0; i < 3; i++)
		{
			insertLast(way[i]);
		}
		return true;
	}
	else if (!checkVowels())//If not vowel, rotate
	{
		insertLast(hyphen);
		while (!checkVowels())
		{
			temp = first;
			first = first->link;
			insertLast(temp->info);

			if (last->info == hyphen) //If
			{
				for (int i = 0; i < 2; i++)
				{
					insertLast(ay[i]);
				}
				return true;
			}
		}
		//If while loop is broken, then it is a vowel, so we check again and then insert -way at the end
		if (checkVowels())
		{
			for (int i = 0; i < 4; i++)
			{
				insertLast(way[i]);
			}
			return true;
		}
	}


	return false;
}
