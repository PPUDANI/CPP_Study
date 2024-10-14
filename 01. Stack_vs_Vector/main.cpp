#include <iostream>
#include <stack>
#include <vector>

#include "../Timer/Timer.h"

int main()
{
    int TestSize = 50000000;

    {
        // Stack�� vector�� ���� ����.
        // Stack�� ���� ������ �����̹Ƿ� vector���� �����Ŷ� ����������

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

        // ���� ����� std::vector�� 4�� ������ ����.
    }


    {
        // Stack�� �����̳� ����ͷ� ���������� deque�� ���ΰ� �ִ� �����̳���. 
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
        // �Ʒ��� ���� �� ��° ���ø� ���ڸ� �߰��Ͽ� vector�� �⺻ �����̳ʷ� ����� �� ����.
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


        // Stack�� �⺻ �����̳ʸ� vector�� �ٲ� ��� Stack�� ������ ũ�� ���� �� �־���.
        // �׷��� Stack�� ���� �����̳ʸ� ���ΰ� �ֱ� ������ vector���� ���� ���� �� �ۿ� ����.

        // [ Stack�� deque�� ���� ���� ]
        // �߰����� �Ҵ��� �ʿ��Ҷ� ���� �����͸� �ű�� vector�� �ٸ���
        // deque�� ���� �޸� ����� �����ϱ� ������ ū �����Ϳ��� ȿ�����̶�� ��.

        // �׷��� vector�� ���Ҵ����� ����Ǵ� �ð����� ���ظ� �� �� �˾����� 1��� push�ص� ���̴� �״����.
        // �޸𸮰� �������� �л�Ǿ��ִ� deque�� �پ��ִ� vector�� ĳ�����߷� ���̷� ����.
    }
}

