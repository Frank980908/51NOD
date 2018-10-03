#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL a[5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int x;
	a[1] = a[2] = a[3] = 0;
	for( int i = 1 ; i <= n ; i++ ){
		cin>>x;
		if( x == 1 || x == 2 ) a[x] ++;
		else a[3]++;
	}
	LL sum = 0;
	sum = a[1]*(n-1) + a[2]*(a[2]-1)/2;
	cout<<sum<<endl;
	return 0;
}