
// 아래 코드는 iostream 라이브러리를 include 하는 코드이다.
// 파일의 내부 코드를 전부 복붙해서 위에 붙이는 것이다.
#include <iostream>

// 파일 코드 복붙이라면 아래와 같은것도 가능?
#include "Code.h"

    int a = 1234;
    std::cout << a << std::endl;
}

// IntelliSense도 밑줄치는 이런 말도안되는 코드가 컴파일이 된다.
// 결론 : 파일 내부 코드 복붙이 맞다.
