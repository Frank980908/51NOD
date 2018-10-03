#include <bits/stdc++.h>
#define LL unsigned long long 
using namespace std;
int main(){
    LL n;
    cin >> n ;
    if( n == 1 || n == 2 ) cout << n << endl;
    else if( n & 1 ){
        cout << n * (n-1) * (n-2) << endl;
    }else{
        if( n % 3 ){
            cout << n * ( n - 1 ) * ( n - 3) << endl;
        }else{
            cout << ( n - 1 ) * ( n - 2 ) * (n-3) << endl;
        }
    }
    return 0 ;
}