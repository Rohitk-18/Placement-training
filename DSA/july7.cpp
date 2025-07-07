#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Letter Combinations
class Solution {
public:
    void getcomb(vector<string>& result, string& curr, const string& digits, int index, const vector<string>& map) {
        if(index == digits.size()) {
            result.push_back(curr);
            return;
        }
        string letters = map[digits[index] - '0'];
        for(char c : letters) {
            curr.push_back(c);
            getcomb(result,curr,digits,index + 1,map);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> result;
        string curr;
        vector<string> map = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        getcomb(result,curr,digits,0,map);
        return result;
    }
};

//2. Combination Sum
class Solution {
public:
    set<vector<int>> set;
    void helper(vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans, int idx, int tar) {
        if(idx == candidates.size() || tar < 0) return;
        else if (tar == 0) {
            if(set.find(comb) == set.end()) {
                ans.push_back(comb);
                set.insert(comb);
            }
        }
        comb.push_back(candidates[idx]);
        helper(candidates,comb,ans,idx + 1,tar - candidates[idx]); //single inclusion
        helper(candidates,comb,ans,idx,tar - candidates[idx]); //multiple inclusion
        comb.pop_back(); //exclusion
        helper(candidates,comb,ans,idx + 1,tar);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int tar) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(candidates, comb, ans, 0,tar);
        return ans;
    }
};

//3. Permutations
class Solution {
public:
    void getperm(vector<int>& nums, vector<vector<int>>& res,int i) {
        if(i == nums.size()) { //base case
            res.push_back({nums});
            return;
        }
        for(int idx=i;idx<nums.size();idx++) {
            swap(nums[i],nums[idx]); //inclusion
            getperm(nums,res,i + 1); //inclusion
            swap(nums[i],nums[idx]); //backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int i = 0;
        getperm(nums,res,i);
        return res;
    }
};