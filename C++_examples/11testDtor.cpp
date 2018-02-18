#include<iostream>
using namespace std;

class CA
{
public:
	CA()
	{
		cout << "CA Ctor" << endl;
	}
	~CA()
	{
		cout << "CA Dtor " << endl;
		delete this;
		/*
		ptr->CA::~CA();
		operator delete(this)
		{
		free(pt);
		}
		*/
	}
};
void main()
{
	CA obj1;

	CA & ob = obj1;
	delete ob;

	CA *ptr = new CA();

	delete ptr;
	/*
	ptr->CA::~CA();
	operator delete(pt)
	{
	  free(pt);
	}
	*/
}