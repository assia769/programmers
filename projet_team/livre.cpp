/*
 #include "livre.h"
#include <QInputDialog>    // Pour QInputDialog
#include <QRegularExpression> // Pour QRegularExpression
#include <QRegularExpressionMatch> // Si nécessaire pour les fonctions avancées de validation
#include <QMessageBox>     // Pour QMessageBox
#include <QDebug>          // Pour qDebug

Livre::Livre(QWidget *parent)
    : QWidget(parent), titre(""), auteur(""), ISBN(""), genre(""), anneePublication(0), editeur(""), nombreCopies(0) {}

bool Livre::estVide(const QString& str) const {
    return str.trimmed().isEmpty();
}

bool Livre::validerISBN(const QString& isbn) const {
    // Modèle pour valider les ISBN avec ou sans séparateurs
    QRegularExpression pattern(R"(^(97[89]-?)?[0-9]{1,5}-?[0-9]+-?[0-9]+-?[0-9X]$)");
    return pattern.match(isbn).hasMatch();
}

bool Livre::validerAnnee(int annee) const {
    return (annee > 1900 && annee <= 2024);
}

void Livre::afficherCadre(const QString& titre) const {
    QString cadre = "+" + QString("-").repeated(titre.length() + 4) + "+\n";
    cadre += "| " + titre + " |\n";
    cadre += "+" + QString("-").repeated(titre.length() + 4) + "+\n";
    qDebug() << cadre;
}

void Livre::saisirDetails() {
    QMessageBox::information(this, "Ajout de Livre", "Saisir les détails du livre.");

    bool ok;
    titre = QInputDialog::getText(this, "Titre du livre", "Titre (obligatoire) :", QLineEdit::Normal, "", &ok);
    while (!ok || estVide(titre)) {
        QMessageBox::warning(this, "Erreur", "Le titre est obligatoire.");
        titre = QInputDialog::getText(this, "Titre du livre", "Titre (obligatoire) :", QLineEdit::Normal, "", &ok);
    }

    auteur = QInputDialog::getText(this, "Auteur du livre", "Auteur (obligatoire) :", QLineEdit::Normal, "", &ok);
    while (!ok || estVide(auteur)) {
        QMessageBox::warning(this, "Erreur", "L'auteur est obligatoire.");
        auteur = QInputDialog::getText(this, "Auteur du livre", "Auteur (obligatoire) :", QLineEdit::Normal, "", &ok);
    }

    ISBN = QInputDialog::getText(this, "ISBN du livre", "ISBN (ex : 978-3-16-148410-0) :", QLineEdit::Normal, "", &ok);
    while (!ok || !validerISBN(ISBN)) {
        QMessageBox::warning(this, "Erreur", "Format ISBN invalide.");
        ISBN = QInputDialog::getText(this, "ISBN du livre", "ISBN (ex : 978-3-16-148410-0) :", QLineEdit::Normal, "", &ok);
    }

    genre = QInputDialog::getText(this, "Genre du livre", "Genre :", QLineEdit::Normal, "", &ok);

    do {
        QString anneeStr = QInputDialog::getText(this, "Année de publication", "Année de publication (ex : 2023) :", QLineEdit::Normal, "", &ok);
        if (ok) {
            anneePublication = anneeStr.toInt(&ok);
        }
        if (!ok || !validerAnnee(anneePublication)) {
            QMessageBox::warning(this, "Erreur", "Année invalide. Veuillez entrer une année entre 1900 et 2024.");
        }
    } while (!validerAnnee(anneePublication));

    editeur = QInputDialog::getText(this, "Éditeur", "Éditeur (obligatoire) :", QLineEdit::Normal, "", &ok);
    while (!ok || estVide(editeur)) {
        QMessageBox::warning(this, "Erreur", "L'éditeur est obligatoire.");
        editeur = QInputDialog::getText(this, "Éditeur", "Éditeur (obligatoire) :", QLineEdit::Normal, "", &ok);
    }

    do {
        QString copiesStr = QInputDialog::getText(this, "Nombre de copies", "Nombre de copies ( > 0) :", QLineEdit::Normal, "", &ok);
        if (ok) {
            nombreCopies = copiesStr.toInt(&ok);
        }
        if (!ok || nombreCopies <= 0) {
            QMessageBox::warning(this, "Erreur", "Le nombre de copies doit être supérieur à 0.");
        }
    } while (nombreCopies <= 0);
}

void Livre::afficherDetails() const {
    QString details = "Titre : " + titre + "\n"
                                           "Auteur : " + auteur + "\n"
                                 "ISBN : " + ISBN + "\n"
                               "Genre : " + genre + "\n"
                                "Année de publication : " + QString::number(anneePublication) + "\n"
                                                            "Éditeur : " + editeur + "\n"
                                  "Nombre de copies : " + QString::number(nombreCopies);

    QMessageBox::information(this, "Détails du Livre", details);
}
*/
#include "Livre.h"

Livre::Livre(const QString &titre, const QString &auteur, const QString &isbn)
    : titre(titre), auteur(auteur), isbn(isbn) {}

QString Livre::getTitre() const {
    return titre;
}
QString Livre::getAuteur() const {
    return auteur;
}
QString Livre::getISBN() const {
    return isbn;
}

void Livre::setTitre(const QString &titre) { this->titre = titre; }
void Livre::setAuteur(const QString &auteur) { this->auteur = auteur; }
void Livre::setISBN(const QString &isbn) { this->isbn = isbn; }
