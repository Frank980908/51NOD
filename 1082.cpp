#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e6;
LL a[AX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	int n;
	memset(a,0,sizeof(a));
	for( int i = 1 ; i <= AX; i++ ){
		int flag = 1;
		if( i % 7 == 0 ) flag = 0;
		int temp = i;
		while( temp ){
			if( temp % 10 == 7 ) { flag = 0 ; break; }
			temp /= 10;
		}
		if( flag ) a[i] = a[i-1] + (LL) i*i ;
		else a[i] = a[i-1];
	}

	while( T-- ){
		cin>>n;
		cout<<a[n]<<endl;			
	}
	return 0;
}