/*
TẬP CON BẰNG NHAU

Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

Output

2
4
1 5 11 5
3
1 3 5 

YES
NO

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
using namespace std;
bool qhd(vector<int> a, int s) {
	vector <bool> t = {};
	t.resize(s + 1);
	t[0] = true;
	for (int i = 0; i < a.size(); i++) {
		for (int j = s; j >= a[i]; j--) {
			if (t[j] == 0 && t[j - a[i]] == 1) t[j] = 1;
		}
	}
	return t[s];
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int sum = 0;
		vector<int> a = {};
		while (n--) {
			int a1;
			cin >> a1;
			sum += a1;
			a.push_back(a1);
		}
		if (sum % 2 != 0) cout << "NO" << endl;
		else {
			if (qhd(a, sum / 2)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}