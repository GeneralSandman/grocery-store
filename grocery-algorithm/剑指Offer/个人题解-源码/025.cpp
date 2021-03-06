#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long a = 0;
        unsigned long long b = 0;

        
        while(l1 != nullptr) {
            a = a * 10 + l1->val;
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            b = b * 10 + l2->val;
            l2 = l2->next;
        }

        unsigned long long sum = a + b;
        ListNode* pre = new ListNode(sum%10);
        sum /= 10;

        while(sum) {
            ListNode* node = new ListNode(sum%10);
            node->next = pre;
            pre = node;
            sum /= 10;
        }

        return pre;
    }
};


class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> left;
        stack<ListNode*> right;

        while(l1!=nullptr) {
            left.push(l1);
            l1 = l1->next;
        }

        while(l2!=nullptr) {
            right.push(l2);
            l2 = l2->next;
        }

        ListNode* pre = nullptr;

        int tmp = 0;
        while(!left.empty() || !right.empty()) {

            if(!left.empty()) {
                ListNode* l1 = left.top();
                left.pop();
                tmp += l1->val;
            }

            if(!right.empty()) {
                ListNode* l2 = right.top();
                right.pop();
                tmp += l2->val;
            }

            ListNode* node = new ListNode(tmp%10);
            node->next = pre;
            pre = node;
            tmp /= 10;
        }

        if(tmp > 0) {
            ListNode* node = new ListNode(tmp%10);
            node->next = pre;
            pre = node;
        }

        return pre;
    }
};


int main() {
    Solution2 s;

    ListNode* l0_0 = new ListNode(1);
    ListNode* l0_1 = new ListNode(4);
    ListNode* l0_2 = new ListNode(5);
    l0_0->next = l0_1;
    l0_1->next = l0_2;

    ListNode* l1_0 = new ListNode(1);
    ListNode* l1_1 = new ListNode(3);
    ListNode* l1_2 = new ListNode(4);
    l1_0->next = l1_1;
    l1_1->next = l1_2;

    ListNode* l2_0 = new ListNode(0);

    ListNode* l3_0 = new ListNode(0);

    ListNode* result = s.addTwoNumbers(l0_0, l1_0);
    while(result != nullptr) {
        cout << result->val;
        result = result->next;
    }

    cout << endl;

    ListNode* result2 = s.addTwoNumbers(l2_0, l3_0);
    while(result2 != nullptr) {
        cout << result2->val;
        result2 = result2->next;
    }
    

    return 0;
}
