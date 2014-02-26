#include "TEditorServer.h"

#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Thread.h>
#include <Poco/Net/Net.h>

using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnection;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServerConnectionFactoryImpl;
using Poco::Net::TCPServerParams;
using Poco::Net::StreamSocket;
using Poco::Net::ServerSocket;
using Poco::Net::SocketAddress;
using Poco::Thread;

#define BUFFERSIZE 2048

class TEditorServer
{
public:
	TEditorServer();
	~TEditorServer();
	void Initialize();
	void Release();
	int SendBytes(const void* buffer,int size);
	int ReceiveBytes(void* buffer,int size);
private:
	ServerSocket* m_ServerSocket;
	StreamSocket* m_ClientSocket;
	TCPServer*    m_Server;
	Poco::UInt16  m_ServerPort;
};

class TConnection: public TCPServerConnection
{
public:
	TConnection(const StreamSocket& s): TCPServerConnection(s){}
	
	void run(){
		StreamSocket& ssocket = socket();
		try{
			int size;
			char Buffer[BUFFERSIZE];
			while(true){
				size = ssocket.receiveBytes(Buffer, sizeof(Buffer));
				if(size>0){
					ssocket.sendBytes(Buffer,size);
				}else{
					break;
				}
			}
		}
		catch (Poco::Exception& exc){
			std::cerr<<exc.displayText()<< std::endl;
		}
	}
};

TEditorServer::TEditorServer():
	m_ServerSocket(0),
	m_ClientSocket(0),
	m_Server(0),
	m_ServerPort(0)
{
	this->Initialize();
}

TEditorServer::~TEditorServer(){
	this->Release();
}

void TEditorServer::Initialize()
{
	m_ServerSocket = new ServerSocket(0);
	m_Server = new TCPServer(new TCPServerConnectionFactoryImpl<TConnection>(),*m_ServerSocket);
	m_Server->start();
	m_ServerPort = m_ServerSocket->address().port();
	SocketAddress addr("localhost", m_ServerPort);
	m_ClientSocket = new StreamSocket(addr);
}

void TEditorServer::Release()
{
	if(m_ClientSocket!=0){
		delete m_ClientSocket;
	}
	if(m_ServerSocket!=0){
		delete m_ServerSocket;
	}
	if(m_Server!=0){
		delete m_Server;
	}
}

int TEditorServer::SendBytes(const void* buffer,int size)
{
	return m_ClientSocket->sendBytes(buffer, size);
}

int TEditorServer::ReceiveBytes(void* buffer,int size)
{
	return m_ClientSocket->receiveBytes(buffer,size);
}

static TEditorServer* GlobalEditorServer = 0;

EDITORNETAPI int SendEditorCommand(void* buffer,int size)
{
	if(GlobalEditorServer==0){
		GlobalEditorServer = new TEditorServer;
	}
	return GlobalEditorServer->SendBytes(buffer,size);
}

EDITORNETAPI int ReceiveEditorCommand(void* buffer,int size)
{
	if(GlobalEditorServer==0){
		GlobalEditorServer = new TEditorServer;
	}
	return GlobalEditorServer->ReceiveBytes(buffer,size);
}

