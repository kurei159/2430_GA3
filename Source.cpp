/*
Authors: 
Cheuk-Wang Chau 33.3%
Nilanjan Chowdhury 33.3%
Ritika Malhotra 33.3%
GA3: Translate a string from user input to pig latin

*/

#include <iostream>
#include <string>
#include "PigLatin.h"
using namespace std;


int main()
{
	string word;
	cout << "Please input string:\n";
	cin >> word;
	PigLatin text(word);
	text.print();
	system("pause");
}
