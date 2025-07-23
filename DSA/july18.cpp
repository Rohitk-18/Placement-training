#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//1.  Binary Tree Iterator
class BSTIterator {
public:
    stack<TreeNode*> s; //To implement the recursive callstack
    void storeLeftNodes(TreeNode* root) { //storing the left nodes
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        storeLeftNodes(curr->right);
        return curr->val;
    }
    bool hasNext() {
        return (!s.empty());
    }
};

//2. LCA in BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

//3. Two Sum in BST
class Solution {
public:
    bool helper(TreeNode* root, int k, unordered_set<int> &s) {
        if(!root) return false;
        if(s.find(k - root->val) != s.end()) {
            return true;
        }
        s.insert(root->val);
        return helper(root->left, k, s) || helper(root->right, k, s);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, k, s);
    }
};

//4. Flatten BT to Linked List
class Solution {
public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);

        root->right = nextRight;
        root->left = NULL;
        nextRight = root;
    }
}; 