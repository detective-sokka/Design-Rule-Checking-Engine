#include "MainWindow.h"

#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupWindow();
    setupMenuBar();
    setupCentralWidget();
    setupStatusBar();
}

void MainWindow::setupWindow()
{
    setWindowTitle("DRC Engine");
    resize(800, 600);
}

void MainWindow::setupMenuBar()
{
    menuBar()->setNativeMenuBar(false);

    QPushButton *themeButton = new QPushButton("Theme", this->menuBar());
    this->menuBar()->setCornerWidget(themeButton, Qt::TopRightCorner);
    
    auto *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit", this, &QWidget::close);
}

void MainWindow::setupCentralWidget()
{
    auto *label = new QLabel("Add Circuit canvas here", this);
    label->setAlignment(Qt::AlignCenter);
    setCentralWidget(label);
}

void MainWindow::setupStatusBar()
{
    statusBar()->showMessage("Ready");
}
