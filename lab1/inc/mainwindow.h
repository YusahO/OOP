#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "scene.h"
#include "mesh.h"
#include "error_processor.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void renderMesh(void);

public slots:
    void loadMesh(void);
    void saveMesh(void);
    void translateMesh(void);
    void rotateMesh(void);
    void scaleMesh(void);
    void clearTransformFields(void);

private:
    Ui::MainWindow *ui;
};

#endif // __MAINWINDOW_H__