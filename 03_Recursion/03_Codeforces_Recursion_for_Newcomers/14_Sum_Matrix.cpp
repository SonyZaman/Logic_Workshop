#include<bits/stdc++.h>
using namespace std;

void matrixSum(vector<vector<int>>&v,vector<vector<int>>&v2,vector<vector<int>>&sum,int rows,int cols,int totalRows,int totalCols){
         
        if (rows>totalRows)return;
        matrixSum(v,v2,sum,(cols==totalCols)?rows+1:rows,(cols==totalCols)?0:cols+1,totalRows,totalCols);
        int amar_index_sum = v[rows][cols]+v2[rows][cols];
        sum[rows][cols]= amar_index_sum;

      
}


int main()
{
int rows, cols; cin>>rows>>cols;
vector<vector<int>> arr(rows, vector<int>(cols));
vector<vector<int>> arr2(rows, vector<int>(cols));
vector<vector<int>> sum(rows, vector<int>(cols));

for (auto &row : arr) {
    for (auto &val : row) {
        cin >> val;
    }
}
for (auto &row : arr2) {
    for (auto &val : row) {
        cin >> val;
    }
}

matrixSum(arr,arr2,sum,0,0,rows-1,cols-1);

for (auto &row : sum) {
    for (auto &val : row) {
        cout<< val<<" ";
    }
    cout<<"\n";
}

}