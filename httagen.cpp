#include "httagen.h"
#include "ui_httagen.h"
#include "about.h"

httagen::httagen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::httagen)
{
    ui->setupUi(this);
    ui->httagen_stacked->setCurrentIndex(0);
    ui->dynamicButton->setText("Encode");
}

httagen::~httagen()
{
    delete ui;
}


void httagen::on_decodeBtn_clicked()
{
    ui->decodeBtn->setDisabled(1);
    ui->httagen_stacked->setCurrentIndex(1);
    ui->dynamicButton->setText("Decode");
    ui->encodeBtn->setDisabled(0);
}

void httagen::on_encodeBtn_clicked()
{
    ui->encodeBtn->setDisabled(1);
    ui->httagen_stacked->setCurrentIndex(0);
    ui->dynamicButton->setText("Encode");
    ui->decodeBtn->setDisabled(0);
}


void httagen::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();
}

