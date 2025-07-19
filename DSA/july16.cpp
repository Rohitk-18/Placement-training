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

//1. Binary Tree Right Side View
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int levelSize = que.size();
            for(int i=0;i<levelSize;i++){ 
                TreeNode* curr = que.front();
                que.pop();
                if(i == levelSize - 1) {
                    ans.push_back(curr->val);
                }
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
        }
        return ans;
    }
};

//2. Path Sum II
class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int> &temp, vector<vector<int>> &res) {
        if(root == NULL) return;
        temp.push_back(root->val);
        if(!root->left && !root->right) {
            if(root->val == targetSum) {
                res.push_back(temp);
            }
        }
        helper(root->left, targetSum - root->val, temp, res);
        helper(root->right, targetSum - root->val, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> res;
        if(!root) return res;
        helper(root, targetSum, temp, res);
        return res;
    }
};

//3. Lowest Common Ancestor
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) {
            return root;
        } else if(leftLCA != NULL) {
            return leftLCA;
        } else {
            return rightLCA;
        }
    }
};

//4. Kth Smallest Element in BST
class Solution {
public:
    int count = 0;
    int result = -1;
    void inorder(TreeNode* root, int k) {
        if(!root || count >= k) return;
        inorder(root->left, k);
        count++;
        if(count == k) {
            result = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};