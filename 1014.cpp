#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL P,A;
	cin >> P >> A ;
	int flag = 0;
	for( LL i = 0 ; i <= P ; i++ ){
		if( ( (LL)(( i % P ) * ( i % P )) ) % P == A ){
			cout<<i<<' ';
			flag = 1;
		}
	}
	if( !flag ) cout<<"No Solution"<<endl;
	return 0;	
}