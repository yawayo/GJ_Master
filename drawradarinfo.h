#ifndef DRAWRADARINFO_H
#define DRAWRADARINFO_H

#include <QWidget>
#include <QDebug>
#include <QPainter>

#include <unistd.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/time.h>

#include <obj_linked_list.h>

#include <cv.h>
#include <highgui.h>

#include <PCANBasicClass.h>

#define FPS 30
#define MAX_OBJ 100
#define INFOBOX_NUM 10

#define NORTH 0
#define SOUTH 1


class DrawRadarInfo : public QWidget
{
public:
    DrawRadarInfo(QWidget* parent = nullptr);

    int pixelStartWidth;
    int pixelStartHeight;
    int Way;

    PCANBasicClass m_PCANDevice;
    bool startRadar;

    int Radar_ID;

    TPCANHandle m_Handle;
    TPCANBaudrate m_Baudrate;
    TPCANType m_Type;
    DWORD m_Port;
    WORD m_Interrupt;

    timeval lastFlame;
    float realFPS = 0.0;
    double minFramePerioMsec = 1000.0 / FPS;

    int MAX_CONTINUOUS;
    int MAX_DISTLONG;
    int MAX_DISTLAT;


    bool first_A;
    SYSTEMTIME A_DateTime;
    timeval A_Cycle_time;
    int N_car;
    int N_car_now;
    int count4Kalman;

    CvKalman* kalman_d[MAX_OBJ];
    CvKalman* kalman_v[MAX_OBJ];

    // - Filter Parameter
    int LOWER_VELOCITY;
    int UPPER_VELOCITY;

    int minDist;
    int maxDist;

    obj_LinkedList Obj_data[MAX_OBJ];
    Obj_inf this_frame_data[MAX_OBJ];
    bool exist[MAX_OBJ];

    int LANE_NUM;
    int LANE_SPACE;
    int LANE_COUNT;

    bool infoBoxOccupied[INFOBOX_NUM] = {};

    float** lanePoint;
    bool haveLanePoint;
    int sizeofLUT_X = 500, sizeofLUT_Y=500;
    IplImage* LookUpImage;
    void setLookUpImage();

    bool graphics_on = true;
    void draw_distline(QPainter* painter);
    void draw_carlane(QPainter* painter);
    void draw_obj(QPainter* painter);


protected:
    void paintEvent(QPaintEvent*) override;
    virtual void resizeEvent(QResizeEvent*);
};

#endif // DRAWRADARINFO_H
