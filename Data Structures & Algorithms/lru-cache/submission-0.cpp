class ListNode{
public: 
    int key;
    int value; 
    ListNode* next;
    ListNode* prev;
    ListNode(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
    int capacity;
    unordered_map< int, ListNode*>mp;//key to node pointer
    ListNode* head;
    ListNode* tail;

    //add node at head
    void addNode(ListNode* temp){
        temp -> next = head -> next;
        temp -> prev = head;
        head -> next = temp;
        temp ->next -> prev = temp;
    }
    void deleteNode(ListNode* temp){
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
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
        //key already exists
        if(mp.find(key) != mp.end()){
            mp[key] -> value = value;
            movetoHead(mp[key]);
            return;
        }

        //create a new node if key dont exists
        ListNode* node = new ListNode(key, value);
        mp[key] = node;
        addNode(node);

        if(mp.size() > capacity){
            ListNode* lru = tail -> prev;
            int k = lru -> key;
            mp.erase(k);
            deleteNode(lru);
            delete lru;
        }
    }
};
