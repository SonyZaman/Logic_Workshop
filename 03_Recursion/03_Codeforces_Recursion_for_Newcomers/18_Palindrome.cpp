#include<bits/stdc++.h>
using namespace std;

bool palindrome(vector<int>&v,int i,int j){

     if(i>j )return true;

     // slave check korbe index 1 to n-2 porjnto 
     // ami check korbo 0,n-1 
     bool recursion_check_korche = palindrome(v,i+1,j-1);
     bool my_check;
     my_check=(v[i]==v[j])?true:false;
     
     bool return_korbe = my_check && recursion_check_korche;
     return return_korbe;

}

int main(){

    int n;cin>>n;
    vector<int>v(n);
    for(int &i:v)cin>>i;

    (palindrome(v,0,n-1))?cout<<"YES":cout<<"NO";

}