#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while( ~scanf("%d",&n) ){
		int num5 = 0 ;
		int num2 = 0 ;
		int temp = n;
		while( temp ){
			num5 += temp/5;
			temp /= 5;
		}
		temp = n;
		while( temp ){
			num2 += temp/2;
			temp /= 2;
		}
		cout<<min(num5,num2)<<endl;;
	}
	return 0;
}