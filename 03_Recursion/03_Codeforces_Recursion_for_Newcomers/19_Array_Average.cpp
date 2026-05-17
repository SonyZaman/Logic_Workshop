#include<bits/stdc++.h> 
using namespace std;

double average(vector<int>&v,int n){

    if(n==0)return v[n];

    // recursion average ber kore dibe 0-n-2 index porjonto
    double recurison_result = average(v,n-1);
    
    //ami ber korbo n-1 index soho average
    double my_average = ((recurison_result*(n))+v[n])/(n+1);

    return my_average;


}

int main(){

    int n;cin>>n;
    vector<int>v(n);

    for(int &i:v){
        cin>>i;
    }
     cout << fixed << setprecision(6) << average(v,n-1) << endl;

}