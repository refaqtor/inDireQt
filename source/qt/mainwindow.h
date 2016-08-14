// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "processconnectiontablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();
    void updateResultsView();

private:
    Ui::MainWindow *ui;

    ProcessConnectionTableModel *_connection_model;
};

#endif // MAINWINDOW_H
