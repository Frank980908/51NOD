#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n;
int main(){
	cin>>n;
	LL mul = 1;
	LL temp = n;
	LL ans = 0;
	while( temp ){
		int single = temp % 10;
		if( single == 1 ){
			ans += ( n / ( mul*10 ) * mul );
			ans += ( n % mul ) +1 ;
		}else if( single == 0 ){
			ans +=  ( n / ( mul*10 ) * mul );
		}else{
			ans += ( (n / (mul*10) + 1 ) * mul  );
		}
		temp /= 10;
		mul *= 10;
	}
	cout<<ans;
	return 0;
}
