#include<bits/stdc++.h>
using namespace std;


long long nCr(int n,int r){
    
    if(r==0)return 1;
     //recursion result dise 
     long long rec_result = nCr(n-1,r-1);

     long long result_after_current_mul = (rec_result*n)/r;

     return result_after_current_mul;
} 


int main(){

    int n,r;
    cin>>n>>r;

    cout<<nCr(n,r);
}
