#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <memory>

#include "Elevator.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onCabinBtnClicked(const int btn_number);
    void onFloorBtnClicked(const int btn_number);

private:
    Ui::MainWindow *ui;

    std::unique_ptr<QVBoxLayout> layout_;
    Elevator m_elevator;
};