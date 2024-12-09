#include "mainwindow.h"

/*
 #include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // Initialise l'application Qt

    MainWindow mainWindow;       // Crée une instance de la fenêtre principale
    mainWindow.setWindowTitle("Library Management System"); // Définit le titre de la fenêtre
    mainWindow.resize(800, 600); // Redimensionne la fenêtre
    mainWindow.show();           // Affiche la fenêtre principale

    return app.exec();           // Exécute la boucle principale de l'application
}
