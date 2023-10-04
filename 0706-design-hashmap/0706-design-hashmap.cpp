class MyHashMap {
public:
    vector<int> hashmp;
    
    MyHashMap() {
        hashmp.resize((int)1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        hashmp[key] = value;
    }
    
    int get(int key) {
        return hashmp[key];
    }
    
    void remove(int key) {
        hashmp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */