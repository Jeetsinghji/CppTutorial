#include<iostream>
using namespace std;
namespace nm7
{
	class IDB
	{
	public:
		virtual void ConnectDb() = 0;
		virtual void DbPooling() = 0;
	};
	class ISocket
	{
	public:
		virtual void SocketEstablish() = 0;
		virtual void ListPort() = 0;
	};

	//-------------------
	class Communication :public IDB, public ISocket
	{
	public:
		virtual void ConnectDb()
		{
			cout << "Connect Db" << endl;
		}
		virtual void DbPooling()
		{
			cout << "Db Pooling" << endl;
			SocketEstablish();
		}
		virtual void SocketEstablish()
		{
			cout << "Socket Establish" << endl;
		}
		virtual void ListPort()
		{
			cout << "List Port" << endl;
		}
	};




	void main()
	{
		Communication cmm;
		cout << sizeof(cmm) << endl;
		ISocket *skt = &cmm;
		skt->SocketEstablish();//skt->vptr->vtable[0]();
		skt->ListPort();//skt->vptr->vtable[1]();
		cout << "______________________" << endl;
		//IDB *db =(IDB*) skt;
		//IDB *db = (Communication*)skt;
		//IDB *db = (IDB*)(Communication*)skt;
		IDB *db = dynamic_cast<IDB*>(skt);
		db->ConnectDb();//db->vptr->vtable[0]();
		db->DbPooling();//db->vptr->vtable[1]();
	}
}