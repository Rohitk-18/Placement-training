#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//1. Add Two NumbAdd Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 !=NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};

//2. Maximum Twin Sum
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head; int Msum = INT_MIN;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        ListNode* temp = head;
        while(prev != NULL && temp != NULL) {
            int sum = 0;
            sum += prev->val;
            sum += temp->val;
            Msum = max(Msum,sum);
            prev = prev->next;
            temp = temp->next;
        }
        return Msum;
    }
};

//3. Design Browser History
class BrowserHistory {
    stack<string> backSt, forwardSt;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    void visit(string url) {
        backSt.push(curr);
        curr = url;
        while(!forwardSt.empty()) forwardSt.pop();
    }
    string back(int steps) {
        while(steps-- && !backSt.empty()) {
            forwardSt.push(curr);
            curr = backSt.top();  backSt.pop();
        }
        return curr;
    }
    string forward(int steps) {
        while(steps-- && !forwardSt.empty()) {
            backSt.push(curr);
            curr = forwardSt.top(); forwardSt.pop();
        }
        return curr;
    }
};