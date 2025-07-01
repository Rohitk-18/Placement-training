#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Design Queue using Arrays
#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int rearIn;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        rearIn = -1;
    }

    void enqueue(int value) {
        if (rearIn == capacity - 1) {
            cout<<"Queue overflow"<<endl;
            return;
        }
        rearIn++;
        arr[rearIn] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue underflow"<<endl;
            return;
        }

        //left shift kro by one place
        for (int i=0;i<rearIn;i++) {
            arr[i] = arr[i+1];
        }
        rearIn--;
    }

    int front() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() {
        return rearIn == -1;
    }

    int size() {
        return rearIn + 1;
    }

};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout<<"Front: "<<q.front()<<endl; 
    q.dequeue();
    cout<<"Front after dequeue: "<<q.front()<<endl; 
    cout<<q.isEmpty()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    return 0;
}

//2. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> s;
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--) {
            while(s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }
            if(s.empty()) {
                //ans.push_back(-1);
                map[nums2[i]] = -1;
            } else {
                //ans.push_back(s.top());
                map[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++) {
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};

//3. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,0);
        for(int i=2*n - 1;i>=0;i--) {
            while(s.size() > 0 && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }
            ans[i % n] = s.empty() ? -1 : nums[s.top()];
            s.push(i % n);
        }
        return ans;
    }
};

//4. Odd Even Linked List
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* start = head->next;
        int count = 1;
        while(even && even->next) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = start;
        return head;
    }
};