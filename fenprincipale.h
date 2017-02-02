#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include <QApplication>
#include <QtWidgets>

class FenPrincipale : public QWidget{
    Q_OBJECT

public:
    FenPrincipale();
    bool chercheListe(QString mot, QListWidget *liste);

private slots:
    void genererCode();
    void genererHeader(const QString &nomClasse);
    void voirHeader();
    void ajouterListInclude();
    void supprimerListeHead();
    void supprimerListeLib();
    void ajouterListAttribut();
    void supprimerListAttribut();


private:
    QLineEdit *nom;
    QLineEdit *mere;

    QCheckBox *inclusion;
    QLineEdit *header;
    QCheckBox *constructeur;
    QCheckBox *destructeur;
    QCheckBox *main;

    QGroupBox *groupeCommentaire;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role;

    QRadioButton *librairie;
    QRadioButton *fichierH;
    QLineEdit *saisieInclude;
    QListWidget *listeIncludeHead;
    QListWidget *listeIncludeLib;
    QPushButton *ajouterInclude;
    QPushButton *supprimerIncludeHead;
    QPushButton *supprimerIncludeLib;

    QTreeWidget *listeAttribut;
    QCheckBox *accesseur;
    QCheckBox * mutateur;
    QLineEdit *saisieType;
    QLineEdit *saisieAttribut;
    QPushButton *ajouterAttribut;
    QPushButton *supprimerAttribut;

    QPushButton *quitter;
    QPushButton *generer;
};

int premierEspace(QString mot);

#endif // FENPRINCIPALE_H
