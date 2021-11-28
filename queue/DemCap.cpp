#include<bits/stdc++.h>
using namespace std;
main(){
	int n;
	cin >> n;
	long long a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	priority_queue<long long,vector<long long>,greater<long long>> pq,pq2;
	pq.push(a[0]);
	map<long long, int > mp;
	mp[a[0]]++;
	long long sum=0,max=a[0];
	for(int i=1;i<n ;i++){
		if(max<a[i]) max=a[i];
		mp[a[i]]++;
		pq.push(a[i]);
		while(pq.top() != a[i]){
			mp[pq.top()]=0;
			pq.pop();
		}
		if(i!= n-1) sum+=pq.size();
		else sum+=1;
		if(pq.size() >= 2 ){
			if(a[i]!= max)
			 sum=sum-pq.size()+mp[a[i]]+1;
		}
	}
	cout << sum ;
}