#include <bits/stdc++.h>
using namespace std;

//1.Reverse digit solution

int reverseDigits(int n) {
    int rev = 0;
    while(n > 0) {
        int rem = n % 10;
        n /= 10;
        rev = rev * 10 + rem;
    }
    return rev;
}

//2.Search Insert Position

int searchInsert(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++) {
        if(nums[i]==target) {
            return i;
        }
    }
    if(target>nums[nums.size()-1]) {
        return nums.size();
    } else {
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]<target && target<nums[i+1]) {
                return i+1;
            }
        }
    }
    return 0;
}

//3.Single number

int singleNumber(vector<int>& nums) {
    int a=0;
    for(int i: nums) {
        a=a^i; //xor use
    }
    return a;
}

//4.Missing number

int missingNumber(vector<int>& nums) {
    int r=-1;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++) {
        if(i!=nums[i]) {
            r=i;
            return r;
        }
    }
    if(r==-1) {
        return nums.size();
    } else {
        return r;
    }
}
        
