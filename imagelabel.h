#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>

class ImageLabel :public QLabel
{
    Q_OBJECT

public:
    ImageLabel(QWidget *parent = nullptr);
    void setPixmap(const QPixmap &image);
};

#endif // IMAGELABEL_H
