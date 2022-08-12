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
class Solution {
public:
    
    int sum ;
    void traverse(TreeNode *root , int key , vector<int> &path , vector<vector<int>> &res){
        
        if(root == NULL)
            return ;
        
        sum += root->val; 
        path.push_back(root->val) ; 
        
        if(root->right == NULL && root->left == NULL){
            if(sum == key)
                res.push_back(path) ;
        }
        
        if(root->left)
            traverse(root->left , key , path , res) ;
        
        if(root->right)
            traverse(root->right , key , path , res) ;
        
        sum -= root->val ;
        path.pop_back() ;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        sum = 0 ;
        
        vector<int> path ;
        vector<vector<int>> res; 
        
        traverse(root , targetSum , path , res) ;
        
        return res; 
    }
};