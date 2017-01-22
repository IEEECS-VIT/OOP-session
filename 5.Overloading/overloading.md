## Overloading

- Overloading is the reuse of the same function name or symbol for two or more distinct functions or operations.
- There are 2 types of Overloading in C++ :
	1. Function Overloading -> A function can be declared more than once with different operations
#	### Example of Function Overloading
	```
	#include<iostream>
	void test (int x, int y);
	void test (char ch);
	int main()
	{
	int n1 = 10;
	int n2 = 30;
	char ch = ‘*’;
	Test (n1,n2);
	Test (ch);
	return (0);
	}
	void test (int x, int y)
	{
		cout<<x+y;
	}
	void test (char ch)
	{
		cout<<ch;
	}
	```
### Note - Function that contains the same name and parameters cannot be overloaded.

