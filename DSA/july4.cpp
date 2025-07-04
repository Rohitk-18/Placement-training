#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Find the Celebrity
class Solution {
  public:
    
    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }
    
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        if (n == 0) return -1; // No people, no celebrity.

        int candidate = 0;

        // Find potential candidate
        for (int i = 1; i < n; i++) {
            if (knows(mat, candidate, i)) {
                candidate = i; // candidate cannot be a celebrity, so update candidate
            }
        }

        // Verifying the candidate
        for (int i = 0; i < n; i++) {
        // Skip self-check
            if (i == candidate) continue;

        // Candidate must not know i, and everyone must know the candidate
            if (knows(mat, candidate, i) || !knows(mat, i, candidate)) {
                return -1; // Candidate fails the test
            }
        }

        return candidate; 
    }
};

//2. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int lmax = 0,rmax = 0;
        while(left < right) {
            lmax = max(lmax,height[left]);
            rmax = max(rmax,height[right]);
            if(lmax < rmax) {
                ans += lmax - height[left];
                left++;
            } else {
                ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};

//3. Design LRU Cache
class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            value = v;
            next = prev = NULL;
        }
    };
    unordered_map<int, Node*> map;
    int limit;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    void addNode(Node* newnode) {
        Node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
    }
    void delNode(Node* oldnode) {
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }
        Node* newNode = map[key];
        int ans = newNode->value;
        map.erase(key);
        delNode(newNode);
        addNode(newNode);
        map[key] = newNode;
        return ans;
    }
    void put(int key, int value) {
        if(map.find(key) != map.end()) { //updation part if already key exist krti hai
            Node* oldNode = map[key]; 
            delNode(oldNode);
            map.erase(key);
        }
        if(map.size() == limit) { //capacity puri use hogyi
            map.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key,value);
        addNode(newNode);
        map[key] = newNode;
    }
};