#include<iostream>
#include<map>
using namespace std;

namespace nm17
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
	//
	//class Wrapper //Jose
	//{
	//	CA *ptr;
	//	int *count;
	//public:
	//	Wrapper() :ptr(new CA()), count(new int(1))
	//	{
	//
	//	}
	//	Wrapper(const Wrapper & par) :ptr(par.ptr), count(par.count)
	//	{
	//		(*count)++;
	//	}
	//	Wrapper & operator=(Wrapper & par)
	//	{
	//		if (ptr != par.ptr)
	//		{
	//			this->Wrapper::~Wrapper();
	//			this->Wrapper::Wrapper(par);
	//
	//		}
	//		return *this;
	//	}
	//	CA* operator->()
	//	{
	//		return ptr;
	//	}
	//	~Wrapper()
	//	{
	//		(*count)--;
	//		if ((*count) == 0)
	//		{
	//			delete ptr;
	//			delete count;
	//		}
	//	}
	//};



	class Wrapper
	{
		CA *ptr;
		static map<CA*, int> MyMap;
	public:
		Wrapper() :ptr(new CA())
		{
			MyMap[ptr] = 1;
		}
		Wrapper(const Wrapper & par) :ptr(par.ptr)
		{
			MyMap[ptr]++;
		}
		Wrapper & operator=(Wrapper & par)
		{
			if (ptr != par.ptr)
			{
				this->Wrapper::~Wrapper();
				this->Wrapper::Wrapper(par);

			}
			return *this;
		}
		CA* operator->()
		{
			return ptr;
		}
		~Wrapper()
		{
			MyMap[ptr]--;
			if (MyMap[ptr] == 0)
			{
				delete ptr;
				MyMap.erase(ptr);
			}

		}
	};
	map<CA*, int> Wrapper::MyMap;

	void main()
	{
		//Wrapper wrap;
		//wrap.operator->()->fun();
		//wrap->fun();

		Wrapper wrap;
		Wrapper wrap1 = wrap;
		Wrapper wrap2(wrap);

		Wrapper wrap3;
		Wrapper wrap4;
		wrap = wrap1;
		cout << "_________________" << endl;
	}
}