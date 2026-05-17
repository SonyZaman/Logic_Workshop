#include<bits/stdc++.h>
using namespace std;

void print_n_to_1(int n){

   
    if (n==1) {cout<<1;return;}
    
    // traversal: going from n → 1 (top → bottom)
    // forward: operation before recursion call
    cout<<n<<" ";
    print_n_to_1(n-1);

}

int main(){

    int n;cin>>n;
    print_n_to_1(n);
}