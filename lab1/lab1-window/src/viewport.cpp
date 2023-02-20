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

void Viewport::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Viewport::paintGL()
{

}