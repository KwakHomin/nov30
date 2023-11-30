#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {		//
	for (auto sorted = first; first != last; last = sorted) {						//first, last�� ���� ������ for�� �ݺ�
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {				//cur, prev�� first �ְ� cur�� ���� �׸�
			if (comp(*cur, *prev)) {												//comp ȣ��
				std::iter_swap(cur, prev);											//comp ��ȯ���� ���� cur�� prev ��ȯ
				sorted = cur;														//������ ��
			}
		}
	}
}

class compGreater {	// �������� ���Ŀ� ���
public:
	bool operator()(int a, int b) const {
		return a > b;							//a, b �� ū �� ��ȯ
	}
};

class compLess {	// �������� ���Ŀ� ���
public:
	bool operator()(int a, int b) const {
		return a < b;							//a, b �� ���� �� ��ȯ
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };		//������ ����Ʈ ����

	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), std::less<int>());		//����Ʈ ������ ���� ȣ��, less�� �־� ������������ ����
	for (const auto& value : values)	{			//���ĵ� ����Ʈ ���ʴ�� ���
		std::cout << " " << value ;
	}
	std::cout << std::endl;


	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), std::greater<int>());		//����Ʈ ������ ���� ȣ��, less�� �־� ������������ ����
	for (const auto& value : values) {			//���ĵ� ����Ʈ ���ʴ�� ���
		std::cout << " " << value;
	}
	std::cout << std::endl;

	return 0;
}