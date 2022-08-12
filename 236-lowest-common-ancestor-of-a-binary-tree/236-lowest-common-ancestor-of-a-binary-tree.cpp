/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool traverse(TreeNode *head , TreeNode *dest , vector<TreeNode *> &path){
        
        if(head == NULL)
            return 0;
        
        path.push_back(head) ;
        
        if(head == dest)
            return 1;
        
        if((head->right && traverse(head->right , dest , path)) || 
           (head->left && traverse(head->left , dest , path)) )
            return 1 ;
        
        path.pop_back() ;
        return 0 ;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL ;
        
        
        vector<TreeNode *> path1 ;
        bool check1 = traverse(root , p , path1) ;
        
        if(!check1)
            return NULL ;
        
        vector<TreeNode *> path2 ;
        bool check2 = traverse(root , q , path2) ;
        
        if(!check2)
            return NULL ;
        
        int x = path1.size() , y = path2.size() ;
        for(int i = 0 ; i < min(x , y) ; i++){
            if(path1[i] != path2[i]){
                return path1[i - 1] ;
            }
        }
        
        return path1[min(x , y) - 1] ;
    }
};