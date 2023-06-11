#include "Doors.hpp"
#include "defines.hpp"
#include <QDebug>

Doors::Doors()
    : m_state(CLOSED)
{
    connect(&m_open_timer,  &QTimer::timeout, this, &Doors::open);
    connect(&m_wait_timer,  &QTimer::timeout, this, &Doors::startClosing);
    connect(&m_close_timer, &QTimer::timeout, this, &Doors::close);
}

void Doors::startOpening()
{
    if (!(m_state == CLOSED || m_state == CLOSING))
        return;

    qDebug() << "Двери открываются...";

    int remaining_time = m_state == CLOSING ? m_close_timer.remainingTime() : 0;
    this->m_state = OPENING;
    
    m_close_timer.stop();
    
    this->m_open_timer.start(WAIT_TIME - remaining_time);
}

void Doors::open()
{
    if (this->m_state != OPENING)
        return;

    this->m_state = OPEN;

    qDebug() << "[!] Двери открыты";

    this->m_wait_timer.start(WAIT_TIME);
}

void Doors::close()
{
    if (this->m_state != CLOSING)
        return;

    this->m_state = CLOSED;

    qDebug() << "[!] Двери закрылись";

    emit doorClosed();
}

void Doors::startClosing()
{
    if (this->m_state != OPEN)
        return;

    this->m_state = CLOSING;

    qDebug() << "Двери закрываются...";

    this->m_close_timer.start(WAIT_TIME);
}
