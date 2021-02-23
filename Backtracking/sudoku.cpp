//https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

#include<bits/stdc++.h>?
using namespace std;

bool isSafe(int grid[N][N],int l,int m,int n){
    for(int i=0;i<9;i++){
        if(grid[i][n]==l){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(grid[m][i]==l){
            return false;
        }
    }
    int smi = (m/3)*3;
    int smj = (n/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[smi+i][smj+j]==l){
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[N][N],int m,int n){
    if(m==8 and n==9){
        return true;
    }
    if(n==9){
        m++;
        n=0;
    }
    if(grid[m][n]==0){
        for(int l=1;l<=9;l++){
            if(isSafe(grid,l,m,n)){
                grid[m][n]=l;
                if(solve(grid,m,n+1)){
                    return true;
                }
                grid[m][n]=0;
            }
        }
        return false;
    }
    else{
        if(solve(grid,m,n+1)){
            return true;
        }
    }
}


bool SolveSudoku(int grid[N][N])  
{ 
    if(solve(grid,0,0)){
        return true;
    }
    else{
        return false;
    }
    
    
}

void printGrid (int grid[N][N]) 
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}