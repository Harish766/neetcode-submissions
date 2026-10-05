class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int limit;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) {
        limit = capacity;

        // Initially:
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key doesn't exist
        if (map.find(key) == map.end()) {
            return -1;
        }

        Node* currNode = map[key];

        // Remove node from current position
        Node* prev = currNode->prev;
        Node* next = currNode->next;

        prev->next = next;
        next->prev = prev;

        // Put it at front (most recently used)
        Node* old = head->next;

        head->next = currNode;
        currNode->prev = head;

        currNode->next = old;
        old->prev = currNode;

        return currNode->val;
    }
void put(int key, int value) {

    // If key already exists, remove old node
    if(map.find(key) != map.end()) {

        Node* curr = map[key];

        Node* prev = curr->prev;
        Node* next = curr->next;

        prev->next = next;
        next->prev = prev;

        map.erase(key);
    }

    // Create new node
    Node* newnode = new Node(key, value);

    // Insert at front
    Node* old = head->next;  // <-- FIX

    head->next = newnode;
    newnode->prev = head;

    newnode->next = old;
    old->prev = newnode;

    map[key] = newnode;

    // If capacity exceeded, remove LRU
    if(map.size() > limit) {

        Node* lru = tail->prev;

        Node* prev = lru->prev;

        prev->next = tail;
        tail->prev = prev;

        map.erase(lru->key);

        delete lru;
    }
}
        };