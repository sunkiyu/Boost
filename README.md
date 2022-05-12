# Boost
* Boost Library?   
* Boost는 C++ 프로그래밍 언어를 위한 선형대수, 의사 난수 발생, 멀티스레딩, 영상 처리, 정규 표현식, 그리고 유닛 테스트와 같은 작업들과 구조들을 지원하는 라이브러리들의 집합이다.    
* [Boost Library 다운로드 경로 https://www.boost.org/](https://www.boost.org/)   
* 2022/05/12 기준 Boost 최신 버전은 1.79.0 이다. 해당 링크를 클릭한다.   
* ![image](https://user-images.githubusercontent.com/68372094/167975666-6feaa761-68e0-445d-9541-7c45f776d293.png)   
* Windows Version을 다운로드 받는다.   
* ![image](https://user-images.githubusercontent.com/68372094/167975811-27ec131d-b5da-4589-986a-d6ab31c9ff82.png)   
* Bootstrap.bat을 실행 시킨다.   
* ![image](https://user-images.githubusercontent.com/68372094/167980803-f72b50c9-df57-4c4d-91c5-8e08aba97401.png)   
* Bootstrap.bat을 실행 시키고 나면 b2.exe 파일이 생기는데 이걸 통해서 빌드 해줘야한다.    
* 위키 백과를 통해 자신의 PC에 설치된 비주얼 스튜디오 버전을 확인한다.   
* [https://en.wikipedia.org/wiki/Microsoft_Visual_C++](https://en.wikipedia.org/wiki/Microsoft_Visual_C++) 위키백과를 통해 확인 가능하다.   
* Developer Command Prompt for VS2019를 실행 시킨다.   
* 본인은 비주얼 스튜디오 2019 16.11 버전이므로 14.29
* b2 toolset=msvc-14.29 variant=debug,release link=static threading=multi address-model=64 runtime-link=static


