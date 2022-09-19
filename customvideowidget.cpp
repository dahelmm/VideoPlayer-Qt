#include "customvideowidget.h"

CustomVideoWidget::CustomVideoWidget()
{

}

void CustomVideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
  if(event->button() == Qt::LeftButton)
  {
    if(this->isFullScreen())
      this->setFullScreen(false);
    else
      this->setFullScreen(true);
  }
}
