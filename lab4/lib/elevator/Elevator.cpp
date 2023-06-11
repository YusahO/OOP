
#include "Elevator.hpp"

Elevator::Elevator(QObject *parent)
    : QObject(parent)
{
    m_controller.setStyleSheet("background-color:lightblue");

    connect(&m_cabin, &Cabin::cabinFinished, &m_controller, &Controller::newTarget);
    connect(&m_controller, &Controller::moveCabinSignal, &m_cabin, &Cabin::handleMoving);
    connect(&m_controller, &Controller::stopCabinSignal, &m_cabin, &Cabin::handleWait);
}

QWidget *Elevator::widget()
{
    return &m_controller;
}
