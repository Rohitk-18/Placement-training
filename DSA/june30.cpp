#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//1. Design Stack using Arrays
class Stack {
    vector<int> stk;
    int capacity;

public:
    Stack(int maxSize) {
        capacity = maxSize;
    }

    bool push(int x) {
        if (stk.size() >= capacity) {
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        stk.push_back(x);
        return true;
    }

    int pop() {
        if (stk.empty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int val = stk.back();
        stk.pop_back();
        return val;
    }

    int top() {
        return stk.empty() ? -1 : stk.back();
    }

    int peep(int position) {
        int index = stk.size() - position;
        if (index < 0 || index >= stk.size()) {
            cout<<"Invalid position"<<endl;
            return -1;
        }
        return stk[index];
    }

    void display() {
        for (int i=stk.size()-1;i>=0;i--)
            cout<<stk[i]<<" ";
        cout<<endl;
    }
};

int main() {
    Stack s(5);  
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  
    s.display();  
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Peep at position 3 from top: "<<s.peep(3) << endl;  
    cout<<"Popped: "<< s.pop()<<endl;
    cout<<"Popped: "<< s.pop()<<endl;
    s.display(); 
    cout<<"Top element: "<<s.top()<<endl;
    return 0;
}

//2. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                char p = st.top();
                if((c == ')' && p == '(') || (c == '}' && p == '{') || (c == ']' && p == '[')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//3. Swapping Nodes
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; ++i) {
            first = first->next;
        }
        ListNode* second = head;
        ListNode* temp = first;
        while (temp->next) {
            temp = temp->next;
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};