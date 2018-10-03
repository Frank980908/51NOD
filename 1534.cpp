#include <bits/stdc++.h>
using namespace std;
int main(){
	int x1 , y1 , x2 ,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int falg = 1;
	if( x2 >= x1 && y2 >= y1 ){
		falg = 0;
	}else{
		if( x1 + y1 <= max(x2,y2) ){
			falg = 0;
		}
	}
	cout << ( falg ? "Vasiliy" : "Polycarp" ) << endl;
	return 0;
}