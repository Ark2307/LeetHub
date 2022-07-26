class MinStack {
    
    stack<long long> st ;
    long long mini ;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long temp = val ;
        if(st.empty()){
            st.push(temp) ;
            mini = temp ;
        }
        
        else if(temp < mini){
            long long key = (2 * temp) - mini ;
            st.push(key) ;
            mini = temp ;
        }
        
        else
            st.push(temp) ;
    }
    
    void pop() {
        if(st.top() < mini){
            mini = (2 * mini) - st.top() ;
        }
        
        st.pop() ;
    }
    
    int top() {
        long long val = max(st.top() , mini) ;
        return int(val) ;
    }
    
    int getMin() {
        return int(mini) ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */