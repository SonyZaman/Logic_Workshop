#include<bits/stdc++.h>
using namespace std;

int countVowels(string s,int idx){
    
    if(s.length()==idx)return 0;

    // slave amake baki characters er vowel count kore dibe, ami just first er ta check kore count korbo
    int recursion_count_kore_dise = countVowels(s,idx+1);
    int count=recursion_count_kore_dise;
    int amar_index_check = (s[idx]=='A'||s[idx]=='E'||s[idx]=='I'||s[idx]=='O'||s[idx]=='U'||s[idx]=='a'||s[idx]=='e'||s[idx]=='i'||s[idx]=='o'||s[idx]=='u')?count++:count;

    return count;

}

int main(){
    
    string s;
    getline(cin,s);
    cout<<countVowels(s,0);
}