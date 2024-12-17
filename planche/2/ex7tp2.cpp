#include <iostream>

using namespace std;

int recrusive( int n){

if (n == 0) {
    return 3;
}else{
    return 3 * recrusive(n-1) + 4 ;

}

}
int main(){
int n;
cin >> n;
cout << recrusive(n) ;

}
