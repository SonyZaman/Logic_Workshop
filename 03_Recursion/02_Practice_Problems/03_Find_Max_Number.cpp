#include<bits/stdc++.h>
using namespace std;


int findMax(vector<int>&v,int index){

     // base case
     // When I reach the last value after all recursive calls, there is only one element left in the array, so that value itself is the maximum
    if(index == v.size() - 1) return v[index];

    // i call recursion before other operation, so backtracking
    int recursion_je_max_value_diyeche = findMax(v,index+1);
    int amar_value_naki_owr_dewa_value_boro = (v[index] >= recursion_je_max_value_diyeche)  ? v[index]:recursion_je_max_value_diyeche;
    int maxValue = amar_value_naki_owr_dewa_value_boro;
    return maxValue;
}

int main(){

    vector<int> nums ={5,2,20,6,3,7};
    cout<<findMax(nums,0);

}