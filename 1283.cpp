#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int t = sqrt(n);
	if( t * t == n ){
		cout<<4*t<<endl;
	}else{
		for( int i = t ; i ; i-- ){
			int b = (double) n / i;
			if( i * b  == n ){
				t =  b + i;
				break;
			}
		}
		cout<<2*t<<endl;
	}
	return 0;
}