#include<bits/stdc++.h>
using namespace std;

int maxNumber(vector<int>&v,int idx){
    
    if((v.size()-1)==idx)return v[idx];

    // second theke last value er moddhe max slave ber kore dibe, ar ami first er ta er sathe compare korbo

    int recursion_dewa_max = maxNumber(v,idx+1);
    int current_Index_Value = v[idx];
    int konta_boro = (v[idx]>=recursion_dewa_max)?v[idx]:recursion_dewa_max;
    return konta_boro;
}


int main(){
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;v.push_back(x);
    }
    cout<<maxNumber(v,0);
}