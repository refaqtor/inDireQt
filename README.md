follow this at : https://gitlab.com/u/refaQtor/projects

This application is an example of embedding a commandline application into the resources of a Qt application, then interacting and displaying the data from the commandline application via Qt standard model-view interface.  In this case, the application is written in D.  But, this could prove a useful technique for flexibly interface obscure languages with unique features to a graphical interface.  Wrapping functionality in a commandline application makes for a positive separation from the user interface.  And, if makes it easy to use behind a web service.

(currently, a work-in-progress.  I've used this pattern successfully. But as I was cleaning private info out of this code to use as an example, I recently broke something.  It still does provide a structure for those wishing to examine the code)

Anyway... to begin,
install dev tools:

    dlang.org
    qt.io

then, do this:

    dmd dprocess.d
    
that results in an executable, to be put in:

    source/qt/resources
    
where the Qt project's .qrc file will build it into the executable Qt application.


The Qt project implements a QProcess handling class, for convenience.
It also implements a class based on QAbstractTableModel, which takes the stdout data and presents it to the QTableModelView.
There is a simple window app to display the data gotten from the commandline process.
