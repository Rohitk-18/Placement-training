#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Binary search

//a) Recursive approach
int BinarySearchRec(vector<int> &arr, int low, int high, int target) {
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return BinarySearchRec(arr, mid + 1, high, target);
    } else {
        return BinarySearchRec(arr, low, mid - 1, target); 
    }
}

//b) Iterative approach
int BinarySearchIter(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

//2. Selection sort

//a) Recursive approach
void SelectionSortRec(vector<int> &arr, int n, int index) {
    if(index == n) return;
    int Idx = index;
    for(int i=index + 1;i<n;i++) {
        if(arr[i] < arr[Idx]) {
            Idx = i;
        }
    }
    swap(arr[Idx], arr[index]);
    SelectionSortRec(arr, n, index + 1);
}

//b) Iterative approach
void SelectionSortIter(vector<int> &arr, int n) {
    for(int i=0;i<n-1;i++) {
        int idx = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[idx]) {
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
    return;
}

//3. Bubble sort

//a) Recursive approach
void BubbleSortRec(vector<int> &arr, int n) {
    if(n == 1) return;
    for(int i=0;i<n-1;i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    BubbleSortRec(arr, n - 1);
}

//b) Iterative approach
void BubbleSortIter(vector<int> &arr, int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return;
}

//4. Insertion sort

//a) Recursive approach
void InsertionSortRec(vector<int> &arr, int n) {
    if(n <= 1) return;
    InsertionSortRec(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while(j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j--];
    }
    arr[j + 1] = key;
}

//b) Iterative approach
void InsertionSortIter(vector<int> &arr, int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
    return;
}

void printAll(vector<int> &arr) {
    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;
}
