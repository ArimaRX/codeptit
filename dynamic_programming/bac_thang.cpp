/*Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input

Output

2

2 2

4 2

 

2

5

 

Giải thích test 1: Có 2 cách đó là (1, 1) và (2).

Giải thích test 2: 5 cách đó là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
const int K = 101;
const int M = 1e9 + 7;
int f[N][K];
int main() {
	f[0][0] = 1;
	for (int i = 1; i < N; ++i) f[i][0] = 0;
	for (int j = 1; j < K; ++j) {
		int ans = 1;
		f[0][j] = 1;
		for (int i = 1; i < j; ++i) {
			f[i][j] = ans;
			ans = (ans + f[i][j]) % M;
		}
		for (int i = j; i < N; ++i) {
			f[i][j] = ans;
			ans = (ans - f[i - j][j] + M) % M;
			ans = (ans + f[i][j]) % M;
		}
	}
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << f[n][k] << '\n';
	}
	return 0;
}


