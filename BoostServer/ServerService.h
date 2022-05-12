#pragma once


class ServerSevice :public enable_shared_from_this<ServerSevice>
{
public:
	ServerSevice();
	~ServerSevice();
	void processAccept(boost::system::error_code ec, tcp::socket& socket, tcp::acceptor& acptor);
	void StartAccept();

	int g_SessionId = 0;

	boost::asio::io_context io_context;
	ip::tcp::endpoint serverEp;
	ip::tcp::acceptor acceptor;
	set<SessionRef> _sessions;
	vector<thread> _threads;
};

