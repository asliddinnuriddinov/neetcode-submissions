class MinStack {
private:
    vector<int> st = {};
    vector<int> minSt = {};
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.empty() || minSt[minSt.size() - 1] >= val){
            minSt.push_back(val);
        }
    }
    
    void pop() {
        if(minSt[minSt.size() - 1] == st[st.size() - 1]){
            minSt.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st[st.size() - 1];
    }
    
    int getMin() {
        return minSt[minSt.size() - 1];
    }
};
