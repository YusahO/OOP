#include "mainwindow.h"

#include <cmath>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <source_location>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    m_facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    m_scene = std::make_shared<QGraphicsScene>(this);

    ui->graphicsView->setScene(m_scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    m_scene->setSceneRect(0, 0, cont.width(), cont.height());
    m_camera_index = 1;

    auto solution(new DrawerSolution<QtFactory, QGraphicsScene>());
    m_drawer = solution->createDrawer(m_scene.get());
}

void MainWindow::updateScene()
{
    auto scene = std::make_shared<Scene>();
    ClearScene clear_cmd(m_drawer);
    m_facade->execute(clear_cmd);

    GetScene get_scene_cmd(scene);
    m_facade->execute(get_scene_cmd);

    DrawScene draw_cmd(scene, m_drawer);
    m_facade->execute(draw_cmd);
}

void MainWindow::checkCamExist()
{
    if (!m_cameras.size())
    {
        auto loc = std::source_location::current();
        throw CameraException(
            loc.file_name(),
            loc.function_name(),
            loc.line(),
            "No camera found"
        );
    }
}

void MainWindow::checkModelsExist()
{
    if (!m_models.size())
    {
        auto loc = std::source_location::current();
        throw ModelException(
            loc.file_name(),
            loc.function_name(),
            loc.line(),
            "No models found"
        );
    }
}

void MainWindow::checkCamDelete()
{
    if (m_cameras.size() <= 1 && m_models.size())
    {
        auto loc = std::source_location::current();
        throw CameraException(
            loc.file_name(),
            loc.function_name(),
            loc.line(),
            "Cannot delete the last camera with the loaded models"
        );
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();

    auto id = std::make_shared<size_t>(0);
    Vertex location(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    Vertex angles(0);
    AddCamera addCMD(id, location, angles);

    m_facade->execute(addCMD);
    m_cameras.push_back(*id);

    updateScene();

    auto cam = ui->cameraCB;

    std::string camName = std::string("Camera") + std::to_string(m_camera_index++);
    cam->addItem(QString(camName.data()));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto path = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", ".");

    if (path.isNull())
        return;

    std::shared_ptr<BaseObject> model = std::make_shared<CarcassModel>();
    auto id = std::make_shared<size_t>(0);
    std::string pathFileName = path.toStdString();

    try
    {
        LoadModel load_cmd(model, pathFileName);
        m_facade->execute(load_cmd);

        AddModel add_cmd(id, model);
        m_facade->execute(add_cmd);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке модели из файла!");
        return;
    }

    m_models.push_back(*id);
    updateScene();
    m_model_index++;
    auto fileName = QFileInfo(path.toUtf8().data()).fileName();
    QString figName = QString("CarcasModel") + QString::number(m_model_index) + QString(" load from ") + QString(fileName);
    ui->modelsCB->addItem(figName);
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    std::size_t id = m_models.at(ui->modelsCB->currentIndex());
    RemoveModel cmd(id);
    m_facade->execute(cmd);

    m_models.erase(m_models.begin() + ui->modelsCB->currentIndex());
    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        std::size_t id = m_models.at(i);
        RemoveModel cmd(id);
        m_facade->execute(cmd);

        m_models.erase(m_models.begin() + i);
        ui->modelsCB->removeItem(i);
    }

    updateScene();
}


void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    std::size_t id = m_cameras.at(index);
    SetCamera cmd(id);
    m_facade->execute(cmd);

    updateScene();
}


void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Для удаления этой камеры необходимо удалить все модели");
        return;
    }

    std::size_t id = m_cameras.at(ui->cameraCB->currentIndex());
    RemoveCamera cmd(id);
    m_facade->execute(cmd);

    m_cameras.erase(m_cameras.begin() + ui->cameraCB->currentIndex());
    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    TranslateCamera move_cmd(camera, 0, 10, 0);
    m_facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    TranslateCamera move_cmd(camera, 0, -10, 0);
    m_facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_rightBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    //std::size_t id = m_cameras.at(ui->cameraCB->currentIndex());
    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    TranslateCamera move_cmd(camera, -10, 0, 0);
    m_facade->execute(move_cmd);

    updateScene();
}


void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    TranslateCamera move_cmd(camera, 10, 0, 0);
    m_facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_botLeftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    RotateCamera rot_cmd(camera, 0, M_PI / 10., 0);
    m_facade->execute(rot_cmd);

    updateScene();
}

void MainWindow::on_botRightBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    RotateCamera rot_cmd(camera, 0, -M_PI / 10., 0);
    m_facade->execute(rot_cmd);
    
    updateScene();
}

void MainWindow::on_topLeftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    qDebug() << "wind camer " << (void *)camera.get();

    RotateCamera rot_cmd(camera, 0, 0, -M_PI / 10.);
    m_facade->execute(rot_cmd);
    
    updateScene();
}

void MainWindow::on_topRightBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::warning(nullptr, "Предупреждение", "Пожалуйста, загрузите камеру");
        return;
    }

    std::shared_ptr<Camera> camera;

    GetMainCamera get_camera(camera);
    m_facade->execute(get_camera);

    RotateCamera rot_cmd(camera, 0, 0, M_PI / 10.);
    m_facade->execute(rot_cmd);
    
    updateScene();
}


void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет каркасных фигур!");
        return;
    }

    std::shared_ptr<BaseObject> model;

    GetSceneObject get_object_cmd(model, m_models.at(ui->modelsCB->currentIndex()));
    m_facade->execute(get_object_cmd);

    TranslateModel move_cmd(model, ui->dxDSB->value(), -ui->dyDSB->value(), ui->dzDSB->value());
    m_facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_moveAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<BaseObject> composite;
    GetSceneObjects get_objs(composite);
    m_facade->execute(get_objs);

    TranslateModels move_cmd(composite, ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value());

    m_facade->execute(move_cmd);
    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<BaseObject> model; // = std::make_shared<CarcassModel>();

    GetSceneObject get_object_cmd(model, m_models.at(ui->modelsCB->currentIndex()));
    m_facade->execute(get_object_cmd);


    ScaleModel scale_cmd(model, ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value());
    m_facade->execute(scale_cmd);

    updateScene();
}

void MainWindow::on_scaleAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<BaseObject> composite;
    GetSceneObjects get_objs(composite);
    m_facade->execute(get_objs);

    ScaleModels scale_cmd(composite,
        ui->kxDSB->value(),
        ui->kyDSB->value(),
        ui->kzDSB->value());
    m_facade->execute(scale_cmd);

    updateScene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    shared_ptr<BaseObject> model; // = std::make_shared<CarcassModel>();

    GetSceneObject get_object_cmd(model, m_models.at(ui->modelsCB->currentIndex()));
    m_facade->execute(get_object_cmd);

    RotateModel rotate_cmd(model,
        ui->axDSB->value() * M_PI / 180,
        ui->ayDSB->value() * M_PI / 180,
        ui->azDSB->value() * M_PI / 180);
    m_facade->execute(rotate_cmd);

    updateScene();
}

void MainWindow::on_rotateAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<BaseObject> composite;
    GetSceneObjects get_objs(composite);
    m_facade->execute(get_objs);

    RotateModels rotate_cmd(composite,
        ui->axDSB->value() * M_PI / 180,
        ui->ayDSB->value() * M_PI / 180,
        ui->azDSB->value() * M_PI / 180);
    m_facade->execute(rotate_cmd);

    updateScene();
}
