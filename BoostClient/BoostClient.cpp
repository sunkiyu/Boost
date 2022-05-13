// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <thread>
#include <vector>
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace boost::asio;
char recvBuf[256] = { 0, };
void RegisterRecv(ip::tcp::socket& client_sock);

void ProcessRecv(ip::tcp::socket& client_sock)
{
	RegisterRecv(client_sock);
}
void RegisterRecv(ip::tcp::socket& client_sock)
{
	client_sock.async_read_some(buffer(recvBuf, 255), [&](boost::system::error_code ec, size_t length)
	{
		if (ec)
		{
			cout << "DisConnectd Client " << endl;
			//_sessions.erase(session);
		}
		else
		{
			recvBuf[length] = 0;
			cout << recvBuf << endl;
			ProcessRecv(client_sock);
		}
	});
}

void RegisterSend(ip::tcp::socket& client_sock, string sendBuf)
{
	client_sock.async_write_some(buffer(sendBuf.c_str(), sendBuf.length()), [&](boost::system::error_code ec, size_t length)
	{
		if (ec)
		{
			cout << "DisConnectd Client "<< endl;
		}
		else
		{

		}
	});
}


vector<thread> _threads;

int main()
{
	this_thread::sleep_for(1s);
	boost::asio::io_context io_context;
	ip::tcp::endpoint server_addr(ip::address::from_string("127.0.0.1"), 53005);
	ip::tcp::socket client_sock(io_context);
	boost::asio::connect(client_sock, &server_addr);

	RegisterRecv(client_sock);

	for (int i = 0; i < 2; i++)
	{
		_threads.push_back(thread([&]()
		{
			while (1)
			{
				io_context.run();
			}
		}));
	}

	while (1)
	{
		string buf;
		boost::system::error_code err;
		getline(std::cin, buf);
		if (!buf.size())break;
		RegisterSend(client_sock,buf);
	}

	for (thread& thread : _threads)
	{
		thread.join();
	}

	return 0;
}

