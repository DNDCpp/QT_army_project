#ifndef POSTDIALOG_H
#define POSTDIALOG_H

#include <QDialog>

namespace Ui {
class PostDialog;
}

class PostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PostDialog(QWidget *parent = 0);
    ~PostDialog();

    QString postType();
    int duration();
    void setPostType(QString type);
    void setDuration(int days);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PostDialog *ui;
};

#endif // POSTDIALOG_H
