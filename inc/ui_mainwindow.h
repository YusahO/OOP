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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadMeshAction;
    QAction *action_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *translateLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *deltaYSB;
    QPushButton *translatePB;
    QLabel *label;
    QDoubleSpinBox *deltaZSB;
    QDoubleSpinBox *deltaXSB;
    QFrame *line_4;
    QGridLayout *rotateLayout;
    QDoubleSpinBox *pivRotYSB;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QDoubleSpinBox *pivRotXSB;
    QDoubleSpinBox *angleZSB;
    QLabel *label_5;
    QDoubleSpinBox *pivRotZSB;
    QDoubleSpinBox *angleYSB;
    QDoubleSpinBox *angleXSB;
    QLabel *label_3;
    QPushButton *rotatePB;
    QFrame *line_5;
    QGridLayout *scaleLayout;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *pivScaleXSB;
    QDoubleSpinBox *pivScaleYSB;
    QDoubleSpinBox *factorZSB;
    QDoubleSpinBox *pivScaleZSB;
    QDoubleSpinBox *factorYSB;
    QDoubleSpinBox *factorXSB;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_3;
    QPushButton *scalePB;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1449, 844);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        loadMeshAction = new QAction(MainWindow);
        loadMeshAction->setObjectName(QString::fromUtf8("loadMeshAction"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 200));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        translateLayout = new QGridLayout();
        translateLayout->setObjectName(QString::fromUtf8("translateLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        translateLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        translateLayout->addWidget(label_2, 2, 0, 1, 1);

        deltaYSB = new QDoubleSpinBox(groupBox);
        deltaYSB->setObjectName(QString::fromUtf8("deltaYSB"));
        deltaYSB->setMinimum(-65536.000000000000000);
        deltaYSB->setMaximum(65536.000000000000000);

        translateLayout->addWidget(deltaYSB, 2, 2, 1, 1);

        translatePB = new QPushButton(groupBox);
        translatePB->setObjectName(QString::fromUtf8("translatePB"));

        translateLayout->addWidget(translatePB, 3, 0, 1, 4);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        translateLayout->addWidget(label, 0, 0, 1, 4);

        deltaZSB = new QDoubleSpinBox(groupBox);
        deltaZSB->setObjectName(QString::fromUtf8("deltaZSB"));
        deltaZSB->setMinimum(-65536.000000000000000);
        deltaZSB->setMaximum(65536.000000000000000);

        translateLayout->addWidget(deltaZSB, 2, 3, 1, 1);

        deltaXSB = new QDoubleSpinBox(groupBox);
        deltaXSB->setObjectName(QString::fromUtf8("deltaXSB"));
        deltaXSB->setMinimum(-65536.000000000000000);
        deltaXSB->setMaximum(65536.000000000000000);

        translateLayout->addWidget(deltaXSB, 2, 1, 1, 1);


        horizontalLayout->addLayout(translateLayout);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        rotateLayout = new QGridLayout();
        rotateLayout->setObjectName(QString::fromUtf8("rotateLayout"));
        pivRotYSB = new QDoubleSpinBox(groupBox);
        pivRotYSB->setObjectName(QString::fromUtf8("pivRotYSB"));
        pivRotYSB->setMinimum(-65536.000000000000000);
        pivRotYSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(pivRotYSB, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rotateLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        rotateLayout->addWidget(label_4, 2, 0, 1, 1);

        pivRotXSB = new QDoubleSpinBox(groupBox);
        pivRotXSB->setObjectName(QString::fromUtf8("pivRotXSB"));
        pivRotXSB->setMinimum(-65536.000000000000000);
        pivRotXSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(pivRotXSB, 2, 1, 1, 1);

        angleZSB = new QDoubleSpinBox(groupBox);
        angleZSB->setObjectName(QString::fromUtf8("angleZSB"));
        angleZSB->setMinimum(-65536.000000000000000);
        angleZSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(angleZSB, 3, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        rotateLayout->addWidget(label_5, 3, 0, 1, 1);

        pivRotZSB = new QDoubleSpinBox(groupBox);
        pivRotZSB->setObjectName(QString::fromUtf8("pivRotZSB"));
        pivRotZSB->setMinimum(-65536.000000000000000);
        pivRotZSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(pivRotZSB, 2, 3, 1, 1);

        angleYSB = new QDoubleSpinBox(groupBox);
        angleYSB->setObjectName(QString::fromUtf8("angleYSB"));
        angleYSB->setMinimum(-65536.000000000000000);
        angleYSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(angleYSB, 3, 2, 1, 1);

        angleXSB = new QDoubleSpinBox(groupBox);
        angleXSB->setObjectName(QString::fromUtf8("angleXSB"));
        angleXSB->setMinimum(-65536.000000000000000);
        angleXSB->setMaximum(65536.000000000000000);

        rotateLayout->addWidget(angleXSB, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        rotateLayout->addWidget(label_3, 0, 0, 1, 4);

        rotatePB = new QPushButton(groupBox);
        rotatePB->setObjectName(QString::fromUtf8("rotatePB"));

        rotateLayout->addWidget(rotatePB, 4, 0, 1, 4);


        horizontalLayout->addLayout(rotateLayout);

        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        scaleLayout = new QGridLayout();
        scaleLayout->setObjectName(QString::fromUtf8("scaleLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        scaleLayout->addWidget(label_6, 0, 0, 1, 4);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        scaleLayout->addWidget(label_7, 2, 0, 1, 1);

        pivScaleXSB = new QDoubleSpinBox(groupBox);
        pivScaleXSB->setObjectName(QString::fromUtf8("pivScaleXSB"));
        pivScaleXSB->setMinimum(-65536.000000000000000);
        pivScaleXSB->setMaximum(65536.000000000000000);

        scaleLayout->addWidget(pivScaleXSB, 2, 1, 1, 1);

        pivScaleYSB = new QDoubleSpinBox(groupBox);
        pivScaleYSB->setObjectName(QString::fromUtf8("pivScaleYSB"));
        pivScaleYSB->setMinimum(-65536.000000000000000);
        pivScaleYSB->setMaximum(65536.000000000000000);

        scaleLayout->addWidget(pivScaleYSB, 2, 2, 1, 1);

        factorZSB = new QDoubleSpinBox(groupBox);
        factorZSB->setObjectName(QString::fromUtf8("factorZSB"));
        factorZSB->setMinimum(-65536.000000000000000);
        factorZSB->setMaximum(65536.000000000000000);
        factorZSB->setValue(1.000000000000000);

        scaleLayout->addWidget(factorZSB, 3, 3, 1, 1);

        pivScaleZSB = new QDoubleSpinBox(groupBox);
        pivScaleZSB->setObjectName(QString::fromUtf8("pivScaleZSB"));
        pivScaleZSB->setMinimum(-65536.000000000000000);
        pivScaleZSB->setMaximum(65536.000000000000000);

        scaleLayout->addWidget(pivScaleZSB, 2, 3, 1, 1);

        factorYSB = new QDoubleSpinBox(groupBox);
        factorYSB->setObjectName(QString::fromUtf8("factorYSB"));
        factorYSB->setMinimum(-65536.000000000000000);
        factorYSB->setMaximum(65536.000000000000000);
        factorYSB->setValue(1.000000000000000);

        scaleLayout->addWidget(factorYSB, 3, 2, 1, 1);

        factorXSB = new QDoubleSpinBox(groupBox);
        factorXSB->setObjectName(QString::fromUtf8("factorXSB"));
        factorXSB->setMinimum(-65536.000000000000000);
        factorXSB->setMaximum(65536.000000000000000);
        factorXSB->setValue(1.000000000000000);

        scaleLayout->addWidget(factorXSB, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        scaleLayout->addWidget(label_8, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scaleLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        scalePB = new QPushButton(groupBox);
        scalePB->setObjectName(QString::fromUtf8("scalePB"));

        scaleLayout->addWidget(scalePB, 4, 0, 1, 4);


        horizontalLayout->addLayout(scaleLayout);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1449, 35));
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
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        translatePB->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\276\321\200\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        rotatePB->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\276\321\200\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202", nullptr));
        scalePB->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
