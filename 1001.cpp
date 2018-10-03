#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+666;
int a[AX];
int n,k;
map<int,int>mp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n;
	for( int i = 0 ; i < n ; i++ ){
		cin>>a[i];
		mp[a[i]] = 1;
	}
	sort(a,a+n);
	int ans = 0;
	for( int i = 0 ; i < n ; i++ ){
		int t = k - a[i];
		if( t == a[i] ) continue;
		if( mp[a[i]] &&  mp[t] ) {
			if( t < a[i] ) swap(a[i],t);
			cout<<a[i]<<' '<<t<<endl;
			mp[t] = 0;
			mp[a[i]] = 0;
			ans++;
		}
	}
	if( ans == 0 ) cout<<"No Solution";
	return 0;
}