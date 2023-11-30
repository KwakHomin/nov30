#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {		//
	for (auto sorted = first; first != last; last = sorted) {						//first, last가 같을 때까지 for문 반복
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {				//cur, prev에 first 넣고 cur은 다음 항목
			if (comp(*cur, *prev)) {												//comp 호출
				std::iter_swap(cur, prev);											//comp 반환값에 따라 cur과 prev 교환
				sorted = cur;														//다음값 비교
			}
		}
	}
}

class compGreater {	// 오름차순 정렬에 사용
public:
	bool operator()(int a, int b) const {
		return a > b;							//a, b 중 큰 값 반환
	}
};

class compLess {	// 내림차순 정렬에 사용
public:
	bool operator()(int a, int b) const {
		return a < b;							//a, b 중 작은 값 반환
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };		//정렬할 리스트 선언

	std::cout << "오름차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), std::less<int>());		//리스트 정렬을 위해 호출, less를 넣어 오름차순으로 정렬
	for (const auto& value : values)	{			//정렬된 리스트 차례대로 출력
		std::cout << " " << value ;
	}
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), std::greater<int>());		//리스트 정렬을 위해 호출, less를 넣어 내림차순으로 정렬
	for (const auto& value : values) {			//정렬된 리스트 차례대로 출력
		std::cout << " " << value;
	}
	std::cout << std::endl;

	return 0;
}