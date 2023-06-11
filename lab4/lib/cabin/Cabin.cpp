#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent)
    : QObject(parent)
{
    m_state = STOP;

    connect(this, &Cabin::openDoors, &m_doors, &Doors::startOpening);
    connect(&m_move_timer, &QTimer::timeout, this, &Cabin::handleStop);
    connect(&m_doors, &Doors::doorClosed, this, &Cabin::handleStop);
}

void Cabin::handleWait()
{
    m_state = WAIT;

    m_move_timer.stop();
    emit openDoors();
}

void Cabin::handleMoving()
{
    if (m_state == STOP || m_state == MOVING)
    {
        m_state = MOVING;
        m_move_timer.start(MOVE_TIME);
    }
}

void Cabin::handleStop()
{
    if (m_state != STOP)
    {
        m_state = STOP;
        emit cabinFinished(false);
    }
}



