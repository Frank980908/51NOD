#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct Node
{
	LL t; 
	LL val;
};
struct cmp1{
	bool operator() ( Node a , Node b ){
		if( a.t == b.t ) return a.val < b.val;
		else return a.t > b.t;
	}
};
struct cmp2{
	bool operator() ( Node a , Node b ){
		if( a.val == b.val ) return a.t > b.t;
		else return a.val > b.val;
	}
};
int main(){
	priority_queue<Node , vector<Node> , cmp1 > q; 
	priority_queue<Node , vector<Node> , cmp2 > c; 
	LL n ;
	cin >> n;
	LL time , value ;
	Node tmp0 ;
	for( int i = 0 ; i < n ; i ++ ){
		cin >> time >> value;
		tmp0.t = time ;
		tmp0.val = value;
		q.push(tmp0);
	}
	while( !q.empty() ){
		Node tmp = q.top();
		q.pop();
		LL size = c.size();
		if( size < tmp.t ){
			c.push(tmp);
		}else{
			Node tmp2 = c.top();
			if( tmp2.val < tmp.val ){
				c.pop();
				c.push(tmp);
			}
		}
	}
	LL res = 0;
	while( !c.empty() ){
		Node tmp = c.top();
		res += tmp.val;
		c.pop();
	}
	cout << res << endl;
	return 0;
}