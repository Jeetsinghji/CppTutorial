#include<iostream>
using namespace std;
namespace nm15
{
	class CA
	{
		static void* operator new(size_t size)
		{
			cout << "Custom new " << endl;
			return NULL;// malloc(size);
		}
			static void* operator new[](size_t size)
		{
			cout << "Custom new " << endl;
			return NULL;// malloc(size);
		}
			static void operator delete(void *p)
		{
			//do nothing
		}
		static void operator delete[](void *p)
		{
			//do nothing
		}
	public:

		CA()
		{
			cout << "CA Ctor" << endl;
		}
		void fun()
		{
			cout << "CA Fun Called " << endl;
		}
		~CA()
		{
		}
	};
	//CA obj;
	void main()
	{
		CA obj1;
		//CA *ptr = new CA();
		//CA *ptr = new CA[5];


		//delete &obj1;
	}
}