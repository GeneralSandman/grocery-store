#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <list>

using namespace std;


class Node {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache
{
private:
    int size;
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> hashTable;

public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto iter = hashTable.find(key);
        if(iter == hashTable.end()) {
            return -1;
        }

        moveNodeToHead(iter->second);

        return iter->second->value;
    }

    void put(int key, int value) {

        Node *node;

        auto iter = hashTable.find(key);
        if(iter == hashTable.end()) {
            node = new Node(key, value);
            hashTable[key] = node;
            insertNodeToHead(node);
            if(hashTable.size() > capacity) {
                deleteEndNode();
            }
        } else {
            node = iter->second;
            node->value = value;
            moveNodeToHead(node);
        }
    }

private:
    void deleteEndNode() {
        Node *del = tail->prev;
        Node *p1 = del->prev;
        Node *p2 = del->next;
        hashTable.erase(hashTable.find(del->key));

        p1->next = p2;
        p2->prev = p1;
        delete del;
    }

    void insertNodeToHead(Node *node) {
        Node *p1 = head;
        Node *p2 = head->next;

        p1->next = node; node->next = p2;
        p2->prev = node; node->prev = p1;
    }
    void moveNodeToHead(Node *node) {
        Node *p1 = node->prev;
        Node *p2 = node->next;

        p1->next = p2;
        p2->prev = p1;

        insertNodeToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    return 0;
}
