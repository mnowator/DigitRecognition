#ifndef SCRIBBLER_H
#define SCRIBBLER_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>

class Scribbler : public QWidget
{
    Q_OBJECT

private:
    QImage m_image;
    QPoint m_lastPoint;
    bool m_modified;
    bool m_scribbling;
    int m_penWidth = 2;
    QColor m_penColor = Qt::black;

    void drawLineTo(const QPoint &endPoint);

public:
    explicit Scribbler(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
    void guessDigit(QVector<double> image);

public slots:
    void clearImage();
    void penSizeChanged(int size);
    void guess();
};

#endif // SCRIBBLER_H
