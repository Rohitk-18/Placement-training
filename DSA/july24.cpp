#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Search in a 2D Matrix 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0){ 
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

//2. Koko Eating Bananas
bool possible(vector<int> &piles, int h, int speed){ 
    long long int hours = 0;
    for(int p : piles){ 
        hours += (1LL * p + speed - 1) / speed; //ceil(piles/speed)
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1, end = *max_element(piles.begin(), piles.end());
    int ans = end;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(possible(piles, h, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

//3. Find Peak Element II 
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    int low = 0, high = col - 1;
        
    while(low <= high) {
        int midc = low + (high - low) / 2;
        int maxr = 0;
        for(int i=0;i<row;i++) {
            if(mat[i][midc] > mat[maxr][midc]) {
                maxr = i; //row with max value in mid column
            }
        }
        int left = (midc - 1) >= 0 ? mat[maxr][midc - 1] : -1;
        int right = (midc + 1) < col ? mat[maxr][midc + 1] : -1;
        if(mat[maxr][midc] > left && mat[maxr][midc] > right) {
            return {maxr, midc};
        } else if (mat[maxr][midc] < left) {
            high = midc - 1;
        } else if (mat[maxr][midc] < right) {
            low = midc + 1;
        }
    }
    return {-1,-1};
}

//4. H-Index
int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    int h = 0;
    for(int i=0;i<n;i++) {
        int papers = n - i;
        if(citations[i] >= papers) {
            h = papers;
            break;
        }
    }
    return h;
}