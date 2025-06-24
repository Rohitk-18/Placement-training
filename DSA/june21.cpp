#include <bits/stdc++.h>
using namespace std;

//1.Minimize Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minL = INT_MAX;
        int sum = 0, left = 0;
        for(int right=0;right<nums.size();right++) {
            sum += nums[right];
            while(sum >= target) {
                minL = min(minL, right - left + 1);
                sum -= nums[left++];
            }
        } 
        return minL == INT_MAX ? 0 : minL;
    }
};

//2.Majority Element II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int candi1 = 0, candi2 = 1; int count1 = 0, count2 = 0;
        for(int num : nums) {
            if(num == candi1) count1++; 
            else if (num == candi2) count2++; 
            else if (count1 == 0) {
                candi1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candi2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int num : nums) {
            if(num == candi1) count1++;
            if(num == candi2) count2++;
        }
        if(count1 > nums.size() / 3) res.push_back(candi1);
        if(count2 > nums.size() / 3) res.push_back(candi2);
        return res;
    }
};

//3.Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1, n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]){ //first element decreasing from end of arr
                piv = i;
                break;
            }
        }
        if(piv == -1) { //means arr is decreasing
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>piv;i--) {
            if(nums[i] > nums[piv]) {
                swap(nums[i],nums[piv]);
                break;
            }
        }
        reverse(nums.begin() + piv + 1,nums.end()); //pivot k baad ke elements
    }
};

//4.Grumpy Bookstore Owner
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0, n = grumpy.size();
        int left = 0, sum = 0,maxS = INT_MIN;
        for(int i=0;i<n;i++) {
            if(grumpy[i] == 0) {
                count += customers[i];
            }
        }
        for(int right = 0;right<n;right++) {
            if(grumpy[right] == 1) {
                sum += customers[right];
            }
            if(right >= minutes) {
                if(grumpy[right - minutes] == 1) {
                    sum -= customers[right - minutes];
                }
            }
            maxS = max(maxS,sum);
        }
        return count + maxS;
    }
};