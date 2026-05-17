#include<bits/stdc++.h>
using namespace std;

long long suffixSum(vector<int>&v,int i){

    if((v.size()-1)==i)return v[i];

    long long slave_er_dewa_sum = suffixSum(v,i+1);
    long long current_index_value_soho_sum = v[i]+slave_er_dewa_sum;
    return current_index_value_soho_sum;
}

int main(){

    int n,index;cin>>n>>index;
    vector<int>v(n);
    for(int &x: v)cin>>x;

    cout<<suffixSum(v,n-index);


}