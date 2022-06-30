#include "drawradarinfo.h"

DrawRadarInfo::DrawRadarInfo(QWidget* parent) : QWidget (parent)
{
    first_A = false;
    gettimeofday(&lastFlame, nullptr);

    graphics_on = true;
}


void DrawRadarInfo::setLookUpImage()
{
    LookUpImage = cvCreateImage(cvSize(sizeofLUT_X, sizeofLUT_Y), IPL_DEPTH_8U, 1);
    cvSetZero(LookUpImage);
    CvPoint Lane_segments_cv[20][20][4];

    int i, j;
    for(i = 0; i < LANE_NUM; i++)
    {
        for(j = 0; j < LANE_COUNT - 1; j++)
        {
            Lane_segments_cv[i][j][0] = cvPoint(lanePoint[i][j] * (sizeofLUT_X/2), sizeofLUT_Y - (j + 0.5) * (sizeofLUT_Y / LANE_COUNT));
            Lane_segments_cv[i][j][1] = cvPoint(lanePoint[i+1][j] * (sizeofLUT_X/2), sizeofLUT_Y - (j + 0.5) * (sizeofLUT_Y / LANE_COUNT));
            Lane_segments_cv[i][j][2] = cvPoint(lanePoint[i+1][j+1] * (sizeofLUT_X/2), sizeofLUT_Y - (j + 1.5) * (sizeofLUT_Y / LANE_COUNT));
            Lane_segments_cv[i][j][3] = cvPoint(lanePoint[i][j+1] * (sizeofLUT_X/2), sizeofLUT_Y - (j + 1.5) * (sizeofLUT_Y / LANE_COUNT));

            cvFillConvexPoly(LookUpImage, Lane_segments_cv[i][j], 4, cvScalar(((i * (LANE_COUNT - 1)) + j + 1)*1));
        }
    }
    //cvShowImage("test", LookUpImage);
}

void DrawRadarInfo::paintEvent(QPaintEvent*)
{
    if(graphics_on)
    {
        QPainter painter(this);
        //painter.setCompositionMode(QPainter::CompositionMode_Source);

        draw_distline(&painter);
        if(haveLanePoint)
            draw_carlane(&painter);
        if(startRadar)
            draw_obj(&painter);
    }

    update();

    timeval thisFlame;
    gettimeofday(&thisFlame, nullptr);

    int diff_msec = (thisFlame.tv_sec - lastFlame.tv_sec) * 1000 + (thisFlame.tv_usec - lastFlame.tv_usec) / 1000;
    int waitMsec = minFramePerioMsec - diff_msec;
    if(waitMsec > 0)
        std::this_thread::sleep_for(std::chrono::milliseconds(waitMsec));

    gettimeofday(&thisFlame, nullptr);
    int diff_now = (thisFlame.tv_sec - lastFlame.tv_sec) * 1000 + (thisFlame.tv_usec - lastFlame.tv_usec) / 1000;

    realFPS = 1000 / ((diff_now > 0) ? diff_now : 1);

    gettimeofday(&lastFlame, nullptr);
}

void DrawRadarInfo::draw_distline(QPainter* painter)
{
    QFont font = painter->font() ;
    font.setPointSize(width() / 80);
    painter->setFont(font);
    QFontMetrics fm(font);

    //painter->setPen(QPen(QColor::fromRgbF(0, 1, 0, 1), 1));

    for(int i=0; i<LANE_COUNT; i++)
    {
        int textWidth = fm.width(QString::number(LANE_SPACE * i) + "m");

        painter->setPen(QPen(Qt::yellow, 1));
        painter->drawLine(pixelStartWidth + Way * ((width() / 50.0) + ((float(LANE_SPACE * i) / MAX_DISTLONG) * (width() * (24.0 / 25.0)))), height() * ( 5.0 / 20.0),
                          pixelStartWidth + Way * ((width() / 50.0) + ((float(LANE_SPACE * i) / MAX_DISTLONG) * (width() * (24.0 / 25.0)))), height() * ( 19.0 / 20.0));

        painter->setPen(Qt::white);
        painter->drawText(pixelStartWidth + Way * ((width() / 50.0) + ((float(LANE_SPACE * i) / MAX_DISTLONG) * (width() * (24.0 / 25.0))) - Way * (textWidth / 2.0)), height(), QString::number(LANE_SPACE * i) + "m");


    }
    int FPStextWidth = fm.width("FPS : " + QString::number(realFPS, 'f', 1));
    int FPStextHeight = fm.height();
    painter->drawText(width() - FPStextWidth, FPStextHeight, "FPS : " + QString::number(realFPS, 'f', 1));
}
//void DrawRadarInfo::draw_distline(QPainter* painter)
//{
//    QFont font = painter->font() ;
//    font.setPointSize(width() / 80);
//    painter->setFont(font);

//    int i;

//    //painter->setPen(QPen(QColor::fromRgbF(0, 1, 0, 1), 1));

//    for(i=0; i<LANE_COUNT; i++)
//    {
//        painter->setPen(QPen(Qt::yellow, 1));
//        painter->drawLine(width() / 4, height() - (height() / 20) - ((float(LANE_SPACE * i) / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20)))),
//                          (width() * 3) / 4, height() - (height() / 20) - ((float(LANE_SPACE * i) / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20)))));


//        painter->setPen(Qt::white);
//        painter->drawText(((width() * 3) / 4)-30, height() - (height() / 20) - ((float(LANE_SPACE * i) / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20)))) - 2, QString::number(LANE_SPACE * i) + "m");

//    }
//    painter->drawText(width() * (16.0 / 20.0), height() / 30.0, '6' + QString::number(Radar_ID) + "A : " + QString::number(A_Cycle) + "ms  FPS : " + QString::number(realFPS, 'f', 1));
//}
void DrawRadarInfo::draw_carlane(QPainter* painter)
{
    QFont font = painter->font() ;
    font.setPointSize(height() / 100);
    painter->setFont(font);

    painter->setPen(Qt::white);
    int i, j;
    for(i=0; i<LANE_NUM + 1; i++)
    {
        for(j=0; j<LANE_COUNT-1; j++)
        {
            painter->drawLine(pixelStartWidth + Way * ((width() / 50.0) + ((float(LANE_SPACE * j) / MAX_DISTLONG) * (width() * (24.0 / 25.0)))), height() * (5.0 / 20.0) + pixelStartHeight + Way * (lanePoint[i][j] * (height() * (7.0 / 20.0))),
                              pixelStartWidth + Way * ((width() / 50.0) + ((float(LANE_SPACE * (j + 1)) / MAX_DISTLONG) * (width() * (24.0 / 25.0)))), height() * (5.0 / 20.0) + pixelStartHeight + Way * (lanePoint[i][j+1] * (height() * (7.0 / 20.0))));
        }
    }
}
//void DrawRadarInfo::draw_carlane(QPainter* painter)
//{
//    QFont font = painter->font() ;
//    font.setPointSize(height() / 100);
//    painter->setFont(font);

//    painter->setPen(Qt::white);
//    int i, j;
//    for(i=0; i<LANE_NUM + 1; i++)
//    {
//        for(j=0; j<LANE_COUNT-1; j++)
//        {
//            painter->drawLine((width()/4) + lanePoint[i][j] * (width()/4), height() - (height() / 20) - ((float(LANE_SPACE * j) / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20)))),
//                              (width()/4) + lanePoint[i][j+1] * (width()/4), height() - (height() / 20) - ((float(LANE_SPACE * (j + 1)) / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20)))));
//        }
//    }
//}

void DrawRadarInfo::draw_obj(QPainter* painter)
{
    for(int i=0; i<MAX_OBJ; i++)
    {
        if(!Obj_data[i].isEmpty())
        {
            painter->setBrush(QBrush(Qt::NoBrush));

            Obj_inf item = Obj_data[i].getLast();

//            int obj_x = ((item.DistLat / 2 - MAX_DISTLAT) * -1) * (float(width()) / (MAX_DISTLAT * 2));
//            int obj_y = height() - (height() / 20) - ((item.DistLong / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20.0))));
            int obj_x = height() * (5.0 / 20.0) + pixelStartHeight + Way * (((item.DistLat / MAX_DISTLAT) + 1.0) * (height() * (7.0 / 20.0)));
            int obj_y = pixelStartWidth + Way * ((width() / 50.0) + ((item.DistLong / MAX_DISTLONG) * (width() * (24.0 / 25.0))));
            int info_x = (width() / INFOBOX_NUM) * (item.index_of_infoBox - 1);
            int info_y = height() * (1.0 / 20.0);
            QRect rect(obj_y-(height() / 100.0), obj_x-(height() / 100.0), height() / 50.0, height() / 50.0);

            painter->setPen(Qt::green);
            painter->setBrush(QBrush(Qt::green));

            painter->drawEllipse(info_x + ((width() / INFOBOX_NUM) / 2), info_y + height() * (4.0 / 20.0) - width() / 400, width() / 200, width() / 200);

            if(item.virtual_obj)
                painter->setBrush(QBrush(Qt::NoBrush));

            painter->drawRect(rect);

            painter->setBrush(QBrush(Qt::NoBrush));

            QFont font = painter->font() ;
            font.setPointSize(height() / 50);
            painter->setFont(font);

            if((item.index_of_infoBox > 0) && (item.index_of_infoBox <= INFOBOX_NUM))
            {
                // 4각형
                QRect rect(info_x, info_y, width() / INFOBOX_NUM, (height() * (4.0 / 20.0)) - 1);
                painter->drawRect(rect);

                QFontMetrics fm(font);
                int textHeight = fm.height();

                painter->drawLine(obj_y, obj_x, info_x + ((width() / INFOBOX_NUM) / 2), info_y + height() * (4.0 / 20.0) - width() / 400);
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 1), "ID       : " + QString::number(item.ID));
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 2), "VELOCITY    : " + QString::number(item.Velocity,'f',1));
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 3), "DISTLONG : " + QString::number(item.DistLong,'f',1));
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 4), "TTC      : " + QString::number(item.ttc,'f',1));
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 5), "Zone Index : " + QString::number(item.zone_index));
                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 6), "Obj : " + QString::number(Obj_data[i].getsize()));
//                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 5), "ArelLat : " + QString::number(item.ArelLat));
//                painter->drawText(info_x + (width() / 200), info_y + (textHeight * 6), "ArelLong : " + QString::number(item.ArelLong));
            }
            else
            {
                painter->drawText(obj_y + 10, obj_x, "[" + QString::number(item.ID) + "] " + QString::number(item.Velocity));
            }
        }
    }
}

//void DrawRadarInfo::draw_obj(QPainter* painter)
//{

//    int i;
//    for(i=0; i<MAX_OBJ; i++)
//    {
//        if(!Obj_data[i].isEmpty())
//        {
//            painter->setBrush(QBrush(Qt::NoBrush));

//            Obj_inf item = Obj_data[i].getLast();

//            int obj_x = ((item.DistLat / 2 - MAX_DISTLAT) * -1) * (float(width()) / (MAX_DISTLAT * 2));
//            int obj_y = height() - (height() / 20) - ((item.DistLong / MAX_DISTLONG) * (height() * (1.0 - (2.0 / 20.0))));
//            int info_x = int((item.index_of_infoBox - 1) / INFOBOX_NUM) * (3 * (width() / 4));
//            int info_y = (height() / 20) + ((item.index_of_infoBox - 1) % INFOBOX_NUM) * ((height() * (19.0 / 20.0)) / INFOBOX_NUM);

//            QRect rect(obj_x-7, obj_y-7, height() / 50, height() / 50);

//            painter->setPen(Qt::green);
//            painter->setBrush(QBrush(Qt::green));

//            painter->drawEllipse((width() / 2) * (0.5 + int((item.index_of_infoBox - 1) / INFOBOX_NUM)) - (width() / 200), info_y + (height() / (INFOBOX_NUM * 2)) - (width() / 200), width() / 100, width() / 100);

//            if(item.virtual_obj)
//                painter->setBrush(QBrush(Qt::NoBrush));

//            painter->drawRect(rect);

//            painter->setBrush(QBrush(Qt::NoBrush));

//            QFont font = painter->font() ;
//            font.setPointSize(height() / 100);
//            painter->setFont(font);

//            if((item.index_of_infoBox > 0) && (item.index_of_infoBox <= (INFOBOX_NUM * 2)))
//            {
//                // 4각형
//                QRect rect(info_x, info_y, width() / 4, ((height() * (19.0 / 20.0)) / INFOBOX_NUM) - 1);
//                painter->drawRect(rect);

//                painter->drawLine(obj_x, obj_y, (width() / 2) * (0.5 + int((item.index_of_infoBox - 1) / INFOBOX_NUM)), info_y + ((height() * (19.0 / 20.0)) / (INFOBOX_NUM * 2)));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 1.0)), "ID       : " + QString::number(item.ID));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 2.0)), "VELOCITY    : " + QString::number(item.Velocity,'f',1));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 3.0)), "DISTLAT  : " + QString::number(item.DistLat,'f',1));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 4.0)), "DISTLONG : " + QString::number(item.DistLong,'f',1));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 5.0)), "RCS      : " + QString::number(item.DistLong,'f',1));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 6.0)), "ProbOfExist : " + QString::number(item.ProbOfExist));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 7.0)), "Zone Index : " + QString::number(item.zone_index));
//                painter->drawText(info_x + (width() / 100), info_y + (float((height() * (19.0 / 20.0))) / (50.0 / 8.0)), "Obj : " + QString::number(Obj_data[i].getsize()));


//                /*
//                // 5각형
//                if(((item.index_of_infoBox - 1) / INFOBOX_NUM) == 0)
//                {
//                    painter->drawLine(info_x, info_y, info_x + (width() / 5), info_y);
//                    painter->drawLine(info_x, info_y, info_x, info_y + ((height() / INFOBOX_NUM) - 1));
//                    painter->drawLine(info_x, info_y + ((height() / INFOBOX_NUM) - 1), info_x + (width() / 5), info_y + ((height() / INFOBOX_NUM) - 1));

//                    painter->drawLine(info_x + (width() / 5), info_y, (width() / 2) * 0.5, info_y + (height() / (INFOBOX_NUM * 2)));
//                    painter->drawLine(info_x + (width() / 5), info_y + ((height() / INFOBOX_NUM) - 1), (width() / 2) * 0.5, info_y + (height() / (INFOBOX_NUM * 2)));

//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 1.0)), "ID       : " + QString::number(item.ID));
//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 2.0)), "SPEED    : " + QString::number(item.Speed,'f',1));
//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 3.0)), "DISTLAT  : " + QString::number(item.DistLat,'f',1));
//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 4.0)), "DISTLONG : " + QString::number(item.DistLong,'f',1));
//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 5.0)), "RCS      : " + QString::number(item.DistLong,'f',1));
//                    painter->drawText(info_x + (width() / 100), info_y + (float(height()) / (50.0 / 6.0)), "ProbOfExist : " + QString::number(item.ProbOfExist));

//                    painter->drawLine(obj_x, obj_y, (width() / 2) * 0.5, info_y + (height() / (INFOBOX_NUM * 2)));
//                }
//                else
//                {
//                    painter->drawLine(info_x + (width() / 20), info_y, info_x + (width() / 4), info_y);
//                    painter->drawLine(info_x + (width() / 4), info_y, info_x + (width() / 4), info_y + ((height() / INFOBOX_NUM) - 1));
//                    painter->drawLine(info_x + (width() / 20), info_y + ((height() / INFOBOX_NUM) - 1), info_x + (width() / 4), info_y + ((height() / INFOBOX_NUM) - 1));

//                    painter->drawLine(info_x + (width() / 20), info_y, (width() / 2) * 1.5, info_y + (height() / (INFOBOX_NUM * 2)));
//                    painter->drawLine(info_x + (width() / 20), info_y + ((height() / INFOBOX_NUM) - 1), (width() / 2) * 1.5, info_y + (height() / (INFOBOX_NUM * 2)));

//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 1.0)), "ID       : " + QString::number(item.ID));
//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 2.0)), "SPEED    : " + QString::number(item.Speed,'f',1));
//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 3.0)), "DISTLAT  : " + QString::number(item.DistLat,'f',1));
//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 4.0)), "DISTLONG : " + QString::number(item.DistLong,'f',1));
//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 5.0)), "RCS      : " + QString::number(item.DistLong,'f',1));
//                    painter->drawText(info_x + (width() / 100) + (width() / 20), info_y + (float(height()) / (50.0 / 6.0)), "ProbOfExist : " + QString::number(item.ProbOfExist));

//                    painter->drawLine(obj_x, obj_y, (width() / 2) * 1.5, info_y + (height() / (INFOBOX_NUM * 2)));
//                }
//                */
//            }
//            else
//            {
//                painter->drawText(obj_x + 10, obj_y, "[" + QString::number(item.ID) + "] " + QString::number(item.Velocity));
//            }
//        }
//    }
//}
void DrawRadarInfo::reset()
{
    for(int i=0; i<MAX_OBJ; i++)
    {
        Obj_data[i].remove_all();
    }
    memset(exist, false, sizeof(bool) * MAX_OBJ);
    memset(this_frame_data, 0, sizeof(Obj_inf) * MAX_OBJ);
    memset(infoBoxOccupied, false, sizeof(bool) * INFOBOX_NUM);

}
void DrawRadarInfo::resizeEvent(QResizeEvent *)
{
    pixelStartWidth = (Way == -1) ? width() : 0;
    pixelStartHeight = (Way == -1) ? height() * (14.0/20.0) : 0;
}
