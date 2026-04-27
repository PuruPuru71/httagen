#ifndef HTTAGEN_H
#define HTTAGEN_H

#include <QWidget>

namespace Ui {
class httagen;
}

class httagen : public QWidget
{
    Q_OBJECT

public:
    explicit httagen(QWidget *parent = nullptr);
    ~httagen();

private slots:
    void on_decodeBtn_clicked();
    void on_encodeBtn_clicked();
    void on_aboutBtn_clicked();

private:
    Ui::httagen *ui;
};

#endif // HTTAGEN_H
