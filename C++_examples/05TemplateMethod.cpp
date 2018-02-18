#include<iostream>
using namespace std;

namespace nm5
{
	class Bank
	{

		int custId;
	protected:
		virtual void DoActualJob() = 0;
	public:

		void DoJob()
		{
			cout << "Open DB " << endl;
			DoActualJob();
			cout << "Close DB " << endl;
			cout << "_____________________________________" << endl;
		}

	};
	class SbAccount :public Bank
	{
		int sbId;
	protected:
		void DoActualJob()
		{
			cout << "Sb Account Job is on ..." << endl;
		}
	public:


	};
	class CurrentAccount :public Bank
	{
		int CurrID;
	protected:
		void DoActualJob()
		{
			cout << "Current Account Job is on ..." << endl;
		}
	public:


	};

	void main()
	{
		SbAccount sb;
		sb.DoJob();
		CurrentAccount curr;
		curr.DoJob();
	}
}