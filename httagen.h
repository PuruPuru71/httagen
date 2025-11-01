#ifndef HTTAGEN_H
#define HTTAGEN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class httagen;
}
QT_END_NAMESPACE

class httagen : public QDialog
{
    Q_OBJECT

public:
    httagen(QWidget *parent = nullptr);
    ~httagen();

private slots:

    void on_genBtn_clicked();

    void on_aboutBtn_clicked();

private:
    Ui::httagen *ui;
};
#endif // HTTAGEN_H
