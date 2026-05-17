#include<bits/stdc++.h>
using namespace std;

int sequence(int n){

    if(n==1)return 1;

    int recursion_result = sequence((n%2==0)?n/2:3*n+1);
    int current_index_soho_length = 1+recursion_result;

    return current_index_soho_length;


}

int main(){

    int n;cin>>n;
    cout<<sequence(n);
    
}