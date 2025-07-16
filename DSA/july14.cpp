#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1. Inorder Traversal
class Solution {
public:
    vector<int>  ans;
    void helper(TreeNode* root,vector<int>& ans) {
        if(root != NULL) {  
            helper(root->left,ans);
            ans.push_back(root->val);
            helper(root->right,ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>  ans;
       helper (root,ans);
       return ans;
    }
};

//2. Level Order Traversal
class Solution { //iterative
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution { //recursive
public:
    void helper(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == NULL) return;
        if(res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }
};

//3. Maximum of Binary Tree
class Solution { //recursive
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return max(leftH,rightH) + 1;
    }
};

class Solution { //iterative
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int height = 0;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int size = que.size();
            for(int i=0;i<size;i++) {
                TreeNode* curr = que.front();
                que.pop();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            height++;
        }
        return height;
    }
};

//4. Diameter of Binary Tree
class Solution { //recursive
public:
    int ans = 0;
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        ans = max(ans,rightH + leftH);
        return max(leftH, rightH) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};

class Solution { //iterative
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> heightmap;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastvis = NULL;
        int diameter = 0;
        while(curr != NULL || !st.empty()) {
            if(curr) { //left node 
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peeking = st.top();
                if(peeking->right && peeking->right != lastvis) { //right node
                    curr = peeking->right;
                } else { //node
                    st.pop();
                    int leftH = peeking->left ? heightmap[peeking->left] : 0;
                    int rightH = peeking->right ? heightmap[peeking->right] : 0;
                    heightmap[peeking] = 1 + max(leftH,rightH);
                    diameter = max(diameter,rightH + leftH);
                    lastvis = peeking;
                }
            }
        }
        return diameter;
    }
};