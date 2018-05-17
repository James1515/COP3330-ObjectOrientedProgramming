//----------------------------------------
// Author: James Anthony Ortiz
// File: cstringsort.h
// Purpose: Header (.h) file for project 1.
//----------------------------------------
#ifndef _CSTRINGSORT_H
#define _CSTRINGSORT_H
int  LexDiff 		  (const char* s1, const char* s2);
int  DictionaryDiff       (const char* s1, const char* s2);
bool LexComp              (const char* s1, const char* s2);
bool DictionaryComp       (const char* s1, const char* s2);
void LexStringSort        (char* *beg, char* *end);    
void DictionaryStringSort (char* *beg, char* *end);    
#endif
