#include "showimage.h"
#include "imagelabel.h"
#include "ui_showimage.h"
#include <QFileDialog>
#include <QMimeData>
#include <QIcon>

ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setText("\n\n Drop Image Here \n\n");
    setStyleSheet("QLabel { border: 4px dashed #aaa; }");
    setFixedSize(350,350);
}

void ImageLabel::setPixmap(const QPixmap &image)
{
    QLabel::setPixmap(image);
}

ShowImage::ShowImage()
    : QWidget()
    , ui(new Ui::ShowImage)
{
    ui->setupUi(this);

    //resize(400, 400);
    setWindowTitle("Show My Image");
    setAcceptDrops(true);
}

void ShowImage::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        //
        QString filePath = event->mimeData()->urls().first().toLocalFile();
        QFileInfo fileInfo(filePath);
        QString suffix = fileInfo.suffix().toLower();


        if(validExtensions.contains(suffix)){
            event->acceptProposedAction();
        }
        else event->ignore();
    }
    else event->ignore();
}

void ShowImage::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
    }
    else event->ignore();
}

void ShowImage::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
        QString filePath = event->mimeData()->urls().first().toLocalFile();
        setImage(filePath);
    }
    else event->ignore();
}

void ShowImage::setImage(const QString &filePath)
{
    QPixmap pixmap(filePath);
    if(!pixmap.isNull()){
        //QSize size(600,400);
        ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

ShowImage::~ShowImage()
{
    delete ui;
}

void ShowImage::on_btnClear_clicked()
{
    ui->imageLabel->clear();
    ui->imageLabel->setText("\n\n Drop Image Here \n\n");
}


void ShowImage::on_btnAdd_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Image", "", "Images (*.png *.bmp *.jpg *.jpeg)");
    if(!filePath.isEmpty()){
        setImage(filePath);
    }
}
