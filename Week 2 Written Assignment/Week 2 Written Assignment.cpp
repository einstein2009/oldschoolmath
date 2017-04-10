// Week 2 Written Assignment.cpp : Defines the entry point for the console application.


/*A singly-linked list can be used to store large integers one digit at a time. For example, the integer 1234 could be stored in a list by storing 1 in the first node,
2 in the second node, 3 in the third node, and 4 in the last node. However, for this assignment you may find it more useful to store the digits backwards;
that is, store 4 in the first node, 3 in the second node, 2 in the third node, and 1 in the last node.

Write a program that reads two positive integers that are of arbitrary length and then outputs the sum of the two numbers.
Your program will read the digits as values of type char so that the number 1234 is read as the four characters '1', '2', '3', and '4'.
As the characters are read they are changed to values of type int and stored in a list. (Now you can see the first reason why storing the digits “backwards” has an advantage.)
After the first number has been read your program reads the second number, storing it in a second list.

Your program will perform the addition by implementing the usual paper-and-pencil addition algorithm. 
(Now you should discover the second reason why storing the digits “backwards” is advantageous.)
The result of the addition is stored in a list and the result is then written to the screen. 
Include a loop that allows the user to continue to do more additions until the user says the program should end.

Of course, your multiple precision addition code should be formulated as a function that accepts a pair of lists, returning a list as its result (the sum of the two inputs).

You might want to base your List class on a simplification of the Node class described in our textbook.*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Linked list node
struct node{

	int data;
	struct node* next;
};

// Function to create a new node with given data
struct node *newNode(int data){

	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// Function to insert a node at the beginning of the List
void push(struct node** head_ref, int new_data){

	struct node* new_node = newNode(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Adds contents of two linked lists and return the head node of current list 
struct node* addTwoLists(struct node* first, struct node* second)
{
	struct node* curr = NULL;
	struct node *temp, *prev = NULL;
	int carry = 0, sum;

	while (first != NULL || second != NULL)
	{
		// Calculate value of next digit in current list.
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = newNode(sum);

		if (curr== NULL)
			curr = temp;
		else
			prev->next = temp;

		prev = temp;

		// Move first and second pointers to next nodes
		if (first) 
			first = first->next;
		if (second) 
			second = second->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);

	return curr;
}

void printList(struct node *node)
{
	while (node != NULL)
	{
		cout << node->data;
		node = node->next;
	}
	cout << endl;
}

int count(int num) {

	int c = 0;
	while (num != 0) {
		c++;
		num /= 10;
	}
	return c;
}


int main()
{
	struct node* curr = NULL;
	struct node* first = NULL;
	struct node* second = NULL;
	char charIn = '0';
	int intIn = 0;
	int length = 0;
	int counter = 0;

	// create first list
	cout << "Enter the first number you would like to add: ";
	do
	{
		cin >> charIn;
		intIn = charIn - 48;
		length = count(intIn);
		cout << "intIn: " << intIn << endl << "charIn: " << charIn << endl << "counter: " << counter << endl;
		push(&first, intIn);
		counter++;
	} while (counter < length + 1); {

		cout << "First List is ";
		printList(first);


		// create second list
		do {
			push(&second, 4);
			push(&second, 8);
		} while (false);
		cout << "Second List is ";
		printList(second);

		// Add the two lists and see result
		curr = addTwoLists(first, second);
		cout << "Current list is ";
		printList(curr);

		system("PAUSE");

		return 0;
	}
}