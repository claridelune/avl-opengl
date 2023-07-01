#include "../include/Window.h"

Window::Window(int width, int height, const char* title)
    : m_Width(width), m_Height(height), m_Title(title) {
    if (!glfwInit()) {
        std::cout << "Fallo en la inicialización de GLFW" << std::endl;
    }
    // glutInit(nullptr, nullptr);
    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

    if (!m_Window) {
        std::cout << "Fallo en la creación de la ventana GLFW" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_Window);
}

Window::~Window() {
    glfwTerminate();
}

void Window::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update() const {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::Closed() const {
    return glfwWindowShouldClose(m_Window);
}
