#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){

    if(n==1 || n==2) return n-1;
    // baki kaj hocche sesh duita jug kora,,baki gula se nije nije kore nibe
    int second_last = fibonacci(n-2);
    int last = fibonacci(n-1);
    
    int current_fibonacci = second_last+last;
    return current_fibonacci;
}

int main(){
    
    int n;cin>>n;
    cout<<fibonacci(n);

}