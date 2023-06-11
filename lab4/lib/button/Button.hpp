#pragma once

#include <QPushButton>
#include <memory>
#include "defines.hpp"

class Button : public QPushButton
{
    Q_OBJECT;

    using ButtonState = enum
    {
        ACTIVE,
        INACTIVE
    };

public:
    explicit Button(QWidget *parent = nullptr);
    ~Button() override = default;

    void setFloor(int floor);

signals:
    void pressSignal(bool, int);
    void unpressSignal();

public slots:
    void pressSlot();
    void unpressSlot();

private:
    ButtonState m_state;
    size_t m_current_button_floor;
};
