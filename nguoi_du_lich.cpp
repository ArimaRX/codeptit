/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.

Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

Kết quả: Chi phí mà người đó phải bỏ ra.

Ví dụ:

INPUT

OUTPUT

4

0 20 35 10

20 0 90 50

35 90 0 12

10 50 12 0

117

 

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<vector<int> > dt;
int n;
int fopt;
vector<bool> check;
void DFS(int di, int sum, int dai) {
	check[di] = 1;
	if (dai == n - 1) {
		fopt = min(fopt, sum + dt[di][0]);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!check[i] && sum + dt[di][i] < fopt) {
				DFS(i, sum + dt[di][i], dai + 1);
			}
		}
	}
	check[di] = 0;
}
int main() {
	check.clear();
	dt.clear();
	cin >> n;
	fopt = INT_MAX;
	check.resize(n, 0);
	for (int i = 0; i < n; i++) {
		vector<int> dt1 = {};
		for (int j = 0; j < n; j++) {
			int dt2;
			cin >> dt2;
			dt1.push_back(dt2);
		}
		dt.push_back(dt1);
	}
	DFS(0, 0, 0);
	cout << fopt << endl;
	return 0;
}
