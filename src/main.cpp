#include "../include/AVL.h"
#include "../include/Window.h"
#include "../include/TreeDraw.h"
#include <iostream>

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    AVL<int> t;

    for (int i = 10; i < 100; i = i+10) {
        t.insert(i);
    }

    t.InOrderR(t.root);

    Window window(800, 600, "AVL zzz");
    TreeDraw tree(t, 800, 600);

    int x;
    while (!window.Closed()) {
        window.Clear();

        tree.Draw();

        window.Update();
        if (std::cin >> x) {
            tree.AddNode(x);
            std::cout << "Nodo agregado: " << x << std::endl;
        }
        glGetError();
    }

    return 0;
}
