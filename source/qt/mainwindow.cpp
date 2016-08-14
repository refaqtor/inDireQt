// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com

#include <QDebug>
#include <QDir>
#include <QStandardPaths>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "processconnection.h"

QString appLocalDataLocation()
{
    return QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation)
        .value(0, QDir::homePath());
}

QString extractResourceFile(QString resource_filepath, QString disk_filename, bool executable = false)
{ //this resource extraction requires "Q_INIT_RESOURCE(data);" in the constructor
    bool ok = false;
    QString local_file_path = appLocalDataLocation();

    qDebug() << "extraction: " << local_file_path;

    QDir dir;
    ok = dir.mkpath(local_file_path);
    if (!ok)
        qDebug() << QString("ERROR: %1 folder creation failed.").arg(local_file_path);

    local_file_path.append("/" + disk_filename);
    QFile::remove(local_file_path);

    ok = QFile::copy(resource_filepath, local_file_path);
    if (!ok)
        qDebug() << QString("ERROR: %1 file copy to %2 failed.").arg(resource_filepath).arg(local_file_path);

    QFile new_file(local_file_path);
    if (!executable) {
        ok = new_file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    } else {
        ok = new_file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner | QFileDevice::ExeOwner);
    }

    if (!ok)
        qDebug() << QString("ERROR: %1 permission settings failed.").arg(local_file_path);

    if (ok)
        return new_file.fileName();
    else
        return QString("");
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _connection_model = new ProcessConnectionTableModel(
        extractResourceFile(":/executables/resources/dprocess",
            "dprocess",
            true));
    ui->tableView->setModel(_connection_model);
}

MainWindow::~MainWindow()
{
    delete _connection_model;
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    // _cdconnection->sendCommand(ui->lineEdit->text());
}

void MainWindow::updateResultsView()
{
    // ui->textBrowser->setText(_cdconnection->output().join("\n"));
}
