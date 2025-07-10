#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1 Combination Sum II 
class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans, int idx, int tar) {
        if(tar == 0) {
            ans.push_back(comb);
            return;
        } 
        for(int i=idx;i<candidates.size();i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue; //skip duplicates
            if(candidates[i] > tar) break;
            comb.push_back(candidates[i]);
            helper(candidates, comb, ans, i + 1, tar - candidates[i]); //move to next index
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int tar) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(),candidates.end());
        helper(candidates,comb,ans,0,tar);
        return ans;
    }
};

//2 Find All Groups of Farmland
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(land[i][j] == 1) {
                    int r = i, c = j;

                    while(r + 1 < m && land[r + 1][j] == 1) r++;
                    while(c + 1 < n && land[i][c + 1] == 1) c++;

                    for(int x=i;x<=r;x++) {
                        for(int y=j;y<=c;y++) { 
                            land[x][y] = 0;
                        }
                    }
                    ans.push_back({i,j,r,c});
                }
            }
        }
        return ans;
    }
};

//3 Rat in A Maze - I
class Solution {
  public:
  
    void helper(vector<vector<int>>& maze, vector<string>& ans, 
                vector<vector<int>>& visited, string path, int n, 
                int i, int j) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        if(i < 0 || j < 0 || i >= n || j >= n 
        || maze[i][j] == 0 || visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        helper(maze,ans,visited,path + "D",n,i+1,j); //down
        helper(maze,ans,visited,path + "L",n,i,j-1); //left
        helper(maze,ans,visited,path + "R",n,i,j+1); //right
        helper(maze,ans,visited,path + "U",n,i-1,j); //up
        
        visited[i][j] = 0;
    }  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string path = "";
        int n = maze.size();
        vector<vector<int>> visited (n,vector<int>(n,0));
        
        if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return ans;
        
        helper(maze,ans,visited,path,n,0,0);
        return ans;
    }
};