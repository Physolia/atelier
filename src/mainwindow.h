/* Atelier KDE Printer Host for 3D Printing
    Copyright (C) <2016>
    Author: Lays Rodrigues - laysrodrigues@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <QMainWindow>
#include <QUrl>
#include <AtCore/AtCore>
#include <KXmlGui/KXmlGuiWindow>
#include <widgets/logwidget.h>
namespace Ui
{
class MainWindow;
}

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AtCore core;
    QStringList firmwaresList;
    QUrl fileName;
    LogWidget *logWidget;
    QAction *_connect;
    void initConnectsToAtCore();
    void initWidgets();
    void setupActions();
    void openFile();
    void printFile();
    void pausePrint();
    void stopPrint();
    void checkReceivedCommand(const QByteArray &message);
    void checkPushedCommands(QByteArray bmsg);
    void handlePrinterStatusChanged(AtCore::STATES newState);
    void checkTemperature(uint sensorType, uint number, uint temp);
    void axisControlClicked(QChar axis, int value);
    void toggleDockTitles(bool checked);

signals:
    void extruderCountChanged(int count);

};
