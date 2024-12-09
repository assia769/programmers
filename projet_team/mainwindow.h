/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QList>
#include "Livre.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Widgets
    QTableWidget *bookTable;
    QLineEdit *titleInput;
    QLineEdit *authorInput;
    QLineEdit *isbnInput;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    // Liste des livres
    QList<Livre> livres;

private slots:
    void addBook();
    void editBook();
    void deleteBook();
};

#endif // MAINWINDOW_H
