#include<iostream>
using namespace std;
namespace nm2
{
	class CA
	{
	public:
		virtual void fun1(){
			cout << "fun1 CA" << endl;
		}
		virtual void fun2(){
			cout << "fun2 CA" << endl;
		}
		void fun3(){
			cout << "fun3 CA" << endl;
		}
	};

	void main1()
	{
		CA obj;
		//((void(*)())*(long*)*(long*)&obj)();
		long *vp = (long*)&obj;//reach the vptr
		long* vt = (long*)*vp;//reach the vtable
		typedef void(*FPTR)();
		FPTR fp = (FPTR)vt[0];//reach the function
		fp();//call back
		((FPTR)vt[1])();
	}

	void main2()
	{
		CA obj;
		CA &objRef = obj;
		CA *objPtr = &obj;

		obj.fun3();
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?fun3@CA@@QAEXXZ			; CA::fun3
		*/
		objRef.fun3();
		/*
		mov	ecx, DWORD PTR _objRef$[ebp]
		call	?fun3@CA@@QAEXXZ			; CA::fun3
		*/
		objPtr->fun3();
		/*
		mov	ecx, DWORD PTR _objPtr$[ebp]
		call	?fun3@CA@@QAEXXZ			; CA::fun3
		*/
		obj.fun2();
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?fun2@CA@@UAEXXZ			; CA::fun2
		*/
		objRef.fun2();//objref.vptr->vtable[1]()
		/*
		mov	eax, DWORD PTR _objRef$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objRef$[ebp]
		mov	eax, DWORD PTR [edx+4]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp
		*/
		objPtr->fun2();//objPtr->vptr->vtable[1]()
		/*
		mov	eax, DWORD PTR _objPtr$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objPtr$[ebp]
		mov	eax, DWORD PTR [edx+4]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp
		*/
	}

}