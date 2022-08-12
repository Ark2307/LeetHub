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
    
    bool traverse(TreeNode *root , int key , vector<TreeNode *> &a){
        
        if(root == NULL)
            return 0 ;
        
        a.push_back(root) ;
        
        if(root->val == key)
            return 1 ;
        
        if(((root->right) && traverse(root->right , key , a))
           || ((root->left) && traverse(root->left , key , a)))
            return 1 ;
        
        a.pop_back() ;
        return 0 ;
    }
    
    TreeNode *findLca(TreeNode *root , int a , int b){
        
        if(root == NULL)
            return root ;
        
        vector<TreeNode *> path1 , path2 ;
        if(!traverse(root , a , path1))
            return NULL ;
        
        if(!traverse(root , b , path2))
            return NULL ;
        
        int x = path1.size() ;
        int y = path2.size() ;
        
        for(int i = 1 ; i < min(x , y) ; i++){
            if(path1[i] != path2[i])
                return path1[i - 1] ;
        }
        
        return path1[min(x , y) - 1] ;
        
    }
    
    bool getPath(TreeNode *root , int key , vector<char> &path , char c){
        if(root == NULL)
            return 0 ;
        
        path.push_back(c) ;
        if(root->val == key)
            return 1 ;
        
        if(((root->right) && getPath(root->right , key , path , 'R'))
           || ((root->left) && getPath(root->left , key , path , 'L')))
            return 1 ;
        
        path.pop_back() ;
        return 0 ;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = findLca(root , startValue , destValue) ;
        
        if(lca == NULL)
            return "" ;
        
        vector<char> x1 , x2 ;
        bool flag1 = getPath(lca , startValue , x1 , '0') ;
        bool flag2 = getPath(lca , destValue , x2 , '0') ;
        
        string res = "" ;
        for(int i = 1 ; i < x1.size() ; i++){
            // cout << x1[i] << " " ;
            res.push_back('U') ;
        }
        
        for(int i = 1 ; i < x2.size() ; i++){
            // cout << x1[i] << " " ;
            res.push_back(x2[i]) ;
        }
        
        return res ;
    }
};