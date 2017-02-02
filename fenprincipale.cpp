#include "fenprincipale.h"
#include "fencodegenere.h"
#include <iostream>

using namespace std;

FenPrincipale::FenPrincipale(){
    /***** PAGE GENERALE *****/
    //Def de la classe
    nom = new QLineEdit;
    mere = new QLineEdit;
    QFormLayout *layoutDef = new QFormLayout;
    layoutDef->addRow("&Nom", nom);
    layoutDef->addRow("Classe &mère", mere);
    QGroupBox *groupeDef = new QGroupBox("Défintion de la classe");
    groupeDef->setLayout(layoutDef);
    //Option
    inclusion = new QCheckBox("Protéger le &header contre les inclusions multiples");
    inclusion->setChecked(true);
    header = new QLineEdit();
    header->setText("HEADER_");
    header->setVisible(true);
    QHBoxLayout *headerLayout = new QHBoxLayout;
    headerLayout->addWidget(inclusion);
    headerLayout->addWidget(header);
    constructeur = new QCheckBox("Générer un &constructeur par défaut");
    destructeur = new QCheckBox("Générer un &destructeur");
    main = new QCheckBox("Générer un fichier main");
    QVBoxLayout *layoutOption = new QVBoxLayout;
    layoutOption->addLayout(headerLayout);
    layoutOption->addWidget(constructeur);
    layoutOption->addWidget(destructeur);
    layoutOption->addWidget(main);
    QGroupBox *groupeOption = new QGroupBox("Options");
    groupeOption->setLayout(layoutOption);
    //Commentaire
    auteur = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    role = new QTextEdit;
    QFormLayout *layoutCommentaire = new QFormLayout;
    layoutCommentaire->addRow("Auteur", auteur);
    layoutCommentaire->addRow("Date", date);
    layoutCommentaire->addRow("Rôle de la classe", role);
    groupeCommentaire = new QGroupBox("Ajouter des commentaires");
    groupeCommentaire->setCheckable(true);
    groupeCommentaire->setChecked(false);
    groupeCommentaire->setLayout(layoutCommentaire);
    //Bouton
    quitter = new QPushButton("Quitter");
    generer = new QPushButton("Générer !");
    QHBoxLayout *layoutBouton = new QHBoxLayout;
    layoutBouton->addWidget(generer);
    layoutBouton->addWidget(quitter);

    /*****LIBRAIRIE*****/
    //Bouton en haut pour savoir quel fichier on ajoute
    QGroupBox *groupeChoixInclude = new QGroupBox("Type fichier");
    QVBoxLayout *layoutChoixInclude = new QVBoxLayout;
    librairie = new QRadioButton("Librairie");
    librairie->setChecked(true);
    fichierH = new QRadioButton("Fichier *.h");
    layoutChoixInclude->addWidget(librairie);
    layoutChoixInclude->addWidget(fichierH);
    groupeChoixInclude->setLayout(layoutChoixInclude);
    //Layout pour affichier la saisie et ajouter
    QFormLayout *layoutSaisieInclude = new QFormLayout;
    saisieInclude = new QLineEdit;
    layoutSaisieInclude->addRow("Ajouter include", saisieInclude);
    ajouterInclude = new QPushButton("Ajouter");
    QHBoxLayout *layoutAjout = new QHBoxLayout;
    layoutAjout->addLayout(layoutSaisieInclude);
    layoutAjout->addWidget(ajouterInclude);
    //Layout pour les deux listes
    //Layout pour liste head
    QVBoxLayout *layoutListeHead = new QVBoxLayout;
    listeIncludeHead = new QListWidget;
    supprimerIncludeHead = new QPushButton("Supprimer fichier.h selectionner");
    layoutListeHead->addWidget(listeIncludeHead);
    layoutListeHead->addWidget(supprimerIncludeHead);
    //Layout pour liste lib
    QVBoxLayout *layoutListeLib = new QVBoxLayout;
    listeIncludeLib = new QListWidget;
    supprimerIncludeLib = new QPushButton("Supprimer librairie selectionner");
    layoutListeLib->addWidget(listeIncludeLib);
    layoutListeLib->addWidget(supprimerIncludeLib);
    QHBoxLayout *layoutListe = new QHBoxLayout;
    layoutListe->addLayout(layoutListeHead);
    layoutListe->addLayout(layoutListeLib);
    QVBoxLayout *layoutInclude = new QVBoxLayout;
    layoutInclude->addWidget(groupeChoixInclude);
    layoutInclude->addLayout(layoutAjout);
    layoutInclude->addLayout(layoutListe);

    /*****ATTRIBUT*****/
    //Ajout des attributs
    QFormLayout *layoutSaisieAttribut = new QFormLayout;
    QHBoxLayout *layoutAjoutAttribut = new QHBoxLayout;
    saisieAttribut = new QLineEdit;
    saisieType = new QLineEdit;
    layoutSaisieAttribut->addRow("Type :", saisieType);
    layoutSaisieAttribut->addRow("Attribut :", saisieAttribut);
    ajouterAttribut = new QPushButton("Ajouter");
    layoutAjoutAttribut->addLayout(layoutSaisieAttribut);
    layoutAjoutAttribut->addWidget(ajouterAttribut);
    QVBoxLayout *choixAttribut = new QVBoxLayout;
    accesseur = new QCheckBox("Voulez-vous un accesseur ?");
    mutateur = new QCheckBox("Voulez-vous un mutateur ?");
    choixAttribut->addLayout(layoutAjoutAttribut);
    choixAttribut->addWidget(accesseur);
    choixAttribut->addWidget(mutateur);
    QGroupBox *groupeAjout = new QGroupBox("Ajout attribut");
    groupeAjout->setLayout(choixAttribut);
    //liste attribut et supprimer
    listeAttribut = new QTreeWidget;
    listeAttribut->header()->hide();
    QVBoxLayout *layoutListeAttribut = new QVBoxLayout;
    supprimerAttribut = new QPushButton("Supprimer");
    layoutListeAttribut->addWidget(listeAttribut);
    layoutListeAttribut->addWidget(supprimerAttribut);
    //Layout attribut générale
    QVBoxLayout *layoutAttribut = new QVBoxLayout;
    layoutAttribut->addWidget(groupeAjout);
    layoutAttribut->addLayout(layoutListeAttribut);
    /*****LAYOUT PRINCIPAL*****/
    QVBoxLayout *layoutGeneral = new QVBoxLayout;
    layoutGeneral->addWidget(groupeDef);
    layoutGeneral->addWidget(groupeOption);
    layoutGeneral->addWidget(groupeCommentaire);
    QTabWidget *onglet = new QTabWidget;
    QWidget *general = new QWidget;
    QWidget *include = new QWidget;
    QWidget *attribut = new QWidget;
    general->setLayout(layoutGeneral);
    include->setLayout(layoutInclude);
    attribut->setLayout(layoutAttribut);
    onglet->addTab(general, "Général");
    onglet->addTab(include, "Include");
    onglet->addTab(attribut, "Attribut");
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(onglet);
    layoutPrincipal->addLayout(layoutBouton);
    setLayout(layoutPrincipal);
    QObject::connect(quitter, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    QObject::connect(generer, SIGNAL(clicked(bool)),
                     this, SLOT(genererCode()));
    QObject::connect(inclusion, SIGNAL(stateChanged(int)),
                     this, SLOT(voirHeader()));
    QObject::connect(nom, SIGNAL(textChanged(QString)),
                     this, SLOT(genererHeader(QString)));
    QObject::connect(ajouterInclude, SIGNAL(clicked(bool)),
                     this, SLOT(ajouterListInclude()));
    QObject::connect(supprimerIncludeHead, SIGNAL(clicked(bool)),
                     this, SLOT(supprimerListeHead()));
    QObject::connect(supprimerIncludeLib, SIGNAL(clicked(bool)),
                     this, SLOT(supprimerListeLib()));
    QObject::connect(ajouterAttribut, SIGNAL(clicked(bool)),
                     this, SLOT(ajouterListAttribut()));
    QObject::connect(supprimerAttribut, SIGNAL(clicked(bool)),
                     this, SLOT(supprimerListAttribut()));
}

void FenPrincipale::genererCode(){
    if(nom->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez entrer un nom de classe");
        return;
    }
    //Generation code header
    QString codeH;
    if(groupeCommentaire->isChecked()){
        codeH += "/* \n";
        codeH += "Auteur : " + auteur->text() + "\n";
        codeH += "Date de création : " + date->text() + "\n \n \n";
        codeH += "Role : " + role->toPlainText() + "\n";
        codeH += "*/ \n \n \n";
    }
    if(inclusion->isChecked()){
        codeH += "#ifndef " + header->text().toUpper() + "\n";
        codeH += "#define " + header->text().toUpper() + "\n \n \n";
    }
    if(listeIncludeLib->count()){
        int tailleLib = listeIncludeLib->count();
        for(int i = 0; i < tailleLib; i++){
            codeH += "#include <" + listeIncludeLib->item(i)->text() + ">\n";
        }
    }
    if(listeIncludeHead->count()){
        int tailleHead = listeIncludeHead->count();
        for(int i = 0; i < tailleHead; i++){
            codeH += "#include \"" + listeIncludeHead->item(i)->text() + "\"\n";
        }
    }
    codeH += "\n";
    codeH += "class " + nom->text();
    if(!mere->text().isEmpty()){
        codeH += " : public " + nom->text();
    }
    codeH += " { \n \n";
    codeH += "public: \n";
    if(constructeur->isChecked()){
        codeH += "  " + nom->text() + "();\n";
    }
    if(destructeur->isChecked()){
        codeH += "  ~" + nom->text() + "();\n";
    }
    for(int i = 0; i < listeAttribut->topLevelItemCount(); i++){
        QTreeWidgetItem *actuel = listeAttribut->topLevelItem(i);
        for(int j = 0; j < actuel->childCount(); j++){
            codeH += "  " + actuel->child(j)->text(0) + ";\n";
        }
    }
    codeH += "\nprotected: \n";
    codeH += "\nprivate: \n";
    for(int i = 0; i < listeAttribut->topLevelItemCount(); i++){
        codeH += "  " + listeAttribut->topLevelItem(i)->text(0) + ";\n";
    }
    codeH += "\n}; \n \n";
    if(inclusion->isChecked()){
        codeH += "#endif";
    }
    //Generation code source
    QString codeCPP;
    codeCPP += "#include \"" + nom->text() + ".h\"";
    codeCPP += "\n\n\n";
    if(constructeur->isChecked()){
        codeCPP += nom->text() + "::" + nom->text() + "(){\n";
        codeCPP += "\n}\n\n";
    }
    if(destructeur->isChecked()){
        codeCPP += "~" + nom->text() + "::" + nom->text() + "(){\n";
        codeCPP += "\n}\n\n";
    }

    for(int i = 0; i < listeAttribut->topLevelItemCount(); i++){
        QTreeWidgetItem *actuel = listeAttribut->topLevelItem(i);
        for(int j = 0; j < actuel->childCount(); j++){
            QString texte = (actuel->child(j)->text(0));
            int premier = premierEspace(texte);
            int longueur = texte.length();
            QString type = texte.remove(premier, longueur - premier);
            texte = (actuel->child(j)->text(0));
            QString lettreG = "g";
            QString nomFonction = texte.remove(0, premier + 1);
            codeCPP += type + " " + nom->text() + "::"
                    + nomFonction + "{\n";
            if(nomFonction[0] == lettreG[0]){
                QString arg = actuel->text(0);
                QString nomArg = arg.remove(0, premierEspace(arg) + 1);
                codeCPP += "    return " + nomArg + ";\n}\n\n";
            }
            else{
                QString arg = actuel->text(0);
                QString nomArg = arg.remove(0, premierEspace(arg) + 1);
                codeCPP += "    " + nomArg + " = value;\n}\n\n";
            }
        }
    }
    //Generation du main
    QString codeMain;
    if(main->isChecked()){
        codeMain += "include \"" + nom->text() + "\"\n\n\n";
        codeMain += "int main(int argc, char *argv[]){\n";
        QString recherche;
        recherche += "QApplication";
        if(chercheListe(QString("QApplication"), listeIncludeLib)){
            codeMain += "QApplication app(argc, argv);\n";
            codeMain += "return app.exec();\n}";
        }
        else{
            codeMain += "   return 0;\n}";
        }
    }
    QString nomClasse;
    nomClasse += nom->text();
    FenCodeGenere *fenCode = new FenCodeGenere(codeH, codeCPP, codeMain,
                                               nomClasse, this);
    fenCode->exec();
}

void FenPrincipale::voirHeader(){
    if(inclusion->isChecked()){
        header->show();
    }
    else{
        header->hide();
    }
}

void FenPrincipale::genererHeader(const QString &nomClasse){
    header->setText(QString("HEADER_") + nomClasse.toUpper());
}

void FenPrincipale::ajouterListInclude(){
    if(saisieInclude->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez saisir un nom d'include");
        return;
    }
    if(librairie->isChecked()){
        if(chercheListe(saisieInclude->text(), listeIncludeLib)){
            QMessageBox::critical(this, "Erreur", "Librairie deja inclut");
        }
        else{
        listeIncludeLib->addItem(saisieInclude->text());
        }
    }
    else{
        if(chercheListe(saisieInclude->text(), listeIncludeHead)){
            QMessageBox::critical(this, "Erreur", "Fichier.h deja inclut");
        }
        else{
        listeIncludeHead->addItem(saisieInclude->text());
        }
    }
    saisieInclude->clear();
}

void FenPrincipale::supprimerListeHead(){
    int rang = listeIncludeHead->currentRow();
    listeIncludeHead->takeItem(rang);
}

void FenPrincipale::supprimerListeLib(){
    int rang = listeIncludeLib->currentRow();
    listeIncludeLib->takeItem(rang);
}

void FenPrincipale::ajouterListAttribut(){
    if(saisieAttribut->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez saisie un nom d'attribut");
        return;
    }
    if(saisieType->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez saisie un nom de type");
        return;
    }
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, saisieType->text() + " " + saisieAttribut->text());
    QString nomClasse;
    nomClasse = saisieAttribut->text();
    nomClasse = nomClasse[0].toUpper() + nomClasse.remove(0, 1);
    if(accesseur->isChecked()){
        QTreeWidgetItem *itemAcceseur = new QTreeWidgetItem;
        itemAcceseur->setText(0, saisieType->text() + " get"
                              + nomClasse + "()");
        item->addChild(itemAcceseur);
        accesseur->setChecked(false);
    }
    if(mutateur->isChecked()){
        QTreeWidgetItem *itemMutateur = new QTreeWidgetItem;
        itemMutateur->setText(0, "void set" + nomClasse + "("
                              + saisieType->text() + " value)" ) ;
        item->addChild(itemMutateur);
        mutateur->setChecked(false);
    }
    listeAttribut->insertTopLevelItem(0, item);
    saisieAttribut->clear();
    saisieType->clear();
}

void FenPrincipale::supprimerListAttribut(){
    int index = listeAttribut->indexOfTopLevelItem(listeAttribut->currentItem());
    listeAttribut->takeTopLevelItem(index);
}

bool FenPrincipale::chercheListe(QString mot, QListWidget *liste){
    for(int i = 0; i < liste->count(); i++){
        if(liste->item(i)->text() == mot){
            return true;
        }
    }
    return false;
}

int premierEspace(QString mot){
    int n = 0;
    QString espace = " ";
    while(mot[n] != espace[0]){
        n ++;
    }
    return n;
}
