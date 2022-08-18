struct Node{
  
    Node *child[26];
    bool isEnd=false;
    
    bool is_present(char ch)
    {
        return (child[ch-'a']!=NULL);
    }
    
    void put_node(char ch,Node *node)
    {
        child[ch-'a']=node;
    }
    
    Node * get_node(char ch)
    {
        return child[ch-'a'];
    }
    
    bool is_End()
    {
        return isEnd;
    }
    
    void set_End_TRUE()
    {
        isEnd=true;
    }
    
    void set_End_FALSE()
    {
        isEnd=false;
    }
    
};


//------------------------------------------------------------------------------------------//
class Trie{
 
    public:
    
    Node *root;
    
    Trie()
    {
        root=new Node();
    }
    
    // insertion
    void insert(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->is_present(word[i])==false)
            {
                node->put_node(word[i],new Node());
            }
            node=node->get_node(word[i]);
        }
        
        node->set_End_TRUE();
    }
    
    // searching
    bool search(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->is_present(word[i])==false)return false;
            node=node->get_node(word[i]);
        }
        
        return node->is_End();
    } 
};

//--------------------------------------------------------------------------------------------//

void dfs(vector<vector<char>>& board,int i,int j,Node *node,string &s,vector<string>&ans)
{
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='#')
    {
        return ;
    }
    
    char ch=board[i][j];
    
    if(node->is_present(ch)==false)
    {
        return ;
    }
    
    // mark visited after checking
    board[i][j]='#';
    s.push_back(ch);
    
    node=node->get_node(ch);
    
    if(node->is_End()==true)
    {
        ans.push_back(s);
        node->set_End_FALSE();
        
    }
    
    dfs(board,i-1,j,node,s,ans); 
    dfs(board,i+1,j,node,s,ans);
    dfs(board,i,j+1,node,s,ans);
    dfs(board,i,j-1,node,s,ans);

      
    
    s.pop_back();
    board[i][j]=ch;
}


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie *t=new Trie();
        vector<string>ans;
        int n=board.size();
        int m=board[0].size();
        
        for(auto x:words)
        {
            t->insert(x);
        }
        
        //--------------DFS-------------//
        
        Node *node=t->root;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string s="";
                dfs(board,i,j,node,s,ans);
            }
        }
        
        return ans;
        
    }
};