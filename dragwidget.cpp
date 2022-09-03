/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "dragwidget.h"

/**
 * @brief Constructs the class that allows us to drag widgets onto one another
 * @param routeType
 * @param parent
 */
DragWidget::DragWidget(RouteType routeType, QWidget *parent)
    : QLabel(parent)
{
    type = routeType;

    setMinimumSize(150, 150);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QLabel *label = new QLabel(this);
    label->setFixedSize(150, 150);
    label->setScaledContents(true);
    label->setStyleSheet("border:3px solid black");

    switch (routeType) {
        case BackDropWishbone:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/WishboneField.png")));
            break;
        case BackDropSpread:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/SpreadField.png")));
            break;
        case BackDropSingleBack:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/SingleBackField.png")));
            break;
        case BackDropShotgun:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/ShotgunField.png")));
            break;
        case BackDropProSet:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/ProSetField.png")));
            break;
        case BackDropGoalLine:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/GoalLineField.png")));
            break;
        case BackDropIFormation:
            label->setFixedSize(791, 601);
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/I-FormationField.png")));
            break;
        case Flat:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/1.png")));
            break;
        case HotFlat:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/1_hot.png")));
            break;
        case Comeback:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/3.png")));
            break;
        case HotComeback:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/3_hot.png")));
            break;
        case Out:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/5.png")));
            break;
        case HotOut:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/5_hot.png")));
            break;
        case Corner:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/7.png")));
            break;
        case HotCorner:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/7_hot.png")));
            break;
        case Go:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/9.png")));
           break;
        case HotGo:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/9_hot.png")));
           break;
        case Post:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/8.png")));
            break;
        case HotPost:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/8_hot.png")));
            break;
        case Dig:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/6.png")));
            break;
        case HotDig:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/6_hot.png")));
            break;
        case Curl:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/4.png")));
            break;
        case HotCurl:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/4_hot.png")));
            break;
        case Slant:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/2.png")));
            break;
        case HotSlant:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/2_hot.png")));
            break;
        case Flat_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/1_flip.png")));
            break;
        case HotFlat_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/1_flip_hot.png")));
            break;
        case Comeback_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/3_flip.png")));
            break;
        case HotComeback_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/3_flip_hot.png")));
            break;
        case Out_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/5_flip.png")));
            break;
        case HotOut_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/5_flip_hot.png")));
            break;
        case Corner_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/7_flip.png")));
            break;
        case HotCorner_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/7_flip_hot.png")));
            break;
        case Go_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/9.png")));
           break;
        case HotGo_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/9_hot.png")));
           break;
        case Post_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/8_flip.png")));
            break;
        case HotPost_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/8_flip_hot.png")));
            break;
        case Dig_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/6_flip.png")));
            break;
        case HotDig_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/6_flip_hot.png")));
            break;
        case Curl_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/4_flip.png")));
            break;
        case HotCurl_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/4_flip_hot.png")));
            break;
        case Slant_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/2_flip.png")));
            break;
        case HotSlant_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/2_flip_hot.png")));
            break;
        case Run1:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r1.png")));
           break;
        case HotRun1:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r1_hot.png")));
           break;
        case Run2:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r2.png")));
            break;
        case HotRun2:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r2_hot.png")));
            break;
        case Run3:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r3.png")));
            break;
        case HotRun3:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r3_hot.png")));
            break;
        case Run4:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r4.png")));
            break;
        case HotRun4:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r4_hot.png")));
            break;
        case Run5:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r5.png")));
            break;
        case HotRun5:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r5_hot.png")));
            break;
        case Run1_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r1_flip.png")));
           break;
        case HotRun1_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r1_flip_hot.png")));
           break;
        case Run2_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r2_flip.png")));
            break;
        case HotRun2_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r2_flip_hot.png")));
            break;
        case Run3_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r3_flip.png")));
            break;
        case HotRun3_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r3_flip_hot.png")));
            break;
        case Run4_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r4_flip.png")));
            break;
        case HotRun4_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r4_flip_hot.png")));
            break;
        case Run5_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r5_flip.png")));
            break;
        case HotRun5_Flip:
            label->setPixmap(QPixmap::fromImage(QImage(":/Images/r5_flip_hot.png")));
            break;
    }
}

/**
 * @brief Drag enter event
 * @param event
 */
void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

/**
 * @brief Drag move event
 * @param event
 */
void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

/**
 * @brief Drop event
 * @param event
 */
void DragWidget::dropEvent(QDropEvent *event)
{
   if (this->type == BackDropIFormation || this->type == BackDropGoalLine || this->type == BackDropProSet || this->type ==BackDropShotgun || this->type == BackDropSingleBack || this->type == BackDropSpread || this->type == BackDropWishbone){
       if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QPixmap pixmap;
            QPoint offset;
            dataStream >> pixmap >> offset;
            if(event->pos().x() > 75 && event->pos().x() < 766 && event->pos().y() < 400) {
                bool hotFound = false;
                for (auto rt : hotRoutes) {
                    if (recentRoute == rt) {
                        hotFound = true;
                    }
                }
                if (hotFound) {
                    if (hotUsed == true) {
                        return;
                    } else {
                        hotUsed = true;
                    }
                }

                QLabel *newIcon = new QLabel(this);
                newIcon->setPixmap(pixmap);
                newIcon->move(event->pos() - offset);
                newIcon->show();
                newIcon->setAttribute(Qt::WA_DeleteOnClose);
                std::pair<QPixmap, QPoint> p;
                p.first = pixmap;
                p.second = (event->pos() - offset);
                DragWidget::currentRoutes.push_back(p);
            }


            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        }
    }
    else {
       event->ignore();
    }
}

/**
 * @brief Mouse press event
 * @param event
 */
void DragWidget::mousePressEvent(QMouseEvent *event)
{
    if (this->type != BackDropIFormation && this->type != BackDropGoalLine && this->type != BackDropProSet && this->type != BackDropShotgun && this->type != BackDropSingleBack && this->type != BackDropSpread && this->type != BackDropWishbone) {

        recentRoute = this->type;

        QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
        if (!child)
            return;

        QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());

        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
        painter.end();

        child->setPixmap(tempPixmap);

        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
            child->close();
        } else {
            child->show();
            child->setPixmap(pixmap);
        }
         //emit hotUsed();
    }
}

