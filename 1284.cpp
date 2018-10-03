#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	LL n;
	cin>>n;
	LL ans = n ; 
	ans -= n/2 + n/3 + n/5 + n/7 ;
	ans += n/6 + n/10 + n/14 ;
	ans += n/15 + n/21 ;
	ans += n/35 ;
	ans -= n/30 + n/42 + n/70 ;
	ans -= n/105 ;
	ans += n/210 ;
	cout << ans <<endl;
	return 0;
}