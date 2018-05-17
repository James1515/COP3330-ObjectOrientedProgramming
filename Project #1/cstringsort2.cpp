#include "cstringsort.h"
#include <cstdlib>

// Program: cstringsort.cpp
// Descritption: Program implementations for main.cpp.
//
//

char convertLower(char in) {
	
	if(in<='Z' && in>='A')
    	return in-('A'-'a');

	return in;
}

//Function LexDiff
//Returns "0" if strings are identical 
//A negative value if s1, comes before s2 in lex order
//A positive value if s1 come after s2 in lex order
int LexDiff (const char* s1, const char* s2) {
	
	/*Check the sizes of the c-strings
	For the first string:*/

	unsigned int length1 = 0;
	/*For the second string:*/
	unsigned int length2 = 0;

	while (*(s1 + length1)){
		length1++;
	}

	while (*(s2 + length2)) {
		length2++;
	}

	unsigned int length = 0;
	if(length1 < length2)
		length = length1;
	else
		length = length2;
	
	unsigned int i=0;
	for(i=0; i<length; i++)
	{
		if(s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}

	if (length1 < length2)
		return -1;
	else if (length1 > length2)
		return 1;
	else
		return 0;

}

//Function DictionaryDiff:
//Return type: int
//Returns 0 if strings are the same (ignoring case)
//Returns -1 if s1 comes before s2 in dictionary order
//Returns 1 if s1 comes after s2 in dictionary order
int DictionaryDiff(const char* s1, const char* s2)
 {

	unsigned int length1 = 0;
	/*For the second string:*/
	unsigned int length2 = 0;

	while (*(s1 + length1)){
		length1++;
	}

	while (*(s2 + length2)) {
		length2++;
	}

	unsigned int length = 0;
	if(length1 < length2)
		length = length1;
	else
		length = length2;
	
	unsigned int i=0;
	for(i=0; i<length; i++)
	{
		if(convertLower(s1[i]) < convertLower(s2[i]) )
			return -1;
		else if (convertLower(s1[i]) > convertLower(s2[i]) )
			return 1;
	}

	if (length1 < length2)
		return -1;
	else if (length1 > length2)
		return 1;
	else
		return 0;


}

//Function LexComp
//Returns a boolean value 
//
//Returns true if the s1 is before s2 in lex order otherwise false
//calls LexDiff, 
bool LexComp(const char* s1, const char* s2)
{
	//If LexDiff < 0 return true,
	//otherwise return false.
	if (LexDiff(s1, s2) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Function DictionaryComp
//Returns a boolean value
//
//Returns true if the s1 is before s2 in dcitionary order otherwise false
//calls LexDiff, 
bool DictionaryComp(const char* s1, const char* s2)
{
	//If DictionaryDiff < 0 return true,
	//otherwise return false.
	if (DictionaryDiff(s1, s2) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void IntegerInsertionSort (int* beg, int* end)
{
	size_t size = end - beg;
	if (size < 2) return;
	size_t i; // outer loop control
	size_t j; // inner loop control
	size_t k; // k is always j - 1
	int    t; // value holder
	for (i = 0; i < size; ++i)
	{
		t = beg[i];
		for (k = i, j = k--; j > 0 && t < beg[k]; --j, --k)
			beg[j] = beg[k];
		
		beg[j] = t;
	}
}


//Function LexStringSort
//Returns a void value
//Uses inertion sort and the function
//LexComp to determine how to sort.
void LexStringSort (char* *beg, char* *end)
{
	size_t size = end - beg;
	if (size < 2) return;
	size_t i; // outer loop control
	size_t j; // inner loop control
	size_t k; // k is always j - 1
	char *t; // value holder
	for (i = 0; i < size; ++i)
	{
		t = beg[i];
		for (k = i, j = k--; j > 0 && LexComp(t, beg[k]); --j, --k)
			beg[j] = beg[k];
					
		beg[j] = t;
	}
}

//Fucntion DictionaryStringSort
//Returns a void value
//Uses inertion sort and the function
//DictionaryComp to determine how to sort.

void DictionaryStringSort (char* *beg, char* *end)
{
	size_t size = end - beg;
	if (size < 2) return;
	size_t i; // outer loop control
	size_t j; // inner loop control
	size_t k; // k is always j - 1
	char *t; // value holder
	for (i = 0; i < size; ++i)
	{
		t = beg[i];
		for (k = i, j = k--; j > 0 && DictionaryComp(t, beg[k]); --j, --k)
			beg[j] = beg[k];
					
		beg[j] = t;
	}
}
