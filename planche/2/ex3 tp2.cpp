#include<iostream>
using namespace std;

int in_adr(int *x){
return ++(*x);
}

void per_adr(int *x , int *a){
int z;

z=*x;
*x=*a;
*a=z;
}
void in_ref (int &x){
 x++;
}

void per_ref(int &x ,int &a){
int z;

z=x;
x=a;
a=z;
}

int main(){
int x=40;
int a=35;
x=in_adr(&x);
cout << "incrementer par adresse "<< x << endl;

per_adr(&x,&a);
cout <<" permeter par adresse "<< x << a << endl;

in_ref(x);
cout << "incrementer par reference "<< x <<endl;

per_ref(x,a);

cout <<"premeter par reference "<< x << a << endl;


}
