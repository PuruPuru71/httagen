#include "encode.h"
#include "./ui_encode.h"
#include "base64.hpp"
#include <QString>
#include "about.h"
using namespace std;

encode::encode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::encode)
{
    ui->setupUi(this);
}

string user, pwd, b64s, encstr, encstr2;

encode::~encode()
{
    delete ui;
}

void encode::on_genBtn_clicked()
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


void encode::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();

}

