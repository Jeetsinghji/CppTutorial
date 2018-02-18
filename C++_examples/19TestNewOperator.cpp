#include<iostream>
using namespace std;

namespace nm19
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor this=" << this << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	};
	void main1()
	{
		try
		{
			CA *ptr = new CA();
			/*
			CA *temp=(push	1
			call	??2@YAPAXI@Z				; operator new
			add	esp, 4)
			try
			{
			temp->CA::CA();
			}
			catch(...)
			{
			free(temp);
			throw;
			}
			ptr=temp;
			*/

			delete ptr;
			//Do Business
		}
		catch (bad_alloc & exp)
		{
			cout << exp.what() << endl;
		}



	}

	void main2()
	{

		CA *ptr = new(nothrow)CA();

		if (ptr != NULL)
			delete ptr;

	}

	void main3()
	{
		/*int *i = new int(10);
		cout << "i=" << *i << endl;
		CA *ptr = new(i+1)CA();

		ptr->CA::~CA();//explicit
		delete i;*/

		char *buffer = new char[255];
		CA *ptr1 = new(buffer)CA();
		CA *ptr2 = new(buffer + 4)CA();
		CA *ptr3 = new(buffer + 8)CA();
		ptr1->CA::~CA();
		ptr2->CA::~CA();
		ptr3->CA::~CA();

		delete[] buffer;
	}
}