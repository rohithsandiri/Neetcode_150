class MyHashSet {
private: 
    vector<bool>h;
public:
    MyHashSet() {
        h = vector<bool>(1000001,false);
    }
    
    void add(int key) {
        h[key] = true;
    }
    
    void remove(int key) {
        h[key] = false;
    }
    
    bool contains(int key) {
        if(h[key])return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */