/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define ll long long

class Solution {
public:
    
    ll count ;
    void traverse(TreeNode *root , ll targetSum){
        if(root == NULL)
            return ;
        
        targetSum -= root->val ;
        if(targetSum == 0)
            count++ ;
        
        if(root->left)
            traverse(root->left , targetSum) ;
        
        if(root->right)
            traverse(root->right , targetSum) ;
        
    }
    
    void dfs(TreeNode *root , ll sum){
        if(root == NULL)
            return ;
        
        dfs(root->left , sum) ;
        dfs(root->right , sum) ;
        
        traverse(root , sum) ;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        count = 0LL ;
        ll sum = targetSum ;
        dfs(root , sum) ;
        
        return int(count); 
    }
};