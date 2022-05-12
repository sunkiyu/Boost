#include "pch.h"
#include "Session.h"
#include "ServerSevice.h"

Session::Session() : sock(nullptr)
{

};

Session::Session(tcp::socket &&connSock, int sessionId) : sock(std::move(connSock)), sessionId(sessionId)
{
};

Session::~Session()
{

}

void Session::writeToClient(SessionRef realsession, size_t length)
{
    for (SessionRef session : _service->_sessions)
    {
        if (session->sessionId != sessionId)
        {
            session->sock.async_write_some(buffer(realsession->buf, 255), [&](boost::system::error_code ec, size_t length)
            {
                if (ec)
                {
                    cout << "DisConnectd Client [" << session->sessionId << "]" << endl;
                }
                else
                {

                }
            });

        }
    }
    readFromClient();
}

void Session::readFromClient()
{
    sock.async_read_some(buffer(buf, 255), [&](boost::system::error_code ec, size_t length)
    {
        if (ec)
        {
            cout << "DisConnectd Client [" << sessionId << "]" << endl;
            //_sessions.erase(session);
        }
        else
        {
            buf[length] = 0;
            cout << buf << endl;
            writeToClient(shared_from_this(), length);
        }
    });
}
