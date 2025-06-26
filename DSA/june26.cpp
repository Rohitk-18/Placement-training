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

//1. Palindrome Linked List
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        while(slow) {
            ListNode *nextnode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextnode;
        }
        ListNode *left = head, *right = prev;
        while(right) {
            if(left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

//2. Rotate List 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) {
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        while(temp->next) {
            temp = temp->next;
            count++;
        }
        k = k % count;
        temp->next = head;
        ListNode* newtail = head;
        for(int i=0;i<count-k-1;i++) {
            newtail = newtail->next;
        }
        ListNode* newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};

//3. Magical String
class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        if(n <= 3) return 1;
        int read = 2;
        string s = "122";
        string nexchar = "1";
        int res = 1;

        while(s.size() < n) {
            int count = s[read++] - '0';
            for(int i=0;i<count && s.size()<n;i++) {
                s += nexchar;
                if(nexchar == "1") res++;
            }
            nexchar = (nexchar == "1" ? "2" : "1");
        }
        return res;
    }
};
