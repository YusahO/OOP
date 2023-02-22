#include "viewport.h"

Viewport::Viewport(QOpenGLWidget *parent)
    : QOpenGLWidget(parent)
{
}

Viewport::~Viewport(void)
{
}

void Viewport::initializeGL(void)
{
    initializeOpenGLFunctions();
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
}

void Viewport::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Viewport::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

}