#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Task Scheduler 
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char task : tasks) freq[task - 'A']++;
    int maxFreq = *max_element(freq.begin(), freq.end());

    int maxCount = count(freq.begin(), freq.end(), maxFreq);

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + maxCount;
    return max((int)tasks.size(), emptySlots);
}

//2. Split Array Largest Sum
bool Possible(int mid, vector<int>& nums, int k) {
    int count = 1, sum = 0;
    for (int num : nums) {
        if (sum + num > mid) {
            count++;
            sum = num;
        } else sum += num;
    }
    return count <= k;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (Possible(mid, nums, k)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

//3. Invalid Transaction
vector<string> invalidTransactions(vector<string>& transactions) {
    struct Transaction {
        string name, city, raw;
        int time, amount;
    };
    vector<Transaction> all; vector<string> result;
    for (string& t : transactions) {
        stringstream ss(t);
        string name, timeStr, amtStr, city;
        getline(ss, name, ','); getline(ss, timeStr, ',');
        getline(ss, amtStr, ','); getline(ss, city, ',');
        all.push_back({name, city, t, stoi(timeStr), stoi(amtStr)});
    }
    unordered_set<int> invalid;
    int n = all.size();
    for (int i=0;i<n;i++) {
        if (all[i].amount > 1000) invalid.insert(i);
        for (int j=0;j<n;j++) {
            if (i == j) continue;
            if (all[i].name == all[j].name &&
                abs(all[i].time - all[j].time) <= 60 &&
                all[i].city != all[j].city) {
                invalid.insert(i);
                break; 
            }
        }
    }
    for (int i : invalid) result.push_back(all[i].raw);   
    return result;
}

//4. Frequency of Most Frequent Element
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long total = 0; //current window sum
    int left = 0, result = 0;

    for (int right=0;right<nums.size();right++) {
        total += nums[right];
        while ((long long)nums[right] * (right - left + 1) - total > k) {
            total -= nums[left];
            left++;
        }
        result = max(result, right - left + 1);
    }
    return result;
}