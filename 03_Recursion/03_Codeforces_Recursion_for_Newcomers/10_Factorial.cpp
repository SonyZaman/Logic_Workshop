#include<bits/stdc++.h>
using namespace std;

long long factorial(long long n){

    if(n==0 || n==1)return 1;
    
    // ami shudhu last er value multification korbo, tar ager value er factorial er sathe,ar tar ager value porjonto factorial slave ber kore dibe

    long long ager_value_porjonto_factorial = factorial(n-1);
    long long current_value_er_factorial = n*ager_value_porjonto_factorial;
    return current_value_er_factorial;
}

int main(){

    int n;cin>>n;
    cout<<factorial(n);
}