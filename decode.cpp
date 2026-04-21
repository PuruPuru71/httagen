#include "decode.h"
#include "ui_decode.h"
#include "base64.hpp"
#include "about.h"
#include <sstream>
#include <string>
#include <vector>
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
    // This is 99% implemented for now because if hash doesn't have ":" in it, it will put the same value in both fields.
    hashstr = ui->hashField->text().toStdString();
    hashstrdec = base64::from_base64(hashstr);
    stringstream hash_ss(hashstrdec);
    vector<string> v;
    if (hashstr == "") {
        ui->usernameField->setText("");
        ui->passwordField->setText("");
    }
    else {
        // There has to be a better way to do this...
        int split_userpwd = hashstrdec.find_first_of(':');
        string user = hashstrdec.substr(0, split_userpwd);
        string pwd = hashstrdec.substr(split_userpwd+1);
        QString user_qstr = QString::fromStdString(user);
        QString pwd_qstr = QString::fromStdString(pwd);
        ui->usernameField->setText(user_qstr);
        ui->passwordField->setText(pwd_qstr);
    }

}


void decode::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();
}

