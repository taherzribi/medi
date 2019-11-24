#include "addrdv.h"
#include "ui_addrdv.h"
#include <QDebug>
#include <QSqlQuery>
#include"rdv.h"


AddRdv::AddRdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRdv)
{
    ui->setupUi(this);
}

AddRdv::~AddRdv()
{
    delete ui;
}
void AddRdv::on_buttonBox_accepted()
{
    QString cin,date,heure,type;
    cin=ui->cin->text();
    date=ui->date->selectedDate().toString();
    heure=ui->heure->text();
    if (ui->typecons1->isChecked())
         type = ui->typecons1->text();
    if (ui->typecons2->isChecked())
         type = ui->typecons2->text();
    if (ui->typecons3->isChecked())
         type = ui->typecons3->text();
    if (ui->typecons4->isChecked())
         type = ui->typecons4->text();

    QSqlQuery qr;
    qr.prepare("INSERT INTO RDV (cin_pat, date_rdv, type_rdv ) VALUES ('"+cin+"', '"+date+heure+"', '"+type+"')");
    emit Ajouter();
}
