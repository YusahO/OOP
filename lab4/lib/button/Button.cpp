#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) 
    : QPushButton(parent)
{
    connect(this, &Button::clicked, this, &Button::pressSlot);
    connect(this, &Button::unpressSignal, this, &Button::unpressSlot);

    m_state = INACTIVE;
    m_current_button_floor = 1;
}

void Button::setFloor(int floor)
{
    m_current_button_floor = floor;
}

void Button::pressSlot()
{
    if (this->m_state != INACTIVE)
        return;

    this->setStyleSheet(QString("background-color:") + ACTIVATED_BUTTON_COLOR);
    this->update();

    qDebug() << "[!] Вызов на этаж №" << this->m_current_button_floor;

    this->m_state = ACTIVE;
    this->setDisabled(true);

    emit pressSignal(true, this->m_current_button_floor);
}

void Button::unpressSlot()
{
    if (this->m_state == INACTIVE)
        return;

    this->setStyleSheet("");
    this->update();

    this->m_state = INACTIVE;
    this->setDisabled(false);
}
