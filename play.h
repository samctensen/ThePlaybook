#ifndef PLAY_H
#define PLAY_H
#include "dragwidget.h"

class Play
{
public:
    Play(DragWidget::RouteType bgType, std::vector<std::pair<QPixmap, QPoint>> rts);
    DragWidget::RouteType backgroundType;
    std::vector<std::pair<QPixmap, QPoint>> routes;
    std::string playName;
    QString backgroundName = "BackDropIFormation";
    bool hotRouteUsed = false;
    void SaveRoutes();

private:
    inline static int numPlays = 0;
};

#endif // PLAY_H
