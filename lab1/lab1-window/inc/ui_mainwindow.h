/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QOpenGLWidget *openGLWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_7;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_3;
    QFrame *line_2;
    QFrame *line;
    QFrame *line_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(875, 560);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(180, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_5, 8, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_8, 5, 1, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_4, 8, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_7, 5, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 0, 1, 3);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 3);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_6, 8, 2, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_9, 5, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 2, 2, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 6, 0, 1, 3);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 0, 1, 3);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "y", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "x", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "y", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "z", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "z", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
