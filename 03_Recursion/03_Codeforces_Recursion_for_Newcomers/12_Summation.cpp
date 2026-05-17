#include<bits/stdc++.h>
using namespace std;

long long summation(vector<int>&v,int idx){
    
    if((v.size()-1) == idx)return v[idx];

    // slave amake 2 to n porjonto value er sum kore dibe, amr kaj tar sathe prothom value add kora
    long long slave_er_dewa_sum = summation(v,idx+1);
    long long current_index_value_soho_sum = slave_er_dewa_sum + v[idx];

    return current_index_value_soho_sum;
}


int main(){

    int n;cin>>n;
    vector<int>v(n);
    for(int &i : v){
        cin>>i;
    }
    cout<<summation(v,0);
}