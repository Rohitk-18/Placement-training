#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//1. Design Stack Using Queues
class MyStack {
    queue<int> q1,q2;
public:
    MyStack() {
    }
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

//2. Design Queues Using Stack
class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
    }
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    int peek() { return s1.top(); }
    bool empty() { return s1.empty(); }
};

//3. Evaluate Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens) {
            if(s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            } else {
                int a = st.top(); ///second operand
                st.pop();
                int b = st.top(); //first operand
                st.pop();
                if(s == "+") st.push(b + a);
                else if(s == "-") st.push(b - a);
                else if(s == "*") st.push(b * a);
                else st.push(b / a);
            }
        }
        return st.top();
    }
};