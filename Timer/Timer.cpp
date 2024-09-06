#include "Timer.h"
#include <chrono>

template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) 
{
    // ���� �ð��� ���
    auto start = std::chrono::high_resolution_clock::now();

    // �Լ� ����
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

    // �� �ð��� ���
    auto end = std::chrono::high_resolution_clock::now();

    // �ҿ�� �ð� ���
    std::chrono::duration<double> duration = end - start;

    // ���
    std::cout.precision(10);
    std::cout << "Execution time: " << duration.count() + 1 << " seconds" << std::endl;

    // �Լ� ��� ��ȯ
    return result;
}
