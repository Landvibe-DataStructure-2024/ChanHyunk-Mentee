

#include <iostream>

using namespace std;

int m;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class linkedList {
public:
    int size;
    Node* head;
    Node* tail;

    linkedList();

    void print();

    bool empty();

    void addFront(int x);

    void removeFront();

    void update(int idx, int x);

    void min();
};


linkedList::linkedList() {
    size = 0;
    head = tail = nullptr;
}

bool linkedList::empty() {
    return size == 0;
}

void linkedList::addFront(int x) {
    Node* newNode = new Node(x);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void linkedList::removeFront() {
    if (empty()) {
        cout << "empty\n";
        return;
    }
    Node* delNode = head;
    int delVal = delNode->val;
    head = delNode->next;
    delete delNode;
    size--;
    cout << delVal << "\n";
}

void linkedList::update(int idx, int x) {
    if (idx < 0 || idx >= size) {
        cout << "error\n";
        return;
    }
    Node* curNode = head;
    for (int i = 0; i < idx; i++) {
        curNode = curNode->next;
    }
    curNode->val = x;
}

void linkedList::min() {
    if (empty())
        cout << "empty\n";
    else {
        Node* curNode = this->head;
        int minVal = curNode->val;
        int minIdx = 0;
        for (int i = 0; i < size; i++) {
            if (curNode->val < minVal) {
                minVal = curNode->val;
                minIdx = i;
            }
            curNode = curNode->next;
        }
        cout << minIdx << " " << minVal << '\n';
    }
}

void linkedList::print() {
    if (empty()) {
        cout << "empty\n";
        return;
    }
    Node* curNode = head;
    for (int i = 0; i < size; i++) {
        cout << curNode->val << " ";
        curNode = curNode->next;
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    linkedList ll;
    cin >> m;
    while (m--) {
        string cmd;
        int x, i;
        cin >> cmd;
        if (cmd == "Print") {
            ll.print();
        }
        else if (cmd == "AddFront") {
            cin >> x;
            ll.addFront(x);
        }
        else if (cmd == "RemoveFront") {
            ll.removeFront();
        }
        else if (cmd == "Update") {
            cin >> i >> x;
            ll.update(i, x);
        }
        else if (cmd == "Min") {
            ll.min();
        }
    }
}