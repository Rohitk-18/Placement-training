#include <bits/stdc++.h>
using namespace std;

//1.Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++) {
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};

//2.3 Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if (n<3) {
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r) {
                int s=nums[i]+nums[l]+nums[r];
                if(s==0) {
                    ans.push_back({nums[i], nums[l], nums[r]}); l++; r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                } else if(s<0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};

//3.Maximum Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int crr = 0, max1 = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) {
                crr++;
                max1 = max(crr,max1); 
            } else {
                crr = 0;
            }
        }
        return max1;
    }
};

//4.Design Twitter
class Twitter {
private: 
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
        time  = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++,tweetId);
    }
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed;
        following[userId].insert(userId);
        for (int followee : following[userId]) {
            for (auto &tweet : tweets[followee]) {
                feed.push_back(tweet);
            }
        }
        sort(feed.rbegin(), feed.rend());
        vector<int> result;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            result.push_back(feed[i].second);
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};