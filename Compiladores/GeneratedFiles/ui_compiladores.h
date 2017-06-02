/********************************************************************************
** Form generated from reading UI file 'compiladores.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILADORES_H
#define UI_COMPILADORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompiladoresClass
{
public:
    QAction *actionCompilar;
    QAction *actionGuardar;
    QAction *actionSalir;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CompiladoresClass)
    {
        if (CompiladoresClass->objectName().isEmpty())
            CompiladoresClass->setObjectName(QStringLiteral("CompiladoresClass"));
        CompiladoresClass->resize(600, 400);
        actionCompilar = new QAction(CompiladoresClass);
        actionCompilar->setObjectName(QStringLiteral("actionCompilar"));
        actionGuardar = new QAction(CompiladoresClass);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionSalir = new QAction(CompiladoresClass);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralWidget = new QWidget(CompiladoresClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 1, 0, 1, 1);

        CompiladoresClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CompiladoresClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        CompiladoresClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CompiladoresClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CompiladoresClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CompiladoresClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CompiladoresClass->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionCompilar);
        menuMenu->addAction(actionGuardar);
        menuMenu->addAction(actionSalir);

        retranslateUi(CompiladoresClass);

        QMetaObject::connectSlotsByName(CompiladoresClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompiladoresClass)
    {
        CompiladoresClass->setWindowTitle(QApplication::translate("CompiladoresClass", "Compiladores", Q_NULLPTR));
        actionCompilar->setText(QApplication::translate("CompiladoresClass", "Compilar", Q_NULLPTR));
        actionGuardar->setText(QApplication::translate("CompiladoresClass", "Guardar", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("CompiladoresClass", "Salir", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("CompiladoresClass", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CompiladoresClass: public Ui_CompiladoresClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILADORES_H
