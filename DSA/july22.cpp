#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Merge sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while(i < left.size()) arr[k++] = left[i++];
    while(j < right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    merge(arr, l, m, r);
}

void MergeSort(vector<int> &arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}

//2. Quick sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for(int j=low;j<high;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void QuickSort(vector<int> &arr, int n) {
    quickSortHelper(arr, 0, n - 1);
}

void printAll(vector<int> &arr) {
    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;
}


//3. Find Position
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1; vector<int> ans(2,-1);
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                start = mid + 1; // Move right to for last position
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};