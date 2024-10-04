#include <iostream>
#include "list.h"

LinkedList::LinkedList() {
    InitList();
}

void LinkedList::InitList() {
    list = new List();
    list->curnode = nullptr;
    list->headnode = nullptr;
}

void LinkedList::PrintCur() {
    if (list->curnode != nullptr) {
        cout << "CurNode: " << list->curnode->data << endl;
    }
    else {            
        cout << "No CurNode! Fail PrintCur" << endl;
    }
}

void LinkedList::PrintAll() {
    if (list->headnode == nullptr) { 
        cout << "No HeadNode! Fail PrintAll" << endl;
        return;
    }
    Node* tempNode = list->headnode;
    cout << "========= Start ==========" << endl;
    while (tempNode != nullptr) {
        cout << tempNode->data << endl;
        tempNode = tempNode->nextnode;
    }
    cout << "========= End ==========" << endl<<endl;
}

Node* LinkedList::Find(List* list, Node* node) {
    if (list->headnode == nullptr) {
        cout << "No HeadNode! Fail Find" << endl;
        return nullptr;
    }
    Node* tempNode = list->headnode;
    while (tempNode != nullptr) {
        if (tempNode != node && tempNode->data == node->data) {
            list->curnode = tempNode;
            return tempNode;
        }
        else {
            tempNode = tempNode->nextnode;
        }
    }
    return nullptr;
}

void LinkedList::InsHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->nextnode = list->headnode;
    list->headnode = list->curnode = newNode;
}

void LinkedList::InsTail(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (list->headnode == nullptr) {
        list->headnode = newNode;
        list->curnode = newNode;
    }
    else {
        Node* tempNode = list->headnode;
        while (true) {
            if (tempNode->nextnode == nullptr) {
                tempNode->nextnode = newNode;
                list->curnode = newNode;
                break;
            }
            tempNode = tempNode->nextnode;
        }
    }
}

void LinkedList::InsAfterCur(int value) {
    if (list->curnode == nullptr) {
        cout << "No CurNode! Fail InsAfterCur" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->nextnode = list->curnode->nextnode;
    newNode->data = value;
    list->curnode->nextnode = newNode;
}

void LinkedList::RemHead() {
    if (list->headnode == nullptr) {
        cout << "No HeadNode! Fail RemHead" << endl;
        return;
    }
    else {
        Node* tempNode = list->headnode;
        if (tempNode->nextnode != nullptr) {
            list->headnode = list->headnode->nextnode;
            list->curnode = list->headnode;
        }
        else {
            list->headnode = nullptr;
            list->curnode = nullptr;
        }
        delete tempNode;
    }
}

void LinkedList::RemCur() {
    if (list->curnode == nullptr) {
        cout << "No CurNode! Fail RemCur" << endl;
        return;
    }
    Node* tempnode = list->headnode;
    if (tempnode == list->curnode) {
        RemHead();
        return;
    }
    while (true) {
        if (tempnode->nextnode == list->curnode) {
            tempnode->nextnode = list->curnode->nextnode;
            delete list->curnode;
            list->curnode = tempnode;
            break;
        }
        tempnode = tempnode->nextnode;
    }
}