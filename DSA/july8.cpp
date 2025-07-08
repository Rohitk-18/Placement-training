#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Flood Fill
class Solution {
public:
    void helper(vector<vector<int>>& image, int i, int j, int color, int initialC) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != initialC || image[i][j] == color) {
            return;
        }
        image[i][j] = color;
        helper(image, i + 1, j, color, initialC);
        helper(image, i - 1, j, color, initialC);
        helper(image, i, j + 1, color, initialC);
        helper(image, i, j - 1, color, initialC);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialC = image[sr][sc];
        if(initialC != color) {
            helper(image,sr,sc,color,initialC);
        }
        return image;
    }
};

//2. Count Good Numbers
class Solution {
public:

    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while(exp > 0) {
            if(exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenpos = (n + 1) / 2;
        long long oddpos = n / 2;

        long long evencnt = power(5,evenpos,MOD);
        long long oddcnt = power(4,oddpos,MOD);

        return (oddcnt * evencnt) % MOD;
    }
};

//3. Permutation ||
class Solution {
public:
    void getperm(vector<int>& nums, vector<vector<int>>& res, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for(int idx=i;idx<nums.size();idx++) {
            if (used.count(nums[idx])) continue;
            used.insert(nums[idx]);
            swap(nums[i],nums[idx]);
            getperm(nums,res,i + 1);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int i = 0;
        getperm(nums,res,i);
        return res;
    }
};

//4. Rabbits in Forest
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        for(int a : answers) {
            map[a]++;
        }
        int total = 0;
        for(auto &p : map) {
            int x = p.first;
            int count = p.second;
            int grsize = x + 1;
            int groups = (count + x) / grsize;
            total += groups * grsize;
        }
        return total;
    }
};