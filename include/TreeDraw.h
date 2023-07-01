#ifndef TREE_DRAW_H
#define TREE_DRAW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <unordered_map>
#include "Node.h"
#include "AVL.h"
#include <cmath>

class TreeDraw {
public:
    TreeDraw(AVL<int>& avl, int _windowWidth, int _windowHeight);
    void Draw() const;
    std::pair<float, float>& getNodePosition(Node<int>* node) {
        for (auto& pair : m_nodePositions) {
          if (pair.first == node) {
            return pair.second;
          }
          throw std::out_of_range("Node not found in m_nodePositions");
        }
    }

    const std::pair<float, float>& getNodePosition(Node<int>* node) const {
        for (const auto& pair : m_nodePositions) {
            if (pair.first == node) {
                return pair.second;
            }
        }
        throw std::out_of_range("Node not found in m_nodePositions");
    }
    void AddNode(int value);
    void DeleteNode(int value);

private:
    void DrawNode(Node<int>* node, float x, float y, float radius) const;
    void DrawEdge(float x1, float y1, float x2, float y2) const;
    void CalculateNodePositions(Node<int>* node, float x, float y, float xSpacing, float ySpacing);
    void drawCircle(float x, float y, float radius) const;
    void drawLine(float x1, float y1, float x2, float y2) const;

    AVL<int>& m_avl;
    std::vector<std::pair<Node<int>*, std::pair<float, float>>> m_nodePositions;
    int windowHeight;
    int windowWidth;

};

#endif
