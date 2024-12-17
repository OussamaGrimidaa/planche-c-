#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

array <int , 5> t{4,5,10,8,9};
sort(t.begin(),t.end());
vector<int> v;
for(const int& i : t){
    v.push_back(i);
}
for(const int& e : v){
    cout<< e <<" ";
}
}
