#include<bits/stdc++.h>
using namespace std;


void binaryConverssion(int n){
    

    if (n==0)return;
    //traversal: n to 0
    //backtracking : 0 to n
    binaryConverssion(n/2);
    cout<<n%2;

}

int main(){
    
    int t;cin>>t;while(t--){
    int n;cin>>n;
    binaryConverssion(n);cout<<"\n";}

}