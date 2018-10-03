#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n ;
	set<int>s;
	for( int i = 2 ; i < sqrt(n*2+1/2) ; i++ ){
		int temp = n/i-(i-1)/2;
		if( temp * i == n - i * (i-1) / 2 )
			s.insert(temp);
	}
	if( !s.size() ) printf("No Solution\n");
	else{
		set<int>::iterator it;
		for( it = s.begin(); it != s.end() ; it++ ){
			cout << *it << endl;
		}
	}
	return 0;
}
