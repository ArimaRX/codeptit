/*
CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN BFS

Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G với đỉnh u ∈ V là gốc của cây bằng thuật toán BFS.

Input

Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.

Tiếp theo là T bộ test, mỗi bộ test có dạng sau:

Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, u (1 ≤ N ≤ 103, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.
Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.
Output

Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 cạnh của cây khung với gốc là đỉnh u trên N – 1 dòng theo thứ tự duyệt của thuật toán BFS. Ngược lại nếu không tồn tại cây khung thì in ra -1.

Ví dụ

Input

Output

2

4 4 2

1 2

1 3

2 4

3 4

4 2 2

1 2

3 4

2 1

2 4

1 3

-1

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
using namespace std;
struct canh {
	int dau;
	int cuoi;
	canh(int x, int y) {
		dau = x; cuoi = y;
	}
};
vector<vector<int>>lst;
vector<canh> edg;
vector<bool> check;
int n,u;
void init() {
	lst = {};
	edg = {};
	check = {};
	int c;
	cin >> n >> c >> u;
	lst.resize(n + 1);
	check.resize(n + 1, 1);
	while (c--) {
		int d1, d2;
		cin >> d1 >> d2;
		lst[d1].push_back(d2);
		lst[d2].push_back(d1);
	}
}
void Tree_BFS(int a) {
	queue<int> q = {};
	q.push(a);
	check[a] = false;
	while (q.size() > 0) {
		int top1 = q.front();
		q.pop();
		for (int i = 0; i < lst[top1].size(); i++) {
			if (check[lst[top1][i]]) {
				edg.push_back(canh(top1, lst[top1][i]));
				q.push(lst[top1][i]);
				check[lst[top1][i]] = false;
			}
		}
	}
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		init();
		Tree_BFS(u);
		if (edg.size() == n - 1) {
			for (int i = 0; i < edg.size(); i++) {
				cout << edg[i].dau << " " << edg[i].cuoi << endl;
			}
		}
		else cout << "-1" << endl;
	}
	return 0;
}