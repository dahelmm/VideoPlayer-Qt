#ifndef CUSTOMVIDEOWIDGET_H
#define CUSTOMVIDEOWIDGET_H

#include <QVideoWidget>
#include <QMouseEvent>

class CustomVideoWidget : public QVideoWidget
{
public:
  CustomVideoWidget();

  void mouseDoubleClickEvent(QMouseEvent* event) override;
};

#endif // CUSTOMVIDEOWIDGET_H
