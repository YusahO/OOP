#pragma once

#include <QObject>

#include "Controller.hpp"
#include "Cabin.hpp"

class Elevator : public QObject
{
    Q_OBJECT

public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() = default;

    QWidget* widget();

private:
    Controller m_controller;
    Cabin m_cabin;
};