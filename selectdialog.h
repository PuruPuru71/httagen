#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QWidget>

namespace Ui {
class selectdialog;
}

class selectdialog : public QWidget
{
    Q_OBJECT

public:
    explicit selectdialog(QWidget *parent = nullptr);
    ~selectdialog();

private slots:
    void on_aboutBtn_clicked();

    void on_encodeBtn_clicked();

    void on_decodeBtn_clicked();

private:
    Ui::selectdialog *ui;
};

#endif // SELECTDIALOG_H
