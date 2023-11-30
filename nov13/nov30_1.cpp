#include <iostream>

template<typename T>
T sum(T last) {     //���ڰ� �ϳ� ���� ��
    return last;    //���������� ���ڰ� �ϳ� ������ �� ���� ��ȯ
}

template<typename T, typename... Other>
T sum(T first, Other... other) {        //���ڰ� �������� �� ���� ���ϱ�
    return first + sum(other...);       //ù��° ���ڿ� ������ ������ ���� ���ϱ� ���� sum�� ��� ȣ��
}

template<typename T, typename... Other>
double average(T first, Other... other) {       //��� ���ϱ�
    // �� ������ ������ �ϱ����� sum�� ȣ���Ͽ� ���� ���ϱ�
    // ���� ȣ������ �� ù��°�� ������ ������ ������ �� + 1 �� �� ������ ��
    return static_cast<double>(sum(first, other...)) / (sizeof...(other) + 1);      
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;      //����� ���ϰ� ���� �����͸� �Է�
}