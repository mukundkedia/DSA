//https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
//KM/gfg 450
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int n,int row,int col,vector<vector<int>>& board){
           int i, j;
 

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
   
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
    }
    
    void solve(int col,int n,vector<int>& combi,vector<vector<int>>& res,vector<vector<int>>& board){
        if(col==n){
            res.push_back(combi);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(n,row,col,board)){
                board[row][col]=1;
                combi.push_back(row+1);
                solve(col+1,n,combi,res,board);
                combi.pop_back();
                board[row][col]=0;
            }
        }
        return;
    }

    vector<vector<int>> nQueen(int n) {
     vector<vector<int>> res;
     vector<int> combi;
     vector<vector<int>> board(n,vector<int>(n,0));
     
     solve(0,n,combi,res,board);
     return res;
    }