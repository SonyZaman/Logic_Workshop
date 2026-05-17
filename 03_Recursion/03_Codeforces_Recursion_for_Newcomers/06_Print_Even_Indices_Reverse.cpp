#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v,int idx){

    if(idx>=v.size())return;
    
    //After slave has printed rest even indices in reverse, i will print first
    print(v,idx+2);
    cout<<v[idx]<<" ";
}

int main(){

    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;v.push_back(x);
    }

    print(v,0);
}