#pragma once

class ServerService;

class Session : public enable_shared_from_this<Session>
{
public:

	Session();
	Session(tcp::socket &&connSock, int sessionId);
	~Session();

	void readFromClient();
	void writeToClient(SessionRef session,size_t length);

	ServerServiceRef _service = nullptr;
	ip::tcp::socket sock;
	int sessionId;
	char buf[256];
};

