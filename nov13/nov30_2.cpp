#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) {     //���ڰ� �ϳ��� ��
    return x;               //���� ��ȯ
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {   //���ڰ� �������� ��
    auto y = min_value(args...);        //�� ���� ���ڸ� ������ ������ ������ ���� ���� ���� ���ϱ� �������� ���ڷ� �־� ��� ȣ��
    return x < y ? x : y;               //ù�� ° ���ڿ� ������ ���� �� ���� ���� �� �� ���� ���� ��ȯ
}


int main() {
    auto x = min_value(42, 3.14, 11.1f, -2);        //���� �� ���� ���� ���� ��� ���� min_value ȣ��
    std::cout << x;                                 //���� ���� �� ���

    getchar();
    return 0;
}