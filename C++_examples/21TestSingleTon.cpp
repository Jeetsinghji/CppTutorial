#include<iostream>
using namespace std;
namespace nm21
{
	class CA
	{
		CA()
		{
			cout << "CA Ctor this=" << this << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
		static CA *head;
		static CA * CreateCA()
		{
			if (head == NULL)
				head = new CA();
			return head;
		}
		static void ReleaseCA()
		{
			delete head;
			head = NULL;
		}
	public:
		void fun()
		{
			cout << "fun called ..." << endl;
		}
		friend class SmartCA;
	};
	CA * CA::head = NULL;

	class SmartCA
	{
		CA *ptr;
		static int count;
	public:
		SmartCA() :ptr(CA::CreateCA())
		{
			count++;
		}
		SmartCA(const SmartCA&) = delete;
		SmartCA& operator=(SmartCA &) = delete;
		CA* operator->()
		{
			return ptr;
		}

		~SmartCA()
		{
			if (--count == 0)
				CA::ReleaseCA();
		}
	};
	int SmartCA::count = 0;

	void DoBusiness()
	{
		SmartCA smt;
		smt->fun();
		SmartCA smt1;
		SmartCA smt2;
	}
	void main()
	{
		DoBusiness();
		SmartCA smt;
		smt->fun();
		SmartCA smt1;
		SmartCA smt2;
	}
}