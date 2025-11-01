#include "httagen.h"
#include "./ui_httagen.h"
#include "base64.hpp"
#include <QString>
#include "about.h"
using namespace std;

httagen::httagen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::httagen)
{
    ui->setupUi(this);
}

string user, pwd, b64s, encstr, encstr2;

httagen::~httagen()
{
    delete ui;
}

void httagen::on_genBtn_clicked()
{
    user = ui->usernameField->text().toStdString();
    pwd = ui->passwordField->text().toStdString();
    b64s = user + ":" + pwd;
    encstr = base64::to_base64(b64s);
    if (user == "" | pwd == "") {
        ui->resultField->setText("");
    }
        else {
            ui->resultField->setText(QString::fromStdString(encstr));
        }

    }


void httagen::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();

}

