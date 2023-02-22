#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <iostream>
#include <string>
extern "C"
{
    #include "mesh.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void unloadMesh(void);

public slots:
    int loadMesh(void);
    
private:
    Ui::MainWindow *ui;
    mesh_t *mesh;
};

#endif // __MAINWINDOW_H__