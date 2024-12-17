#include <iostream>
using namespace std;

bool pval( int a , int b){
return a==b;
}
bool padr(int *a, int *b) {
    return *a == *b;
}
bool pref(int &a, int &b) {
    return a == b;
}

int main(){
int a=5;
int b=5;

cout << pval(a,b) << endl;
cout << padr(&a,&b) << endl;
cout << pref(a,b) << endl;

}
