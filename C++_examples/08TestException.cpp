#include<iostream>
using namespace std;
namespace nm8
{
	void fun(int par)
	{
		cout << "Ooty Apple" << endl;
		if (10 == par)
			throw 100;
	}
	class CA
	{
		static int count;
		int val;
	public:
		CA()
		{
			count++;
			val = count;
			cout << "CA Ctor" << endl;
		}
		CA(CA & par)
		{
			count++;
			val = count;
			cout << "CA Copy" << endl;
		}
		~CA()
		{
			cout << "CA Dtor val=" << val << endl;
		}

	};
	int CA::count = 0;


	void main1()
	{

		cout << "Simla Apple" << endl;

		try
		{
			CA obj;
			//fun(10);
			throw obj;
			cout << "Coorg Apple" << endl;
		}
		catch (int exp)
		{
			cout << "int exp =" << exp << endl;
		}
		catch (CA ob)
		{
			cout << "CA exp " << endl;
		}
		cout << "Kashmir Apple" << endl;
	}



void main()
	{
		try
		{
			try
			{
				//if
				throw 100;
			}
			catch (int exp)
			{
				exp += 99;
				cout << "int  exp outer=" << exp << endl;
				//	throw 300;
				throw;
			}
			catch (...)//catch any/All
			{
				cout << "General exp outer" << endl;
			}
		}
		catch (int exp)
		{
			cout << "int  exp inner=" << exp << endl;
		}
		catch (...)//catch any/All
		{
			cout << "General exp inner" << endl;
		}
		cout << "apple" << endl;
	}
}
