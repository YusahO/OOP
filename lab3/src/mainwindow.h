#pragma once

#include "ui_mainwindow.h"
#include <QtWidgets>

#include "BaseAction.h"
#include "CameraAction.h"
#include "ModelAction.h"
#include "ModelsAction.h"
#include "SceneAction.h"
#include "Exceptions.h"
#include "BaseDrawer.h"
#include "DrawerSolution.h"
#include "QtFactory.h"
#include "Facade.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addCameraBtn_clicked();

    void on_loadModelBtn_clicked();
    void on_deleteModelBtn_clicked();
    void on_deleteModelsBtn_clicked();

    void on_cameraCB_currentIndexChanged(int index);

    void on_deleteCameraBtn_clicked();

    void on_upBtn_clicked();

    void on_rightBtn_clicked();

    void on_downBtn_clicked();

    void on_leftBtn_clicked();

    void on_moveBtn_clicked();

    void on_scaleBtn_clicked();

    void on_rotateBtn_clicked();

    void on_moveAllBtn_clicked();

    void on_scaleAllBtn_clicked();

    void on_rotateAllBtn_clicked();

    void on_botLeftBtn_clicked();
    void on_botRightBtn_clicked();

    void on_topLeftBtn_clicked();
    void on_topRightBtn_clicked();


protected:
    void setupScene();
    void updateScene();
    void checkCamExist();
    void checkModelsExist();
    void checkCamDelete();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *_scene;
    std::shared_ptr<QGraphicsScene> m_scene;
    std::shared_ptr<Facade> m_facade;
    std::shared_ptr<BaseDrawer> m_drawer;

    std::vector<std::size_t> m_models;
    std::vector<std::size_t> m_cameras;
    std::size_t m_camera_index = 0;
    std::size_t m_model_index = 0;
};
