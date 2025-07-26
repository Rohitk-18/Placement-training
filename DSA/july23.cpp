#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {
    int s=0,e=nums.size()-1;
    while(s<=e) {
        int m=s+(e-s)/2;
        if(nums[m]==target) {
            return m;
        }  
        if (nums[s]<=nums[m]) { //left part sorted hai?
            if(nums[s]<=target && target<=nums[m]) { //sorted array me target hai?
                e=m-1;
            } else {
                s=m+1;
            }
        } else { //right part sorted hai?
            if(nums[m]<=target && target<=nums[e]) { //sorted array me target hai? 
                s=m+1;
            } else {
                e=m-1;
            }
        }
    }
    return -1;
}

//2. Find Peak Element
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

//3. Allocate Minimum Pages 
bool isValid(vector<int> &arr, int n, int m, int maxPage) {
    int stud = 1, page = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] > maxPage) return false;
        if(arr[i] + page <= maxPage) {
            page += arr[i];
        } else {
            stud++;
            page = arr[i];
        }
    }
    return stud <=m;
}
  
int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if(k > n) return -1; //students more than books
    int s = 0, ans = s;
    s = accumulate(arr.begin(), arr.end(), s);
    int start = 0, end = s; //possible range of values
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isValid(arr, n, k, mid)) { //found a possible value
            ans = mid;
            end = mid - 1; //look for more smaller value
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

//4. Minimum Number of Days to Make Bouquets
bool check(vector<int> &bloomDay, int m, int k, int d) {
    int b = 0, f = 0;
    for(int i : bloomDay) {
        if (i <= d) {
            f++;
            if(f == k) {
                b++;
                f = 0;
            }
        } else f = 0;
    }
    return b >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long int n = bloomDay.size();
    long long int q = (long long) m*k;
    if (q > n) return -1;
    else {
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r){
            int mi = l + (r - l) / 2;
            if (check(bloomDay, m, k, mi)) r = mi - 1;
            else l = mi + 1;
        }
        return l;
    }
} 