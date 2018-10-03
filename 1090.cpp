#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e4+6;
int n;
struct  Node
{
	int x;
	int y;
	LL sum;
}e[AX];
int a[AX];
bool cmp( const Node &a , const Node &b ){
	return a.sum < b.sum;
}

bool check( int x ){
	int l = 0 , r = n-1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( a[mid] < x ) l = mid + 1;
		else if( a[mid] > x ) r = mid - 1;
		else return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for( int i = 0 ; i < n ; i++ ){
		cin>>a[i];
	}
	int tot = 0;
	sort(a,a+n);
/*	for( int i = 0 ; i < n ; i++ ){
		for( int j = i + 1 ; j < n ; j++ ){
			e[tot].sum = a[i]+a[j];
			e[tot].x = i;
			e[tot].y = j;
			tot++;
		}
	}*/
	int flag  =  0;
	/*for( int i = 0 ; i < tot ; i++ ){
		if( check(-e[i].sum) ){
			flag = 1;
			cout<<a[e[i].x]<<' '<<a[e[i].y]<<' '<<-e[i].sum<<endl;
		}
	}*/
	for( int i = 0 ; i < n ; i++ ){
		for( int j = i + 1 ; j < n ; j ++ ){
			int temp = -a[i]-a[j];
			if( temp <= a[j] ) break;
			if( check(temp) ){
				flag = 1;
				cout<<a[i]<<' '<<a[j]<<' '<<temp<<endl;
			}
		}
	}
	if( !flag ) cout<<"No Solution"<<endl;

	return 0;
}