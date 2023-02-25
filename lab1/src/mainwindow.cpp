#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "mesh_actions.h"
#include <QFileDialog>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(ui->loadMeshAction, &QAction::triggered, this, &MainWindow::loadMesh);
    connect(ui->translatePB, &QPushButton::clicked, this, &MainWindow::translateMesh);
    connect(ui->rotatePB, &QPushButton::clicked, this, &MainWindow::rotateMesh);
    connect(ui->scalePB, &QPushButton::clicked, this, &MainWindow::scaleMesh);
}

MainWindow::~MainWindow()
{
    action_t action = { .id = DESTROY };
    process_action(action);
    delete ui;
}

void MainWindow::renderMesh(void)
{
    ui->graphicsView->scene()->clear();
    scene_t scene = { 
        .scene = ui->graphicsView->scene(), 
        .width = (double)ui->graphicsView->width(), 
        .height = (double)ui->graphicsView->height() 
    };

    action_t action = { 
        .id = RENDER, 
        .scene = scene 
    };
    error_code_t ec = process_action(action);
    process_error(ec);
}

void MainWindow::translateMesh(void)
{
    double dx = ui->deltaXSB->value();
    double dy = ui->deltaYSB->value();
    double dz = ui->deltaZSB->value();

    action_t action = { 
        .id = TRANSLATE, 
        .translation = { dx, dy, dz } 
    };

    error_code_t ec = process_action(action);
    process_error(ec);
    if (ec == SUCCESS)
        renderMesh();
}

void MainWindow::rotateMesh(void)
{
    double px = ui->pivRotXSB->value();
    double py = ui->pivRotYSB->value();
    double pz = ui->pivRotZSB->value();

    double ax = ui->angleXSB->value() * 3.1416 / 180;
    double ay = ui->angleYSB->value() * 3.1416 / 180;
    double az = ui->angleZSB->value() * 3.1416 / 180;

    action_t action = {
        .id = ROTATE,
        .rotation = { .pivot = { px, py, pz }, .angles = { ax, ay, az } }
    };

    error_code_t ec = process_action(action);
    process_error(ec);
    if (ec == SUCCESS)
        renderMesh();
}

void MainWindow::scaleMesh(void)
{
    double px = ui->pivScaleXSB->value();
    double py = ui->pivScaleYSB->value();
    double pz = ui->pivScaleZSB->value();

    double kx = ui->factorXSB->value();
    double ky = ui->factorYSB->value();
    double kz = ui->factorZSB->value();

    action_t action = {
        .id = SCALE,
        .scaling = { .pivot = { px, py, pz }, .factor = { kx, ky, kz } }
    };
    
    error_code_t ec = process_action(action);
    process_error(ec);
    if (ec == SUCCESS)
        renderMesh();
}   

void MainWindow::loadMesh(void) 
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите файл модели"), "", tr("OBJ Files (*.obj)"));

    action_t action = { 
        .id = LOAD, 
        .filename = filename.toUtf8().data() 
    };
    
    error_code_t ec = process_action(action);
    process_error(ec);

    if (ec == SUCCESS)
        renderMesh();
}