class RandomizedSet {

private:
    unordered_map<int,int> mp; //it will store elements and its indices.
    vector<int> nums; //it will store values.
public:
    
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
        {//The element is present already
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size()-1; 
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) 
        {   
            //Element is not present so unable to delete
            return false;
        }
        //We want the deletion in O(1).
        //Since we don't care about the order of elements.
        //So pick the last element swap it with curr val and remove.
        int last = nums.back();
        int indVal = mp[val];
        mp[last] = indVal;
        nums[indVal] = last; //we saved the last element.
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()]; //since it is given that at the time of calling the function we have some elements always so just return the random value
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */