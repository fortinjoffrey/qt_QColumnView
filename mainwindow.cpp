#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   fillItemModelWithDummyNumbers();

   ui->columnView->setModel(&_itemModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillItemModelWithDummyNumbers()
{
    for(int i = 0; i < 100; i++) {
        QStandardItem* row = new QStandardItem(QString("%1").arg(i));

        for(int j = 0; j < 5; j++) {
            row->appendRow(new QStandardItem(QString("%1").arg(j*i)));
        }
        _itemModel.appendRow(row);
    }
}

