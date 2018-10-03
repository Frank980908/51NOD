#include <stdio.h>
#include <algorithm>
using namespace std;
const int AX = 4e5+666;
struct Node
{
	int sy , sm , sd;
	int ey , em , ed;
	int x;
}a[AX];
bool cmp( const Node &a , const Node &b ){
	return a.x < b.x;
}
int main(){
	int n ;
	int Sy, Sm, Sd , Ey , Em, Ed , x;
	int tot = 0;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d%d%d%d%d%d%d",&Sy,&Sm,&Sd,&Ey,&Em,&Ed,&x);
		if( Ey - Sy >= 2 || ( Ey == Sy && Em - Sm >= 2 ) || ( Ey == Sy && Em - Sm == 1 && Ed >= Sd )
			|| ( Ey - Sy == 1 && Em >= 2 ) || ( Ey - Sy == 1 && Sm == 12 && Ed >= Sd ) 
			|| ( Ey - Sy == 1 && Sm <= 11 ) ){
			a[tot].sy = Sy ; a[tot].sm = Sm; a[tot].sd = Sd;
		a[tot].ey = Ey ; a[tot].em = Em; a[tot].ed = Ed;
		a[tot++].x = x ;
	}  
}
sort( a , a + tot , cmp );
int q;
scanf("%d",&q);
int y , m , d;
while( q-- ){
	int res = 0;
	int ans[201];
	scanf("%d%d%d",&y,&m,&d);
	for( int i = 0 ; i < tot ; i++ ){
		Node tmp = a[i];
		if( y < tmp.sy || y > tmp.ey ) continue;
		if( y == tmp.sy ){
			if( m < tmp.sm ) continue;
			else if( m == tmp.sm && d < tmp.sd ) continue;
		}
		if( y == tmp.ey ){
			if( m > tmp.em ) continue;
			else if( m == tmp.em && d > tmp.ed ) continue;
		}
		ans[res++] = tmp.x;
	}
	printf("%d ",res);
	if( !res ) printf("\n");
	if( res ){
		for( int i = 0 ; i < res ; i++ ){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}
return 0;
}