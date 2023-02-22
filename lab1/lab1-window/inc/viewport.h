#ifndef __VIEWPORT_H__
#define __VIEWPORT_H__

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <string>

class Viewport : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit Viewport(QOpenGLWidget *parent = nullptr);
    ~Viewport();

protected:
    void initializeGL(void);
    void resizeGL(int width, int height);
    void paintGL();

// private:
//     mesh_t *mesh;

};

#endif // __VIEWPORT_H__