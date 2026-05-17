#include<bits/stdc++.h>
using namespace std;

int log2(long long n){
    
    if(n==1)return 0;

    int slave_of_result = log2(n/2);
    
    int amar_current_value_er_log = 1+ slave_of_result;

    return amar_current_value_er_log;
    
}

int main(){

    long long n;cin>>n;

    cout<<log2(n);
}