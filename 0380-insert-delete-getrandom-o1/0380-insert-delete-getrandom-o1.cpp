class RandomizedSet {
public:
    
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()) 
            return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()) 
        {
            st.erase(val); 
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ind = rand()%st.size();
        auto it = st.begin();
        int i = 0;
        while(i != ind) 
        {
            it++;
            i++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */