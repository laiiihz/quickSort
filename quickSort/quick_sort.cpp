#include <iostream>
#include <algorithm>


//quickSort(start, end)
template <typename Tem> bool quickSort(Tem *a, Tem *b) {
	ptrdiff_t diff = b - a;
	if (diff < 1) {
		std::cout << "----WRONG POINTOR\n----the end point is bigger than start point" << std::endl;
		return false;
	}
	realQuickSort(a, (b - 1));
	return true;
}

template <typename Tem> void realQuickSort(Tem *a,Tem *b) {
	ptrdiff_t diff_a_b = b - a; //下标最大
	int left = 0;
	int right = diff_a_b;
	if (left <= right) {
		int mid_number = a[0];
		while (right != left) {
			while (right>left&&a[right] >= mid_number)right--;
			a[left] = a[right];
			while (right > left&&a[left] <= mid_number)left++;
			a[right] = a[left];
		}
		a[right]=mid_number;
		int diff_a_mid = right - 0;
		realQuickSort(a, &a[left-1]);
		realQuickSort(&a[right+1], b);
	}

}



int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int b[10] = { 10,9,8,7,6,5,4,3,2,1 };

	std::sort(b, b + 10);
	quickSort(a, a + 10);
	quickSort(a + 10, a);
	for (int i = 0; i < 10; i++) {
		std::cout << a[i] << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		if (a[i] == b[i])continue;
		else {
			std::cout << "not the same" << std::endl;
			return 0;
		}
	}
	std::cout << "the same" << std::endl;
	return 0;
}