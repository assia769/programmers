/*#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Widgets setup
    bookTable = new QTableWidget(this);
    bookTable->setColumnCount(3);
    bookTable->setHorizontalHeaderLabels({"Title", "Author", "ISBN"});
    bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    titleInput = new QLineEdit(this);
    titleInput->setPlaceholderText("Enter book title");
    authorInput = new QLineEdit(this);
    authorInput->setPlaceholderText("Enter author name");
    isbnInput = new QLineEdit(this);
    isbnInput->setPlaceholderText("Enter ISBN");

    addButton = new QPushButton("Add Book", this);
    editButton = new QPushButton("Edit Book", this);
    deleteButton = new QPushButton("Delete Book", this);

    // Layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *formLayout = new QHBoxLayout;

    formLayout->addWidget(titleInput);
    formLayout->addWidget(authorInput);
    formLayout->addWidget(isbnInput);

    mainLayout->addWidget(bookTable);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(editButton);
    mainLayout->addWidget(deleteButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connections
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editBook);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteBook);
}

MainWindow::~MainWindow() {}

void MainWindow::addBook()
{
    QString titre = titleInput->text();
    QString auteur = authorInput->text();
    QString isbn = isbnInput->text();

    if (titre.isEmpty() || auteur.isEmpty() || isbn.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    Livre livre(titre, auteur, isbn);
    livres.append(livre);

    int row = bookTable->rowCount();
    bookTable->insertRow(row);
    bookTable->setItem(row, 0, new QTableWidgetItem(livre.getTitre()));
    bookTable->setItem(row, 1, new QTableWidgetItem(livre.getAuteur()));
    bookTable->setItem(row, 2, new QTableWidgetItem(livre.getISBN()));

    titleInput->clear();
    authorInput->clear();
    isbnInput->clear();
}

void MainWindow::editBook()
{
    int currentRow = bookTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a book to edit.");
        return;
    }

    QString titre = titleInput->text();
    QString auteur = authorInput->text();
    QString isbn = isbnInput->text();

    if (!titre.isEmpty()) {
        livres[currentRow].setTitre(titre);
        bookTable->setItem(currentRow, 0, new QTableWidgetItem(titre));
    }
    if (!auteur.isEmpty()) {
        livres[currentRow].setAuteur(auteur);
        bookTable->setItem(currentRow, 1, new QTableWidgetItem(auteur));
    }
    if (!isbn.isEmpty()) {
        livres[currentRow].setISBN(isbn);
        bookTable->setItem(currentRow, 2, new QTableWidgetItem(isbn));
    }

    titleInput->clear();
    authorInput->clear();
    isbnInput->clear();
}

void MainWindow::deleteBook()
{
    int currentRow = bookTable->currentRow();
    if (currentRow >= 0) {
        livres.removeAt(currentRow);
        bookTable->removeRow(currentRow);
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a book to delete.");
    }
}
