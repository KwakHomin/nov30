#include <iostream>

template<typename T>
T sum(T last) {     //인자가 하나 있을 때
    return last;    //마지막으로 인자가 하나 남았을 때 인자 반환
}

template<typename T, typename... Other>
T sum(T first, Other... other) {        //인자가 여러개일 때 합을 구하기
    return first + sum(other...);       //첫번째 인자와 나머지 인자의 합을 구하기 위해 sum을 재귀 호출
}

template<typename T, typename... Other>
double average(T first, Other... other) {       //평균 구하기
    // 합 나누기 개수를 하기위해 sum을 호출하여 합을 구하기
    // 최초 호출했을 때 첫번째를 제외한 나머지 인자의 수 + 1 은 총 인자의 수
    return static_cast<double>(sum(first, other...)) / (sizeof...(other) + 1);      
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;      //평균을 구하고 싶은 데이터를 입력
}