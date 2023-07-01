#include "../include/TreeDraw.h"
#include <iostream>
TreeDraw::TreeDraw(AVL<int>& avl, int _windowWidth, int _windowHeight) : m_avl(avl), windowWidth(_windowWidth), windowHeight(_windowHeight) {
    std::cout << "Constructor de TreeDraw" << std::endl;
    CalculateNodePositions(avl.root, 0.0f, -0.750f, 0.40f, 0.40f);
}

void TreeDraw::drawCircle(float x, float y, float radius) const{
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void TreeDraw::drawLine(float x1, float y1, float x2, float y2) const{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void TreeDraw::Draw() const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Limpiar el buffer de color

    std::cout << "alñskdjfañlsdkfjañsldkfja" << std::endl;
    for (const auto& nodePosition : m_nodePositions) {
        float x = nodePosition.second.first;
        float y = nodePosition.second.second;
        float radius = 0.1f;
        DrawNode(nodePosition.first, x, y, radius);
    }

    for (const auto& nodePosition : m_nodePositions) {
        float x1 = nodePosition.second.first;
        float y1 = nodePosition.second.second;
        Node<int>* node = nodePosition.first;
        if (node->nodes[0] != nullptr) {
            Node<int> *node0 = node->nodes[0];
            float x2 = getNodePosition(node0).first;
            float y2 = getNodePosition(node0).second;
            DrawEdge(x1, y1, x2, y2);
        }
        if (node->nodes[1] != nullptr) {
            Node<int>* node1 = node->nodes[1];
            float x2 = getNodePosition(node1).first;
            float y2 = getNodePosition(node1).second;
            DrawEdge(x1, y1, x2, y2);
        }
    }
    glFlush();
}

void TreeDraw::DrawNode(Node<int>* node, float x, float y, float radius) const {
    std::cout << "\nx: " << x << " y: " << y << std::endl;
    glColor3f(1.0f, 1.0f, 1.0f); // color blanco
    drawCircle(x, y, radius);

    glColor3f(0.0f, 0.0f, 0.0f); // color blanco
    glRasterPos2f(x - 0.05f, y - 0.05f);
    std::string keyString = std::to_string(node->key);
    std::cout << "KEYYYY: " << keyString << std::endl;
    for (char c : keyString) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void TreeDraw::DrawEdge(float x1, float y1, float x2, float y2) const {
    glColor3f(1.0f, 1.0f, 1.0f); // color blanco
    drawLine(x1, y1, x2, y2);
}

void TreeDraw::CalculateNodePositions(Node<int>* node, float x, float y, float xSpacing, float ySpacing) {
    if (node == nullptr) {
        return;
    }

    CalculateNodePositions(node->nodes[0], x - xSpacing, y + ySpacing, xSpacing / 2.0f, ySpacing);
    m_nodePositions.push_back(std::make_pair(node, std::make_pair(x, y)));
    CalculateNodePositions(node->nodes[1], x + xSpacing, y + ySpacing, xSpacing / 2.0f, ySpacing);
}

void TreeDraw::AddNode(int value) {
    m_avl.insert(value);
    m_nodePositions.clear();
    CalculateNodePositions(m_avl.root, 0.0f, -0.750f, 0.40f, 0.40f);
}

void TreeDraw::DeleteNode(int value) {
    m_avl.remove(value);
    m_nodePositions.clear();
    CalculateNodePositions(m_avl.root, 0.0f, -0.750f, 0.40f, 0.40f);
}
