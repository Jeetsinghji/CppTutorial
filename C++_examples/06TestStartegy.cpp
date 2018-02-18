#include<iostream>
using namespace std;
namespace nm6
{
	class ISort
	{
	public:
		virtual void DoSort() = 0;
	};

	class CArray
	{
		ISort *srt;
	public:
		CArray(ISort *srt) :srt(srt)
		{

		}
		void Insert(int val, int index)
		{
			cout << "Insert worked " << endl;
		}
		void Sort()
		{
			srt->DoSort();
		}
		void Erase(int index)
		{
			cout << "Erase worked " << endl;
		}

	};
	//----------------------------------------

	class BubbleSort :public ISort
	{
	public:
		void DoSort()
		{
			cout << "Buble Sort worked " << endl;
		}
	};


	class LinearSort :public ISort
	{
	public:
		void DoSort()
		{
			cout << "Linear Sort worked " << endl;
		}
	};
	void main()
	{
		LinearSort bbl;
		CArray arr(&bbl);
		arr.Insert(1, 2);
		arr.Erase(4);
		arr.Sort();
	}
}