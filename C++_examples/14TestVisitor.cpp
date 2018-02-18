#include<iostream>
using namespace std;
namespace nm14
{
	class Bank;
	class SBAccount;
	class CurrentAccount;
	class DMat;

	class IUI
	{
	public:
		virtual void ShowUI(Bank*) = 0;
		virtual void ShowUI(SBAccount*) = 0;
		virtual void ShowUI(CurrentAccount*) = 0;
		virtual void ShowUI(DMat*) = 0;
	};
	class Bank
	{
	protected:
		Bank()
		{
		}
		static IUI *ui;
	public:
		static void SetUI(IUI *iui)
		{
			ui = iui;
		}
	};
	IUI * Bank::ui;

	class SBAccount :public Bank
	{
	public:
		void SbAccountJob()
		{
			cout << "SB Account JobStarted " << endl;
			ui->ShowUI(this);  //show UI
			cout << "SB Account Completed " << endl;
			cout << "_________________________" << endl;
		}
	};

	class CurrentAccount :public Bank
	{
	public:
		void CurrentAccountJob()
		{
			cout << "Current Account JobStarted " << endl;
			ui->ShowUI(this); //show UI
			cout << "Current Account Completed " << endl;
			cout << "_________________________" << endl;
		}
	};

	class DMat :public Bank
	{
	public:
		void CurrentAccountJob()
		{
			cout << "DMat Account JobStarted " << endl;
			ui->ShowUI(this); //show UI
			cout << "DMat Account Completed " << endl;
			cout << "_________________________" << endl;
		}
	};


	//---------------
	class Christmas :public IUI
	{
	public:
		virtual void ShowUI(Bank*)
		{
			cout << "Christmas Show UI General Bank" << endl;
		}
		virtual void ShowUI(SBAccount*)
		{
			cout << "Christmas Show UI SBAccount " << endl;
		}
		virtual void ShowUI(CurrentAccount*)
		{
			cout << "Christmas Show UI CurrentAccount" << endl;
		}
		virtual void ShowUI(DMat*)
		{
			cout << "Christmas Show UI DMat" << endl;
		}
	};

	class Deewali :public IUI
	{
	public:
		virtual void ShowUI(Bank*)
		{
			cout << "Deewali Show UI General Bank" << endl;
		}
		virtual void ShowUI(SBAccount*)
		{
			cout << "Deewali Show UI SBAccount " << endl;
		}
		virtual void ShowUI(CurrentAccount*)
		{
			cout << "Deewali Show UI CurrentAccount" << endl;
		}
		virtual void ShowUI(DMat*)
		{
			cout << "Deewali Show UI DMat" << endl;
		}
	};
	IUI* CreatorUI()
	{
		return new Deewali();
	}

	void main()
	{
		Bank::SetUI(CreatorUI());
		SBAccount sbAcct;
		CurrentAccount currAcct;
		DMat dmat;

		sbAcct.SbAccountJob();
		currAcct.CurrentAccountJob();
		dmat.CurrentAccountJob();
	}
}