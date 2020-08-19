#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMap<QString, QList<Vehicle>> manufacturersVehiclesMap;
    manufacturersVehiclesMap = fillManufacturersVehiclesMap();

    fillItemModelFromMap(manufacturersVehiclesMap);

   ui->columnView->setModel(&_itemModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<Vehicle> MainWindow::fillVehiclesList()
{
    QList<Vehicle> vehicles;
    vehicles.append(Vehicle("Model S", "Tesla"));
    vehicles.append(Vehicle("Model 3", "Tesla"));
    vehicles.append(Vehicle("250 GTO", "Ferrari"));
    vehicles.append(Vehicle("488 GTB", "Ferrari"));
    vehicles.append(Vehicle("F430", "Ferrari"));
    vehicles.append(Vehicle("i8", "BMW"));
    vehicles.append(Vehicle("E39 M5", "BMW"));
    return vehicles;
}


void MainWindow::fillItemModelFromMap(QMap<QString, QList<Vehicle>> map)
{
    QMap<QString, QList<Vehicle>>::const_iterator iterator = map.constBegin();

    while (iterator != map.constEnd()) {

        QStandardItem* manufacturerRow = new QStandardItem(iterator.key());

        const QList<Vehicle> vehicles = iterator.value();

        foreach (Vehicle vehicle, vehicles) {
            manufacturerRow->appendRow(new QStandardItem(vehicle.name));
        }

        _itemModel.appendRow(manufacturerRow);

        ++iterator;
    }
}

QMap<QString, QList<Vehicle>> MainWindow::fillManufacturersVehiclesMap()
{
    QMap<QString, QList<Vehicle>> _manufacturersVehiclesMap;
    QList<Vehicle> vehicles = fillVehiclesList();

    foreach (Vehicle vehicle, vehicles) {
        if (!_manufacturersVehiclesMap.contains(vehicle.manufacturer)) {
            QList<Vehicle> vehiculesList = QList<Vehicle>();
            vehiculesList.append(vehicle);
            _manufacturersVehiclesMap.insert(vehicle.manufacturer, vehiculesList);
        } else {
            QList<Vehicle> &vehiculesList = _manufacturersVehiclesMap[vehicle.manufacturer];
            vehiculesList.append(vehicle);
        }
    }

    return _manufacturersVehiclesMap;
}
