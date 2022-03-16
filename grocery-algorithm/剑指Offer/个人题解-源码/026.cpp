#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {

        

        ListNode* slowNode = head;
        ListNode* fastNode = head;

        while(fastNode != nullptr && fastNode->next != nullptr) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }


        ListNode* tmp = slowNode->next;
        while (tmp != nullptr) {
            cout << "tmp:" << tmp->val << endl;
            tmp = tmp->next;
        }


        
    }

    ListNode* link(ListNode* head1, ListNode* head2) {
        return nullptr;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *pre = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;

        while(next != nullptr) {
            curr->next = pre;

            pre = curr;
            curr = next;
            next = next->next;
        }

        curr->next = pre;
        return curr;
    }
};







class Solution2 {
public:
    void reorderList(ListNode *head) {
        if(head == nullptr) {
            return;
        }

        vector<ListNode*> array;
        ListNode*         tmp = head;
        while(tmp!=nullptr) {
            array.push_back(tmp);
            tmp = tmp->next;
        }

        int i = 0;
        int j = array.size() - 1;
        while(i<j) {
            array[i]->next = array[j];

            i++;
            if(i==j) {
                break;
            }

            array[j]->next = array[i];
            j--;
        }

        array[i]->next = nullptr;
    }
};



int main() {
    Solution s;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node5;
    node5->next = nullptr;


    s.reorderList(node1);

    while(node1!=nullptr){
        cout << node1->val << endl;
        node1 = node1->next;
    }

    return 0;
}
