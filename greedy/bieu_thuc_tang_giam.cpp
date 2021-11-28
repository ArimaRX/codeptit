/*
BIỂU THỨC TĂNG GIẢM

Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

A[] = “I”               : số tăng nhỏ nhất là 12.
A[] = “D”              : số giảm nhỏ nhất là 21
A[] =”DD”            : số giảm nhỏ nhất là 321
A[] = “DDIDDIID”: số thỏa mãn 321654798
Input: Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu S. T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .

Output: Đưa ra thứ tự bộ test và kết quả mỗi test theo từng dòng.

Ví dụ:

Input:

Output:

4

I

D

DD
DDIDDIID

Test 1: 12

Test 2: 21

Test 3: 321

Test 4: 321654798

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 150000 Kb
*/
#include<bits/stdc++.h>
using namespace std;
string tanggiam(string s) {
	string res = "";
	int max1 = 1;
	int j = 0;
	int dem1 = 0;
	while (j < s.size() && s[j] == 'D') {
		j++; dem1++;
	}
	max1 += dem1;
	for (int i = max1; i >= 1; i--) res.push_back(i + '0');
	int min1 = max1 + 1;
	while (j < s.size()) {
		int dem = 0;
		if (s[j] == 'I') {
			j++; dem++;
		}
		while (j < s.size() && s[j] == 'D') {
			j++; dem++;
		}
		max1 += dem;
		for (int i = max1; i >= min1; i--) res.push_back(i + '0');
		min1 = max1 + 1;
	}
	return res;
}
int main() {
	int test;
	cin >> test;
	for(int i=1;i<=test;i++) {
		string s;
		cin >> s;
		cout << "Test " << i << ": " << tanggiam(s) << endl;
	}
	return 0;
}