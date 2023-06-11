#include "Controller.hpp"

#include <QLabel>
#include <QDebug>

Controller::Controller(QWidget *parent)
    : QWidget(parent),
      m_is_visit(FLOORS, false)
{
    connect(this, &Controller::reachFloorSignal, this, &Controller::reachFloor);
}

void Controller::saveFloorButtons(const std::vector<Button *> &buttons)
{
    m_buttons_floor = buttons;
}

void Controller::saveCabinButtons(const std::vector<Button *> &buttons)
{
    m_buttons_elevator = buttons;
}


void Controller::newTarget(bool new_floor_queried, int floor)
{
    this->m_state = BUSY;
    if (new_floor_queried)
    {
        this->m_is_visit[floor - 1] = true;

        findNewTarget(floor);
        m_target_floor = floor;

        decideDirection();
        if (m_direction == STAY)
        {
            emit reachFloorSignal();
        }
        else
        {
            emit moveCabinSignal();
        }
    }
    else if (findNewTarget(floor))
    {
        m_target_floor = floor;
        decideDirection();

        if (m_direction != STAY)
        {
            updateFloor();
            emit moveCabinSignal();
        }
        else
        {
            emit reachFloorSignal();
        }
    }
}

void Controller::decideDirection()
{
    if (m_target_floor > m_cur_floor)
    {
        m_direction = UP;
    }
    else if (m_target_floor < m_cur_floor)
    {
        m_direction = DOWN;
    }
    else
    {
        m_last_direction = m_direction;
        m_direction = STAY;
    }
}

bool Controller::findNewTarget(int &new_target)
{
    bool rc = false;

    Direction dir;

    if (m_direction != STAY)
        dir = m_direction;
    else
        dir = (m_last_direction == STAY) ? UP : m_last_direction;

    for (int i = m_cur_floor; !rc && i <= FLOORS && i > 0; i = i + dir)
    {
        if (m_is_visit[i - 1])
        {
            new_target = i;
            rc = true;
        }
    }

    if (!rc)
    {
        dir = ((dir == UP) ? DOWN : UP);

        for (int i = m_cur_floor; !rc && i <= FLOORS && i > 0; i = i + dir)
        {
            if (m_is_visit[i - 1])
            {
                new_target = i;
                rc = true;
            }
        }
    }

    return rc;
}

void Controller::reachFloor()
{
    if (m_state != BUSY)
        return;

    emit m_buttons_floor[m_target_floor - 1]->unpressSignal();
    emit m_buttons_elevator[m_target_floor - 1]->unpressSignal();

    m_is_visit[m_target_floor - 1] = false;

    m_state = FREE;
    emit stopCabinSignal();
}

void Controller::updateFloor()
{
    m_cur_floor += m_direction;

    qDebug() << "... Лифт едет на этаж № " << m_cur_floor;
}
