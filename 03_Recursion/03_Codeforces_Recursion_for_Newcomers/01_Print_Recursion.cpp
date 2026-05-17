#include<bits/stdc++.h>
using namespace std;

void printRecursion(int n){
     

     if(n==0)return;
     // my work
     cout<<"I love Recursion\n";

     // rest of work will do my slave
     // traversal: going from n → 1 (top to bottom)
    // forward-> i call recursion after all operations
     printRecursion(n-1);


}

int main(){

    int n;cin>>n;
    printRecursion(n);
}