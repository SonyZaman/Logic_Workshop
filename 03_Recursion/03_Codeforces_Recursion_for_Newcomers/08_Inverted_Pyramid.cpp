#include<bits/stdc++.h>
using namespace std;

void pyramid(int n,int row){
      
      if(row>n)return;


      pyramid(n,row+1);
      for(int i=0;i<(n-row);i++)cout<<" ";
      for (int i=0;i<2*row-1;i++)cout<<"*";
      cout<<'\n';
      

}

int main(){
    int n;cin>>n;
    pyramid(n,1);

}