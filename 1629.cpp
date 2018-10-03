#include <bits/stdc++.h>
#define pi 3.1415926
using namespace std;
int main(){
	double s;
	cin >> s;
	double res = s/6*s/sqrt(2*pi*s);
	printf("%.6lf\n",res);
	return 0;
}