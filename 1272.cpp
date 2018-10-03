#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int AX = 5e4+66;
struct Node
{
	int val;
	int id;
	int pre;
}a[AX];
bool cmp( const Node &a , const Node &b ){
	if( a.val == b.val ) return a.id < b.id;
	else return a.val < b.val;
}
int main(){
	int n;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i].val);
		a[i].id = i;
	}
	for( int i = 0 ; i < n ; i++ ){
		a[i].pre = 0;
	}
	sort( a , a + n , cmp );
	stack<Node>q;
	int maxum = 0;
	q.push(a[0]);
	for( int i = 1 ; i < n ; i++ ){
		while( true ){
			Node tmp = q.top();
			if( tmp.id < a[i].id ){
				maxum = max( maxum , a[i].id - ( tmp.id - tmp.pre ) );
				q.pop();
				a[i].pre =  max ( a[i].pre , a[i].id - ( tmp.id - tmp.pre ) );
				if( q.empty() ){ q.push(a[i]); break; }
			}else{
				q.push(a[i]);
				break;
			}
		}
		
	} 
	printf("%d\n",maxum);
	return 0;
}