//#include<iostream>
//using namespace std;
namespace nm3
{
	class Animal
	{
	public:
		Animal()
		{
		}
		void Breathe()
		{
		}
	};
	class Cat :public Animal
	{
	public:
		Cat()
		{//	call	??0Animal@@QAE@XZ			; Animal::Animal

		}
		void Climb()
		{
		}
	};



	class Leg
	{
	public:
		Leg()
		{
		}
	};

	class Human
	{
		Leg legs;
	public:
		/*Human()
		{//call	??0Leg@@QAE@XZ				; Leg::Leg

		}*/
	};

	class Tiger :public Animal
	{
		Leg legs;
	public:
		Tiger()
		{
			//	call	??0Animal@@QAE@XZ			; Animal::Animal
			//  mov	DWORD PTR [eax], OFFSET ??_7Tiger@@6B@
			//  call	??0Leg@@QAE@XZ				; Leg::Leg
		}
		virtual void Run()
		{
		}
	};
	void main1()
	{
		//	Animal anm;
		//anm.Breathe();
		//Cat cat;
		/*
		lea	ecx, DWORD PTR _cat$[ebp]
		call	??0Cat@@QAE@XZ				; Cat::Cat
		*/
		//cat.Climb();
		/*Tiger tig;
		tig.Breathe();
		tig.Run();*/
		//Human hum;
		/*
			lea	ecx, DWORD PTR _hum$[ebp]
			call	??0Human@@QAE@XZ			; Human::Human
			*/
		Tiger tig;
		/*
		lea	ecx, DWORD PTR _tig$[ebp]
		call	??0Tiger@@QAE@XZ			; Tiger::Tiger
		*/
	}

	class CA
	{
	public:
		CA()
		{//mov	DWORD PTR [eax], OFFSET ??_7CA@@6B@

		}
		virtual void fun3(){

		}
	};
	void main()
	{
		//CA obj;
		/*
			lea	ecx, DWORD PTR _obj$[ebp]
			call	??0CA@@QAE@XZ				; CA::CA
			*/
		Tiger tig;
		/*
		lea	ecx, DWORD PTR _tig$[ebp]
		call	??0Tiger@@QAE@XZ			; Tiger::Tiger
		*/
	}
}