#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) {     //인자가 하나일 때
    return x;               //인자 반환
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {   //인자가 여러개일 때
    auto y = min_value(args...);        //맨 앞의 인자를 제외한 나머지 인자중 가장 작은 값을 구하기 나머지를 인자로 넣어 재귀 호출
    return x < y ? x : y;               //첫번 째 인자와 나머지 인자 중 가장 작은 값 중 작은 값을 반환
}


int main() {
    auto x = min_value(42, 3.14, 11.1f, -2);        //인자 중 가장 작은 값을 얻기 위해 min_value 호출
    std::cout << x;                                 //가장 작은 값 출력

    getchar();
    return 0;
}