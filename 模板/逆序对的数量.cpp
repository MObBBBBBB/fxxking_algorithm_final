#include<iostream>
using namespace std;

const int N = 1e6 + 1;
int a[N], tmp[N];
int ans = 0;

void solution(int *a, int left, int right)
{
    if (left >= right) return;
    int mid = left + right >> 1;
    solution(a, left, mid), solution(a, mid + 1, right);
    
    int k = 0, l = left, r = mid + 1;
    while (l <= mid && r <= right)
        if (a[l] <= a[r]) tmp[k++] = a[l++];
        else 
        {
            tmp[k++] = a[r++];
            ans += mid - l + 1;
        }
    while (l <= mid) tmp[k++] = a[l++];
    while (r <= right) tmp[k++] = a[r++];
    for (l = left, r = 0; l <= right; l++, r++) a[l] = tmp[r];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    solution(a, 0, n - 1);
    cout << ans << endl;
    return 0;
}

/*

input:
6
2 3 4 5 6 1

output:
5

*/