#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }


        queue<Node*> accessPath;
        helper(head, accessPath);

        Node* result = nullptr;

        Node* pre = nullptr;
        while(!accessPath.empty()) {
            Node* tmp = accessPath.front();
            tmp->prev = pre;
            tmp->child = nullptr;
            tmp->next = nullptr;

            if(pre == nullptr) {
                result = tmp;
            } else {
                pre->next = tmp;
            }
            pre = tmp;
            accessPath.pop();
        }


        return result;
    }

    void helper(Node* head, queue<Node*> &accessPath) {
        if(head == nullptr) {
            return;
        }

        accessPath.push(head);
        helper(head->child, accessPath);
        helper(head->next, accessPath);
    }
};


int main() {
    Solution s;

    Node* l0_0 = new Node(0);
    Node* l0_1 = new Node(1);
    Node* l0_2 = new Node(2);
    Node* l0_3 = new Node(3);
    Node* l0_4 = new Node(4);

    Node* l1_0 = new Node(5);
    Node* l1_1 = new Node(6);

    Node* l2_0 = new Node(7);

    l0_0->next=l0_1;
    l0_1->next=l0_2;
    l0_2->next=l0_3;
    l0_3->next=l0_4;

    l1_0->next = l1_1;


    l0_1->child = l1_0;
    l1_0->child = l2_0;

    Node* result = s.flatten(l0_0);

    while(result!=nullptr) {
        cout << result->val << "-" << result->prev << "-" << result->next << endl;
        result = result->next;
    } 


    return 0;
}
