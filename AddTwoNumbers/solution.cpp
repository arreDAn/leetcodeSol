#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry =0;
    int sum =0;
    ListNode* ans = new ListNode(0);
    ListNode* curr= ans;
    int val1, val2;

    while(l1 || l2)
    {
        if(l1)
            val1 = l1->val;
        else
            val1 =0;
        if(l2)
            val2 = l2->val;
        else
            val2 =0;
        sum = val1 + val2 + carry;
        carry = sum/10;
        curr->next= new ListNode(sum%10);
        curr = curr->next;
        if (l1) {
            l1 = l1->next;
        } else {
            l1 = nullptr;
        }
        if (l2) {
            l2 = l2->next;
        } else {
            l2 = nullptr;
        }
    }
    if(carry == 1)
        curr->next= new ListNode(1);
    return ans->next;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode* l1 = new ListNode(2);
    ListNode* current = l1;
    current->next=new ListNode(4);
    current = current->next;
    current->next=new ListNode(3);
    current = current->next;

    ListNode* l2 = new ListNode(5);
    current = l2;
    current->next=new ListNode(6);
    current = current->next;
    current->next=new ListNode(4);
    current = current->next;

    ListNode* ans = addTwoNumbers(l1,l2);
    current = ans;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    return 0;
}
