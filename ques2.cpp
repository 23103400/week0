#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows,col;
    cin>>rows>>col;
    vector<vector<int>>matrix(rows,vector<int>(col));
    for(int i = 0;i<rows;i++){
        for(int j=0;j<col;j++){
            int val ;
            cout<<"enter elements of matrix";
            cin>>val;
            matrix[i][j]=val;
        }
    }
    for(int i = 0;i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
            
        }
        cout<<" "<<endl;
    }
    vector<vector<int>>transpose(col,vector<int>(rows));
    for(int i =0;i<col;i++){
        for(int j =0;j<rows;j++){
            transpose[i][j]=matrix[j][i];
            
        }
    }
    for(int i = 0;i<col;i++){
        for(int j=0;j<rows;j++){
            cout<<transpose[i][j]<<" ";
            
        }
        cout<<" "<<endl;
    }
    return 0 ;
}
