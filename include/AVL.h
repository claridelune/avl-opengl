#ifndef AVL_H
#define AVL_H

#include "Node.h"
#include <iostream>
#include <ostream>
#include <vector>

template<class T>
class AVL {
public:
    AVL();
    bool find(T x, Node<T>**& p, std::vector<Node<T>**>& path);
    bool insert(T x);
    bool remove(T x);
    Node<T>** Rep(Node<T>** q);
    void InOrderR(Node<T>* n);

    Node<T>* root;

private:
    int height(Node<T>* n);
    int balanceFactor(Node<T>* n);
    Node<T>* rightRotation(Node<T>* head);
    Node<T>* leftRotation(Node<T>* head);
    void updateHeight(Node<T>* n);
    void balance(Node<T>** p);

    bool m_b;
    int n;
};

template<class T>
AVL<T>::AVL() {
    root = nullptr;
    n = 0;
}

template<class T>
bool AVL<T>::find(T x, Node<T>**& p, std::vector<Node<T>**>& path) {
    for (p = &root; *p && (*p)->key != x; p = &((*p)->nodes[(*p)->key < x])) {
        path.push_back(p);
    }
    return *p && (*p)->key == x;
}

template <class T> bool AVL<T>::insert(T x) {
    std::cout << "\nINSERTING....\n";
    Node<T> * *p;
    std::vector<Node<T>**> path;
    if ( find(x, p, path)) return 0;
    *p = new Node<T>(x);
    path.push_back(p);
    Node<T>** temp;
    while (!path.empty()) {
        temp = path.back();
        std::cout << "temp: " << (*temp)->key << std::endl;
        path.pop_back();
        updateHeight(*temp);
        balance(temp);
    }
    return 1;
}

template<class T>
bool AVL<T>::remove(T x) {
    Node<T>** p;
    std::vector<Node<T>**> path;
    if ( !find(x, p, path) ) return 0;
    if ( (*p)->nodes[0] && (*p)->nodes[1] )
    {
        Node<T>** q = Rep(p);
        (*p)->key = (*q)->key;
        p = q;
    }
    Node<T>* t = *p;
    *p = (*p)->nodes[ (*p)->nodes[0] == 0 ];
    delete t;
    Node<T>** temp;
    while (!path.empty()) {
        temp = path.back();
        path.pop_back();
        updateHeight(*temp);
        balance(temp);
    }
    return 1;
}

template<class T>
Node<T>** AVL<T>::Rep(Node<T>** q){
    m_b = !m_b;
    q = &((*q)->nodes[!m_b]);
    while( (*q)->nodes[m_b] )
        q = &((*q)->nodes[m_b]);
    return q;
}


template<class T>
void AVL<T>::InOrderR(Node<T>* n)
{
    if ( !n ) return;
    InOrderR(n->nodes[0]);
    std::cout<<n->key<<" ";
    InOrderR(n->nodes[1]);
}

template<class T>
int AVL<T>::height(Node<T>* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

template<class T>
void AVL<T>::updateHeight(Node<T>* n) {
    n->height = 1 +std::max(height(n->nodes[0]), height(n->nodes[1]));
}

template<class T>
Node<T>* AVL<T>::rightRotation(Node<T>* head) {
    if (head == nullptr || head->nodes[0] == nullptr) {
        return head;
    }
    Node<T>* newHead = head->nodes[0];
    head->nodes[0] = newHead->nodes[1];
    newHead->nodes[1] = head;
    updateHeight(head);
    updateHeight(newHead);
    return newHead;
}

template<class T>
Node<T>* AVL<T>::leftRotation(Node<T>* head) {
    if (head == nullptr || head->nodes[1] == nullptr) {
        return head;
    }
    Node<T>* newHead = head->nodes[1];
    head->nodes[1] = newHead->nodes[0];
    newHead->nodes[0] = head;
    updateHeight(head);
    updateHeight(newHead);
    return newHead;
}

template<class T>
int AVL<T>::balanceFactor(Node<T>* n) {
    if (n == nullptr) {
        return 0;
    }
    return height(n->nodes[1]) - height(n->nodes[0]);
}

template<class T>
void AVL<T>::balance(Node<T>** p) {
    if (*p == nullptr) {
        return;
    }
    int balance = balanceFactor(*p);
    std::cout << "BALANCE: " << balance << std::endl;
    if (balance > 1) {
        if ((*p)->nodes[1] != nullptr && balanceFactor((*p)->nodes[1]) < 0)
          (*p)->nodes[1] = rightRotation((*p)->nodes[1]);
        *p = leftRotation(*p);
    } else if (balance < -1) {
        if ((*p)->nodes[0] != nullptr && balanceFactor((*p)->nodes[0]) > 0)
          (*p)->nodes[0] = leftRotation((*p)->nodes[0]);
        *p = rightRotation(*p);
    }
}
#endif
