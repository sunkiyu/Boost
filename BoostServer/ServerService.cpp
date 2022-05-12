#include "pch.h"
#include "Container.h"
#include "ServerSevice.h"
#include "Session.h"


ServerSevice::ServerSevice() : serverEp(ip::tcp::endpoint(tcp::v4(), 53005)),
acceptor(ip::tcp::acceptor(io_context, serverEp))
{
}

ServerSevice::~ServerSevice()
{
}

void ServerSevice::processAccept(boost::system::error_code ec, tcp::socket& socket, tcp::acceptor& acptor)
{
    int sessionId = g_SessionId++;
    cout << "New Session Connected [" << sessionId << "]" << endl;
    shared_ptr<Session> newSession = make_shared<Session>(move(socket), sessionId);
    ServerServiceRef tmpRef = shared_from_this();
    newSession->_service = tmpRef;
    _sessions.insert(newSession);
    newSession->readFromClient();
    acptor.async_accept([&](boost::system::error_code ec, tcp::socket socket)
    {
        processAccept(ec, socket, acptor);
    });
}

void ServerSevice::StartAccept()
{
    acceptor.async_accept([&](boost::system::error_code ec, tcp::socket socket)
    {
        processAccept(ec, socket, acceptor);
    });
}
