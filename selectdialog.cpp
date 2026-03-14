#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "about.h"
#include "encode.h"
#include "decode.h"

selectdialog::selectdialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selectdialog)
{
    ui->setupUi(this);
}

selectdialog::~selectdialog()
{
    delete ui;
}


void selectdialog::on_aboutBtn_clicked()
{
    about *at = new about();
    at->show();
}


void selectdialog::on_encodeBtn_clicked()
{
    encode *en = new encode();
    en->show();
}


void selectdialog::on_decodeBtn_clicked()
{
    decode *de = new decode();
    de->show();
}

