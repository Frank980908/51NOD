#include <bits/stdc++.h>
using namespace std;
const int AX = 2e5+666;
int mark[AX];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n , k , a , q;
	cin >> n >> k >> a >> q;
	//FILE * fp1 = fopen("51nod_Problem_1521_Test_20_In.txt","r");
	//fscanf(fp1,"%d%d%d%d",&n,&k,&a,&q);
	int flag = 1;
	int num = (n+1)/(a+1);
	int x;
	memset(mark,0,sizeof(mark));
	for( int i = 0 ; i < q ; i++ ){
		//fscanf(fp1,"%d",&x);
		cin >> x;
		int l = x-1 , r = x+1;
		mark[x] = 1;
		while(l >= 1 && !mark[l] ) l -- ;
		while(r <= n && !mark[r] ) r ++ ;
		num -= (r-l)/(a+1) - (x-l)/(a+1) - (r-x)/(a+1);
		if( num < k ){
			cout << i + 1 << endl;
			flag = 0;
			break;
		}
	}
	if(flag) cout << "-1" << endl;
	return 0;
}