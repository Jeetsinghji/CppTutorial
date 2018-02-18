#include<iostream>
using namespace std;
namespace nm10
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor" << endl;
			//throw 450;
		}
		~CA()
		{
			cout << "CA Dtor " << endl;
		}
	};

	void main()
	{
		CA *ptr = NULL;
		try
		{
			ptr = new CA();
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
		}
		catch (int x)
		{
			cout << "int exp=" << x << endl;
		}

		if (ptr == NULL)
		{
			cout << "Apple" << endl;
		}
		else
		{
			cout << "Orange" << endl;
			delete ptr;
		}
	}
}