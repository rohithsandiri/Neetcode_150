class MinStack {
    stack<int>st;
    stack<int>minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!minst.empty()){
            if(minst.top() > val){
                minst.push(val);
            }
            else{
                minst.push(minst.top());
            }
        }
        else minst.push(val);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
