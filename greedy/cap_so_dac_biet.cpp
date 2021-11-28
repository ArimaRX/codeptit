/*
 CẶP SỐ ĐẶC BIỆT

Cho dãy số nguyên A có n phần tử.

Hãy đếm xem có bao nhiêu cặp (i,j) thỏa mãn:

i < j
A[i] > A[j] và đều là số chẵn
Tồn tại chỉ số k với i < k < j sao cho A[k] là số lẻ
Input

Dòng đầu tiên ghi số n (1 ≤ n ≤ 105).

Output

Dòng thứ 2 ghi n số của dãy A, các giá trị A[i] không vượt quá 106.

Ví dụ

Input

Output

5

4 3 2 5 1

1

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int i, int j) {
	return i > j;
}
void thuchien() {
	int n;
	cin >> n;
	vector<int> a = {};
	vector<int> t = {};
	int dem = 0;
	int k = 0;
	bool z = true;
	while (n--) {
		int a1;
		cin >> a1;
		if (a1 % 2 != 0) {
			for (int i = a.size() - 1; i >= 0; i--) {
				if (t[i] == 1) break;
				else t[i] = 1;
			}
			k = a.size();
			z = true;
		}
		else {
			for (int i = 0; i < k; i++) {
				if (a[i] > a1) dem++;
			}
			a.push_back(a1);
			t.push_back(0);
			if (z) {
				k = a.size() - 1;
				z = false;
			}
		}
	}
	cout << dem << endl;
}
int main() {
	thuchien();
	return 0;
}