#include "plaincolorpicker.h"

#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>

PlainColorPicker::PlainColorPicker(QWidget *parent) : QWidget(parent), mouse_pressed(false)
{
    QGradientStops stops(255);

    for(int i = 0; i < stops.size(); i++)
    {
        double value = 1.0 / stops.size() * i;

        stops[i].first = value;
        stops[i].second = QColor::fromHsvF(value, 1.0f, 1.0f);
    }

    gradient.setStops(stops);
}

void PlainColorPicker::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::black));

    if(gradient_rect.width() > 0)
    {
        painter.setBrush(QBrush(gradient));
        painter.drawRect(gradient_rect);
    }

    if(color_rect.width() > 0)
    {
        painter.setBrush(QBrush(color()));
        painter.drawRect(color_rect);
    }
}

void PlainColorPicker::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();

    gradient.setStart(QPointF(0, 0));
    gradient.setFinalStop(QPointF(size.width(), 0));

    if(size.width() > 2 * size.height() + 2)
    {
        gradient_rect = QRect(0, 0, width() - (2 + size.height()) - 1, size.height() - 1);
        color_rect = QRect(gradient_rect.width() + 2, 0, size.height() - 1, size.height() - 1);
    }
    else
    {
        gradient_rect = QRect(0, 0, size.width() - 1, size.height() - 1);
        color_rect = QRect(0, 0, 0, 0);
    }
}

void PlainColorPicker::mousePressEvent(QMouseEvent *)
{
    mouse_pressed = true;
}

void PlainColorPicker::mouseReleaseEvent(QMouseEvent *)
{
     mouse_pressed = false;
}

void PlainColorPicker::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_pressed)
    {
        double value = static_cast<double>(std::min(gradient_rect.width(), std::max(0, event->x()))) / gradient_rect.width();
        setColor(QColor::fromHsvF(value, 1.0f, 1.0f));
    }
}

QSize PlainColorPicker::sizeHint() const
{
    return QSize(150, 16);
}

QSize PlainColorPicker::minimumSizeHint() const
{
    return QSize(40, 16);
}

QColor PlainColorPicker::color() const
{
    return current_color;
}

void PlainColorPicker::setColor(const QColor &color)
{
    current_color = color;
    emit colorChanged(color);

    repaint();
}
