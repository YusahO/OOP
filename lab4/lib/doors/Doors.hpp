#pragma once

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT

    using doorsState = enum {
        OPEN,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    Doors();
    ~Doors() override = default;

signals:
    void doorClosed();

public slots:
    void startClosing();
    void startOpening();
    void open();
    void close();

private:
    doorsState m_state;

    QTimer m_open_timer;
    QTimer m_close_timer;
    QTimer m_wait_timer;
};
