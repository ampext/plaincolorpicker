#pragma once

#include <QWidget>
#include <QLinearGradient>

class PlainColorPicker : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    PlainColorPicker(QWidget *parent = 0);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    QColor color() const;
    void setColor(const QColor &color);

signals:
    void colorChanged(QColor);

private:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QLinearGradient gradient;
    QRect color_rect;
    QRect gradient_rect;
    QColor current_color;

    bool mouse_pressed;
};
