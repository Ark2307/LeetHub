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
    
    bool valid(vector<int> res){
        for(int i = 1 ;  i < res.size() ; i++){
            if(res[i] <= res[i - 1])
                return 0 ;
        }
        return 1 ;
    }
    
    void traverse(TreeNode *head , vector<int> &res){
        
        if(head == NULL)
            return ;
        
        traverse(head->left , res) ;
        res.push_back(head->val) ;
        traverse(head->right , res) ;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int> res;
        traverse(root , res) ;
        
        return valid(res) ;
    }
};