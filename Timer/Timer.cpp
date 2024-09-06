#include "Timer.h"
#include <chrono>

template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) 
{
    // 시작 시간을 기록
    auto start = std::chrono::high_resolution_clock::now();

    // 함수 실행
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

    // 끝 시간을 기록
    auto end = std::chrono::high_resolution_clock::now();

    // 소요된 시간 계산
    std::chrono::duration<double> duration = end - start;

    // 출력
    std::cout.precision(10);
    std::cout << "Execution time: " << duration.count() + 1 << " seconds" << std::endl;

    // 함수 결과 반환
    return result;
}
