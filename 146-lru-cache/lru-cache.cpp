class LRUCache {
public:
    class node {
    public:
        int key, value;
        node* next;
        node* prev;
        node(int key_, int value_) {
            key = key_;
            value = value_;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;
    node* tail;
    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void del(node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    void ins(node* temp) {
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            node* temp = mpp[key];
            mpp.erase(key);
            del(temp);
            ins(temp);
            mpp[temp->key] = head->next;
            return temp->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* temp = mpp[key];
            mpp.erase(key);
            del(temp);
            temp->value = value;
            ins(temp);
            mpp[temp->key] = head->next;
        }
        else if (mpp.size() == cap) {
            node* temp = tail->prev;
            mpp.erase(temp->key);
            del(temp);
            temp = new node(key, value);
            ins(temp);
            mpp[temp->key] = head->next;
        } else {
            node* temp = new node(key, value);
            ins(temp);
            mpp[temp->key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */