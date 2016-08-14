// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com


#ifndef PROCESSCONNECTIONTABLEMODEL_H
#define PROCESSCONNECTIONTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QVariantMap>

#include "processconnection.h"

class ProcessConnectionTableModel : public QAbstractTableModel
{
public:
    ProcessConnectionTableModel(QString exe);
    ~ProcessConnectionTableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    ProcessConnection *_process_connection;
    QVariantMap _data_map;

    // QAbstractItemModel interface

};

#endif // PROCESSCONNECTIONTABLEMODEL_H
