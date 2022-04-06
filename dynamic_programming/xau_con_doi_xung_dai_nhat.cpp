/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
Output:  Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input

Output

2

abcbadd

aaaaa

 

5

5

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int doixung(string s) {
	map<pair<int, int>, bool> mp;
	mp.clear();
	int fopt = 1;
	for (int i = 0; i < s.size(); i++) mp[{i, i}] = 1;
	int i2 = 0, j2 = 1;
	while (j2 < s.size()) {
		if (s[i2] == s[j2]) {
			mp[{i2, j2}] = 1;
			fopt = 2;
		}
		i2++; j2++;
	}
	for (int i = 3; i <= s.size(); i++) {
		int l = 0, r = i - 1;
		while (r < s.size()) {
			if (s[l] == s[r]) {
				if (mp[{l + 1, r - 1}]) {
					fopt = i;
					mp[{l, r}] = 1;
				}
			}
			l++; r++;
		}
	}
	return fopt;
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		cout << doixung(s) << endl;
	}
	return 0;
}
