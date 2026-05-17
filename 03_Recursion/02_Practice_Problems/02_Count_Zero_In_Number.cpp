#include<bits/stdc++.h>
using namespace std;

int countZero(int n){

    if(n==0)return 0;

    // I call recursion first, so this is backtracking
    // traversal: last → first (digit by digit)
    // backtracking: first → last
    // After my salve has done rest, I will check last digit 0 or not and count
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