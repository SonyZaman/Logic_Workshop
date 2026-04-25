#include<bits/stdc++.h>
using namespace std;

bool checkSort(int n,int i,vector<int>&v){

      if(i==(n-1))return true;
      
      // i call recursion before other operation, so backtracking
      bool recursion_amake_dibe = checkSort(n,i+1,v);
      bool amar_result = false;

      if(v[i]<=v[i+1])amar_result =true;

      bool return_korbo = recursion_amake_dibe && amar_result;
      
      return return_korbo;

}

int main(){


    // cout<<"Enter number: ";
    // int n;
    // cin>>n;
    // vector<int>vec(n);
    // for(int &i:vec){
    //     cin>>i;
    // }

    vector<int> v = {1,4,6,9,11};
    cout<<checkSort(v.size(),0,v)<<"\n";

    vector<int> v2 = {1,4,6,9,11,10};
    cout<<checkSort(v2.size(),0,v2)<<"\n";


}