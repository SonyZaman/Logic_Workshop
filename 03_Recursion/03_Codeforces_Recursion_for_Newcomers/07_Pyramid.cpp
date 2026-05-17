#include<bits/stdc++.h>
using namespace std;

void pyramid(int n,int row){
      
      if(row>n)return;


      //amar kaj pyramid er first row print kora,bakita slave korbe
      for(int i=0;i<(n-row);i++)cout<<" ";
      for (int i=0;i<2*row-1;i++)cout<<"*";
      cout<<'\n';
      pyramid(n,row+1);

}

int main(){
    int n;cin>>n;
    pyramid(n,1);

}