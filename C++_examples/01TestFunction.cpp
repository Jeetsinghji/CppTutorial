namespace nm1
{
	extern "C" void  fun() //_fun
	{
	}
	extern "C++" void  fun1()//?fun1@@YAXXZ	
	{
	}
	void  fun2()//?fun2@@YAXXZ
	{
	}
	void  fun2(int y)//?fun2@@YAXH@Z
	{
	}
	void main1()
	{
		fun();//call	_fun
		fun1();//call	?fun1@@YAXXZ
		fun2();//call	?fun2@@YAXXZ
		fun2(10);
		/*
		push	10					; 0000000aH
		call	?fun2@@YAXH@Z				; fun2
		add	esp, 4
		*/
	}


	void fun3(int x, int y)
	{
	}//ret	0

	void __cdecl fun4(int x, int y)
	{
	}//ret	0

	void __stdcall fun5(int x, int y)
	{
	}//ret	8

	void __fastcall fun6(int x, int y)
	{
	}//	ret	0

	class CA
	{
	public:
		void __thiscall fun7()//CA::fun7
		{
		}
	};

	void main()
	{
		fun3(10, 20);
		/*
		push	20					; 00000014H
		push	10					; 0000000aH
		call	?fun3@@YAXHH@Z				; fun3
		add	esp, 8
		*/
		fun3(11, 22);
		/*
		push	22					; 00000016H
		push	11					; 0000000bH
		call	?fun3@@YAXHH@Z				; fun3
		*/
		fun4(1, 2);
		/*
		push	2
		push	1
		call	?fun4@@YAXHH@Z				; fun4
		add	esp, 8
		*/

		fun6(1, 2);
		/*
		mov	edx, 2
		mov	ecx, 1
		call	?fun6@@YIXHH@Z				; fun6
		*/
		CA obj1;
		obj1.fun7();
		/*
		lea	ecx, DWORD PTR _obj1$[ebp]
		call	?fun7@CA@@QAEXXZ			; CA::fun7
		*/
	}
}