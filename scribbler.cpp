#include "scribbler.h"

#include <QDebug>

Scribbler::Scribbler(QWidget *parent) : QWidget(parent)
{
    m_image = QImage(280,280, QImage::Format_RGB32);
    clearImage();
}

void Scribbler::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&m_image);
    painter.setPen(QPen(m_penColor, m_penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(m_lastPoint, endPoint);
    m_modified = true;

    int rad = (m_penWidth / 2) + 2;
    update(QRect(m_lastPoint, endPoint).normalized()
           .adjusted(-rad, -rad, +rad, +rad));
    m_lastPoint = endPoint;
}

void Scribbler::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_scribbling = true;
    }
}

void Scribbler::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && m_scribbling)
        drawLineTo(event->pos());
}

void Scribbler::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_scribbling)
    {
        drawLineTo(event->pos());
        m_scribbling = false;
    }
}

void Scribbler::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, m_image, dirtyRect);
}

void Scribbler::clearImage()
{
    m_image.fill(qRgb(255, 255, 255));
    update();
}

void Scribbler::penSizeChanged(int size)
{
    m_penWidth = size;
}

void Scribbler::guess()
{
    QImage scaledImage = m_image.scaled(QSize(28,28),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QVector<double> vec;

    for ( unsigned i=0; i<28*28; ++i )
    {
        vec.append(static_cast<double>(1.0-(qGray(scaledImage.pixel(i%28,i/28))/255.0)));
    }

    emit guessDigit(vec);
}





































