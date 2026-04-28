#include "httagen.h"
#include "ui_httagen.h"
#include "about.h"
#include "base64.hpp"
using namespace std;

string user, pwd, b64s, encstr, hashstr, hashstrdec;

httagen::httagen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::httagen)
{
    ui->setupUi(this);
    ui->httagen_stacked->setCurrentIndex(0);
    ui->dynamicBtn->setText("Encode");
}

httagen::~httagen()
{
    delete ui;
}


void httagen::on_decodeBtn_clicked()
{
    ui->decodeBtn->setDisabled(1);
    ui->httagen_stacked->setCurrentIndex(1);
    ui->dynamicBtn->setText("Decode");
    ui->encodeBtn->setDisabled(0);
}

void httagen::on_encodeBtn_clicked()
{
    ui->encodeBtn->setDisabled(1);
    ui->httagen_stacked->setCurrentIndex(0);
    ui->dynamicBtn->setText("Encode");
    ui->decodeBtn->setDisabled(0);
}


void httagen::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();
}


void httagen::on_dynamicBtn_clicked()
{
    try {
    string buttonLabel = ui->dynamicBtn->text().toStdString();
    if (buttonLabel == "Encode") {
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
    else if (buttonLabel == "Decode") {
        hashstr = ui->hashField->text().toStdString();
        hashstrdec = base64::from_base64(hashstr);
        if (hashstr == "") {
            ui->usernameField_2->setText("");
            ui->passwordField_2->setText("");
        }
        else {
            // I still haven't found a better way to do this.
            int split_userpwd = hashstrdec.find_first_of(':');
            string split_userpwd_str = to_string(split_userpwd);
            user = hashstrdec.substr(0, split_userpwd);
            pwd = hashstrdec.substr(split_userpwd+1);
            if (split_userpwd != string::npos) {
                QString user_qstr = QString::fromStdString(user);
                QString pwd_qstr = QString::fromStdString(pwd);
                ui->usernameField_2->setText(user_qstr);
                ui->passwordField_2->setText(pwd_qstr);
            }
        }
        }
    }
    catch (std::runtime_error& e) {
        string buttonLabel = ui->dynamicBtn->text().toStdString();
        if (buttonLabel == "Encode") {
            ui->resultField->setText("");
        }
        else if (buttonLabel == "Decode") {
            ui->usernameField_2->setText("");
            ui->passwordField_2->setText("");
        }
    }
}

