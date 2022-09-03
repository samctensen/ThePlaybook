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

#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QLabel>
#include <QtWidgets>
#include <iostream>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

//! [0]
class DragWidget : public QLabel
{
    Q_OBJECT

public:
    enum RouteType {BackDropSingleBack, BackDropGoalLine, BackDropWishbone, BackDropProSet, BackDropSpread, BackDropShotgun, BackDropIFormation,
                    Flat, HotFlat, Comeback, HotComeback, Out, HotOut, Corner, HotCorner, Go, HotGo, Post, HotPost, Dig, HotDig, Curl, HotCurl, Slant, HotSlant,
                    Flat_Flip, HotFlat_Flip, Comeback_Flip, HotComeback_Flip, Out_Flip, HotOut_Flip, Corner_Flip, HotCorner_Flip, Go_Flip, HotGo_Flip, Post_Flip, HotPost_Flip, Dig_Flip, HotDig_Flip, Curl_Flip, HotCurl_Flip, Slant_Flip, HotSlant_Flip,
                    Run1, HotRun1, Run2, HotRun2, Run3, HotRun3, Run4, HotRun4, Run5, HotRun5,
                    Run1_Flip, HotRun1_Flip, Run2_Flip, HotRun2_Flip, Run3_Flip, HotRun3_Flip, Run4_Flip, HotRun4_Flip, Run5_Flip, HotRun5_Flip};
    std::vector<RouteType> hotRoutes = {HotFlat, HotComeback, HotOut, HotCorner, HotGo, HotPost, HotDig, HotCurl, HotSlant, HotFlat_Flip, HotComeback_Flip, HotOut_Flip, HotCorner_Flip, HotGo_Flip, HotPost_Flip, HotDig_Flip, HotCurl_Flip, HotSlant_Flip, HotRun1, HotRun2, HotRun3, HotRun4, HotRun5, HotRun1_Flip, HotRun2_Flip, HotRun3_Flip, HotRun4_Flip, HotRun5_Flip};
    explicit DragWidget(RouteType routeType, QWidget *parent = nullptr);
    inline static std::vector<std::pair<QPixmap, QPoint>> currentRoutes = {};
    inline static bool hotUsed;
    inline static RouteType recentRoute;
    RouteType type;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

//! [0]

#endif // DRAGWIDGET_H
