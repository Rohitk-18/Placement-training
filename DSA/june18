#include <bits/stdc++.h>
using namespace std;

//1.Two Sum 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++) {
            int req = tar - nums[i];
            if(map.find(req) != map.end()) {
                ans.push_back(i);
                ans.push_back(map[req]);
            }
            map[nums[i]] = i;
        }
        
        return ans;
    }
};

//2.Alone in Couple
class Solution {
  public:
    int findSingle(vector<int> &arr) {
        int num = 0;
        for(int i : arr) {
            num ^= i;
        }
        return num;
    }
};

//3. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0; int m=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]<m) {
                m=prices[i];
            } else {
                int p=prices[i]-m;
                ans=max(ans,p);
            }
        }
        return ans;
    }
};

//4.Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
