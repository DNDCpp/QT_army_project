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

    int postType();
    int duration();
    int punktNumber();
    void setPostType(int type);
    void setDuration(int days);
    void setPunktNumber(int punkt);
    QString shortType(int currentIndex, int punkt = 0);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_postType_currentIndexChanged(const QString &arg1);

private:
    Ui::PostDialog *ui;
};

#endif // POSTDIALOG_H
