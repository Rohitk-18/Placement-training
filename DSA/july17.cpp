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

//1. Lowest Common Ancestor
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

//2. Time to be Infected in Binary Tree
class Solution {
public:
    int maxTime = 0;

    int dfs(TreeNode* root, int start) {
        if(!root) return -1;

        int leftS = dfs(root->left, start);
        int rightS = dfs(root->right, start);

        if(root->val == start) {
            maxTime = max(maxTime, maxDepth(root) - 1);
            return 0;
        }

        if(leftS != -1) {
            maxTime = max(maxTime, 1 + leftS + maxDepth(root->right));
            return leftS + 1;
        }

        if(rightS != -1) {
            maxTime = max(maxTime, 1 + rightS + maxDepth(root->left));
            return rightS + 1;
        }
        return -1;
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return 1 + max(leftH, rightH);
    }

    int amountOfTime(TreeNode* root, int start) {
        maxTime = 0;
        dfs(root, start);
        return maxTime;
    }
};

//3. Count Nodes in Complete Tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftN = countNodes(root->left);
        int rightN = countNodes(root->right);
        return leftN + rightN + 1;
    }
};

//4. Validate BST 
class Solution {
public:

    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        if(min != NULL && root->val <= min->val) return false;
        if(max != NULL && root->val >= max->val) return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
   