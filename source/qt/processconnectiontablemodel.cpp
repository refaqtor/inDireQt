// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com

#include "processconnectiontablemodel.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

ProcessConnectionTableModel::ProcessConnectionTableModel(QString exe)
    : _process_connection(new ProcessConnection(exe, this))
{
    QString model_data;
    _process_connection->sendCommand("anything", model_data);
    QByteArray ba = model_data.toLocal8Bit();
    QJsonDocument model_doc = QJsonDocument::fromJson(ba);
    _data_map = model_doc.object().toVariantMap();
}

ProcessConnectionTableModel::~ProcessConnectionTableModel()
{
}

int ProcessConnectionTableModel::rowCount(const QModelIndex& parent) const
{
    return _data_map.count();
}

int ProcessConnectionTableModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant ProcessConnectionTableModel::data(const QModelIndex& index, int role) const
{
    QString key(QString::number(index.row()));
    QString return_value = _data_map.value(key, "invalid").toString();
    qDebug() << key << " : " << return_value;
    return return_value;
}
