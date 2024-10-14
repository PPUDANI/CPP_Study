#include <iostream>
#include <stack>
#include <vector>

#include "../Timer/Timer.h"

int main()
{
    int TestSize = 50000000;

    {
        // Stack과 vector의 성능 실험.
        // Stack이 더욱 간단한 구조이므로 vector보다 빠를거라 예상했지만

        std::stack<double> double_stack;
        std::vector<double> double_vector;

        std::cout << "Test Size : 100,000,000" << std::endl;
        Timer::Getinstance()->StartTimer();


        // Push_back 
        for (int i = 0; i < TestSize; ++i)
        {
            double_stack.push(static_cast<double>(i));
        }
        std::cout << "stack push : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;
        for (int i = 0; i < TestSize; ++i)
        {
            double_vector.push_back(static_cast<double>(i));
        }
        std::cout << "vector push : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;


        // Pop_back 
        for (int i = 0; i < TestSize; ++i)
        {
            double_stack.pop();
        }
        std::cout << "stack pop : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;
        for (int i = 0; i < TestSize; ++i)
        {
            double_vector.pop_back();
        }
        std::cout << "vector pop : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;
        std::cout << std::endl;

        //        [ RESULT ]
        // --------------------------
        //     Test Size : 50,000,000
        // 
        //    stack push : 8.41848 sec
        //   vector push : 2.40036 sec
        // 
        //     stack pop : 4.18026 sec
        //    vector pop : 1.65255 sec
        // --------------------------

        //        [ RESULT ]
        // --------------------------
        //     Test Size : 100,000,000
        // 
        //    stack push : 47.5393 sec
        //   vector push : 11.0904 sec
        // 
        //     stack pop : 16.6877 sec
        //    vector pop : 6.27037 sec
        // --------------------------
        // 

        // 삽입 결과는 std::vector가 4배 가까이 빠름.
    }


    {
        // Stack은 컨테이너 어댑터로 내부적으로 deque를 감싸고 있는 컨테이너임. 
        typedef std::stack<int> Stack;
        typedef std::stack<int, std::deque<int>> Stack_Deque;

        if (std::is_same<Stack, Stack_Deque>::value)
        {
            std::cout << "\"stack\" uses \"deque\" by default." << std::endl;
        }
        else
        {
            std::cout << "\"stack\" does not use \"deque\" by default." << std::endl;
        }
        std::cout << std::endl;
    }

    {
        // 아래와 같이 두 번째 템플릿 인자를 추가하여 vector를 기본 컨테이너로 사용할 수 있음.
        std::stack<double, std::vector<double>> double_stack_vec;
        std::vector<double> double_vector2;

        Timer::Getinstance()->StartTimer();
        // Push_back 
        for (int i = 0; i < TestSize; ++i)
        {
            double_stack_vec.push(static_cast<double>(i));
        }
        std::cout << "stack_vec push : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;
        for (int i = 0; i < TestSize; ++i)
        {
            double_vector2.push_back(static_cast<double>(i));
        }
        std::cout << "vector push : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;

        // Pop_back 
        for (int i = 0; i < TestSize; ++i)
        {
            double_stack_vec.pop();
        }
        std::cout << "stack_vec pop : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;
        for (int i = 0; i < TestSize; ++i)
        {
            double_vector2.pop_back();
        }
        std::cout << "vector pop : " << Timer::Getinstance()->TimeCheck() << " sec" << std::endl;

        //        [ RESULT ]
        // -------------------------------
        //        Test Size : 50,000,000
        // 
        //   stack_vec push : 2.28892 sec
        //      vector push : 2.25454 sec
        // 
        //    stack_vec pop : 1.825 sec
        //       vector pop : 1.67493 sec
        // -------------------------------

        //        [ RESULT ]
        // -------------------------------
        //        Test Size : 100,000,000
        // 
        //   stack_vec push : 9.91611 sec
        //      vector push : 7.65561 sec
        // 
        //    stack_vec pop : 6.74763 sec
        //       vector pop : 6.42369 sec
        // -------------------------------


        // Stack의 기본 컨테이너를 vector로 바꾼 결과 Stack의 성능을 크게 높일 수 있었음.
        // 그래도 Stack이 내부 컨테이너를 감싸고 있기 때문에 vector보다 조금 느릴 수 밖에 없음.

        // [ Stack이 deque를 쓰는 이유 ]
        // 추가적인 할당일 필요할때 기존 데이터를 옮기는 vector와 다르게
        // deque는 여러 메모리 블록을 관리하기 때문에 큰 데이터에서 효율적이라고 함.

        // 그런데 vector의 재할당으로 복사되는 시간으로 손해를 볼 줄 알았지만 1억번 push해도 차이는 그대로임.
        // 메모리가 블럭단위로 분산되어있는 deque와 붙어있는 vector의 캐시적중률 차이로 보임.
    }
}

