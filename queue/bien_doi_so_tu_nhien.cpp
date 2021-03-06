/*
BIẾN ĐỔI SỐ TỰ NHIÊN

Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.

Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a) biến đổi N = N-1 =16.
Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi N = max(2, 8)=8 hoặc N=max(4, 4)=4.
Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các thao tác (a), (b) được thực hiện ít nhất. Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như sau:

                                    Thao tác (a): N = N-1 = 17-1 = 16

                                    Thao tác (b): 16 = max(4,4) = 4

                                    Thao tác (b): 4 = max(2,2) = 2

                                    Thao tác (a): 2 = 2-1 = 1

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số N.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 

Input

Output

3

17

50

100

4

5

5

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 150000 Kb
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int nhonhat(int n) {
	unordered_map<int, int> m;
	queue<int> a;
	a.push(n);
	while (1) {
		if (m[1] > 0) break;
		int top1 = a.front();
		a.pop();
		for (int i = 2; i <= sqrt(top1); i++) {
			if (top1 % i == 0) {
				if (m[top1 / i] == 0) {
					m[top1 / i] = m[top1] + 1;
					a.push(top1 / i);
				}
			}
		}
		if (m[top1 - 1] == 0) {
			m[top1 - 1] = m[top1] + 1;
			a.push(top1 - 1);
		}
	}
	return m[1];
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		cout << nhonhat(n) << endl;
	}
	return 0;
}