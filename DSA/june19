#include <bits/stdc++.h>
using namespace std;

//1.Find the Town Judge
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n + 1,0);
        vector<int> in(n + 1,0);
        for(auto &p : trust) {
            out[p[0]]++;
            in[p[1]]++;
        }

        for(int i=1;i<=n;i++) {
            if(out[i] == 0 && in[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

//2.Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--) {
            if(digits[i]<9) {
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

//3.Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ms=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            cs+=nums[i];
            ms=max(ms,cs);
            if(cs<0) {
                cs=0;
            }
        }
        return ms;
    }
};

//4.Assign Cookies
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int child = 0, cook = 0;
        while(child < g.size() && cook < s.size()) {
            if(s[cook] >= g[child]) {
                child++;
            } 
            cook++;
        }
        return child;
    }
};