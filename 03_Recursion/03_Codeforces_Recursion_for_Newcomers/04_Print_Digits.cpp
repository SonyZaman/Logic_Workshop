#include<bits/stdc++.h>
using namespace std;

void printDigits(long long n){

   if (n==0)return ;
   
   // i have to traverse from last to first, because it's easy to get last digit from a number, but i need to print from first to last, so backtracking is an easy approach

   // After  my slave (recursion) has printed rest, i will print last digit, 

   printDigits(n/10);
   cout<<n%10<<" ";



   
}

int main(){
    int t;
    cin>>t;
    while(t--){
    long long n;cin>>n;
    if(n==0){cout<<n<<"\n";continue;}
    printDigits(n);cout<<'\n';}

}