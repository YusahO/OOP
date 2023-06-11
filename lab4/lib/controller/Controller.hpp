#pragma once

#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <memory>
#include <vector>

#include "defines.hpp"
#include "Button.hpp"

class Controller : public QWidget
{
    Q_OBJECT

    using ControllerState = enum
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

    void saveFloorButtons(const std::vector<Button *> &buttons);
    void saveCabinButtons(const std::vector<Button *> &buttons);

signals:
    void stopCabinSignal();
    void moveCabinSignal();
    void reachFloorSignal();

public slots:
    void newTarget(bool, int = 1);
    void reachFloor();

private:
    bool findNewTarget(int &new_target);
    void decideDirection();
    void updateFloor();

private:
    int m_cur_floor = START_FLOOR;
    int m_target_floor = START_FLOOR;

    Direction m_last_direction = STAY;
    Direction m_direction = STAY;

    ControllerState m_state = FREE;
    std::vector<bool> m_is_visit;

    std::vector<Button *> m_buttons_floor;
    std::vector<Button *> m_buttons_elevator;
    
    std::unique_ptr<QHBoxLayout> m_layout;
};
