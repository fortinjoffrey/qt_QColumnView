#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct Vehicle {
    QString name;
    QString manufacturer;

    Vehicle(const QString& pName, const QString& pManufacturer) : name(pName), manufacturer(pManufacturer) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStandardItemModel _itemModel;

    /*
     * Returns a map of the following format
     *     key   : QString (company name)
     *     value : QList<Vehicle> (company vehicles')
     */
    QMap<QString, QList<Vehicle>> fillManufacturersVehiclesMap();

    /*
     * Returns a list of vehicles
     * These vehicles might come from an API or a database
     */
    QList<Vehicle> fillVehiclesList();

    /*
     * Fill the QStandardItemModel from map model
     */
    void fillItemModelFromMap(QMap<QString, QList<Vehicle>> map);
};
#endif // MAINWINDOW_H
