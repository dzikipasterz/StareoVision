#ifndef CLOSECONFIRM_H
#define CLOSECONFIRM_H

#include <QDialog>

namespace Ui {
class closeConfirm;
}

class closeConfirm : public QDialog
{
    Q_OBJECT

public:
    explicit closeConfirm(QWidget *parent = nullptr);
    ~closeConfirm();

signals:
    void closeApplication();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::closeConfirm *ui;
};

#endif // CLOSECONFIRM_H
