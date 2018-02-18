#include<iostream>
using namespace std;
namespace nm4
{
	class Animal
	{
	public:
		/*Animal()
		{
		}*/
		void Breathe()
		{
		}
	};


	void main1()
	{
		Animal *anm = new Animal();
		/*
		push	1
		call	??2@YAPAXI@Z				; operator new
		add	esp, 4
		mov	DWORD PTR $T3[ebp], eax
		mov	DWORD PTR __$EHRec$[ebp+8], 0
		cmp	DWORD PTR $T3[ebp], 0
		je	SHORT $LN3@main
		mov	ecx, DWORD PTR $T3[ebp]
		call	??0Animal@@QAE@XZ			; Animal::Animal
		mov	DWORD PTR tv71[ebp], eax
		jmp	SHORT $LN4@main
		$LN3@main:
		mov	DWORD PTR tv71[ebp], 0
		$LN4@main:
		mov	eax, DWORD PTR tv71[ebp]
		mov	DWORD PTR $T2[ebp], eax
		mov	DWORD PTR __$EHRec$[ebp+8], -1
		mov	ecx, DWORD PTR $T2[ebp]
		mov	DWORD PTR _anm$[ebp], ecx
		*/
		/*
		mov	DWORD PTR $T1[ebp], 1
	mov	eax, DWORD PTR $T1[ebp]
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T2[ebp], eax
	cmp	DWORD PTR $T2[ebp], 0
	je	SHORT $LN3@main1
	mov	ecx, DWORD PTR $T1[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR $T2[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH
	mov	eax, DWORD PTR $T2[ebp]
	mov	DWORD PTR tv67[ebp], eax
	jmp	SHORT $LN4@main1
	$LN3@main1:
	mov	DWORD PTR tv67[ebp], 0
	$LN4@main1:
	mov	ecx, DWORD PTR tv67[ebp]
	mov	DWORD PTR _anm$[ebp], ecx
		*/

	}

	class CA
	{
	public:
		CA()
		{
			fun2();
		}
		virtual void fun1(){
			cout << "\t\t\tfun1 CA" << endl;
		}
		virtual void fun2(){
			cout << "\t\t\tfun2 CA" << endl;
		}
		void fun3(){
			//cout << "\t\t\tfun3 CA" << endl;
			fun2();
		}
	};
	class CB :public CA
	{
	public:
		CB()
		{
			fun2();
		}
		virtual void fun4(){
			cout << "\t\t\tfun4 CB" << endl;
		}
		virtual void fun2()
		{
			cout << "\t\t\tfun2 CB" << endl;
		}
	};
	void main2()
	{
		//typedef void(*FPTR)();
		using FPTR = void(*)();

		CA objCa;
		CB objCb;

		long *vp1 = (long*)&objCa;
		long *vt1 = (long*)*vp1;
		cout << "CA::vftable=" << vt1 << endl;
		((FPTR)vt1[0])();
		((FPTR)vt1[1])();
		//((FPTR)vt1[2])();
		long *vp2 = (long*)&objCb;
		long *vt2 = (long*)*vp2;
		cout << "CB::vftable=" << vt2 << endl;
		((FPTR)vt2[0])();
		((FPTR)vt2[1])();
		((FPTR)vt2[2])();
	}


	void main()
	{
		CB objCb;
		objCb.fun3();
		/*CA &objRefCa = objCb;//LSP
		objRefCa.fun2();//objRefCa.vptr->vtable[1]();
		objRefCa.CA::CA();
		objRefCa.fun2();//objRefCa.vptr->vtable[1]();
		*/
	}
}