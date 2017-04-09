// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <tchar.h>

class List {
public:
	List();
	bool isEmpty();
	void addNode(char val);
	void printValue();
private:
	typedef struct node{
		int data;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
};


// TODO: reference additional headers your program requires here
