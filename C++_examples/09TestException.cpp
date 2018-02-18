#include<iostream>
using namespace std;
//never throw exception from dtor
namespace nm9
{
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
			throw 450;
		}

	};

	void main()
	{
		try{
			try
			{
				CA obj;
				throw 100;
			}
			catch (int exp)
			{
				cout << "int exp outer =" << exp << endl;
			}
		}
		catch (CA obj)
		{
			cout << "CA exp inner " << endl;
		}
		catch (int exp)
		{
			cout << "int exp inner =" << exp << endl;
		}
	}
}