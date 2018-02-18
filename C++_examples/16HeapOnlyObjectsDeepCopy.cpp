#include<iostream>
using namespace std;
namespace nm16
{
	class CA
	{
		int *i;
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
		CA() :i(new int(10))
		{
			cout << "CA Ctor" << endl;
		}
		CA(const CA& par) :i(new int(*par.i))
		{
			cout << "CA Copy" << endl;
		}
		CA & operator=(const CA & par)
		{
			*i = *par.i;
			return *this;
		}
	public:
		void fun()
		{
			cout << "CA Fun Called " << endl;
		}
		friend class Wrapper;
	};

	class Wrapper //Amar jeeth naik
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
		CA *ptr;
	public:
		Wrapper()
		{
			ptr = new CA();
		}
		Wrapper(const Wrapper & par) :ptr(new CA(*par.ptr))
		{
			cout << "Wrapper Copy ..." << endl;
			//ptr = par.ptr;
		}
		Wrapper & operator=(Wrapper & par)
		{
			cout << "Wrapper Assign ..." << endl;
			*ptr = *par.ptr;
			return *this;
		}
		CA* operator->()
		{
			return ptr;
		}
		~Wrapper()
		{
			delete ptr;
		}
	};
	void main()
	{
		//Wrapper wrap;
		//wrap.operator->()->fun();
		//wrap->fun();

		Wrapper wrap;
		Wrapper wrap1 = wrap;
		Wrapper wrap2(wrap);
		wrap = wrap1;
	}
}