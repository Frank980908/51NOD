#include <bits/stdc++.h>
using namespace std;
priority_queue<int , vector<int> , greater<int> >q;
int main(){
	int n;
	cin >> n;	
	int x;
	for( int i = 0 ; i < n ; i++ ){
		cin >> x;
		q.push(x);
	}
	int res = 0;
	while( q.size() > 1 ){
		int t1 = q.top();
		q.pop();
		int t2 = q.top();
		q.pop();
		int tmp = t1 + t2;
		res += tmp;
		q.push( tmp );
	}
	cout << res << endl;
	return 0 ;
}