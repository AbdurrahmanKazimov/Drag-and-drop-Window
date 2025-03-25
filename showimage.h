#ifndef SHOWIMAGE_H
#define SHOWIMAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui {
class ShowImage;
}
QT_END_NAMESPACE

class ShowImage : public QWidget
{
    Q_OBJECT

private:
    void setImage(const QString &filePath);
    void clearImage();
    void addImage();
    QStringList validExtensions = {"png", "jpg", "jpeg", "bmp"};
    Ui::ShowImage *ui;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

public:
    ShowImage();
    ~ShowImage();
private slots:
    void on_btnClear_clicked();
    void on_btnAdd_clicked();
};
#endif // SHOWIMAGE_H
