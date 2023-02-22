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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadMeshAction;
    QAction *action_2;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QOpenGLWidget *openGLWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QFrame *line_4;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLabel *label_3;
    QFrame *line_2;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_10;
    QFrame *line;
    QLineEdit *lineEdit_17;
    QPushButton *pushButton;
    QLineEdit *lineEdit_9;
    QLabel *label;
    QFrame *line_3;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1160, 850);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        loadMeshAction = new QAction(MainWindow);
        loadMeshAction->setObjectName(QString::fromUtf8("loadMeshAction"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(250, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_4, 16, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 3, 2, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_8, 7, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 18, 0, 1, 3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 6, 0, 1, 3);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 19, 0, 1, 3);

        lineEdit_11 = new QLineEdit(groupBox);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_11, 8, 1, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_12, 8, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 13, 0, 1, 3);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 12, 0, 1, 3);

        lineEdit_18 = new QLineEdit(groupBox);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_18, 17, 2, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_7, 7, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_5, 16, 1, 1, 1);

        lineEdit_16 = new QLineEdit(groupBox);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_16, 17, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_6, 16, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 10, 0, 1, 3);

        lineEdit_10 = new QLineEdit(groupBox);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_10, 8, 0, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 3);

        lineEdit_17 = new QLineEdit(groupBox);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_17, 17, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 0, 1, 3);

        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_9, 7, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 0, 1, 3);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 3, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 20, 0, 1, 3);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1160, 35));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(loadMeshAction);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadMeshAction->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\321\200\320\260\320\275\321\201\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "ay", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        lineEdit_11->setPlaceholderText(QCoreApplication::translate("MainWindow", "y", nullptr));
        lineEdit_12->setPlaceholderText(QCoreApplication::translate("MainWindow", "z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_18->setPlaceholderText(QCoreApplication::translate("MainWindow", "z", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "ax", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        lineEdit_16->setPlaceholderText(QCoreApplication::translate("MainWindow", "x", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("MainWindow", "x", nullptr));
        lineEdit_17->setPlaceholderText(QCoreApplication::translate("MainWindow", "y", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "az", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
