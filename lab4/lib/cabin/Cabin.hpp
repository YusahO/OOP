#pragma once

#include <QObject>
#include <QTimer>

#include "defines.hpp"
#include "Doors.hpp"

class Cabin : public QObject
{
    Q_OBJECT

    using cabinState = enum {
        WAIT,
        MOVING,
        STOP
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() override = default;

signals:
    void openDoors();
    void updateFloorSignal();
    void readyToMoveSignal();
    void cabinFinished(bool, int = 1);

public slots:
    void handleWait();
    void handleMoving();
    void handleStop();

private:
    cabinState m_state;
    Doors m_doors;
    QTimer m_move_timer;
};
