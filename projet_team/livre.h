/*
#ifndef LIVRE_H
#define LIVRE_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMessageBox>

class Livre : public QWidget
{
    Q_OBJECT

public:
    explicit Livre(QWidget *parent = nullptr);

    void saisirDetails();
    void afficherDetails() const;

private:
    QString titre;
    QString auteur;
    QString ISBN;
    QString genre;
    int anneePublication;
    QString editeur;
    int nombreCopies;

    bool estVide(const QString& str) const;
    bool validerISBN(const QString& isbn) const;
    bool validerAnnee(int annee) const;

    void afficherCadre(const QString& titre) const;
};

#endif // LIVRE_H

*/
#ifndef LIVRE_H
#define LIVRE_H

#include <QString>

class Livre
{
public:
    Livre(const QString &titre, const QString &auteur, const QString &isbn);

    QString getTitre() const;
    QString getAuteur() const;
    QString getISBN() const;

    void setTitre(const QString &titre);
    void setAuteur(const QString &auteur);
    void setISBN(const QString &isbn);

private:
    QString titre;
    QString auteur;
    QString isbn;
};

#endif // LIVRE_H
