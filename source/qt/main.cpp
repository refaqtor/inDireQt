// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (c) 2015, Shannon Mackey refaQtor@gmail.com

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("refaqtory");
    QCoreApplication::setOrganizationDomain("refaqtory.com");
    QCoreApplication::setApplicationName("qtdprocess");
    QCoreApplication::setApplicationVersion("0.1");

    MainWindow w;
    w.show();

    return a.exec();
}
