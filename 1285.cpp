#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
map<int,int>mp;
int main(){
	int n;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i]);
	}
	for( int i = 0 ; i < n ; i++ ){
		if( i > 0 && i < n - 1 && a[i] > a[i-1] && a[i] > a[i+1] ){
			mp[i] = 1;
		}
	}

	for( int i = n - 1 ; i >= 1 ; i-- ){
		if( n % i == 0 ){
			int j = 0;
			int tmp = (int) (n / i);  //ave
			int num = 0;
			int falg = 1;
			while( num < i ){
				int f = 0;
				for( ; j < tmp + num * tmp ; j++ ){
					if( mp[j] ){
						f = 1 ;
						j = tmp + num * tmp ;
						break;
					}
				}
				if( f == 0 ){
					falg = 0;
					break;
				}
				num++;
			}
			if( falg == 1 ){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}