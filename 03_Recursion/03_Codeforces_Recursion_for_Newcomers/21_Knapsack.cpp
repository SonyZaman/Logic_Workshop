// #include<bits/stdc++.h>
// using namespace std;


// int knapsack(int num_of_items, int index_num_of_items,int total_capacity,int capacity_stored,vector<pair<int,int>>value_weights,bool pick){
    
   
//     if((num_of_items-1)==index_num_of_items && pick==true){
//         return value_weights[index_num_of_items].second;
//     }
//      if((num_of_items-1)==index_num_of_items && pick==false){
//         return 0;
//     }
   
//     if((num_of_items-1)>index_num_of_items && pick==true) {
//         capacity_stored+=value_weights[index_num_of_items].first;
//         index_num_of_items+=1;    
//     }
//     if((num_of_items-1)>index_num_of_items && pick==false) {
//         index_num_of_items+=1;    
//     }
    


    
   

//     //dhore nibo slave already root node er duita branch er jonno max ber kore diche
//     int yes_pick_max = knapsack(num_of_items,index_num_of_items,total_capacity,capacity_stored,value_weights,true);
//     int not_pick_max = knapsack(num_of_items,index_num_of_items,total_capacity,capacity_stored,value_weights,false);

   

//     //ami shudhu root node er ta check korbo nibo naki nibo na
//      int max_weight_pick = max(yes_pick_max,not_pick_max);
    

//     return max_weight_pick;

// }

// int main(){
    
//     int num_of_items,total_capacity;
//     vector<pair<int,int>>value_weights;




// }

#include<bits/stdc++.h>
using namespace std;

int main(){

    int a=5;
    int *p = &a;
    int &b = a;

    cout<<a<<"\n";
    cout<<b<<"\n";
    cout<<p<<"\n";

    cout<<&a<<"\n";
    cout<<&b<<"\n";
    cout<<&p<<"\n";

    
}