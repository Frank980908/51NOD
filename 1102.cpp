#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 5e5+66;
LL a[AX];
stack<int>s;
int main(){
	int n ;
	cin >> n ;

	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	LL maxum = a[0];
	LL sum ;
	for( int i = 1 ; i < n ; i++ ){
		sum = a[i] ;
		for( int j = i - 1 ; j >= 0 ; j -- ){
			if( a[j] < a[i] ) break;
			sum += a[i];
		}
		for( int j = i + 1 ; j < n ; j++ ){
			if( a[j] < a[i] ) break;
			sum += a[i];
		}
		maxum = max( maxum , sum ) ;
	}	
	cout << maxum << endl;
	return 0;
}