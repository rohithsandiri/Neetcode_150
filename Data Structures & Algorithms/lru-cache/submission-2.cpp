class ListNode{
public:
    int key;
    int value;
    ListNode* prev;
    ListNode* next;
    ListNode(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
    int capacity;
    unordered_map<int, ListNode*>mp;//key to node map
    ListNode* head;
    ListNode* tail;
    void addNode(ListNode* temp){
        temp -> next = head -> next;
        temp -> prev = head;
        temp -> next -> prev = temp;
        head -> next = temp;
        return;
    }
    void deleteNode(ListNode* temp){
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        return;
    }
    void movetoHead(ListNode* temp){
        deleteNode(temp);
        addNode(temp);
    }
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head -> next = tail;
        tail -> prev = head;

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        movetoHead(mp[key]);
        return mp[key] -> value;
    }
    
    void put(int key, int value) {
        //if key doesn't exist
        if(mp.find(key) != mp.end()){
            mp[key] -> value = value;
            movetoHead(mp[key]);
            return;
        }
        //if key doesn't exists
        //create it and move it to the front
        ListNode* temp = new ListNode(key, value);
        mp[key] = temp;
        addNode(temp);
        //if increases more than capacity remove the tail (lru)
        if(mp.size() > capacity){
            ListNode* lru = tail -> prev;
            deleteNode(lru);
            mp.erase(lru -> key);
            delete lru;
        }
        return;
    }
};
