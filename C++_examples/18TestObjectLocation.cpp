#include<iostream>
using namespace std;
namespace nm18
{
	class CA
	{
		bool isOnHeap;
		static bool flag;
		static int gCount;
	public:
		CA() :isOnHeap(flag)
		{
			if (--gCount == 0)
			{
				flag = false;
			}
			cout << "Ctor called " << endl;
		}
		void Location()
		{
			if (isOnHeap == true)
			{
				cout << "Object is on heap" << endl;
			}
			else
			{
				cout << "Object is (Not) on heap" << endl;
			}
		}
		static void * operator new (size_t size)
		{
			gCount = 1;
			flag = true;
			cout << "Custom new called " << endl;
			return malloc(size);;
		}
			static void * operator new[](size_t size)
		{
			gCount = size / sizeof(CA);
			flag = true;
			cout << "Custom new called " << endl;
			return malloc(size);;
		}
			~CA()
		{
		}
	};
	bool CA::flag = false;
	int CA::gCount = 0;

	void main()
	{
		CA obj;
		CA *ptr = new CA();

		obj.Location();
		ptr->Location();

		CA *ptr1 = new CA[5];
		cout << "______________________" << endl;
		for (size_t i = 0; i < 5; i++)
		{
			(ptr1 + i)->Location();
		}
		CA *ptr2 = new CA();
		ptr2->Location();
		CA obj2;
		obj2.Location();
	}
}