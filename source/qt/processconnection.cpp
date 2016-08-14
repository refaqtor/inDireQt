// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com

#include "processconnection.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>

//#include <//qDebug>

ProcessConnection::ProcessConnection(QString exe_pathname, QObject* parent)
    : QObject(parent)
    , _output(QString(""))
{
    executeDprocess(QStringList() << exe_pathname);
}

void ProcessConnection::executeDprocess(QStringList args)
{
    _output.clear();
    QFileInfo fi(args.value(0));
    QString working_directory(fi.absolutePath());

    QDir::setCurrent(working_directory);
    _Dprocess = new QProcess(qobject_cast<QObject*>(this));
    _Dprocess = new QProcess();

    _Dprocess->setReadChannel(QProcess::StandardOutput);

    connect(_Dprocess, &QProcess::readyRead,
        this, &ProcessConnection::harvestOutput);
    connect(_Dprocess, &QProcess::readyReadStandardError,
        this, &ProcessConnection::harvestOutput);
    connect(_Dprocess, &QProcess::readyReadStandardOutput,
        this, &ProcessConnection::harvestOutput);

    _Dprocess->setWorkingDirectory(working_directory);

    _Dprocess->setProcessChannelMode(QProcess::MergedChannels);
    qDebug() << args;
    _Dprocess->start(args.value(0), args);
    qDebug() << _Dprocess->waitForStarted();
    qDebug() << _Dprocess->state();
}

void ProcessConnection::sendCommand(QString cmd, QString payload)
{
    QString stuff = QString("%1 %2\n").arg(cmd).arg(payload);
    _Dprocess->write(stuff.toLocal8Bit());
}

void ProcessConnection::harvestOutput()
{
    //qDebug("harvestOutput");

    QString msg = _Dprocess->readAllStandardOutput();
    if (msg != "") {
        //qDebug() << msg;
        _output.append(msg.remove("\""));
    }
    QString err = _Dprocess->readAllStandardError();
    if (err != "") {
        //qDebug() << err;
        _output.append(err);
    }
    emit resultsReady();
}

QString ProcessConnection::output()
{
    return _output;
}
