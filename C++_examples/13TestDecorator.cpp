#include<iostream>
using namespace std;
namespace nm13
{
	struct ILogger
	{
		virtual void LogMessage(char *msg) = 0;
	};
	struct NullLogger :ILogger
	{
		NullLogger()
		{

		}
		void LogMessage(char *msg)
		{
			//Do Nothing
		}
	};
	class Helper :public ILogger
	{
		ILogger *il;
	protected:
		Helper(ILogger *il) :il(il)
		{
		}
		void LogMessage(char *msg)
		{
			il->LogMessage(msg);
		}
	};
	struct ConsoleLogger :Helper
	{
		ConsoleLogger(ILogger *il) :Helper(il)
		{

		}
		void LogMessage(char *msg)
		{
			cout << "Console Logger Logged(" << msg << ")" << endl;
			Helper::LogMessage(msg);
		}
	};

	struct FileLogger :Helper
	{
		FileLogger(ILogger *il) :Helper(il)
		{

		}
		void LogMessage(char *msg)
		{
			cout << "File Logger Logged(" << msg << ")" << endl;
			Helper::LogMessage(msg);
		}
	};

	struct ServiceLogger :Helper
	{
		ServiceLogger(ILogger *il) :Helper(il)
		{

		}
		void LogMessage(char *msg)
		{
			cout << "Service Logger Logged(" << msg << ")" << endl;
			Helper::LogMessage(msg);
		}
	};
	struct EtwLogger :Helper
	{
		EtwLogger(ILogger *il) :Helper(il)
		{

		}
		void LogMessage(char *msg)
		{
			cout << "Etw Logger Logged(" << msg << ")" << endl;
			Helper::LogMessage(msg);
		}
	};
	//creator or Factory
	ILogger * CreateLoggers()
	{
		//Reflection
		return new ServiceLogger(new FileLogger(new ConsoleLogger(new EtwLogger(new NullLogger()))));
	}

	//--------------------
	void main()
	{
		ILogger *il = CreateLoggers();
		cout << "Business Started ..." << endl;
		il->LogMessage("India is great...");
		cout << "Business Completed ..." << endl;
		il->LogMessage("India wins WI...");
	}
}