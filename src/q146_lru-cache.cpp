#include <unordered_map>
#include <list>



class LRUCache {
private:
    int capacity;
    //key: key, value: iter for that std::list(we need to use it to delete entry in std::list)
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator > dic; 
    std::list<std::pair<int, int>> lru;

public:
    LRUCache(int capacity) :capacity(capacity) 
    { }
    
    int get(int key) {
        if (!(dic.count(key)>0)) {
            return -1;
        } else {
            auto iter = dic[key];
            int value = iter->second;
            lru.erase(iter);
            lru.push_front({key, value});

            dic.erase(key);
            dic[key] = lru.begin();
            return value;
        }
    }
    
    void put(int key, int value) {
        if (dic.count(key)>0) {
             lru.erase(dic[key]);
             dic.erase(key);
        } 

        lru.push_front({key, value});
        dic[key] = lru.begin();

        if (dic.size()>capacity) {
            int key = lru.back().first;
            dic.erase(key);
            lru.pop_back();
        }
    }

};


struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache2 {
private:
    int capacity;
    std::unordered_map<int, Node*> dic;
    Node* head;
    Node* tail;

public:
    LRUCache2(int capacity) :capacity(capacity), head(new Node(-1,-1)), tail(new Node(-1,-1)) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (dic.find(key) == dic.end()) {
            return -1;
        }

        Node* node = dic[key];
        removeNode(node);
        addToBack(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (dic.find(key) != dic.end()) {
            Node* oldNode = dic[key];
            removeNode(oldNode);
            dic.erase(key);
        }

        Node* node = new Node(key, value);
        dic[key] = node;
        addToBack(node);

        if (dic.size()>capacity) {
            Node* nodeToDelete = head->next;
            removeNode(nodeToDelete);
            dic.erase(nodeToDelete->key);

        }
    }

    void addToBack(Node* node) {
        Node* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
