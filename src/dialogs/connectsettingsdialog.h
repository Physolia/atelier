#pragma once

#include <QDialog>
#include <Solid/DeviceNotifier>

namespace Ui {
class ConnectSettingsDialog;
}

class ConnectSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectSettingsDialog(QStringList firmwaresList, QWidget *parent = nullptr);
    ~ConnectSettingsDialog();

private:
    Ui::ConnectSettingsDialog *ui;
    void locateSerialPort();
    QStringList serialPortList;
    Solid::DeviceNotifier *deviceNotifier;
    void initFirmwareComboBox(QStringList fw);
    void initBaudRateComboBox();

signals:
    void _connect(QString port, QString baud);
};
