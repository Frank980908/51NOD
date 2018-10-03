#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+666;
char a[AX];
int main(){
	while( ~scanf("%s",a+1) ){
		int len = strlen(a+1);
		int flag ;
		int l = len;
		int n = len/2;
		if( len % 2 == 0 ){
			for( int i = 1 ; i <= n ; i++ ){
				if( a[i] != a[i+n] ){
					flag = 0;
					break;
				}else{
					flag = 1;
				}
			}
		}else{
			flag = 0;
		}
		cout<<(flag == 1 ? "YES" : "NO")<<endl;
	}
	return 0;
}