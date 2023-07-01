#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void Clear() const;
    void Update() const;
    bool Closed() const;

private:
    GLFWwindow* m_Window;
    int m_Width, m_Height;
    const char* m_Title;
};
