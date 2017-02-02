#include "fencodegenere.h"
#include <iostream>

using namespace std;

FenCodeGenere::FenCodeGenere(QString &codeH, QString &codeCPP,
                             QString &codeMain, QString &nomClasse,
                             QWidget *parent = 0) : QDialog(parent){
    nom = nomClasse;
    onglet = new QTabWidget(this);
    QWidget *page1 = new QWidget();
    QWidget *page2 = new QWidget();
    codeGenH = new QTextEdit();
    codeGenH->setPlainText(codeH);
    codeGenH->setReadOnly(true);
    codeGenH->setFont(QFont("Courier"));
    fermer = new QPushButton("Fermer");
    sauvegarder = new QPushButton("Sauvegarder");
    QVBoxLayout *layoutHeader = new QVBoxLayout;
    layoutHeader->addWidget(codeGenH);
    page1->setLayout(layoutHeader);

    codeGenCPP = new QTextEdit();
    codeGenCPP->setPlainText(codeCPP);
    codeGenCPP->setReadOnly(true);
    codeGenCPP->setFont(QFont("Courier"));
    QPalette p = codeGenCPP->palette();
    p.setColor(QPalette::Base, QColor(255, 0, 0));
    codeGenCPP->setPalette(p);
    QVBoxLayout *layoutSource = new QVBoxLayout;
    layoutSource->addWidget(codeGenCPP);
    page2->setLayout(layoutSource);
    onglet->addTab(page1, nom + ".h");
    onglet->addTab(page2, nom + ".cpp");
    if(!codeMain.isEmpty()){
        QWidget *page3 = new QWidget;
        codeGenMain = new QTextEdit();
        codeGenMain->setPlainText(codeMain);
        codeGenMain->setReadOnly(true);
        codeGenMain->setFont(QFont("Courier"));
        QVBoxLayout *layoutMain = new QVBoxLayout;
        layoutMain->addWidget(codeGenMain);
        page3->setLayout(layoutMain);
        onglet->addTab(page3, "Main");
    }
    QVBoxLayout *layoutPrincipale = new QVBoxLayout;
    QHBoxLayout *layoutBouton = new QHBoxLayout;
    layoutBouton->addWidget(sauvegarder);
    layoutBouton->addWidget(fermer);
    layoutPrincipale->addWidget(onglet);
    layoutPrincipale->addLayout(layoutBouton);
    resize(350, 450);
    setLayout(layoutPrincipale);
    QObject::connect(fermer, SIGNAL(clicked(bool)), this, SLOT(accept()));
    QObject::connect(sauvegarder, SIGNAL(clicked(bool)),
                     this, SLOT(enregistrer()));
}

void FenCodeGenere::enregistrer(){
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier",
                                                    nom, "tout");
    if(fichier.isEmpty()){
        return;
    }
    QFile *sauvegardeH = new QFile(fichier + ".h");
    if(sauvegardeH->open(QFile::WriteOnly)){
        QTextStream out(sauvegardeH);
        out << codeGenH->toPlainText();
    }
    QFile *sauvegardeCPP = new QFile(fichier + ".cpp");
    if(sauvegardeCPP->open(QFile::WriteOnly)){
        QTextStream out(sauvegardeCPP);
        out << codeGenCPP->toPlainText();
    }
}
