#include "mainwindow.h"
#include "viewport.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Viewport viewport;

    connect(ui->loadMeshAction, &QAction::triggered, this, &MainWindow::loadMesh);
}

MainWindow::~MainWindow()
{
    unloadMesh();
    delete ui;
}

int MainWindow::loadMesh(void)
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите файл модели"), "", tr("OBJ Files (*.obj)"));
    std::string filenameStd = filename.toStdString();
    std::cout << filenameStd.c_str() << '\n';

    mesh_t *m = mesh_create_from_file(filenameStd.c_str());
    if (!m)
    {
        std::cout << "Failed to load mesh from " << filenameStd << "There is miniryr.txt" << std::endl;
        return -1;
    }
    mesh = m;
    return 0;
}

void MainWindow::unloadMesh(void)
{
    if (mesh)
        mesh_destroy(mesh);
}