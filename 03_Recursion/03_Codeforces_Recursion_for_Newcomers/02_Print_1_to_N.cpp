#include<bits/stdc++.h>
using namespace std;

void print_1_to_n(int n){

    if (n==0)return;
    print_1_to_n(n-1);
    // backtracking: operations after recursion call
    // traversal: going from n → 1 (top to bottom)
    // backtracking: coming back from 1 → n (bottom to top)

    cout<<n<<"\n";

}

int main(){

    int n;cin>>n;
    print_1_to_n(n);
}