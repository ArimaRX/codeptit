/*
TỔNG BÌNH PHƯƠNG

Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52. Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test là một số tự nhiên N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 

Input

Output

3
100
6
25

1
3
1
 

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
using namespace std;
int dem[11000];
void init() {
	dem[0] = 0;
	for (int i = 1; i <= 10005; i++) {
		int h = sqrt(i);
		int Min = INT_MAX;
		for (int j = h; j >= 1; j--) {
			if (1 + dem[i - j * j] < Min) Min = 1 + dem[i - j * j];
		}
		dem[i] = Min;
	}
}
int main() {
	int test;
	cin >> test;
	init();
	while (test--) {
		int n;
		cin >> n;
		cout << dem[n] << endl;
	}
	return 0;
}
//testcase dac biet:61