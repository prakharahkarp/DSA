class MyHashSet {
public:
    vector<bool> hashst;
    
    MyHashSet() {
        hashst.resize((int)1e6 + 1, false);
    }
    
    void add(int key) {
        hashst[key] = true;
    }
    
    void remove(int key) {
        hashst[key] = false;
    }
    
    bool contains(int key) {
        return hashst[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */