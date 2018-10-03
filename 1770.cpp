#include <bits/stdc++.h>
#define LL long long 
using namespace std;
map<int,int>mp;
int main(){
	int T;
/*	FILE *file;
	file = freopen("1770.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin >> T;
	LL a , b , d , n;
	while( T-- ){
		mp.clear();
		cin >> a >> b >> d >> n;
		int ans = 0;
		int m = 1;
		if( n < 3 ){
			for( int i = 1 ; i <= n ; i++ ){
				ans += a * m;
				m *= 10;
			}
			ans = ans * b;
			while(ans){
				mp[ans%10]++;
				ans /= 10;
			}
			cout << mp[d] << endl;
			continue;
		}
		for( int i = 1 ; i <= 3 ; i ++ ){
			ans += a * m;
			m *= 10;
		}
		ans %= 1000;
		int t = ans * b;
		int tt = t;
		int one = t / 1000;
		int up = 0;
		if( (t / 1000) != 0 ) up = 1;
		int sing = tt % 10;
		tt /= 10;
		int ten = tt % 10;
		tt /= 10;
		int hun = tt % 10;
		if( hun != ten ){
			mp[sing]++;
			mp[ten]++;
			mp[hun] += ( up + n - 3 );
			mp[one] ++;
		}else{
			mp[sing] ++;
			t /= 10;
			t %= 10;
			int tmp = ( t - sing ) == 0 ? t : t - sing;
			mp[tmp]++;
			mp[t] += ( up + n - 2 );
		}
		cout << mp[d] << endl;
	}
	return 0;
}