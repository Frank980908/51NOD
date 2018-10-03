#include <bits/stdc++.h>
using namespace std;
const int AX = 1e4+6;
string a[AX];

bool cmp(const string x , const string y ){
	string x1 = x + y ; string x2 = y + x;
	return x1 < x2;
}

int main(){
	int n ;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	sort( a , a + n , cmp );
	int tot = 0;
	for( int i = 0 ; i < n ; i++ ){
		int len = a[i].size();
		for( int j = 0 ; j < len ; j++ ){
			cout << a[i][j];
			tot ++ ;
			if( tot == 1000 ) { tot -= 1000; puts("");}
		}
	}
	puts("");
	return 0 ;
}