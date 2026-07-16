class LRUCache {
   public:
    class Node {
       public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void AddNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void DeleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key_) {
        if(mp.find(key_) != mp.end()) {   
        Node* resultNode = mp[key_];
        int result = resultNode->val;
        DeleteNode(resultNode);
        AddNode(resultNode);
        return result;
    }
    return -1;
    }

    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()) {  
        Node* existingNode = mp[key_];
        DeleteNode(existingNode);
    } else {
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            DeleteNode(tail->prev);
        }
    }
    Node* newNode = new Node(key_, value);
    AddNode(newNode);
    mp[key_] = newNode;

    }
};
