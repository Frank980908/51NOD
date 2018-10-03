#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int AX = 1e6+66;
int a[AX];
int b[AX];
template <class T>
inline void scan_d(T &ret){
	char c; 
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0' && c <= '9')
	{ 
		ret = ret * 10 + (c - '0'), c = getchar();
	}
}
int main(){
	int n , k ;
	scan_d(n);
	scan_d(k);
	int op ,v;
	int tot = 0;
	int flag = 0;
	int sum = 0;
	memset( a , -1 , sizeof(a) );
	for( int i = 0 ; i < n ; i++ ){
		scan_d(op);
		if( op == 1 ){
			scan_d(v);
			sum += v;
			if( tot >= k ) { flag = 1; tot = 0;}
			if( flag ){
				sum -= a[tot];
			}
			a[tot++] = v;
		}else if( op == 2 ){
			int total ;
			if( flag )  total = k;
			else total = tot;
			int ave = (double)sum / total;
			printf("%d.00\n",ave);
		}else if( op == 3 ){
			int total ;
			if( flag )  total = k;
			else total = tot;
			double ave = (double)sum / total;
			double sum = 0.0;
			for( int j = 0 ; j < total ; j++ ){
				sum += ( a[j] - ave ) * ( a[j] - ave );
			}
			printf("%.2lf\n",(double)sum/total);
		}else{
			int t = 0;
			for( int j = 0 ; j < k ; j++ ){
				if( a[j] != -1 ){
					b[++t] = a[j];
				}	
			}
			sort( b + 1 , b + t + 1 );
			printf("%.2lf\n",( b[(t+1)/2] + b[t/2+1] ) * 1.0 / 2.0 );
		}
	}
	return 0;
}