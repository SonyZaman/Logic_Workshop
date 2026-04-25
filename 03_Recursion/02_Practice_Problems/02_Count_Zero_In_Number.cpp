#include<bits/stdc++.h>
using namespace std;

int countZero(int n){

    if(n==0)return 0;

    // i call recursion before other operation, so backtracking
    int recursion_amake_dibe = countZero(n/10);
    int last_digit = n%10;
    int return_korbo = last_digit==0? recursion_amake_dibe+1: recursion_amake_dibe;
    return return_korbo;
}

int main(){

    int n;
    cin>>n;
    //if input only 0
    if(n==0){
    cout<<1;
    return 0;
    }
    cout<<countZero(n)<<"\n";

}