struct Node{
    
    Node *links[26] ;
    bool flag = 0 ;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL) ;
    }
    
    Node *get(char ch){
        return links[ch - 'a'] ;
    }
    
    void put(char ch , Node *node){
        links[ch - 'a'] = node ;
    }
    
    void end(){
        flag = 1 ;
    }
    
    bool isEnd(){
        return flag ;
    }
    
};

class Trie{
    
    private:Node *root ;
    
    public:Trie(){
        root = new Node() ;
    }

    public: void insert(string word){
        Node *node = root ;

        for(auto it : word){
            if(!node->containsKey(it))
                node->put(it , new Node()) ;

            node = node->get(it) ;
        }

        node->end() ;
    }
    
    public:bool searchPrefix(string word){
        Node *node = root;
        bool flag = true;
        for(auto it: word){
            
            if(!node->containsKey(it))
                return 0 ;
            
            else{
                node = node->get(it); 
                flag = flag & node->isEnd();
            }
        }
        
        return flag ;
    }
    
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        
        Trie *obj = new Trie() ;
        
        for(auto itr: words)
            obj->insert(itr) ;
        
        
        string maxi = "" ;
        
        for(auto st: words){
            
            if(obj->searchPrefix(st)){
                
                if(st.length() > maxi.length())
                    maxi = st ;
                
                else if(st.length() == maxi.length() && st < maxi){
                    maxi = st ;
                }
                
            }
            
        }
        
        return maxi ;
    }
};