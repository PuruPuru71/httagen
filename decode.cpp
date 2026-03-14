#include "decode.h"
#include "ui_decode.h"
#include "base64.hpp"
#include "about.h"
using namespace std;

decode::decode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::decode)
{
    ui->setupUi(this);
}

string hashstr, hashstrdec;

decode::~decode()
{
    delete ui;
}

void decode::on_decodeBtn_clicked()
{
    // This is 95% implemented because for now this is a Generic base64 decoder, no matter if it's a HTTP Authorizaation Token or not.
    hashstr = ui->hashField->text().toStdString();
    hashstrdec = base64::from_base64(hashstr);
    if (hashstr == "") {
        ui->resultField->setText("");
    }
    else {
        ui->resultField->setText(QString::fromStdString(hashstrdec));
    }

}


void decode::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();
}

