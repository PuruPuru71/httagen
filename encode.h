#ifndef ENCODE_H
#define ENCODE_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class encode;
}
QT_END_NAMESPACE

class encode : public QDialog
{
    Q_OBJECT

public:
    encode(QWidget *parent = nullptr);
    ~encode();

private slots:

    void on_genBtn_clicked();

    void on_aboutBtn_clicked();

private:
    Ui::encode *ui;
};
#endif // ENCODE_H
