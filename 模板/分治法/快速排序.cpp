#include<iostream>
using namespace std;
typedef int status;

void quick_sort(status *a, int left, int right)
{
    if (left >= right) return;
    int l = left - 1, r = right + 1;
	status p = a[(l + r) >> 1];
    while (l < r)
    {
        do ++l; while (p > a[l]);
        do --r; while (p < a[r]);
        if (l < r) swap(a[l], a[r]);
    }
    quick_sort(a, left, r), quick_sort(a, r + 1, right);
}

int main()
{
	status arr[] = { 23,6,4,8,49,616,479,64,4,-1 };
	quick_sort(arr, 0, sizeof(arr) / sizeof(status) - 1);
	for (int i = 0; i < sizeof(arr) / sizeof(status); ++i) cout << arr[i] << ' ';
	cout << endl;
	return 0;
}