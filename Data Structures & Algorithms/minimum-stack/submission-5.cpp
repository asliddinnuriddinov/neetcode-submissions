class MinStack {
private:
    vector<int> st = {};
    vector<int> minSt = {};
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.empty() || val <= minSt.back()){
            minSt.push_back(val);
        }
    }
    
    void pop() {
        if(st.back() == minSt.back()){
            minSt.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};
