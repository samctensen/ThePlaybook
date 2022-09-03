#include "play.h"

/**
 * @brief Sets up plays
 * @param bgType
 * @param rts
 */
Play::Play(DragWidget::RouteType bgType, std::vector<std::pair<QPixmap, QPoint>> rts)
{
    backgroundType = bgType;
    routes = rts;
    numPlays++;
    playName = "Play " + std::to_string(numPlays);
}

/**
 * @brief Saves routes in the play
 */
void Play::SaveRoutes() {
    for (auto route : DragWidget::currentRoutes) {
        routes.push_back(route);
    }
    DragWidget::currentRoutes.clear();

    hotRouteUsed = DragWidget::hotUsed;
    DragWidget::hotUsed = false;
}

