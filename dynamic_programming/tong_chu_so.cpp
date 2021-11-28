/*
TỔNG CHỮ SỐ

Cho hai số nguyên dương A và B. Tìm số N nhỏ nhất thỏa mãn: A là tổng các chữ số của N, B là tổng bình phương các chữ số của N. Nếu không tồn tại N thỏa mãn A và B hãy đưa ra -1. Giả thiết N có không quá 100 chữ số.

Ví dụ với A = 18, B = 162 ta tìm được số nhỏ nhất N=99 vì 9+9=18 và 92 + 92 = 162. Với A = 12, B = 9 ta có kết quả  là -1.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số A, B được viết trên một dòng.
T, A, B thỏa mãn ràng buộc: 1≤T≤100;  1≤A≤100; 1≤B≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 Input

Output

2
18  162
12  9

99

-1

 

Giới hạn thời gian: 2s

Giới hạn bộ nhớ: 65536 Kb
*/
#include <bits/stdc++.h>
using namespace std;

int D[101][10001];

void qhd(){
	int i,j,k;
	for(i=0; i<=100; i++)
		for(j=0; j<=10000; j++)
			D[i][j] = 101;
	D[0][0] = 0;
	for(i=1; i<10; i++) D[i][i*i] = 1;

	for(i=1; i<=100; i++)
		for(j=i; j<=i*81; j++){
			for(k = 9; k > 0; k--){
				int kk=k*k;
				if(i>k && j>kk && D[i][j] > D[i-k][j-kk]+1)
					D[i][j]= D[i-k][j-kk]+1;
		}
	}
}

void inkq(int a, int b){
    if (a<=0 || a>100 || b<=0 || b>10000 || (D[a][b] >100)){
	  cout << -1 << endl;
	  return;
	}
	int i, k, n=D[a][b];
	for(k=n; k>0; k--){
		for(i=1; i<=9; i++)
			if(a>=i && b>=i*i && (D[a][b]==D[a-i][b-i*i]+1)){
				cout << i;
				a -= i;
				b -= i*i;
				break;
		 }
	}
	cout << endl;
}

main(){
    int t; cin >> t;
    qhd();
    while (t--){
        int a, b;
        cin >> a >> b;
        inkq(a,b);
    }
}
