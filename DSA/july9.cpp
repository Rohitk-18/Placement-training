#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1 Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        int a = 1,  b = 2;
        for(int i=3;i<=n;i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

//2 Subsets
class Solution {
public:
    void getsubset(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back({curr});
            return;
        }
        curr.push_back(nums[i]);
        getsubset(nums,i + 1,curr,res);

        curr.pop_back();
        getsubset(nums,i + 1,curr,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int i = 0;
        getsubset(nums,i,curr,res);
        return res;
    }
};

//3 House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]); //max(dont rob at curr only till i-1, rob at curr, i-2 + nums[i])
        }
        return dp[n - 1];
    }
};

//4 House Robber 2
class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for(int i=start;i<=end;i++) {
            int curr = max(prev1,prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int cand1 = helper(nums, 0, n - 2);
        int cand2 = helper(nums, 1, n - 1);
        return max(cand1, cand2);
    }
};