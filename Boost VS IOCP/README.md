# Boost VS IOCP

## Accept 작업
* IOCP는 AcceptEx를 하기위해 런타임에 함수 포인터로 해당 함수를 받아오고 Bind/listen/accept 시켜주는 등 여러가지 단계가 필요하다.   
* Boost는 IO Context 만들어주고 endpoint 만들어 acceptor에 넣어주고 acceptor로 비동기 함수만 호출해주면 된다.   

## I/O 완료 처리
* IOCP는 WorkerThread 들이 GQCS에서 완료 작업들을 꺼내어 accept/receive/send 에 대한 구분 작업과 처리를 따로 해주었다.   
* Boost는 io_context.run() 을 통해 WorkerThread 들이 완료 작업을 핸들러에게 넘겨준다.   
* 따라서 Boost는 어떤 작업이 완료되었는지 구분 작업을 해줄 필요가 없다.   

## Overlapped 확장
* IOCP는 Overlapped 인자에 이게 세션 정보 버퍼정보를 직접 넣어주고 GQCS에서 세션 정보를 얻은 후 Recv인가? Send? 인가 파싱해야 했다.   
* Boost는 Session 별 소켓으로 비동기 입출력 함수를 호출하면 자동으로 호출시 등록한 핸들러가 호출되어 별도의 파싱 과정이 필요없다.
