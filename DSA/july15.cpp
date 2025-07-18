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


//1. Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }
        if( p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//2. Zigzag Level Order Traversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        bool leftToRight = true;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int levelSize = que.size();
            vector<int> level(levelSize);
            for(int i=0;i<levelSize;i++) {
                TreeNode* temp = que.front();
                que.pop();

                int index = leftToRight ? i : levelSize - i - 1;
                level[index] = temp->val;

                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};

//3. Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) {
            return targetSum == root->val;
        }
        return hasPathSum(root->left, targetSum - root->val) ||    hasPathSum(root->right, targetSum - root->val);
    }
};

//4. Invert Binary Tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};