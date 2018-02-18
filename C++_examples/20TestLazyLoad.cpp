#include<iostream>
using namespace std;

namespace nm20
{
	class SmartArray
	{
		int ar[3];
	public:
		SmartArray() 	{
			ar[0] = 10;
			ar[1] = 20;
			ar[2] = 30;
		}
		class Helper
		{
			SmartArray *smptr;
			int index;
		public:
			Helper(SmartArray *smptr, int index) :smptr(smptr), index(index)
			{
			}
			operator int()
			{
				cout << "reading" << endl;
				return smptr->ar[index];
			}
			Helper & operator=(int val)
			{
				cout << "writing" << endl;
				smptr->ar[index] = val;
				return *this;
			}
			Helper & operator=(Helper hlp)
			{
				cout << "reading/writing" << endl;
				smptr->ar[index] = hlp.smptr->ar[hlp.index];
				return *this;
			}
		};
		Helper operator[](int index)
		{
			return Helper(this, index);
		}
		friend ostream & operator<<(ostream & os, SmartArray & smt)
		{
			for (size_t i = 0; i < 3; i++)
			{
				os << "arr[" << i << "]=" << smt.ar[i] << endl;
			}
			return os;
		}
	};

	void main1()
	{
		SmartArray arr;
		int x = arr[1];//reading
		arr[0] = 999;//writing
		arr[2] = arr[1];//read/write

		cout << arr << endl;
	}

	//TDD // DBC

}