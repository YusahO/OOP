#include "mainwindow.h"

#include <memory>
#include <array>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->layout_ = std::make_unique<QVBoxLayout>();
    this->ui->centralwidget->setLayout(this->layout_.get());
    this->layout_->addWidget(this->m_elevator.widget());

    std::vector<Button *> cabin_buttons = {
        ui->cabin_button_10,
        ui->cabin_button_9,
        ui->cabin_button_8,
        ui->cabin_button_7,
        ui->cabin_button_6,
        ui->cabin_button_5,
        ui->cabin_button_4,
        ui->cabin_button_3,
        ui->cabin_button_2,
        ui->cabin_button
    };

    std::vector<Button *> floor_buttons = {
        ui->floor_button_10,
        ui->floor_button_9,
        ui->floor_button_8,
        ui->floor_button_7,
        ui->floor_button_6,
        ui->floor_button_5,
        ui->floor_button_4,
        ui->floor_button_3,
        ui->floor_button_2,
        ui->floor_button
    };

    Controller *controller = dynamic_cast<Controller *>(m_elevator.widget());

    controller->saveFloorButtons(floor_buttons);
    controller->saveCabinButtons(cabin_buttons);

    for (size_t i = 0; i < FLOORS; ++i)
    {
        cabin_buttons[i]->setFloor(i + 1);
        floor_buttons[i]->setFloor(i + 1);

        connect(cabin_buttons[i], &Button::pressSignal, controller, &Controller::newTarget);
        connect(floor_buttons[i], &Button::pressSignal, controller, &Controller::newTarget);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

