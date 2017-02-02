#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H
#include <QApplication>
#include <QtWidgets>

class FenCodeGenere : public QDialog{
    Q_OBJECT

public:
    FenCodeGenere(QString &codeH, QString &codeCPP,
                  QString &codeMain, QString &nomClasse, QWidget *parent);
private slots:
    void enregistrer();

private:
    QString nom;
    QTextEdit *codeGenH;
    QTextEdit *codeGenCPP;
    QTextEdit *codeGenMain;
    QTabWidget *onglet;
    QPushButton *sauvegarder;
    QPushButton *fermer;

};

#endif // FENCODEGENERE_H
