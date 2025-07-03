#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st; int sum = 0;
        for(string c : operations) {
            if(c != "+" && c != "D" && c != "C"){ 
                st.push(stoi(c));
            } else {
                int p = st.top();
                st.pop();
                if(c == "+") {
                    int q = st.top();
                    st.push(p);
                    st.push(q + p);
                }
                else if (c == "D") {
                    st.push(p);
                    st.push(2 * p);
                } 
            }
        }
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

//2. Stock Span
class StockSpanner {
    stack<pair<int, int>> st; 
public:
    StockSpanner() {
        
    }
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

//3. Linked List Random Node
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom() {
        int result = -1;
        ListNode* curr = head;
        int i = 1;
        while (curr) {
            if (rand() % i == 0) {
                result = curr->val;
            }
            curr = curr->next;
            i++;
        }
        return result;
    }
};
