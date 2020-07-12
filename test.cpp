#include<iostream>
using namespace std;

void end(){
    cout << "end"<<endl;
}

void __test(int l, int r){
   // cout << "运算前： l= " << l<<" r= "<<r;
    if(l >= r)return;
    int mid = (l + r) /2;
   // cout << "运算后： l= " << l<<" r= "<<r <<" mid= "<<mid<< endl;
    __test(l,mid);
    cout << "test 1"<<endl;
    __test(mid+1,r);
    cout << "test 2" << endl;
    // end();

}

int main()
{
    int l = 0;
    int r = 8;
    __test(l,r);
    return 0;
}