#include<iostream>
using namespace std;
typedef int status;

const int N = 1e6 + 1;
status tmp[N];

void merge_sort(status a[], int left, int right)
{
    if (left >= right) return;
    
    int mid = left + right >> 1;
    merge_sort(a, left, mid), merge_sort(a, mid + 1, right);
    
    int k = 0, l = left, r = mid + 1;
    while (l <= mid && r <= right)
        if (a[l] <= a[r]) tmp[k++] = a[l++];
        else tmp[k++] = a[r++];
        
    while (l <= mid) tmp[k++] = a[l++];
    while (r <= right) tmp[k++] = a[r++];
    
    for (l = left, r = 0; l <= right; ++l, ++r) a[l] = tmp[r];
}

int main()
{
	status arr[] = { 23,6,4,8,49,616,479,64,4,-1 };
	merge_sort(arr, 0, sizeof(arr) / sizeof(status) - 1);
	for (int i = 0; i < sizeof(arr) / sizeof(status); ++i) cout << arr[i] << ' ';
	cout << endl;
	return 0;
}