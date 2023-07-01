#ifndef OPENGL_H
#define OPENGL_H

#include "AVL.h"
#include "Node.h"

class TreeRenderer {
public:
    TreeRenderer();
    void drawTree(Node<int>* root);

private:
    void drawNode(Node<int>* node, float x, float y, float radius);
};

#endif
