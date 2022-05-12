// BoostServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include "ServerSevice.h"
#include "Session.h"
#include "Container.h"
#include "CoreGlobal.h"


int main()
{
   
    ServerServiceRef service = make_shared<ServerSevice>();
    service->StartAccept();


    for (int i = 0; i < 2; i++)
    {
        service->_threads.push_back(thread([&]()
        {
            while (1)
            {
                service->io_context.run();
            }
        }));
    }

    for (thread& thread : service->_threads)
    {
        thread.join();
    }
}

