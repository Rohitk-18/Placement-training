#include <iostream>
using namespace std;

//1.Implementation of Singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {
        if(pos < 0) {
            cout<<"Negative no"<<endl;
            return;
        } 
        if(pos == 0) {
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i=0;i<pos-1;i++) {
            if(temp == NULL) {
                cout<<"Invalid indx"<<endl;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode; 
    }

    void delete_at(int index) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp; 
        
            if (head == NULL) tail = NULL;
            return;
        }
        Node* curr = head;
        for (int i = 0; curr != NULL && i < index - 1; ++i) {
            curr = curr->next;
        }
        if (curr == NULL || curr->next == NULL) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        if (temp == tail) tail = curr;
        delete temp;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    List l1;
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(5);
    l1.pop_front();
    l1.pop_front();
    l1.pop_back();
    l1.pop_back();
    l1.delete_at(0);
    l1.insert(6,1);
    l1.delete_at(1);
    l1.print();
    return 0;
}

//2.Delete a Node in Singly Linked List
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        int count = 1;
        if(count == x) { 
            Node* temp = head; 
            head = temp->next; 
            delete temp; 
        } 
        Node* prev = head; 
        Node* curr = head->next;
        while(curr != NULL && count != x - 1) { 
            prev = prev->next;
            curr = curr->next;
            count++;
        } 
        if(curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }
        return head;
        
    }
};

//3.Find Middle
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MidSolution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};