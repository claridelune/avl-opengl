#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
public:
    T key;
    int height;
    Node* nodes[2];

    Node(T k);
};

template<class T>
Node<T>::Node(T k) {
    key = k;
    height = 1;
    nodes[0] = nodes[1] = 0;
}

#endif
