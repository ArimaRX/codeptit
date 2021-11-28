/*
MIN VÀ MAX

Cho dãy số A[] có N phần tử là các số nguyên dương không quá 6 chữ số.

Người ta tạo ra ma trận C[][] như sau:

Kích thước của C là N*N
Với chỉ số tính từ 1 thì C[i][j] = j * min (A[i], A[i+1], …, A[i+j-1]).
với 1 <= j <=n; 1 <= i <= N – j + 1.

 

Hãy tìm giá trị lớn nhất của ma trận C.

 

Input

Dòng đầu ghi số N (1 < N <= 105).

Dòng tiếp theo ghi N số của dãy A[], các giá trị đều dương và không quá 106.  

Output

Ghi ra giá trị lớn nhất tính được.

Ví dụ

Input

Output

5

1 4 6 3 2

9

 

Giới hạn thời gian: 1s

Giới hạn bộ nhớ: 100000 Kb
*/
#include<bits/stdc++.h>
using namespace std;
long long Max(vector<int> a) {
	long long max1 = LLONG_MIN;
	for (int i = a.size() - 1; i >= 0; i--) {
		int l = i, r = i;
		while (l - 1 >= 0 && a[l - 1] >= a[i]) l--;
		while (r + 1 < a.size() && a[r + 1] >= a[i])r++;
		int h =r-l+1;
		long long tich = (long long)a[i] * h;
		if (max1 < tich) max1 = tich;
	}
	return max1;
}
int main() {
	int n;
	cin >> n;
	vector<int> a = {};
	for (int i = 0; i < n; i++) {
		int a1;
		cin >> a1;
		a.push_back(a1);
	}
	cout << Max(a) << endl;
	return 0;
}