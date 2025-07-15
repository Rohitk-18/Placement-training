#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Palindrome Partitioning
class Solution {
public:
    bool ispalin(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return s1 == s;
    }
    void getpart(string s,vector<string>& part,vector<vector<string>>& ans) {
        if(s.length() == 0) {
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.length();i++) {
            string pa = s.substr(0,i + 1);
            if(ispalin(pa)) {
                part.push_back(pa);
                getpart(s.substr(i + 1),part,ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        getpart(s,part,ans);
        return ans;
    }
};

//2. Fair Distribution of Cookies
class Solution {
public:
    int minfair = INT_MAX;
    void back(vector<int> &child, vector<int> &cookies, int index, int k) {
        if(index == cookies.size()) {
            int maxcook = *max_element(child.begin(),child.end());
            minfair = min(minfair,maxcook);
            return;
        }
        for(int i=0;i<k;i++) {
            if(child[i] + cookies[index] >= minfair) {
                continue;
            }
            child[i] += cookies[index];
            back(child,cookies,index + 1,k);
            child[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k,0);
        back(child,cookies,0,k);
        return minfair;
    }
};

//3. N-Queens
class Solution {
public:
    bool safe(vector<string>& board,int row,int col,int n) {
        for(int j=0;j<n;j++) { //horizontal
            if(board[row][j] == 'Q') {
                return false;
            }
        }
        for(int i=0;i<n;i++) { //vertical
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        for(int i=row,j=col; i>=0 && j>=0; i--,j--) { //left diagonal
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=row,j=col; i>=0 && j<n; i--,j++) { //right diagonal
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true; 
    }
    void queen(vector<string>& board,vector<vector<string>>& ans,int row,int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++) {
            if(safe(board,row,j,n)) {
                board[row][j] = 'Q';
                queen(board,ans,row + 1,n);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        int r = 0;
        queen(board,ans,r,n);
        return ans;
    }
};