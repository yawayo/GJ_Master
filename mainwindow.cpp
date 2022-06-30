#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    do_print_text = true;
    do_kalman = false;
    do_print_table = false;

    createUI();

    //initValue();

//    GetLocalTime(&global_time);

//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(readTime()));
//    timer->start(10);

//    int try_count = 1;

//    //while(!Connect_Radar())
//    {
//        qDebug("Retry...%d", try_count);
//        try_count++;
//    }
//    qDebug("Radar Connection Successful");
//    //while(!Connect_Camera())
//    {
//        qDebug("Retry...%d", try_count);
//        try_count++;
//    }
//    qDebug("Camera Connection Successful");
//    //while(!Connect_Socket())
//    {
//        qDebug("Retry...%d", try_count);
//        try_count++;
//    }
//    qDebug("Socket Connection Successful");
//    //while(!Connect_Serial())
//    {
//        qDebug("Retry...%d", try_count);
//        try_count++;
//    }
//    qDebug("Serial Connection Successful");
}

MainWindow::~MainWindow()
{

}

void MainWindow::createUI()
{
    //Total Layout
    main_layout = new QVBoxLayout;

    // Button
    button_layout = new QHBoxLayout;

    radarGroup = new QGroupBox("Radar");
    Connectbtn_Radar = new QPushButton("Connect");
    Disconnectbtn_Radar = new QPushButton("Disconnect"); Disconnectbtn_Radar->setEnabled(false);
    QHBoxLayout* radarGroup_layout = new QHBoxLayout;
    connect(Connectbtn_Radar, SIGNAL(clicked()), SLOT(on_Connectbtn_Radar_clicked()));
    connect(Disconnectbtn_Radar, SIGNAL(clicked()), SLOT(on_Disconnectbtn_Radar_clicked()));
    radarGroup->setMaximumSize(300,100);

    radarGroup_layout->addWidget(Connectbtn_Radar);
    radarGroup_layout->addWidget(Disconnectbtn_Radar);
    radarGroup->setLayout(radarGroup_layout);


    cameraGroup = new QGroupBox("Camera");
    Connectbtn_Camera = new QPushButton("Connect");
    Disconnectbtn_Camera = new QPushButton("Disconnect"); Disconnectbtn_Camera->setEnabled(false);
    QHBoxLayout* cameraGroup_layout = new QHBoxLayout;
    connect(Connectbtn_Camera, SIGNAL(clicked()), SLOT(on_Connectbtn_Camera_clicked()));
    connect(Disconnectbtn_Camera, SIGNAL(clicked()), SLOT(on_Disconnectbtn_Camera_clicked()));
    cameraGroup->setMaximumSize(300,100);

    cameraGroup_layout->addWidget(Connectbtn_Camera);
    cameraGroup_layout->addWidget(Disconnectbtn_Camera);
    cameraGroup->setLayout(cameraGroup_layout);


    socketGroup = new QGroupBox("Socket");
    Connectbtn_Socket = new QPushButton("Connect");
    Disconnectbtn_Socket = new QPushButton("Disconnect"); Disconnectbtn_Socket->setEnabled(false);
    QHBoxLayout* socketGroup_layout = new QHBoxLayout;
    connect(Connectbtn_Socket, SIGNAL(clicked()), SLOT(on_Connectbtn_Socket_clicked()));
    connect(Disconnectbtn_Socket, SIGNAL(clicked()), SLOT(on_Disconnectbtn_Socket_clicked()));
    socketGroup->setMaximumSize(300,100);

    socketGroup_layout->addWidget(Connectbtn_Socket);
    socketGroup_layout->addWidget(Disconnectbtn_Socket);
    socketGroup->setLayout(socketGroup_layout);


    serialGroup = new QGroupBox("Serial");
    Connectbtn_Serial = new QPushButton("Connect");
    Disconnectbtn_Serial = new QPushButton("Disconnect"); Disconnectbtn_Serial->setEnabled(false);
    QHBoxLayout* serialGroup_layout = new QHBoxLayout;
    connect(Connectbtn_Serial, SIGNAL(clicked()), SLOT(on_Connectbtn_Serial_clicked()));
    connect(Disconnectbtn_Serial, SIGNAL(clicked()), SLOT(on_Disconnectbtn_Serial_clicked()));
    serialGroup->setMaximumSize(300,100);

    serialGroup_layout->addWidget(Connectbtn_Serial);
    serialGroup_layout->addWidget(Disconnectbtn_Serial);
    serialGroup->setLayout(serialGroup_layout);


    settingGroup = new QGroupBox("Setting");
    Settingbtn = new QPushButton("Setting");
    QHBoxLayout* settingGroup_layout = new QHBoxLayout;
    connect(Settingbtn, SIGNAL(clicked()), SLOT(on_Settingbtn_clicked()));
    settingGroup->setMaximumSize(300,100);

    settingGroup_layout->addWidget(Settingbtn);
    settingGroup->setLayout(settingGroup_layout);


    button_layout_spacer = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Fixed);

    Logo = new QLabel;
    QPixmap logo("C:/Users/ODYSSEY/Desktop/img/HBrain.png");
    Logo->setPixmap(logo);
    Logo->setScaledContents(true);


    button_layout->addWidget(radarGroup);
    button_layout->addWidget(cameraGroup);
    button_layout->addWidget(socketGroup);
    button_layout->addWidget(serialGroup);
    button_layout->addWidget(settingGroup);
    button_layout->addSpacerItem(button_layout_spacer);
    button_layout->addWidget(Logo);
    button_layout->setContentsMargins(10, 10, 0, 5);
    button_layout->setSpacing(10);


    // Main Panel
    page = new QStackedWidget;

    // Main page
    main_page = new QWidget;
    main_page_layout = new QHBoxLayout;

    main_page_layout1 = new QVBoxLayout;

    N_Radar_Table = new QTableView;
    N_Radar_Viewer = new DrawRadarInfo; N_Radar_Viewer->setStyleSheet("background-color: rgb(0, 0, 0);");

    main_page_layout1_1 = new QHBoxLayout; main_page_layout1_1->setAlignment(Qt::AlignLeft);
    N_Display_Status = new QLabel;
    QPixmap N_DisplayImg("C:/Users/ODYSSEY/Desktop/img/Display_OFF.png");
    N_Display_Status->setPixmap(N_DisplayImg);

    main_page_layout1_1->addWidget(N_Display_Status);

    main_page_layout1->addWidget(N_Radar_Table);
    main_page_layout1->addWidget(N_Radar_Viewer);
    main_page_layout1->addLayout(main_page_layout1_1);
    main_page_layout1->setStretch(0, 1);
    main_page_layout1->setStretch(1, 1);
    main_page_layout1->setStretch(2, 1);


    main_page_layout2 = new QVBoxLayout;

    E_PD_Status = new QLabel; E_PD_Status->setStyleSheet("background-color: rgb(0, 0, 0);");
    QPixmap E_PDstatusImg("C:/Users/ODYSSEY/Desktop/img/PD_OUT.png");
    E_PD_Status->setPixmap(E_PDstatusImg);
    E_PD_Status->setScaledContents(true);



    main_page_layout2_1 = new QVBoxLayout;

    Camera_Viewer = new QVideoWidget; Camera_Viewer->setStyleSheet("background-color: rgb(0, 0, 0);");


    main_page_layout2_1_1 = new QHBoxLayout;

    move_UP = new QPushButton("UP");
    move_DOWN = new QPushButton("DOWN");
    move_LEFT = new QPushButton("LEFT");
    move_RIGHT = new QPushButton("RIGHT");
    connect(move_UP, SIGNAL(pressed()), SLOT(on_moveUP_pressed()));
    connect(move_UP, SIGNAL(released()), SLOT(on_moveUP_released()));
    connect(move_DOWN, SIGNAL(pressed()), SLOT(on_moveDOWN_pressed()));
    connect(move_DOWN, SIGNAL(released()), SLOT(on_moveDOWN_released()));
    connect(move_LEFT, SIGNAL(pressed()), SLOT(on_moveLEFT_pressed()));
    connect(move_LEFT, SIGNAL(released()), SLOT(on_moveLEFT_released()));
    connect(move_RIGHT, SIGNAL(pressed()), SLOT(on_moveRIGHT_pressed()));
    connect(move_RIGHT, SIGNAL(released()), SLOT(on_moveRIGHT_released()));


    main_page_layout2_1_1_spacer = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    main_page_layout2_1_1_1 = new QVBoxLayout;
    main_page_layout2_1_1_2 = new QVBoxLayout;
    main_page_layout2_1_1_3 = new QVBoxLayout;


    main_page_layout2_1_1_1->addWidget(move_LEFT);
    main_page_layout2_1_1_2->addWidget(move_UP);
    main_page_layout2_1_1_2->addWidget(move_DOWN);
    main_page_layout2_1_1_3->addWidget(move_RIGHT);

    main_page_layout2_1_1->addSpacerItem(main_page_layout2_1_1_spacer);
    main_page_layout2_1_1->addLayout(main_page_layout2_1_1_1);
    main_page_layout2_1_1->addLayout(main_page_layout2_1_1_2);
    main_page_layout2_1_1->addLayout(main_page_layout2_1_1_3);

    main_page_layout2_1->addWidget(Camera_Viewer);
    main_page_layout2_1->addLayout(main_page_layout2_1_1);

    W_PD_Status = new QLabel; W_PD_Status->setStyleSheet("background-color: rgb(0, 0, 0);");
    QPixmap W_PDstatusImg("C:/Users/ODYSSEY/Desktop/img/PD_OUT.png");
    W_PD_Status->setPixmap(W_PDstatusImg);
    W_PD_Status->setScaledContents(true);

    main_page_layout2->addWidget(E_PD_Status);
    main_page_layout2->addLayout(main_page_layout2_1);
    main_page_layout2->addWidget(W_PD_Status);
    main_page_layout2->setStretch(0, 1);
    main_page_layout2->setStretch(1, 1);
    main_page_layout2->setStretch(2, 1);


    main_page_layout3 = new QVBoxLayout;

    main_page_layout3_1 = new QHBoxLayout; main_page_layout3_1->setAlignment(Qt::AlignRight);
    S_Display_Status = new QLabel;
    QPixmap S_DisplayImg("C:/Users/ODYSSEY/Desktop/img/Display_OFF.png");
    S_Display_Status->setPixmap(S_DisplayImg);

    main_page_layout3_1->addWidget(S_Display_Status);

    S_Radar_Viewer = new DrawRadarInfo; S_Radar_Viewer->setStyleSheet("background-color: rgb(0, 0, 0);");
    S_Radar_Table = new QTableView;

    main_page_layout3->addLayout(main_page_layout3_1);
    main_page_layout3->addWidget(S_Radar_Viewer);
    main_page_layout3->addWidget(S_Radar_Table);
    main_page_layout3->setStretch(0, 1);
    main_page_layout3->setStretch(1, 1);
    main_page_layout3->setStretch(2, 1);


    main_page_layout->addLayout(main_page_layout1);
    main_page_layout->addLayout(main_page_layout2);
    main_page_layout->addLayout(main_page_layout3);
    main_page_layout->setStretch(0, 2);
    main_page_layout->setStretch(1, 1);
    main_page_layout->setStretch(2, 2);

    main_page->setLayout(main_page_layout);


    // Radar Setting page
    {
        radarSetting_page = new QWidget;
        radarSetting_page_layout = new QHBoxLayout;

        radarSetting_layout = new QVBoxLayout;

        radar_title_layout = new QHBoxLayout;
        radar_title = new QLabel("Radar"); radar_title->setFont(QFont("맑은 고딕", 20, QFont::Bold));
        radar_title_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
        writebtn_radarSetting = new QPushButton("Write");

        radar_title_layout->addWidget(radar_title);
        radar_title_layout->addSpacerItem(radar_title_spacer);
        radar_title_layout->addWidget(writebtn_radarSetting);


        radarSetting_value_layout = new QHBoxLayout;

        read_radarSetting_layout = new QVBoxLayout;

        read_NVMReadStatus_layout = new QHBoxLayout;
        read_NVMReadStatus_label = new QLabel("NVMReadStatus");
        read_NVMReadStatus_value = new QLabel("-"); read_NVMReadStatus_value->setAlignment(Qt::AlignRight);
        read_NVMReadStatus_layout->addWidget(read_NVMReadStatus_label);
        read_NVMReadStatus_layout->addWidget(read_NVMReadStatus_value);
        read_NVMReadStatus_layout->setStretch(0, 1);
        read_NVMReadStatus_layout->setStretch(1, 1);

        read_NVMWriteStatus_layout = new QHBoxLayout;
        read_NVMWriteStatus_label = new QLabel("NVMWriteStatus");
        read_NVMWriteStatus_value = new QLabel("-"); read_NVMWriteStatus_value->setAlignment(Qt::AlignRight);
        read_NVMWriteStatus_layout->addWidget(read_NVMWriteStatus_label);
        read_NVMWriteStatus_layout->addWidget(read_NVMWriteStatus_value);
        read_NVMWriteStatus_layout->setStretch(0, 1);
        read_NVMWriteStatus_layout->setStretch(1, 1);

        read_MaxDistanceCfg_layout = new QHBoxLayout;
        read_MaxDistanceCfg_label = new QLabel("MaxDistanceCfg");
        read_MaxDistanceCfg_value = new QLabel("-"); read_MaxDistanceCfg_value->setAlignment(Qt::AlignRight);
        read_MaxDistanceCfg_layout->addWidget(read_MaxDistanceCfg_label);
        read_MaxDistanceCfg_layout->addWidget(read_MaxDistanceCfg_value);
        read_MaxDistanceCfg_layout->setStretch(0, 1);
        read_MaxDistanceCfg_layout->setStretch(1, 1);

        read_PersistentError_layout = new QHBoxLayout;
        read_PersistentError_label = new QLabel("Persistent Error");
        read_PersistentError_value = new QLabel("-"); read_PersistentError_value->setAlignment(Qt::AlignRight);
        read_PersistentError_layout->addWidget(read_PersistentError_label);
        read_PersistentError_layout->addWidget(read_PersistentError_value);
        read_PersistentError_layout->setStretch(0, 1);
        read_PersistentError_layout->setStretch(1, 1);

        read_Interference_layout = new QHBoxLayout;
        read_Interference_label = new QLabel("Interference");
        read_Interference_value = new QLabel("-"); read_Interference_value->setAlignment(Qt::AlignRight);
        read_Interference_layout->addWidget(read_Interference_label);
        read_Interference_layout->addWidget(read_Interference_value);
        read_Interference_layout->setStretch(0, 1);
        read_Interference_layout->setStretch(1, 1);

        read_TemperatureError_layout = new QHBoxLayout;
        read_TemperatureError_label = new QLabel("Temperature Error");
        read_TemperatureError_value = new QLabel("-"); read_TemperatureError_value->setAlignment(Qt::AlignRight);
        read_TemperatureError_layout->addWidget(read_TemperatureError_label);
        read_TemperatureError_layout->addWidget(read_TemperatureError_value);
        read_TemperatureError_layout->setStretch(0, 1);
        read_TemperatureError_layout->setStretch(1, 1);

        read_TemporaryError_layout = new QHBoxLayout;
        read_TemporaryError_label = new QLabel("Temporary Error");
        read_TemporaryError_value = new QLabel("-"); read_TemporaryError_value->setAlignment(Qt::AlignRight);
        read_TemporaryError_layout->addWidget(read_TemporaryError_label);
        read_TemporaryError_layout->addWidget(read_TemporaryError_value);
        read_TemporaryError_layout->setStretch(0, 1);
        read_TemporaryError_layout->setStretch(1, 1);

        read_VoltageError_layout = new QHBoxLayout;
        read_VoltageError_label = new QLabel("Voltage Error");
        read_VoltageError_value = new QLabel("-"); read_VoltageError_value->setAlignment(Qt::AlignRight);
        read_VoltageError_layout->addWidget(read_VoltageError_label);
        read_VoltageError_layout->addWidget(read_VoltageError_value);
        read_VoltageError_layout->setStretch(0, 1);
        read_VoltageError_layout->setStretch(1, 1);

        read_SensorID_layout = new QHBoxLayout;
        read_SensorID_label = new QLabel("Sensor ID");
        read_SensorID_value = new QLabel("-"); read_SensorID_value->setAlignment(Qt::AlignRight);
        read_SensorID_layout->addWidget(read_SensorID_label);
        read_SensorID_layout->addWidget(read_SensorID_value);
        read_SensorID_layout->setStretch(0, 1);
        read_SensorID_layout->setStretch(1, 1);

        read_SortIndex_layout = new QHBoxLayout;
        read_SortIndex_label = new QLabel("SortIndex");
        read_SortIndex_value = new QLabel("-"); read_SortIndex_value->setAlignment(Qt::AlignRight);
        read_SortIndex_layout->addWidget(read_SortIndex_label);
        read_SortIndex_layout->addWidget(read_SortIndex_value);
        read_SortIndex_layout->setStretch(0, 1);
        read_SortIndex_layout->setStretch(1, 1);

        read_RadarPowerCfg_layout = new QHBoxLayout;
        read_RadarPowerCfg_label = new QLabel("RadarPowerCfg");
        read_RadarPowerCfg_value = new QLabel("-"); read_RadarPowerCfg_value->setAlignment(Qt::AlignRight);
        read_RadarPowerCfg_layout->addWidget(read_RadarPowerCfg_label);
        read_RadarPowerCfg_layout->addWidget(read_RadarPowerCfg_value);
        read_RadarPowerCfg_layout->setStretch(0, 1);
        read_RadarPowerCfg_layout->setStretch(1, 1);

        read_CtrlRelayCfg_layout = new QHBoxLayout;
        read_CtrlRelayCfg_label = new QLabel("CtrlRelayCfg");
        read_CtrlRelayCfg_value = new QLabel("-"); read_CtrlRelayCfg_value->setAlignment(Qt::AlignRight);
        read_CtrlRelayCfg_layout->addWidget(read_CtrlRelayCfg_label);
        read_CtrlRelayCfg_layout->addWidget(read_CtrlRelayCfg_value);
        read_CtrlRelayCfg_layout->setStretch(0, 1);
        read_CtrlRelayCfg_layout->setStretch(1, 1);

        read_OutputTypeCfg_layout = new QHBoxLayout;
        read_OutputTypeCfg_label = new QLabel("OutputTypeCfg");
        read_OutputTypeCfg_value = new QLabel("-"); read_OutputTypeCfg_value->setAlignment(Qt::AlignRight);
        read_OutputTypeCfg_layout->addWidget(read_OutputTypeCfg_label);
        read_OutputTypeCfg_layout->addWidget(read_OutputTypeCfg_value);
        read_OutputTypeCfg_layout->setStretch(0, 1);
        read_OutputTypeCfg_layout->setStretch(1, 1);

        read_SendQualityCfg_layout = new QHBoxLayout;
        read_SendQualityCfg_label = new QLabel("SendQualityCfg");
        read_SendQualityCfg_value = new QLabel("-"); read_SendQualityCfg_value->setAlignment(Qt::AlignRight);
        read_SendQualityCfg_layout->addWidget(read_SendQualityCfg_label);
        read_SendQualityCfg_layout->addWidget(read_SendQualityCfg_value);
        read_SendQualityCfg_layout->setStretch(0, 1);
        read_SendQualityCfg_layout->setStretch(1, 1);

        read_SendExtInfoCfg_layout = new QHBoxLayout;
        read_SendExtInfoCfg_label = new QLabel("SendExtInfoCfg");
        read_SendExtInfoCfg_value = new QLabel("-"); read_SendExtInfoCfg_value->setAlignment(Qt::AlignRight);
        read_SendExtInfoCfg_layout->addWidget(read_SendExtInfoCfg_label);
        read_SendExtInfoCfg_layout->addWidget(read_SendExtInfoCfg_value);
        read_SendExtInfoCfg_layout->setStretch(0, 1);
        read_SendExtInfoCfg_layout->setStretch(1, 1);

        read_MotionRxState_layout = new QHBoxLayout;
        read_MotionRxState_label = new QLabel("MotionRxState");
        read_MotionRxState_value = new QLabel("-"); read_MotionRxState_value->setAlignment(Qt::AlignRight);
        read_MotionRxState_layout->addWidget(read_MotionRxState_label);
        read_MotionRxState_layout->addWidget(read_MotionRxState_value);
        read_MotionRxState_layout->setStretch(0, 1);
        read_MotionRxState_layout->setStretch(1, 1);

        read_RCSThreshold_layout = new QHBoxLayout;
        read_RCSThreshold_label = new QLabel("RCS Threshold");
        read_RCSThreshold_value = new QLabel("-"); read_RCSThreshold_value->setAlignment(Qt::AlignRight);
        read_RCSThreshold_layout->addWidget(read_RCSThreshold_label);
        read_RCSThreshold_layout->addWidget(read_RCSThreshold_value);
        read_RCSThreshold_layout->setStretch(0, 1);
        read_RCSThreshold_layout->setStretch(1, 1);

        read_InvalidClusters_layout = new QHBoxLayout;
        read_InvalidClusters_label = new QLabel("InvalidClusters");
        read_InvalidClusters_value = new QLabel("-"); read_InvalidClusters_value->setAlignment(Qt::AlignRight);
        read_InvalidClusters_layout->addWidget(read_InvalidClusters_label);
        read_InvalidClusters_layout->addWidget(read_InvalidClusters_value);
        read_InvalidClusters_layout->setStretch(0, 1);
        read_InvalidClusters_layout->setStretch(1, 1);

        read_radarSetting_layout->addLayout(read_NVMReadStatus_layout);     read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_NVMWriteStatus_layout);    read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_MaxDistanceCfg_layout);    read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_PersistentError_layout);   read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_Interference_layout);      read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_TemperatureError_layout);  read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_TemporaryError_layout);    read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_VoltageError_layout);      read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_SensorID_layout);          read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_SortIndex_layout);         read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_RadarPowerCfg_layout);     read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_CtrlRelayCfg_layout);      read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_OutputTypeCfg_layout);     read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_SendQualityCfg_layout);    read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_SendExtInfoCfg_layout);    read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_MotionRxState_layout);     read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_RCSThreshold_layout);      read_radarSetting_layout->addStretch(1);
        read_radarSetting_layout->addLayout(read_InvalidClusters_layout);


        write_radarSetting_layout = new QVBoxLayout;

        write_MaxDistance_layout = new QHBoxLayout;
        write_MaxDistance_label = new QCheckBox("MaxDistance");
        write_MaxDistance_value = new QLineEdit;
        write_MaxDistance_layout->addWidget(write_MaxDistance_label);
        write_MaxDistance_layout->addWidget(write_MaxDistance_value);
        write_MaxDistance_layout->setStretch(0, 1);
        write_MaxDistance_layout->setStretch(1, 1);

        write_SensorID_layout = new QHBoxLayout;
        write_SensorID_label = new QCheckBox("Sensor ID");
        write_SensorID_value = new QComboBox; write_SensorID_value->addItems({"0", "1", "2", "3", "4", "5", "6", "7"});
        write_SensorID_layout->addWidget(write_SensorID_label);
        write_SensorID_layout->addWidget(write_SensorID_value);
        write_SensorID_layout->setStretch(0, 1);
        write_SensorID_layout->setStretch(1, 1);

        write_OutputType_layout = new QHBoxLayout;
        write_OutputType_label = new QCheckBox("OutputType");
        write_OutputType_value = new QComboBox; write_OutputType_value->addItems({"none", "send objects", "send clusters"});
        write_OutputType_layout->addWidget(write_OutputType_label);
        write_OutputType_layout->addWidget(write_OutputType_value);
        write_OutputType_layout->setStretch(0, 1);
        write_OutputType_layout->setStretch(1, 1);

        write_RadarPower_layout = new QHBoxLayout;
        write_RadarPower_label = new QCheckBox("RadarPower");
        write_RadarPower_value = new QComboBox; write_RadarPower_value->addItems({"standard", "-3dB Tx gain", "-6dB Tx gain", "-9dB Tx gain"});
        write_RadarPower_layout->addWidget(write_RadarPower_label);
        write_RadarPower_layout->addWidget(write_RadarPower_value);
        write_RadarPower_layout->setStretch(0, 1);
        write_RadarPower_layout->setStretch(1, 1);

        write_CtrlRelay_layout = new QHBoxLayout;
        write_CtrlRelay_label = new QCheckBox("CtrlRelay");
        write_CtrlRelay_value = new QComboBox; write_CtrlRelay_value->addItems({"inactive", "active"});
        write_CtrlRelay_layout->addWidget(write_CtrlRelay_label);
        write_CtrlRelay_layout->addWidget(write_CtrlRelay_value);
        write_CtrlRelay_layout->setStretch(0, 1);
        write_CtrlRelay_layout->setStretch(1, 1);

        write_SendQuality_layout = new QHBoxLayout;
        write_SendQuality_label = new QCheckBox("SendQuality");
        write_SendQuality_value = new QComboBox; write_SendQuality_value->addItems({"inactive", "active"});
        write_SendQuality_layout->addWidget(write_SendQuality_label);
        write_SendQuality_layout->addWidget(write_SendQuality_value);
        write_SendQuality_layout->setStretch(0, 1);
        write_SendQuality_layout->setStretch(1, 1);

        write_SendExtInfo_layout = new QHBoxLayout;
        write_SendExtInfo_label = new QCheckBox("SendExtInfo");
        write_SendExtInfo_value = new QComboBox; write_SendExtInfo_value->addItems({"inactive", "active"});
        write_SendExtInfo_layout->addWidget(write_SendExtInfo_label);
        write_SendExtInfo_layout->addWidget(write_SendExtInfo_value);
        write_SendExtInfo_layout->setStretch(0, 1);
        write_SendExtInfo_layout->setStretch(1, 1);

        write_SortIndex_layout = new QHBoxLayout;
        write_SortIndex_label = new QCheckBox("SortIndex");
        write_SortIndex_value = new QComboBox; write_SortIndex_value->addItems({"no sorting", "sorted by range", "sorted by RCS"});
        write_SortIndex_layout->addWidget(write_SortIndex_label);
        write_SortIndex_layout->addWidget(write_SortIndex_value);
        write_SortIndex_layout->setStretch(0, 1);
        write_SortIndex_layout->setStretch(1, 1);

        write_StoreInNVM_layout = new QHBoxLayout;
        write_StoreInNVM_label = new QCheckBox("StoreInNVM");
        write_StoreInNVM_value = new QComboBox; write_StoreInNVM_value->addItems({"inactive", "active"});
        write_StoreInNVM_layout->addWidget(write_StoreInNVM_label);
        write_StoreInNVM_layout->addWidget(write_StoreInNVM_value);
        write_StoreInNVM_layout->setStretch(0, 1);
        write_StoreInNVM_layout->setStretch(1, 1);

        write_RCSThreshold_layout = new QHBoxLayout;
        write_RCSThreshold_label = new QCheckBox("RCSThreshold");
        write_RCSThreshold_value = new QComboBox; write_RCSThreshold_value->addItems({"Standard", "High sensitivity"});
        write_RCSThreshold_layout->addWidget(write_RCSThreshold_label);
        write_RCSThreshold_layout->addWidget(write_RCSThreshold_value);
        write_RCSThreshold_layout->setStretch(0, 1);
        write_RCSThreshold_layout->setStretch(1, 1);

        write_InvalidClusters_layout = new QHBoxLayout;
        write_InvalidClusters_label = new QCheckBox("InvalidClusters");
        write_InvalidClusters_value = new QComboBox; write_InvalidClusters_value->addItems({"Disable", "Enable all invalid clusters", "Enable low RCS dynamic", "Enable low RCS static", "Enable invalid range rate", "Enable range < 1m", "Enable ego mirror", "Enable wrapped stationary"});
        write_InvalidClusters_layout->addWidget(write_InvalidClusters_label);
        write_InvalidClusters_layout->addWidget(write_InvalidClusters_value);
        write_InvalidClusters_layout->setStretch(0, 1);
        write_InvalidClusters_layout->setStretch(1, 1);

        write_radarSetting_layout->addLayout(write_MaxDistance_layout);     write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_SensorID_layout);        write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_OutputType_layout);      write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_RadarPower_layout);      write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_CtrlRelay_layout);       write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_SendQuality_layout);     write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_SendExtInfo_layout);     write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_SortIndex_layout);       write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_StoreInNVM_layout);      write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_RCSThreshold_layout);    write_radarSetting_layout->addStretch(1);
        write_radarSetting_layout->addLayout(write_InvalidClusters_layout);


        radarSetting_value_layout->addLayout(read_radarSetting_layout);
        radarSetting_value_layout->addLayout(write_radarSetting_layout);
        radarSetting_value_layout->setStretch(0, 1);
        radarSetting_value_layout->setStretch(1, 1);

        radarSetting_layout->addLayout(radar_title_layout);
        radarSetting_layout->addLayout(radarSetting_value_layout);
        radarSetting_layout->setStretch(0, 1);
        radarSetting_layout->setStretch(1, 20);


        // Filter Setting page
        filterSetting_layout = new QVBoxLayout;

        filter_title_layout = new QHBoxLayout;
        filter_title = new QLabel("Filter"); filter_title->setFont(QFont("맑은 고딕", 20, QFont::Bold));
        filter_title_spacer = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        writebtn_filterSetting = new QPushButton("Write");

        filter_title_layout->addWidget(filter_title);
        filter_title_layout->addSpacerItem(filter_title_spacer);
        filter_title_layout->addWidget(writebtn_filterSetting);

        filterSetting_value_layout = new QHBoxLayout;


        read_filterSetting_layout = new QVBoxLayout;

        read_MinMax_layout = new QHBoxLayout;
        read_Empty_label = new QLabel;
        read_Min_label = new QLabel("Min"); read_Min_label->setFont(QFont("맑은 고딕", 10, QFont::Bold)); read_Min_label->setAlignment(Qt::AlignRight); read_Min_label->setAlignment(Qt::AlignVCenter); read_Min_label->setMaximumHeight(30); read_Min_label->setMinimumHeight(30);
        read_Max_label = new QLabel("Max"); read_Max_label->setFont(QFont("맑은 고딕", 10, QFont::Bold)); read_Max_label->setAlignment(Qt::AlignRight); read_Max_label->setAlignment(Qt::AlignVCenter); read_Max_label->setMaximumHeight(30); read_Max_label->setMinimumHeight(30);
        read_MinMax_layout->addWidget(read_Empty_label);
        read_MinMax_layout->addWidget(read_Min_label);
        read_MinMax_layout->addWidget(read_Max_label);
        read_MinMax_layout->setStretch(0, 1);
        read_MinMax_layout->setStretch(1, 1);
        read_MinMax_layout->setStretch(2, 1);

        read_NofObj_layout = new QHBoxLayout;
        read_NofObj_label = new QLabel("NofObj");
        read_NofObj_min = new QLabel("-"); read_NofObj_min->setAlignment(Qt::AlignRight);
        read_NofObj_max = new QLabel("-"); read_NofObj_max->setAlignment(Qt::AlignRight);
        read_NofObj_layout->addWidget(read_NofObj_label);
        read_NofObj_layout->addWidget(read_NofObj_min);
        read_NofObj_layout->addWidget(read_NofObj_max);
        read_NofObj_layout->setStretch(0, 1);
        read_NofObj_layout->setStretch(1, 1);
        read_NofObj_layout->setStretch(2, 1);

        read_Distance_layout = new QHBoxLayout;
        read_Distance_label = new QLabel("Distance");
        read_Distance_min = new QLabel("-"); read_Distance_min->setAlignment(Qt::AlignRight);
        read_Distance_max = new QLabel("-"); read_Distance_max->setAlignment(Qt::AlignRight);
        read_Distance_layout->addWidget(read_Distance_label);
        read_Distance_layout->addWidget(read_Distance_min);
        read_Distance_layout->addWidget(read_Distance_max);
        read_Distance_layout->setStretch(0, 1);
        read_Distance_layout->setStretch(1, 1);
        read_Distance_layout->setStretch(2, 1);

        read_Azimuth_layout = new QHBoxLayout;
        read_Azimuth_label = new QLabel("Azimuth");
        read_Azimuth_min = new QLabel("-"); read_Azimuth_min->setAlignment(Qt::AlignRight);
        read_Azimuth_max = new QLabel("-"); read_Azimuth_max->setAlignment(Qt::AlignRight);
        read_Azimuth_layout->addWidget(read_Azimuth_label);
        read_Azimuth_layout->addWidget(read_Azimuth_min);
        read_Azimuth_layout->addWidget(read_Azimuth_max);
        read_Azimuth_layout->setStretch(0, 1);
        read_Azimuth_layout->setStretch(1, 1);
        read_Azimuth_layout->setStretch(2, 1);

        read_VrelOncome_layout = new QHBoxLayout;
        read_VrelOncome_label = new QLabel("VrelOncome");
        read_VrelOncome_min = new QLabel("-"); read_VrelOncome_min->setAlignment(Qt::AlignRight);
        read_VrelOncome_max = new QLabel("-"); read_VrelOncome_max->setAlignment(Qt::AlignRight);
        read_VrelOncome_layout->addWidget(read_VrelOncome_label);
        read_VrelOncome_layout->addWidget(read_VrelOncome_min);
        read_VrelOncome_layout->addWidget(read_VrelOncome_max);
        read_VrelOncome_layout->setStretch(0, 1);
        read_VrelOncome_layout->setStretch(1, 1);
        read_VrelOncome_layout->setStretch(2, 1);

        read_VrelDepart_layout = new QHBoxLayout;
        read_VrelDepart_label = new QLabel("VrelDepart");
        read_VrelDepart_min = new QLabel("-"); read_VrelDepart_min->setAlignment(Qt::AlignRight);
        read_VrelDepart_max = new QLabel("-"); read_VrelDepart_max->setAlignment(Qt::AlignRight);
        read_VrelDepart_layout->addWidget(read_VrelDepart_label);
        read_VrelDepart_layout->addWidget(read_VrelDepart_min);
        read_VrelDepart_layout->addWidget(read_VrelDepart_max);
        read_VrelDepart_layout->setStretch(0, 1);
        read_VrelDepart_layout->setStretch(1, 1);
        read_VrelDepart_layout->setStretch(2, 1);

        read_RCS_layout = new QHBoxLayout;
        read_RCS_label = new QLabel("RCS");
        read_RCS_min = new QLabel("-"); read_RCS_min->setAlignment(Qt::AlignRight);
        read_RCS_max = new QLabel("-"); read_RCS_max->setAlignment(Qt::AlignRight);
        read_RCS_layout->addWidget(read_RCS_label);
        read_RCS_layout->addWidget(read_RCS_min);
        read_RCS_layout->addWidget(read_RCS_max);
        read_RCS_layout->setStretch(0, 1);
        read_RCS_layout->setStretch(1, 1);
        read_RCS_layout->setStretch(2, 1);

        read_Lifetime_layout = new QHBoxLayout;
        read_Lifetime_label = new QLabel("Lifetime");
        read_Lifetime_min = new QLabel("-"); read_Lifetime_min->setAlignment(Qt::AlignRight);
        read_Lifetime_max = new QLabel("-"); read_Lifetime_max->setAlignment(Qt::AlignRight);
        read_Lifetime_layout->addWidget(read_Lifetime_label);
        read_Lifetime_layout->addWidget(read_Lifetime_min);
        read_Lifetime_layout->addWidget(read_Lifetime_max);
        read_Lifetime_layout->setStretch(0, 1);
        read_Lifetime_layout->setStretch(1, 1);
        read_Lifetime_layout->setStretch(2, 1);

        read_Size_layout = new QHBoxLayout;
        read_Size_label = new QLabel("Size");
        read_Size_min = new QLabel("-"); read_Size_min->setAlignment(Qt::AlignRight);
        read_Size_max = new QLabel("-"); read_Size_max->setAlignment(Qt::AlignRight);
        read_Size_layout->addWidget(read_Size_label);
        read_Size_layout->addWidget(read_Size_min);
        read_Size_layout->addWidget(read_Size_max);
        read_Size_layout->setStretch(0, 1);
        read_Size_layout->setStretch(1, 1);
        read_Size_layout->setStretch(2, 1);

        read_ProbExists_layout = new QHBoxLayout;
        read_ProbExists_label = new QLabel("ProbExists");
        read_ProbExists_min = new QLabel("-"); read_ProbExists_min->setAlignment(Qt::AlignRight);
        read_ProbExists_max = new QLabel("-"); read_ProbExists_max->setAlignment(Qt::AlignRight);
        read_ProbExists_layout->addWidget(read_ProbExists_label);
        read_ProbExists_layout->addWidget(read_ProbExists_min);
        read_ProbExists_layout->addWidget(read_ProbExists_max);
        read_ProbExists_layout->setStretch(0, 1);
        read_ProbExists_layout->setStretch(1, 1);
        read_ProbExists_layout->setStretch(2, 1);

        read_Y_layout = new QHBoxLayout;
        read_Y_label = new QLabel("Y");
        read_Y_min = new QLabel("-"); read_Y_min->setAlignment(Qt::AlignRight);
        read_Y_max = new QLabel("-"); read_Y_max->setAlignment(Qt::AlignRight);
        read_Y_layout->addWidget(read_Y_label);
        read_Y_layout->addWidget(read_Y_min);
        read_Y_layout->addWidget(read_Y_max);
        read_Y_layout->setStretch(0, 1);
        read_Y_layout->setStretch(1, 1);
        read_Y_layout->setStretch(2, 1);

        read_X_layout = new QHBoxLayout;
        read_X_label = new QLabel("X");
        read_X_min = new QLabel("-"); read_X_min->setAlignment(Qt::AlignRight);
        read_X_max = new QLabel("-"); read_X_max->setAlignment(Qt::AlignRight);
        read_X_layout->addWidget(read_X_label);
        read_X_layout->addWidget(read_X_min);
        read_X_layout->addWidget(read_X_max);
        read_X_layout->setStretch(0, 1);
        read_X_layout->setStretch(1, 1);
        read_X_layout->setStretch(2, 1);

        read_VYRightLeft_layout = new QHBoxLayout;
        read_VYRightLeft_label = new QLabel("VYRightLeft");
        read_VYRightLeft_min = new QLabel("-"); read_VYRightLeft_min->setAlignment(Qt::AlignRight);
        read_VYRightLeft_max = new QLabel("-"); read_VYRightLeft_max->setAlignment(Qt::AlignRight);
        read_VYRightLeft_layout->addWidget(read_VYRightLeft_label);
        read_VYRightLeft_layout->addWidget(read_VYRightLeft_min);
        read_VYRightLeft_layout->addWidget(read_VYRightLeft_max);
        read_VYRightLeft_layout->setStretch(0, 1);
        read_VYRightLeft_layout->setStretch(1, 1);
        read_VYRightLeft_layout->setStretch(2, 1);

        read_VXOncome_layout = new QHBoxLayout;
        read_VXOncome_label = new QLabel("VXOncome");
        read_VXOncome_min = new QLabel("-"); read_VXOncome_min->setAlignment(Qt::AlignRight);
        read_VXOncome_max = new QLabel("-"); read_VXOncome_max->setAlignment(Qt::AlignRight);
        read_VXOncome_layout->addWidget(read_VXOncome_label);
        read_VXOncome_layout->addWidget(read_VXOncome_min);
        read_VXOncome_layout->addWidget(read_VXOncome_max);
        read_VXOncome_layout->setStretch(0, 1);
        read_VXOncome_layout->setStretch(1, 1);
        read_VXOncome_layout->setStretch(2, 1);

        read_VYLeftRight_layout = new QHBoxLayout;
        read_VYLeftRight_label = new QLabel("VYLeftRight");
        read_VYLeftRight_min = new QLabel("-"); read_VYLeftRight_min->setAlignment(Qt::AlignRight);
        read_VYLeftRight_max = new QLabel("-"); read_VYLeftRight_max->setAlignment(Qt::AlignRight);
        read_VYLeftRight_layout->addWidget(read_VYLeftRight_label);
        read_VYLeftRight_layout->addWidget(read_VYLeftRight_min);
        read_VYLeftRight_layout->addWidget(read_VYLeftRight_max);
        read_VYLeftRight_layout->setStretch(0, 1);
        read_VYLeftRight_layout->setStretch(1, 1);
        read_VYLeftRight_layout->setStretch(2, 1);

        read_VXDepart_layout = new QHBoxLayout;
        read_VXDepart_label = new QLabel("VXDepart");
        read_VXDepart_min = new QLabel("-"); read_VXDepart_min->setAlignment(Qt::AlignRight);
        read_VXDepart_max = new QLabel("-"); read_VXDepart_max->setAlignment(Qt::AlignRight);
        read_VXDepart_layout->addWidget(read_VXDepart_label);
        read_VXDepart_layout->addWidget(read_VXDepart_min);
        read_VXDepart_layout->addWidget(read_VXDepart_max);
        read_VXDepart_layout->setStretch(0, 1);
        read_VXDepart_layout->setStretch(1, 1);
        read_VXDepart_layout->setStretch(2, 1);


        read_filterSetting_layout->addLayout(read_MinMax_layout);
        read_filterSetting_layout->addLayout(read_NofObj_layout);       read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_Distance_layout);     read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_Azimuth_layout);      read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VrelOncome_layout);   read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VrelDepart_layout);   read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_RCS_layout);          read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_Lifetime_layout);     read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_Size_layout);         read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_ProbExists_layout);   read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_Y_layout);            read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_X_layout);            read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VYRightLeft_layout);  read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VXOncome_layout);     read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VYLeftRight_layout);  read_filterSetting_layout->addStretch(1);
        read_filterSetting_layout->addLayout(read_VXDepart_layout);


        write_filterSetting_layout = new QVBoxLayout;


        write_MinMaxActive_layout = new QHBoxLayout;
        write_Empty_label = new QLabel;
        write_Min_label = new QLabel("Min"); write_Min_label->setFont(QFont("맑은 고딕", 10, QFont::Bold)); write_Min_label->setAlignment(Qt::AlignRight); write_Min_label->setMaximumHeight(30); write_Min_label->setMinimumHeight(30);
        write_Max_label = new QLabel("Max"); write_Max_label->setFont(QFont("맑은 고딕", 10, QFont::Bold)); write_Max_label->setAlignment(Qt::AlignRight);  write_Max_label->setMaximumHeight(30); write_Max_label->setMinimumHeight(30);
        write_Active_label = new QLabel("Active"); write_Active_label->setFont(QFont("맑은 고딕", 10, QFont::Bold)); write_Active_label->setAlignment(Qt::AlignRight); write_Active_label->setMaximumHeight(30); write_Active_label->setMinimumHeight(30);
        write_MinMaxActive_layout->addWidget(write_Empty_label);
        write_MinMaxActive_layout->addWidget(write_Min_label);
        write_MinMaxActive_layout->addWidget(write_Max_label);
        write_MinMaxActive_layout->addWidget(write_Active_label);
        write_MinMaxActive_layout->setStretch(0, 5);
        write_MinMaxActive_layout->setStretch(1, 5);
        write_MinMaxActive_layout->setStretch(2, 5);
        write_MinMaxActive_layout->setStretch(3, 1);

        write_NofObj_layout = new QHBoxLayout;
        write_NofObj_valid = new QCheckBox("NofObj");
        write_NofObj_min = new QLineEdit;
        write_NofObj_max = new QLineEdit;
        write_NofObj_active = new QCheckBox;
        write_NofObj_layout->addWidget(write_NofObj_valid);
        write_NofObj_layout->addWidget(write_NofObj_min);
        write_NofObj_layout->addWidget(write_NofObj_max);
        write_NofObj_layout->addWidget(write_NofObj_active);
        write_NofObj_layout->setStretch(0, 5);
        write_NofObj_layout->setStretch(1, 5);
        write_NofObj_layout->setStretch(2, 5);
        write_NofObj_layout->setStretch(3, 1);

        write_Distance_layout = new QHBoxLayout;
        write_Distance_valid = new QCheckBox("Distance");
        write_Distance_min = new QLineEdit;
        write_Distance_max = new QLineEdit;
        write_Distance_active = new QCheckBox;
        write_Distance_layout->addWidget(write_Distance_valid);
        write_Distance_layout->addWidget(write_Distance_min);
        write_Distance_layout->addWidget(write_Distance_max);
        write_Distance_layout->addWidget(write_Distance_active);
        write_Distance_layout->setStretch(0, 5);
        write_Distance_layout->setStretch(1, 5);
        write_Distance_layout->setStretch(2, 5);
        write_Distance_layout->setStretch(3, 1);

        write_Azimuth_layout = new QHBoxLayout;
        write_Azimuth_valid = new QCheckBox("Azimuth");
        write_Azimuth_min = new QLineEdit;
        write_Azimuth_max = new QLineEdit;
        write_Azimuth_active = new QCheckBox;
        write_Azimuth_layout->addWidget(write_Azimuth_valid);
        write_Azimuth_layout->addWidget(write_Azimuth_min);
        write_Azimuth_layout->addWidget(write_Azimuth_max);
        write_Azimuth_layout->addWidget(write_Azimuth_active);
        write_Azimuth_layout->setStretch(0, 5);
        write_Azimuth_layout->setStretch(1, 5);
        write_Azimuth_layout->setStretch(2, 5);
        write_Azimuth_layout->setStretch(3, 1);

        write_VrelOncome_layout = new QHBoxLayout;
        write_VrelOncome_valid = new QCheckBox("VrelOncome");
        write_VrelOncome_min = new QLineEdit;
        write_VrelOncome_max = new QLineEdit;
        write_VrelOncome_active = new QCheckBox;
        write_VrelOncome_layout->addWidget(write_VrelOncome_valid);
        write_VrelOncome_layout->addWidget(write_VrelOncome_min);
        write_VrelOncome_layout->addWidget(write_VrelOncome_max);
        write_VrelOncome_layout->addWidget(write_VrelOncome_active);
        write_VrelOncome_layout->setStretch(0, 5);
        write_VrelOncome_layout->setStretch(1, 5);
        write_VrelOncome_layout->setStretch(2, 5);
        write_VrelOncome_layout->setStretch(3, 1);

        write_VrelDepart_layout = new QHBoxLayout;
        write_VrelDepart_valid = new QCheckBox("VrelDepart");
        write_VrelDepart_min = new QLineEdit;
        write_VrelDepart_max = new QLineEdit;
        write_VrelDepart_active = new QCheckBox;
        write_VrelDepart_layout->addWidget(write_VrelDepart_valid);
        write_VrelDepart_layout->addWidget(write_VrelDepart_min);
        write_VrelDepart_layout->addWidget(write_VrelDepart_max);
        write_VrelDepart_layout->addWidget(write_VrelDepart_active);
        write_VrelDepart_layout->setStretch(0, 5);
        write_VrelDepart_layout->setStretch(1, 5);
        write_VrelDepart_layout->setStretch(2, 5);
        write_VrelDepart_layout->setStretch(3, 1);

        write_RCS_layout = new QHBoxLayout;
        write_RCS_valid = new QCheckBox("RCS");
        write_RCS_min = new QLineEdit;
        write_RCS_max = new QLineEdit;
        write_RCS_active = new QCheckBox;
        write_RCS_layout->addWidget(write_RCS_valid);
        write_RCS_layout->addWidget(write_RCS_min);
        write_RCS_layout->addWidget(write_RCS_max);
        write_RCS_layout->addWidget(write_RCS_active);
        write_RCS_layout->setStretch(0, 5);
        write_RCS_layout->setStretch(1, 5);
        write_RCS_layout->setStretch(2, 5);
        write_RCS_layout->setStretch(3, 1);

        write_Lifetime_layout = new QHBoxLayout;
        write_Lifetime_valid = new QCheckBox("Lifetime");
        write_Lifetime_min = new QLineEdit;
        write_Lifetime_max = new QLineEdit;
        write_Lifetime_active = new QCheckBox;
        write_Lifetime_layout->addWidget(write_Lifetime_valid);
        write_Lifetime_layout->addWidget(write_Lifetime_min);
        write_Lifetime_layout->addWidget(write_Lifetime_max);
        write_Lifetime_layout->addWidget(write_Lifetime_active);
        write_Lifetime_layout->setStretch(0, 5);
        write_Lifetime_layout->setStretch(1, 5);
        write_Lifetime_layout->setStretch(2, 5);
        write_Lifetime_layout->setStretch(3, 1);

        write_Size_layout = new QHBoxLayout;
        write_Size_valid = new QCheckBox("Size");
        write_Size_min = new QLineEdit;
        write_Size_max = new QLineEdit;
        write_Size_active = new QCheckBox;
        write_Size_layout->addWidget(write_Size_valid);
        write_Size_layout->addWidget(write_Size_min);
        write_Size_layout->addWidget(write_Size_max);
        write_Size_layout->addWidget(write_Size_active);
        write_Size_layout->setStretch(0, 5);
        write_Size_layout->setStretch(1, 5);
        write_Size_layout->setStretch(2, 5);
        write_Size_layout->setStretch(3, 1);

        write_ProbExists_layout = new QHBoxLayout;
        write_ProbExists_valid = new QCheckBox("ProbExists");
        write_ProbExists_min = new QComboBox; write_ProbExists_min->addItems({"0%", "25%", "50%", "75%", "90%", "99%", "99.9%", "100%"});
        write_ProbExists_max = new QComboBox; write_ProbExists_max->addItems({"0%", "25%", "50%", "75%", "90%", "99%", "99.9%", "100%"});
        write_ProbExists_active = new QCheckBox;
        write_ProbExists_layout->addWidget(write_ProbExists_valid);
        write_ProbExists_layout->addWidget(write_ProbExists_min);
        write_ProbExists_layout->addWidget(write_ProbExists_max);
        write_ProbExists_layout->addWidget(write_ProbExists_active);
        write_ProbExists_layout->setStretch(0, 5);
        write_ProbExists_layout->setStretch(1, 5);
        write_ProbExists_layout->setStretch(2, 5);
        write_ProbExists_layout->setStretch(3, 1);

        write_Y_layout = new QHBoxLayout;
        write_Y_valid = new QCheckBox("Y");
        write_Y_min = new QLineEdit;
        write_Y_max = new QLineEdit;
        write_Y_active = new QCheckBox;
        write_Y_layout->addWidget(write_Y_valid);
        write_Y_layout->addWidget(write_Y_min);
        write_Y_layout->addWidget(write_Y_max);
        write_Y_layout->addWidget(write_Y_active);
        write_Y_layout->setStretch(0, 5);
        write_Y_layout->setStretch(1, 5);
        write_Y_layout->setStretch(2, 5);
        write_Y_layout->setStretch(3, 1);

        write_X_layout = new QHBoxLayout;
        write_X_valid = new QCheckBox("X");
        write_X_min = new QLineEdit;
        write_X_max = new QLineEdit;
        write_X_active = new QCheckBox;
        write_X_layout->addWidget(write_X_valid);
        write_X_layout->addWidget(write_X_min);
        write_X_layout->addWidget(write_X_max);
        write_X_layout->addWidget(write_X_active);
        write_X_layout->setStretch(0, 5);
        write_X_layout->setStretch(1, 5);
        write_X_layout->setStretch(2, 5);
        write_X_layout->setStretch(3, 1);

        write_VYRightLeft_layout = new QHBoxLayout;
        write_VYRightLeft_valid = new QCheckBox("VYRightLeft");
        write_VYRightLeft_min = new QLineEdit;
        write_VYRightLeft_max = new QLineEdit;
        write_VYRightLeft_active = new QCheckBox;
        write_VYRightLeft_layout->addWidget(write_VYRightLeft_valid);
        write_VYRightLeft_layout->addWidget(write_VYRightLeft_min);
        write_VYRightLeft_layout->addWidget(write_VYRightLeft_max);
        write_VYRightLeft_layout->addWidget(write_VYRightLeft_active);
        write_VYRightLeft_layout->setStretch(0, 5);
        write_VYRightLeft_layout->setStretch(1, 5);
        write_VYRightLeft_layout->setStretch(2, 5);
        write_VYRightLeft_layout->setStretch(3, 1);

        write_VXOncome_layout = new QHBoxLayout;
        write_VXOncome_valid = new QCheckBox("VXOncome");
        write_VXOncome_min = new QLineEdit;
        write_VXOncome_max = new QLineEdit;
        write_VXOncome_active = new QCheckBox;
        write_VXOncome_layout->addWidget(write_VXOncome_valid);
        write_VXOncome_layout->addWidget(write_VXOncome_min);
        write_VXOncome_layout->addWidget(write_VXOncome_max);
        write_VXOncome_layout->addWidget(write_VXOncome_active);
        write_VXOncome_layout->setStretch(0, 5);
        write_VXOncome_layout->setStretch(1, 5);
        write_VXOncome_layout->setStretch(2, 5);
        write_VXOncome_layout->setStretch(3, 1);

        write_VYLeftRight_layout = new QHBoxLayout;
        write_VYLeftRight_valid = new QCheckBox("VYLeftRight");
        write_VYLeftRight_min = new QLineEdit;
        write_VYLeftRight_max = new QLineEdit;
        write_VYLeftRight_active = new QCheckBox;
        write_VYLeftRight_layout->addWidget(write_VYLeftRight_valid);
        write_VYLeftRight_layout->addWidget(write_VYLeftRight_min);
        write_VYLeftRight_layout->addWidget(write_VYLeftRight_max);
        write_VYLeftRight_layout->addWidget(write_VYLeftRight_active);
        write_VYLeftRight_layout->setStretch(0, 5);
        write_VYLeftRight_layout->setStretch(1, 5);
        write_VYLeftRight_layout->setStretch(2, 5);
        write_VYLeftRight_layout->setStretch(3, 1);

        write_VXDepart_layout = new QHBoxLayout;
        write_VXDepart_valid = new QCheckBox("VXDepart");
        write_VXDepart_min = new QLineEdit;
        write_VXDepart_max = new QLineEdit;
        write_VXDepart_active = new QCheckBox;
        write_VXDepart_layout->addWidget(write_VXDepart_valid);
        write_VXDepart_layout->addWidget(write_VXDepart_min);
        write_VXDepart_layout->addWidget(write_VXDepart_max);
        write_VXDepart_layout->addWidget(write_VXDepart_active);
        write_VXDepart_layout->setStretch(0, 5);
        write_VXDepart_layout->setStretch(1, 5);
        write_VXDepart_layout->setStretch(2, 5);
        write_VXDepart_layout->setStretch(3, 1);


        write_filterSetting_layout->addLayout(write_MinMaxActive_layout);
        write_filterSetting_layout->addLayout(write_NofObj_layout);         write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_Distance_layout);       write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_Azimuth_layout);        write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VrelOncome_layout);     write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VrelDepart_layout);     write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_RCS_layout);            write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_Lifetime_layout);       write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_Size_layout);           write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_ProbExists_layout);     write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_Y_layout);              write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_X_layout);              write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VYRightLeft_layout);    write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VXOncome_layout);       write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VYLeftRight_layout);    write_filterSetting_layout->addStretch(1);
        write_filterSetting_layout->addLayout(write_VXDepart_layout);


        filterSetting_value_layout->addLayout(read_filterSetting_layout);
        filterSetting_value_layout->addLayout(write_filterSetting_layout);
        filterSetting_value_layout->setStretch(0, 1);
        filterSetting_value_layout->setStretch(1, 1);


        filterSetting_layout->addLayout(filter_title_layout);
        filterSetting_layout->addLayout(filterSetting_value_layout);
        filterSetting_layout->setStretch(0, 1);
        filterSetting_layout->setStretch(1, 20);

        radarSetting_page_layout->addLayout(radarSetting_layout);
        radarSetting_page_layout->addLayout(filterSetting_layout);
        radarSetting_layout->setStretch(0, 1);
        radarSetting_layout->setStretch(1, 1);

        radarSetting_page->setLayout(radarSetting_page_layout);
    }

    page->insertWidget(0, main_page);
    page->insertWidget(1, radarSetting_page);


    // Show Status Bar
    statusBar_layout = new QHBoxLayout;
    realTime = new QLabel; realTime->setAlignment(Qt::AlignCenter); realTime->setMaximumSize(300, 20);
    statusBar_layout_spacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
    status_layout = new QHBoxLayout; statusBar_layout->setSpacing(0);
    N_Radar_Status = new QLabel("Radar"); N_Radar_Status->setAlignment(Qt::AlignCenter); N_Radar_Status->setMaximumSize(100, 20); N_Radar_Status->setFrameShape(QFrame::Box); N_Radar_Status->setLineWidth(1);
    S_Radar_Status = new QLabel("Radar"); S_Radar_Status->setAlignment(Qt::AlignCenter); S_Radar_Status->setMaximumSize(100, 20); S_Radar_Status->setFrameShape(QFrame::Box); S_Radar_Status->setLineWidth(1);
    Camera_Status = new QLabel("Camera"); Camera_Status->setAlignment(Qt::AlignCenter); Camera_Status->setMaximumSize(100, 20); Camera_Status->setFrameShape(QFrame::Box); Camera_Status->setLineWidth(1);
    Socket_Status = new QLabel("Serial"); Socket_Status->setAlignment(Qt::AlignCenter); Socket_Status->setMaximumSize(100, 20); Socket_Status->setFrameShape(QFrame::Box); Socket_Status->setLineWidth(1);
    Serial_Status = new QLabel("Serial"); Serial_Status->setAlignment(Qt::AlignCenter); Serial_Status->setMaximumSize(100, 20); Serial_Status->setFrameShape(QFrame::Box); Serial_Status->setLineWidth(1);

    status_layout->addWidget(N_Radar_Status);
    status_layout->addWidget(S_Radar_Status);
    status_layout->addWidget(Camera_Status);
    status_layout->addWidget(Socket_Status);
    status_layout->addWidget(Serial_Status);
    status_layout->setStretch(0, 1);
    status_layout->setStretch(1, 1);
    status_layout->setStretch(2, 1);
    status_layout->setStretch(3, 1);
    status_layout->setStretch(4, 1);
    status_layout->setContentsMargins(0, 0, 0, 0);
    status_layout->setSpacing(0);

    statusBar_layout->addWidget(realTime);
    statusBar_layout->addSpacerItem(statusBar_layout_spacer);
    statusBar_layout->addLayout(status_layout);
    statusBar_layout->setContentsMargins(0, 0, 0, 0);


    main_layout->addLayout(button_layout);
    main_layout->addWidget(page);
    main_layout->addLayout(statusBar_layout);
    main_layout->setStretch(0, 1);
    main_layout->setStretch(1, 30);
    main_layout->setStretch(2, 1);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->setSpacing(0);

    window = new QWidget();
    window->setLayout(main_layout);
    window->setMinimumSize(1280, 720);
    setCentralWidget(window);
}
void MainWindow::readTime()
{
    GetLocalTime(&global_time);
    realTime->setText("    " + QString::number(global_time.wYear) + "/" + QString::number(global_time.wMonth) + "/" + QString::number(global_time.wDay));
}
void MainWindow::read_Setting_ini(QString path)
{
    QSettings* setting = new QSettings(path, QSettings::IniFormat);
    QString key;

    key = "RADAR/";
    N_Radar_Viewer->LOWER_VELOCITY = setting->value(key + "LOWER_VELOCITY", 0).toInt();
    N_Radar_Viewer->UPPER_VELOCITY = setting->value(key + "UPPER_VELOCITY", 150).toInt();
    S_Radar_Viewer->LOWER_VELOCITY = setting->value(key + "LOWER_VELOCITY", 0).toInt();
    S_Radar_Viewer->UPPER_VELOCITY = setting->value(key + "UPPER_VELOCITY", 150).toInt();
}

void MainWindow::writeSettings()
{
    //    m_settings.beginGroup("/Settings");

    //    m_settings.setValue("/RadarID", radarID_edit->text()); N_Radar_Viewer->Radar_ID = radarID_edit->text().toInt();
    //    m_settings.setValue("/minDist", minDist_edit->text()); minDist = minDist_edit->text().toInt();
    //    m_settings.setValue("/maxDist", maxDist_edit->text()); maxDist = maxDist_edit->text().toInt();

    //    m_settings.setValue("/cameraIP", cameraIP_edit->text()); cameraIP = cameraIP_edit->text();
    //    m_settings.setValue("/cameraPort", cameraPort_edit->text()); cameraPort = cameraPort_edit->text();
    //    m_settings.setValue("/cameraID", cameraID_edit->text()); cameraID = cameraID_edit->text();
    //    m_settings.setValue("/cameraPW", cameraPW_edit->text()); cameraPW = cameraPW_edit->text();

    //    m_settings.endGroup();
}

void MainWindow::readSettings() {

    //    m_settings.beginGroup("/Settings");

    //    radarID_edit->setText(m_settings.value("/RadarID", "0").toString()); N_Radar_Viewer->Radar_ID = radarID_edit->text().toInt();
    //    minDist_edit->setText(m_settings.value("/minDist", "0").toString()); minDist = minDist_edit->text().toInt();
    //    maxDist_edit->setText(m_settings.value("/maxDist", "150").toString()); maxDist = maxDist_edit->text().toInt();

    //    cameraIP_edit->setText(m_settings.value("/cameraIP", "192.168.1.30").toString()); cameraIP = cameraIP_edit->text();
    //    cameraPort_edit->setText(m_settings.value("/cameraPort", "554").toString()); cameraPort = cameraPort_edit->text();
    //    cameraID_edit->setText(m_settings.value("/cameraID", "admin").toString()); cameraID = cameraID_edit->text();
    //    cameraPW_edit->setText(m_settings.value("/cameraPW", "admin").toString()); cameraPW = cameraPW_edit->text();

    //    m_settings.endGroup();
}

void MainWindow::initValue()
{
    InitializeValue_Radar();
    InitializeValue_Camera();
    InitializeValue_Socket();
    InitializeValue_Serial();

    readSettings();
    read_Setting_ini("C:/Users/ODYSSEY/Desktop/Setting/Simulator_Setting.ini");

    storage_make_empty();
}

bool MainWindow::read_CarLane_ini(QString N_path, QString S_path)
{
    {
        QSettings* setting = new QSettings(N_path, QSettings::IniFormat);

        QString key = "LANE/";
        N_Radar_Viewer->MAX_DISTLONG = setting->value(key + "MAX_DISTLONG", 150).toInt();
        N_Radar_Viewer->MAX_DISTLAT = setting->value(key + "MAX_DISTLAT", 10).toInt();
        N_Radar_Viewer->LANE_NUM = setting->value(key + "LANE_NUM", 1).toInt();
        N_Radar_Viewer->LANE_SPACE = setting->value(key + "LANE_SPACE", 25).toInt();
        N_Radar_Viewer->LANE_COUNT = int(N_Radar_Viewer->MAX_DISTLONG / N_Radar_Viewer->LANE_SPACE) + 1;

        int i;
        N_Radar_Viewer->lanePoint = new float*[N_Radar_Viewer->LANE_NUM + 1];
        for(i=0; i<(N_Radar_Viewer->LANE_NUM + 1); i++)
            N_Radar_Viewer->lanePoint[i] = new float[N_Radar_Viewer->LANE_COUNT];

        key = "POINT/";
        for(int i=0; i<(N_Radar_Viewer->LANE_NUM + 1); i++)
        {
            for(int j=0; j<N_Radar_Viewer->LANE_COUNT; j++)
            {
                QString count = QString::number(i*N_Radar_Viewer->LANE_COUNT + j);
                N_Radar_Viewer->lanePoint[i][j] = setting->value(key + count).toFloat() + 1.000f;
            }
        }

        N_Radar_Viewer->setLookUpImage();

        N_Radar_Viewer->haveLanePoint = true;

        delete setting;
    }

    {
        QSettings* setting = new QSettings(S_path, QSettings::IniFormat);

        QString key = "LANE/";
        S_Radar_Viewer->MAX_DISTLONG = setting->value(key + "MAX_DISTLONG", 150).toInt();
        S_Radar_Viewer->MAX_DISTLAT = setting->value(key + "MAX_DISTLAT", 10).toInt();
        S_Radar_Viewer->LANE_NUM = setting->value(key + "LANE_NUM", 1).toInt();
        S_Radar_Viewer->LANE_SPACE = setting->value(key + "LANE_SPACE", 25).toInt();
        S_Radar_Viewer->LANE_COUNT = int(S_Radar_Viewer->MAX_DISTLONG / S_Radar_Viewer->LANE_SPACE) + 1;

        int i;
        S_Radar_Viewer->lanePoint = new float*[S_Radar_Viewer->LANE_NUM + 1];
        for(i=0; i<(S_Radar_Viewer->LANE_NUM + 1); i++)
            S_Radar_Viewer->lanePoint[i] = new float[S_Radar_Viewer->LANE_COUNT];

        key = "POINT/";
        for(int i=0; i<(S_Radar_Viewer->LANE_NUM + 1); i++)
        {
            for(int j=0; j<S_Radar_Viewer->LANE_COUNT; j++)
            {
                QString count = QString::number(i*S_Radar_Viewer->LANE_COUNT + j);
                S_Radar_Viewer->lanePoint[i][j] = setting->value(key + count).toFloat() + 1.000f;
            }
        }

        S_Radar_Viewer->setLookUpImage();

        S_Radar_Viewer->haveLanePoint = true;

        delete setting;
    }
}

void MainWindow::storage_make_empty()
{

}
bool MainWindow::InitializeValue_Radar()
{
    N_Radar_Viewer->m_Handle = PCAN_USBBUS1;
    N_Radar_Viewer->m_Baudrate = PCAN_BAUD_500K;
    N_Radar_Viewer->m_Type = PCAN_TYPE_ISA;
    N_Radar_Viewer->m_Port = 0x0100;
    N_Radar_Viewer->m_Interrupt = 0x3;
    N_Radar_Viewer->Radar_ID = 0;
    N_Radar_Viewer->startRadar = false;
    N_Radar_Viewer->Way = -1;

    S_Radar_Viewer->m_Handle = PCAN_USBBUS2;
    S_Radar_Viewer->m_Baudrate = PCAN_BAUD_500K;
    S_Radar_Viewer->m_Type = PCAN_TYPE_ISA;
    S_Radar_Viewer->m_Port = 0x0100;
    S_Radar_Viewer->m_Interrupt = 0x3;
    S_Radar_Viewer->Radar_ID = 1;
    S_Radar_Viewer->startRadar = false;
    S_Radar_Viewer->Way = 1;

    read_CarLane_ini("C:/Users/ODYSSEY/Desktop/Setting/North_LaneInfo.ini", "C:/Users/ODYSSEY/Desktop/Setting/South_LaneInfo.ini");

    return true;
}

void MainWindow::on_Connectbtn_Radar_clicked()
{
    Connect_Radar();
}

void MainWindow::on_Disconnectbtn_Radar_clicked()
{
    Disconnect_Radar();
}
bool MainWindow::Connect_Radar()
{
    if(!N_Radar_Viewer->startRadar)
    {
        Connectbtn_Radar->setEnabled(false);

        TPCANStatus stsResult;
        stsResult = N_Radar_Viewer->m_PCANDevice.Initialize(N_Radar_Viewer->m_Handle, N_Radar_Viewer->m_Baudrate, N_Radar_Viewer->m_Type, N_Radar_Viewer->m_Port, N_Radar_Viewer->m_Interrupt);
        if(stsResult != PCAN_ERROR_OK)
        {
            qDebug() << "PCAN Initialize ERROR";
            return false;
        }
        else
        {
            N_Radar_Viewer->reset();

            gettimeofday(&N_Radar_Viewer->A_Cycle_time, nullptr);
            N_Radar_Viewer->startRadar = true;
            N_Radar_Status->setStyleSheet("background-color: rgb(0, 255, 0);");
            pthread_create(&thread_radar[NORTH], nullptr, MainWindow::N_callreadCANMessageFunc, this);

            //            setFilterbtn->click();

            //            Traffictimer = new QTimer(this);
            //            connect(Traffictimer, SIGNAL(timeout()), this, SLOT(traffic_save_timer()));
            //            Traffictimer->start(10000);
        }
    }

    if(!S_Radar_Viewer->startRadar)
    {
        Connectbtn_Radar->setEnabled(false);

        TPCANStatus stsResult;
        stsResult = S_Radar_Viewer->m_PCANDevice.Initialize(S_Radar_Viewer->m_Handle, S_Radar_Viewer->m_Baudrate, S_Radar_Viewer->m_Type, S_Radar_Viewer->m_Port, S_Radar_Viewer->m_Interrupt);
        if(stsResult != PCAN_ERROR_OK)
        {
            qDebug() << "PCAN Initialize ERROR";
            return false;
        }
        else
        {
            S_Radar_Viewer->reset();

            gettimeofday(&S_Radar_Viewer->A_Cycle_time, nullptr);
            S_Radar_Viewer->startRadar = true;
            S_Radar_Status->setStyleSheet("background-color: rgb(0, 255, 0);");
            pthread_create(&thread_radar[SOUTH], nullptr, MainWindow::S_callreadCANMessageFunc, this);

            //            setFilterbtn->click();

            //            Traffictimer = new QTimer(this);
            //            connect(Traffictimer, SIGNAL(timeout()), this, SLOT(traffic_save_timer()));
            //            Traffictimer->start(10000);
        }
    }
    Connectbtn_Radar->setEnabled(false);
    Disconnectbtn_Radar->setEnabled(true);
    return true;
}
bool MainWindow::Disconnect_Radar()
{
    if(N_Radar_Viewer->startRadar)
    {
        N_Radar_Viewer->startRadar = false;
        N_Radar_Viewer->first_A = false;
        TPCANStatus stsResult = N_Radar_Viewer->m_PCANDevice.Uninitialize(N_Radar_Viewer->m_Handle);
        if(stsResult != PCAN_ERROR_OK)
        {
            N_Radar_Viewer->startRadar = true;
            qDebug() << "UnInit ERROR";
            return false;
        }
        else
        {
            pthread_join(thread_radar[NORTH], nullptr);

            N_Radar_Viewer->reset();
            //Traffictimer->stop();
            N_Radar_Status->setStyleSheet("background-color: rgb(255, 0, 0);");
        }
    }

    if(S_Radar_Viewer->startRadar)
    {
        S_Radar_Viewer->startRadar = false;
        S_Radar_Viewer->first_A = false;
        TPCANStatus stsResult = S_Radar_Viewer->m_PCANDevice.Uninitialize(S_Radar_Viewer->m_Handle);
        if(stsResult != PCAN_ERROR_OK)
        {
            S_Radar_Viewer->startRadar = true;
            qDebug() << "UnInit ERROR";
            return false;
        }
        else
        {
            pthread_join(thread_radar[SOUTH], nullptr);

            //Traffictimer->stop();
            S_Radar_Viewer->reset();
            S_Radar_Status->setStyleSheet("background-color: rgb(255, 0, 0);");
        }
    }
    Connectbtn_Radar->setEnabled(true);
    Disconnectbtn_Radar->setEnabled(false);
    return true;
}

void *MainWindow::N_callreadCANMessageFunc(void *func)
{
    (static_cast<MainWindow *>(func))->readCANMessage(NORTH);
    return nullptr;
}
void *MainWindow::S_callreadCANMessageFunc(void *func)
{
    (static_cast<MainWindow *>(func))->readCANMessage(SOUTH);
    return nullptr;
}
void MainWindow::readCANMessage(int Way)
{
    TPCANStatus stsResult;
    TPCANMsg msg;
    TPCANTimestamp time;
    switch(Way)
    {
    case NORTH:
    {
        while(N_Radar_Viewer->startRadar)
        {
            stsResult = N_Radar_Viewer->m_PCANDevice.Read(N_Radar_Viewer->m_Handle, &msg, &time);

            if(stsResult != PCAN_ERROR_QRCVEMPTY)
                ClassifyingEachCANMessage(msg);
        }
    }
        break;

    case SOUTH:
    {
        while(S_Radar_Viewer->startRadar)
        {
            stsResult = S_Radar_Viewer->m_PCANDevice.Read(S_Radar_Viewer->m_Handle, &msg, &time);

            if(stsResult != PCAN_ERROR_QRCVEMPTY)
                ClassifyingEachCANMessage(msg);
        }
    }
        break;

    default:
        break;
    }
}
void MainWindow::ClassifyingEachCANMessage(TPCANMsg msg)
{
    if((msg.ID & 0xF0F) == 0x60A)
    {
        Set_Obj_A(msg);
    }
    else if((msg.ID & 0xF0F) == 0x60B)
    {
        Set_Obj_B(msg);
    }
    else if((msg.ID & 0xF0F) == 0x60C)
    {
        Set_Obj_C(msg);
    }
    else if((msg.ID & 0xF0F) == 0x60D)
    {
        Set_Obj_D(msg);
    }
}
void MainWindow::Set_Obj_A(TPCANMsg msg)
{
    Object_Status os;
    memcpy(&os, msg.DATA, sizeof(Object_Status));

    if(static_cast<int>(msg.ID) == (0x60A + (N_Radar_Viewer->Radar_ID * 0x10)))
    {
        //qDebug() << "60A NORTH" << os.NofObjects;
        timeval now; gettimeofday(&now, nullptr);
        N_Radar_Viewer->A_Cycle_time = now;
        GetLocalTime(&N_Radar_Viewer->A_DateTime);
        N_Radar_Viewer->first_A = true;

        N_Radar_Viewer->N_car = os.NofObjects;
        N_Radar_Viewer->N_car_now = 0;
        N_Radar_Viewer->count4Kalman = 0;

        memset(N_Radar_Viewer->exist, 0, sizeof(bool) * MAX_OBJ);
        memset(N_Radar_Viewer->this_frame_data, 0, sizeof(Obj_inf) * MAX_OBJ);

        if(do_kalman)
        {
            if(N_Radar_Viewer->N_car == 0)
            {
                for(int i=0; i<MAX_OBJ; i++)
                {
                    if(!N_Radar_Viewer->Obj_data[i].isEmpty())
                    {
                        Obj_inf last_data = N_Radar_Viewer->Obj_data[i].getLast();
                        if(((N_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (N_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                        {
                            if(last_data.index_of_infoBox != 0)
                                N_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                            N_Radar_Viewer->Obj_data[i].remove_all();
                            cvReleaseKalman(&N_Radar_Viewer->kalman_d[i]);
                            cvReleaseKalman(&N_Radar_Viewer->kalman_v[i]);
                        }
                        else if(N_Radar_Viewer->Obj_data[i].getsize() >= 2)
                        {
                            Obj_inf pred_data = last_data;
                            cvKalmanPredict(N_Radar_Viewer->kalman_d[i], 0);
                            cvKalmanPredict(N_Radar_Viewer->kalman_v[i], 0);

                            QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                            QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                            pred_data.DistLat = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                            pred_data.DistLong = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                            pred_data.VrelLat = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                            pred_data.VrelLong = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                            pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                            pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                            if(pred_data.Velocity != 0.0)
                                pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                            else
                                pred_data.ttc = 100;

                            int x = ((pred_data.DistLat - N_Radar_Viewer->MAX_DISTLAT) * -1)
                                    * (N_Radar_Viewer->LookUpImage->width / (N_Radar_Viewer->MAX_DISTLAT * 2));
                            int y = N_Radar_Viewer->LookUpImage->height
                                    - ((0.5 * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT))
                                       + (pred_data.DistLong / N_Radar_Viewer->MAX_DISTLONG)
                                       * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT)
                                       * (N_Radar_Viewer->LANE_COUNT - 1));

                            pred_data.virtual_obj = true;

                            if((x >= 0) && (x < N_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < N_Radar_Viewer->LookUpImage->height))
                            {
                                if(N_Radar_Viewer->haveLanePoint)
                                {
                                    int index = (x + (y * N_Radar_Viewer->LookUpImage->widthStep));

                                    pred_data.zone_index = N_Radar_Viewer->LookUpImage->imageData[index];

                                    if(pred_data.zone_index != 0)
                                    {
                                        memcpy(&N_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                        N_Radar_Viewer->exist[i] = true;
                                    }
                                }

                                CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                measurement_d->data.fl[0] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                measurement_d->data.fl[1] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                measurement_v->data.fl[0] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                measurement_v->data.fl[1] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                memcpy(N_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                memcpy(N_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                cvKalmanCorrect(N_Radar_Viewer->kalman_d[i], measurement_d);
                                cvKalmanCorrect(N_Radar_Viewer->kalman_v[i], measurement_v);

                                cvReleaseMat(&measurement_d);
                                cvReleaseMat(&measurement_v);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<MAX_OBJ; i++)
            {
                if(!N_Radar_Viewer->Obj_data[i].isEmpty())
                {
                    Obj_inf last_data = N_Radar_Viewer->Obj_data[i].getLast();
                    if(((N_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (N_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                    {
                        if(last_data.index_of_infoBox != 0)
                            N_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                        N_Radar_Viewer->Obj_data[i].remove_all();
                    }
                }
            }
        }
    }
    else if(static_cast<int>(msg.ID) == (0x60A + (S_Radar_Viewer->Radar_ID * 0x10)))
    {
        //qDebug() << "60A SOUTH" << os.NofObjects;
        timeval now; gettimeofday(&now, nullptr);
        S_Radar_Viewer->A_Cycle_time = now;
        GetLocalTime(&S_Radar_Viewer->A_DateTime);
        S_Radar_Viewer->first_A = true;

        S_Radar_Viewer->N_car = os.NofObjects;
        S_Radar_Viewer->N_car_now = 0;
        S_Radar_Viewer->count4Kalman = 0;

        memset(S_Radar_Viewer->exist, 0, sizeof(bool) * MAX_OBJ);
        memset(S_Radar_Viewer->this_frame_data, 0, sizeof(Obj_inf) * MAX_OBJ);

        if(do_kalman)
        {
            if(S_Radar_Viewer->N_car == 0)
            {
                for(int i=0; i<MAX_OBJ; i++)
                {
                    if(!S_Radar_Viewer->Obj_data[i].isEmpty())
                    {
                        Obj_inf last_data = S_Radar_Viewer->Obj_data[i].getLast();
                        QTime RealTime = QTime::currentTime();
                        if(((S_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (S_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                        {
                            if(last_data.index_of_infoBox != 0)
                                S_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                            S_Radar_Viewer->Obj_data[i].remove_all();
                            cvReleaseKalman(&S_Radar_Viewer->kalman_d[i]);
                            cvReleaseKalman(&S_Radar_Viewer->kalman_v[i]);
                        }
                        else if(S_Radar_Viewer->Obj_data[i].getsize() >= 2)
                        {
                            Obj_inf pred_data = last_data;
                            cvKalmanPredict(S_Radar_Viewer->kalman_d[i], 0);
                            cvKalmanPredict(S_Radar_Viewer->kalman_v[i], 0);

                            QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                            QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                            pred_data.DistLat = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                            pred_data.DistLong = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                            pred_data.VrelLat = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                            pred_data.VrelLong = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                            pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                            pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                            if(pred_data.Velocity != 0.0)
                                pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                            else
                                pred_data.ttc = 100;

                            int x = ((pred_data.DistLat - S_Radar_Viewer->MAX_DISTLAT) * -1)
                                    * (S_Radar_Viewer->LookUpImage->width / (S_Radar_Viewer->MAX_DISTLAT * 2));
                            int y = S_Radar_Viewer->LookUpImage->height
                                    - ((0.5 * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT))
                                       + (pred_data.DistLong / S_Radar_Viewer->MAX_DISTLONG)
                                       * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT)
                                       * (S_Radar_Viewer->LANE_COUNT - 1));

                            pred_data.virtual_obj = true;

                            if((x >= 0) && (x < S_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < S_Radar_Viewer->LookUpImage->height))
                            {
                                if(S_Radar_Viewer->haveLanePoint)
                                {
                                    int index = (x + (y * S_Radar_Viewer->LookUpImage->widthStep));

                                    pred_data.zone_index = S_Radar_Viewer->LookUpImage->imageData[index];

                                    if(pred_data.zone_index != 0)
                                    {
                                        memcpy(&S_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                        S_Radar_Viewer->exist[i] = true;
                                    }
                                }

                                CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                measurement_d->data.fl[0] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                measurement_d->data.fl[1] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                measurement_v->data.fl[0] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                measurement_v->data.fl[1] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                memcpy(S_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                memcpy(S_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                cvKalmanCorrect(S_Radar_Viewer->kalman_d[i], measurement_d);
                                cvKalmanCorrect(S_Radar_Viewer->kalman_v[i], measurement_v);

                                cvReleaseMat(&measurement_d);
                                cvReleaseMat(&measurement_v);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<MAX_OBJ; i++)
            {
                if(!S_Radar_Viewer->Obj_data[i].isEmpty())
                {
                    Obj_inf last_data = S_Radar_Viewer->Obj_data[i].getLast();
                    if(((S_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (S_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                    {
                        if(last_data.index_of_infoBox != 0)
                            S_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                        S_Radar_Viewer->Obj_data[i].remove_all();
                    }
                }
            }
        }
    }
    else
    {
        qDebug() << "(6*A) Num of Obj : " << os.NofObjects;
    }

}
void MainWindow::Set_Obj_B(TPCANMsg msg)
{
    Object_General og;
    memcpy(&og, msg.DATA, sizeof(Object_General));

    if(static_cast<int>(msg.ID) == (0x60B + (N_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(N_Radar_Viewer->first_A)
        {
            //qDebug() << "60B NORTH";
            int i;
            if(do_kalman)
            {
                for(i=N_Radar_Viewer->count4Kalman; i<og.ID; i++)
                {
                    if(!N_Radar_Viewer->Obj_data[i].isEmpty())
                    {
                        Obj_inf last_data = N_Radar_Viewer->Obj_data[i].getLast();
                        if(((N_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (N_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                        {
                            if(last_data.index_of_infoBox != 0)
                                N_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                            N_Radar_Viewer->Obj_data[i].remove_all();
                            cvReleaseKalman(&N_Radar_Viewer->kalman_d[i]);
                            cvReleaseKalman(&N_Radar_Viewer->kalman_v[i]);
                        }
                        else if(N_Radar_Viewer->Obj_data[i].getsize() >= 2)
                        {
                            Obj_inf pred_data = last_data;
                            cvKalmanPredict(N_Radar_Viewer->kalman_d[i], 0);
                            cvKalmanPredict(N_Radar_Viewer->kalman_v[i], 0);

                            QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                            QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                            pred_data.DistLat = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                            pred_data.DistLong = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                            pred_data.VrelLat = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                            pred_data.VrelLong = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                            pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                            pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                            if(pred_data.Velocity != 0.0)
                                pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                            else
                                pred_data.ttc = 100;

                            int x = ((pred_data.DistLat - N_Radar_Viewer->MAX_DISTLAT) * -1)
                                    * (N_Radar_Viewer->LookUpImage->width / (N_Radar_Viewer->MAX_DISTLAT * 2));
                            int y = N_Radar_Viewer->LookUpImage->height
                                    - ((0.5 * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT))
                                       + (pred_data.DistLong / N_Radar_Viewer->MAX_DISTLONG)
                                       * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT)
                                       * (N_Radar_Viewer->LANE_COUNT - 1));

                            pred_data.virtual_obj = true;

                            if((x >= 0) && (x < N_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < N_Radar_Viewer->LookUpImage->height))
                            {
                                if(N_Radar_Viewer->haveLanePoint)
                                {
                                    int index = (x + (y * N_Radar_Viewer->LookUpImage->widthStep));

                                    pred_data.zone_index = N_Radar_Viewer->LookUpImage->imageData[index];

                                    if(pred_data.zone_index != 0)
                                    {
                                        memcpy(&N_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                        N_Radar_Viewer->exist[i] = true;
                                    }
                                }

                                CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                measurement_d->data.fl[0] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                measurement_d->data.fl[1] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                measurement_v->data.fl[0] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                measurement_v->data.fl[1] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                memcpy(N_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                memcpy(N_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                cvKalmanCorrect(N_Radar_Viewer->kalman_d[i], measurement_d);
                                cvKalmanCorrect(N_Radar_Viewer->kalman_v[i], measurement_v);

                                cvReleaseMat(&measurement_d);
                                cvReleaseMat(&measurement_v);
                            }
                        }
                    }
                }
            }

            N_Radar_Viewer->count4Kalman = og.ID + 1;
            N_Radar_Viewer->N_car_now++;

            Obj_inf now_data = {N_Radar_Viewer->A_DateTime, N_Radar_Viewer->A_Cycle_time, };
            now_data.ID = og.ID;
            now_data.DistLong = ((((og.DistLong_u << 5) + og.DistLong_d) * 0.2) -500);
            now_data.DistLat = ((((og.DistLat_u << 8) + og.DistLat_d) * 0.2) - 204.6);
            now_data.VrelLong = ((((og.VrelLong_u << 2) + og.VrelLong_d) * 0.25) - 128);
            now_data.VrelLat = ((((og.VrelLat_u << 3) + og.VrelLat_d) * 0.25) - 64);
            now_data.DynProp = og.DynProp;
            now_data.RCS = ((og.RCS * 0.5) - 64.0);
            now_data.Distance = sqrt((now_data.DistLong * now_data.DistLong) + (now_data.DistLat * now_data.DistLat));
            now_data.Velocity = 3.6 * sqrt((now_data.VrelLong * now_data.VrelLong) + (now_data.VrelLat * now_data.VrelLat));
            if(now_data.Velocity >= 1)
                now_data.ttc = now_data.Distance/now_data.Velocity;
            else
                now_data.ttc = 100;


            if(do_kalman)
            {
                if(N_Radar_Viewer->Obj_data[og.ID].getsize() >= 2)
                {
                    //Obj_inf last_data = N_Radar_Viewer->Obj_data[og.ID].getLast();
                    //if(now_data.DistLong <= last_data.DistLong)
                    {
                        cvKalmanPredict(N_Radar_Viewer->kalman_d[og.ID], 0);
                        cvKalmanPredict(N_Radar_Viewer->kalman_v[og.ID], 0);

                        CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                        CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                        measurement_d->data.fl[0] = now_data.DistLat;
                        measurement_d->data.fl[1] = now_data.DistLong;
                        measurement_v->data.fl[0] = now_data.VrelLat;
                        measurement_v->data.fl[1] = now_data.VrelLong;

                        now_data.DistLat    = N_Radar_Viewer->kalman_d[og.ID]->state_pre->data.fl[0];
                        now_data.DistLong   = N_Radar_Viewer->kalman_d[og.ID]->state_pre->data.fl[1];
                        now_data.VrelLat    = N_Radar_Viewer->kalman_v[og.ID]->state_pre->data.fl[0];
                        now_data.VrelLong   = N_Radar_Viewer->kalman_v[og.ID]->state_pre->data.fl[1];

                        memcpy(N_Radar_Viewer->kalman_d[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                        memcpy(N_Radar_Viewer->kalman_v[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                        cvKalmanCorrect(N_Radar_Viewer->kalman_d[og.ID], measurement_d);
                        cvKalmanCorrect(N_Radar_Viewer->kalman_v[og.ID], measurement_v);

                        cvReleaseMat(&measurement_d);
                        cvReleaseMat(&measurement_v);
                    }
                    //else
                    //    N_Radar_Viewer->Obj_data[og.ID].remove_all();
                }
            }

            if((N_Radar_Viewer->LOWER_VELOCITY <= now_data.Velocity) && (N_Radar_Viewer->UPPER_VELOCITY >= now_data.Velocity))
            {
                now_data.DateTime = N_Radar_Viewer->A_DateTime;

                if(N_Radar_Viewer->haveLanePoint)
                {
                    int x = ((now_data.DistLat - N_Radar_Viewer->MAX_DISTLAT) * -1)
                            * (N_Radar_Viewer->LookUpImage->width / (N_Radar_Viewer->MAX_DISTLAT * 2));
                    int y = N_Radar_Viewer->LookUpImage->height
                            - ((0.5 * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT))
                               + (now_data.DistLong / N_Radar_Viewer->MAX_DISTLONG)
                               * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT)
                               * (N_Radar_Viewer->LANE_COUNT - 1));

                    if((x >= 0) && (x < N_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < N_Radar_Viewer->LookUpImage->height))
                    {
                        int index = (x + (y * N_Radar_Viewer->LookUpImage->widthStep));
                        now_data.zone_index = N_Radar_Viewer->LookUpImage->imageData[index];

                        if(now_data.zone_index != 0)
                        {
                            if(N_Radar_Viewer->Obj_data[og.ID].isEmpty())
                            {
                                if(do_kalman)
                                {
                                    N_Radar_Viewer->kalman_d[og.ID] = cvCreateKalman(4, 2, 0);
                                    memcpy(N_Radar_Viewer->kalman_d[og.ID]->transition_matrix->data.fl, A, sizeof(A));
                                    memcpy(N_Radar_Viewer->kalman_d[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvSetIdentity(N_Radar_Viewer->kalman_d[og.ID]->process_noise_cov, cvRealScalar(1e-6));
                                    cvSetIdentity(N_Radar_Viewer->kalman_d[og.ID]->measurement_noise_cov, cvRealScalar(0.000006));
                                    cvSetIdentity(N_Radar_Viewer->kalman_d[og.ID]->error_cov_post, cvRealScalar(1e+10));

                                    N_Radar_Viewer->kalman_v[og.ID] = cvCreateKalman(4, 2, 0);
                                    memcpy(N_Radar_Viewer->kalman_v[og.ID]->transition_matrix->data.fl, A, sizeof(A));
                                    memcpy(N_Radar_Viewer->kalman_v[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvSetIdentity(N_Radar_Viewer->kalman_v[og.ID]->process_noise_cov, cvRealScalar(1e-6));
                                    cvSetIdentity(N_Radar_Viewer->kalman_v[og.ID]->measurement_noise_cov, cvRealScalar(0.000006));
                                    cvSetIdentity(N_Radar_Viewer->kalman_v[og.ID]->error_cov_post, cvRealScalar(1e+10));
                                }

                                for(i=0; i<INFOBOX_NUM; i++)
                                {
                                    if(!N_Radar_Viewer->infoBoxOccupied[i])
                                    {
                                        now_data.index_of_infoBox = i + 1;
                                        N_Radar_Viewer->infoBoxOccupied[i] = true;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                Obj_inf last_data = N_Radar_Viewer->Obj_data[og.ID].getLast();

                                now_data.index_of_infoBox = N_Radar_Viewer->Obj_data[og.ID].getLast().index_of_infoBox;
                            }

                            memcpy(&N_Radar_Viewer->this_frame_data[og.ID], &now_data, sizeof(Obj_inf));
                            N_Radar_Viewer->exist[og.ID] = true;
                        }
                    }
                }
            }
            if(do_kalman)
            {
                if(N_Radar_Viewer->N_car == N_Radar_Viewer->N_car_now)
                {
                    for(i=og.ID + 1; i<MAX_OBJ; i++)
                    {
                        if(!N_Radar_Viewer->Obj_data[i].isEmpty())
                        {
                            Obj_inf last_data = N_Radar_Viewer->Obj_data[i].getLast();
                            if(((N_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (N_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                            {
                                if(last_data.index_of_infoBox != 0)
                                    N_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                                N_Radar_Viewer->Obj_data[i].remove_all();
                                cvReleaseKalman(&N_Radar_Viewer->kalman_d[i]);
                                cvReleaseKalman(&N_Radar_Viewer->kalman_v[i]);
                            }
                            else if(N_Radar_Viewer->Obj_data[i].getsize() >= 2)
                            {
                                Obj_inf pred_data = last_data;
                                cvKalmanPredict(N_Radar_Viewer->kalman_d[i], 0);
                                cvKalmanPredict(N_Radar_Viewer->kalman_v[i], 0);

                                QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                                QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                                pred_data.DistLat = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                                pred_data.DistLong = N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                                pred_data.VrelLat = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                                pred_data.VrelLong = N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                                pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                                pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                                if(pred_data.Velocity != 0.0)
                                    pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                                else
                                    pred_data.ttc = 100;

                                int x = ((pred_data.DistLat - N_Radar_Viewer->MAX_DISTLAT) * -1)
                                        * (N_Radar_Viewer->LookUpImage->width / (N_Radar_Viewer->MAX_DISTLAT * 2));
                                int y = N_Radar_Viewer->LookUpImage->height
                                        - ((0.5 * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT))
                                           + (pred_data.DistLong / N_Radar_Viewer->MAX_DISTLONG)
                                           * (N_Radar_Viewer->LookUpImage->height / N_Radar_Viewer->LANE_COUNT)
                                           * (N_Radar_Viewer->LANE_COUNT - 1));

                                pred_data.virtual_obj = true;

                                if((x >= 0) && (x < N_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < N_Radar_Viewer->LookUpImage->height))
                                {
                                    if(N_Radar_Viewer->haveLanePoint)
                                    {
                                        int index = (x + (y * N_Radar_Viewer->LookUpImage->widthStep));

                                        pred_data.zone_index = N_Radar_Viewer->LookUpImage->imageData[index];

                                        if(pred_data.zone_index != 0)
                                        {
                                            memcpy(&N_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                            N_Radar_Viewer->exist[i] = true;
                                        }
                                    }

                                    CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                    CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                    measurement_d->data.fl[0] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                    measurement_d->data.fl[1] = 4 * N_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                    measurement_v->data.fl[0] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                    measurement_v->data.fl[1] = 4 * N_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                    memcpy(N_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                    memcpy(N_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvKalmanCorrect(N_Radar_Viewer->kalman_d[i], measurement_d);
                                    cvKalmanCorrect(N_Radar_Viewer->kalman_v[i], measurement_v);

                                    cvReleaseMat(&measurement_d);
                                    cvReleaseMat(&measurement_v);
                                }
                            }
                        }
                    }
                }
                N_Radar_Viewer->N_car_now = 0;
                N_Radar_Viewer->count4Kalman = 0;
            }
        }
    }
    else if(static_cast<int>(msg.ID) == (0x60B + (S_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(S_Radar_Viewer->first_A)
        {
            //qDebug() << "60B SOUTH";
            int i;
            if(do_kalman)
            {
                for(i=S_Radar_Viewer->count4Kalman; i<og.ID; i++)
                {
                    if(!S_Radar_Viewer->Obj_data[i].isEmpty())
                    {
                        Obj_inf last_data = S_Radar_Viewer->Obj_data[i].getLast();
                        if(((S_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (S_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                        {
                            if(last_data.index_of_infoBox != 0)
                                S_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                            S_Radar_Viewer->Obj_data[i].remove_all();
                            cvReleaseKalman(&S_Radar_Viewer->kalman_d[i]);
                            cvReleaseKalman(&S_Radar_Viewer->kalman_v[i]);
                        }
                        else if(S_Radar_Viewer->Obj_data[i].getsize() >= 2)
                        {
                            Obj_inf pred_data = last_data;
                            cvKalmanPredict(S_Radar_Viewer->kalman_d[i], 0);
                            cvKalmanPredict(S_Radar_Viewer->kalman_v[i], 0);

                            QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                            QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                            pred_data.DistLat = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                            pred_data.DistLong = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                            pred_data.VrelLat = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                            pred_data.VrelLong = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                            pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                            pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                            if(pred_data.Velocity != 0.0)
                                pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                            else
                                pred_data.ttc = 100;

                            int x = ((pred_data.DistLat - S_Radar_Viewer->MAX_DISTLAT) * -1)
                                    * (S_Radar_Viewer->LookUpImage->width / (S_Radar_Viewer->MAX_DISTLAT * 2));
                            int y = S_Radar_Viewer->LookUpImage->height
                                    - ((0.5 * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT))
                                       + (pred_data.DistLong / S_Radar_Viewer->MAX_DISTLONG)
                                       * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT)
                                       * (S_Radar_Viewer->LANE_COUNT - 1));

                            pred_data.virtual_obj = true;

                            if((x >= 0) && (x < S_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < S_Radar_Viewer->LookUpImage->height))
                            {
                                if(S_Radar_Viewer->haveLanePoint)
                                {
                                    int index = (x + (y * S_Radar_Viewer->LookUpImage->widthStep));

                                    pred_data.zone_index = S_Radar_Viewer->LookUpImage->imageData[index];

                                    if(pred_data.zone_index != 0)
                                    {
                                        memcpy(&S_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                        S_Radar_Viewer->exist[i] = true;
                                    }
                                }

                                CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                measurement_d->data.fl[0] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                measurement_d->data.fl[1] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                measurement_v->data.fl[0] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                measurement_v->data.fl[1] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                memcpy(S_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                memcpy(S_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                cvKalmanCorrect(S_Radar_Viewer->kalman_d[i], measurement_d);
                                cvKalmanCorrect(S_Radar_Viewer->kalman_v[i], measurement_v);

                                cvReleaseMat(&measurement_d);
                                cvReleaseMat(&measurement_v);
                            }
                        }
                    }
                }
            }
            S_Radar_Viewer->count4Kalman = og.ID + 1;
            S_Radar_Viewer->N_car_now++;

            Obj_inf now_data = {S_Radar_Viewer->A_DateTime, S_Radar_Viewer->A_Cycle_time, };
            now_data.ID = og.ID;
            now_data.DistLong = ((((og.DistLong_u << 5) + og.DistLong_d) * 0.2) -500);
            now_data.DistLat = ((((og.DistLat_u << 8) + og.DistLat_d) * 0.2) - 204.6);
            now_data.VrelLong = ((((og.VrelLong_u << 2) + og.VrelLong_d) * 0.25) - 128);
            now_data.VrelLat = ((((og.VrelLat_u << 3) + og.VrelLat_d) * 0.25) - 64);
            now_data.DynProp = og.DynProp;
            now_data.RCS = ((og.RCS * 0.5) - 64.0);
            now_data.Distance = sqrt((now_data.DistLong * now_data.DistLong) + (now_data.DistLat * now_data.DistLat));
            now_data.Velocity = 3.6 * sqrt((now_data.VrelLong * now_data.VrelLong) + (now_data.VrelLat * now_data.VrelLat));
            if(now_data.Velocity >= 1)
                now_data.ttc = now_data.Distance/now_data.Velocity;
            else
                now_data.ttc = 100;

            if(do_kalman)
            {
                if(S_Radar_Viewer->Obj_data[og.ID].getsize() >= 2)
                {
                    //Obj_inf last_data = S_Radar_Viewer->Obj_data[og.ID].getLast();
                    //if(now_data.DistLong <= last_data.DistLong)
                    {
                        cvKalmanPredict(S_Radar_Viewer->kalman_d[og.ID], 0);
                        cvKalmanPredict(S_Radar_Viewer->kalman_v[og.ID], 0);

                        CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                        CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                        measurement_d->data.fl[0] = now_data.DistLat;
                        measurement_d->data.fl[1] = now_data.DistLong;
                        measurement_v->data.fl[0] = now_data.VrelLat;
                        measurement_v->data.fl[1] = now_data.VrelLong;

                        now_data.DistLat    = S_Radar_Viewer->kalman_d[og.ID]->state_pre->data.fl[0];
                        now_data.DistLong   = S_Radar_Viewer->kalman_d[og.ID]->state_pre->data.fl[1];
                        now_data.VrelLat    = S_Radar_Viewer->kalman_v[og.ID]->state_pre->data.fl[0];
                        now_data.VrelLong   = S_Radar_Viewer->kalman_v[og.ID]->state_pre->data.fl[1];

                        memcpy(S_Radar_Viewer->kalman_d[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                        memcpy(S_Radar_Viewer->kalman_v[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                        cvKalmanCorrect(S_Radar_Viewer->kalman_d[og.ID], measurement_d);
                        cvKalmanCorrect(S_Radar_Viewer->kalman_v[og.ID], measurement_v);

                        cvReleaseMat(&measurement_d);
                        cvReleaseMat(&measurement_v);
                    }
                    //else
                    //    S_Radar_Viewer->Obj_data[og.ID].remove_all();
                }
            }

            if((S_Radar_Viewer->LOWER_VELOCITY <= now_data.Velocity) && (S_Radar_Viewer->UPPER_VELOCITY >= now_data.Velocity))
            {
                now_data.DateTime = S_Radar_Viewer->A_DateTime;

                if(S_Radar_Viewer->haveLanePoint)
                {
                    int x = ((now_data.DistLat - S_Radar_Viewer->MAX_DISTLAT) * -1)
                            * (S_Radar_Viewer->LookUpImage->width / (S_Radar_Viewer->MAX_DISTLAT * 2));
                    int y = S_Radar_Viewer->LookUpImage->height
                            - ((0.5 * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT))
                               + (now_data.DistLong / S_Radar_Viewer->MAX_DISTLONG)
                               * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT)
                               * (S_Radar_Viewer->LANE_COUNT - 1));

                    if((x >= 0) && (x < S_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < S_Radar_Viewer->LookUpImage->height))
                    {
                        int index = (x + (y * S_Radar_Viewer->LookUpImage->widthStep));
                        now_data.zone_index = S_Radar_Viewer->LookUpImage->imageData[index];

                        if(now_data.zone_index != 0)
                        {
                            if(S_Radar_Viewer->Obj_data[og.ID].isEmpty())
                            {
                                if(do_kalman)
                                {
                                    S_Radar_Viewer->kalman_d[og.ID] = cvCreateKalman(4, 2, 0);
                                    memcpy(S_Radar_Viewer->kalman_d[og.ID]->transition_matrix->data.fl, A, sizeof(A));
                                    memcpy(S_Radar_Viewer->kalman_d[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvSetIdentity(S_Radar_Viewer->kalman_d[og.ID]->process_noise_cov, cvRealScalar(1e-6));
                                    cvSetIdentity(S_Radar_Viewer->kalman_d[og.ID]->measurement_noise_cov, cvRealScalar(0.000006));
                                    cvSetIdentity(S_Radar_Viewer->kalman_d[og.ID]->error_cov_post, cvRealScalar(1e+10));

                                    S_Radar_Viewer->kalman_v[og.ID] = cvCreateKalman(4, 2, 0);
                                    memcpy(S_Radar_Viewer->kalman_v[og.ID]->transition_matrix->data.fl, A, sizeof(A));
                                    memcpy(S_Radar_Viewer->kalman_v[og.ID]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvSetIdentity(S_Radar_Viewer->kalman_v[og.ID]->process_noise_cov, cvRealScalar(1e-6));
                                    cvSetIdentity(S_Radar_Viewer->kalman_v[og.ID]->measurement_noise_cov, cvRealScalar(0.000006));
                                    cvSetIdentity(S_Radar_Viewer->kalman_v[og.ID]->error_cov_post, cvRealScalar(1e+10));
                                }

                                for(i=0; i<INFOBOX_NUM; i++)
                                {
                                    if(!S_Radar_Viewer->infoBoxOccupied[i])
                                    {
                                        now_data.index_of_infoBox = i + 1;
                                        S_Radar_Viewer->infoBoxOccupied[i] = true;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                Obj_inf last_data = S_Radar_Viewer->Obj_data[og.ID].getLast();

                                now_data.index_of_infoBox = S_Radar_Viewer->Obj_data[og.ID].getLast().index_of_infoBox;
                            }

                            memcpy(&S_Radar_Viewer->this_frame_data[og.ID], &now_data, sizeof(Obj_inf));
                            S_Radar_Viewer->exist[og.ID] = true;
                        }
                    }
                }
            }
            if(do_kalman)
            {
                if(S_Radar_Viewer->N_car == S_Radar_Viewer->N_car_now)
                {
                    for(i=og.ID + 1; i<MAX_OBJ; i++)
                    {
                        if(!S_Radar_Viewer->Obj_data[i].isEmpty())
                        {
                            Obj_inf last_data = S_Radar_Viewer->Obj_data[i].getLast();
                            if(((S_Radar_Viewer->A_Cycle_time.tv_sec - last_data.Time.tv_sec) * 1000 + (S_Radar_Viewer->A_Cycle_time.tv_usec - last_data.Time.tv_usec) / 1000 )/1000 >= KEEP_SEC)
                            {
                                if(last_data.index_of_infoBox != 0)
                                    S_Radar_Viewer->infoBoxOccupied[last_data.index_of_infoBox - 1] = false;
                                S_Radar_Viewer->Obj_data[i].remove_all();
                                cvReleaseKalman(&S_Radar_Viewer->kalman_d[i]);
                                cvReleaseKalman(&S_Radar_Viewer->kalman_v[i]);
                            }
                            else if(S_Radar_Viewer->Obj_data[i].getsize() >= 2)
                            {
                                Obj_inf pred_data = last_data;
                                cvKalmanPredict(S_Radar_Viewer->kalman_d[i], 0);
                                cvKalmanPredict(S_Radar_Viewer->kalman_v[i], 0);

                                QPointF last_dist(pred_data.DistLat, pred_data.DistLong);
                                QPointF last_vrel(pred_data.VrelLat, pred_data.VrelLong);

                                pred_data.DistLat = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0];
                                pred_data.DistLong = S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1];
                                pred_data.VrelLat = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0];
                                pred_data.VrelLong = S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1];
                                pred_data.Distance = sqrt((pred_data.DistLong * pred_data.DistLong) + (pred_data.DistLat * pred_data.DistLat));
                                pred_data.Velocity = 3.6 * sqrt((pred_data.VrelLong * pred_data.VrelLong) + (pred_data.VrelLat * pred_data.VrelLat));
                                if(pred_data.Velocity != 0.0)
                                    pred_data.ttc = pred_data.Distance/pred_data.Velocity;
                                else
                                    pred_data.ttc = 100;

                                int x = ((pred_data.DistLat - S_Radar_Viewer->MAX_DISTLAT) * -1)
                                        * (S_Radar_Viewer->LookUpImage->width / (S_Radar_Viewer->MAX_DISTLAT * 2));
                                int y = S_Radar_Viewer->LookUpImage->height
                                        - ((0.5 * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT))
                                           + (pred_data.DistLong / S_Radar_Viewer->MAX_DISTLONG)
                                           * (S_Radar_Viewer->LookUpImage->height / S_Radar_Viewer->LANE_COUNT)
                                           * (S_Radar_Viewer->LANE_COUNT - 1));

                                pred_data.virtual_obj = true;

                                if((x >= 0) && (x < S_Radar_Viewer->LookUpImage->width) && (y >= 0) && (y < S_Radar_Viewer->LookUpImage->height))
                                {
                                    if(S_Radar_Viewer->haveLanePoint)
                                    {
                                        int index = (x + (y * S_Radar_Viewer->LookUpImage->widthStep));

                                        pred_data.zone_index = S_Radar_Viewer->LookUpImage->imageData[index];

                                        if(pred_data.zone_index != 0)
                                        {
                                            memcpy(&S_Radar_Viewer->this_frame_data[i], &pred_data, sizeof(Obj_inf));
                                            S_Radar_Viewer->exist[i] = true;
                                        }
                                    }

                                    CvMat* measurement_d = cvCreateMat(2, 1, CV_32FC1);
                                    CvMat* measurement_v = cvCreateMat(2, 1, CV_32FC1);
                                    measurement_d->data.fl[0] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[0] - 3 * last_dist.x();
                                    measurement_d->data.fl[1] = 4 * S_Radar_Viewer->kalman_d[i]->state_pre->data.fl[1] - 3 * last_dist.y();
                                    measurement_v->data.fl[0] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[0] - 3 * last_vrel.x();
                                    measurement_v->data.fl[1] = 4 * S_Radar_Viewer->kalman_v[i]->state_pre->data.fl[1] - 3 * last_vrel.y();

                                    memcpy(S_Radar_Viewer->kalman_d[i]->measurement_matrix->data.fl, H, sizeof(H));
                                    memcpy(S_Radar_Viewer->kalman_v[i]->measurement_matrix->data.fl, H, sizeof(H));
                                    cvKalmanCorrect(S_Radar_Viewer->kalman_d[i], measurement_d);
                                    cvKalmanCorrect(S_Radar_Viewer->kalman_v[i], measurement_v);

                                    cvReleaseMat(&measurement_d);
                                    cvReleaseMat(&measurement_v);
                                }
                            }
                        }
                    }
                }
                S_Radar_Viewer->N_car_now = 0;
                S_Radar_Viewer->count4Kalman = 0;
            }
        }
    }
}
void MainWindow::Set_Obj_C(TPCANMsg msg)
{
    Object_Quality oq;
    memcpy(&oq, msg.DATA, sizeof(Object_Quality));

    //qDebug() << "(60C) Obj ID : " << oq.ID;

    if((int)msg.ID == (0x60C + (N_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(N_Radar_Viewer->exist[oq.ID])
        {
            if(N_Radar_Viewer->first_A)
            {
                if(!N_Radar_Viewer->this_frame_data[oq.ID].C)
                {
//                    N_Radar_Viewer->this_frame_data[oq.ID].DistLong_rms = oq.DistLong_rms;
//                    N_Radar_Viewer->this_frame_data[oq.ID].DistLat_rms = ((oq.DistLat_rms_u << 2) + oq.DistLat_rms_d);
//                    N_Radar_Viewer->this_frame_data[oq.ID].VrelLong_rms = oq.VrelLong_rms;
//                    N_Radar_Viewer->this_frame_data[oq.ID].VrelLat_rms = ((oq.VrelLat_rms_u << 4) + oq.VrelLat_rms_d);
//                    N_Radar_Viewer->this_frame_data[oq.ID].ArelLong_rms = ((oq.ArelLong_rms_u << 1) + oq.ArelLong_rms_d);
//                    N_Radar_Viewer->this_frame_data[oq.ID].ArelLat_rms = oq.ArelLat_rms;
//                    N_Radar_Viewer->this_frame_data[oq.ID].Orientation_rms = ((oq.Orientation_rms_u << 3) + oq.Orientation_rms_d);
                    N_Radar_Viewer->this_frame_data[oq.ID].MirrorProb = oq.MirrorProb;
                    N_Radar_Viewer->this_frame_data[oq.ID].MeasState = oq.MeasState;
                    N_Radar_Viewer->this_frame_data[oq.ID].ProbOfExist = oq.ProbOfExist;
                    N_Radar_Viewer->this_frame_data[oq.ID].C = true;
                }
            }
        }
    }
    else if((int)msg.ID == (0x60C + (S_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(S_Radar_Viewer->exist[oq.ID])
        {
            if(S_Radar_Viewer->first_A)
            {
                if(!S_Radar_Viewer->this_frame_data[oq.ID].C)
                {
//                    S_Radar_Viewer->this_frame_data[oq.ID].DistLong_rms = oq.DistLong_rms;
//                    S_Radar_Viewer->this_frame_data[oq.ID].DistLat_rms = ((oq.DistLat_rms_u << 2) + oq.DistLat_rms_d);
//                    S_Radar_Viewer->this_frame_data[oq.ID].VrelLong_rms = oq.VrelLong_rms;
//                    S_Radar_Viewer->this_frame_data[oq.ID].VrelLat_rms = ((oq.VrelLat_rms_u << 4) + oq.VrelLat_rms_d);
//                    S_Radar_Viewer->this_frame_data[oq.ID].ArelLong_rms = ((oq.ArelLong_rms_u << 1) + oq.ArelLong_rms_d);
//                    S_Radar_Viewer->this_frame_data[oq.ID].ArelLat_rms = oq.ArelLat_rms;
//                    S_Radar_Viewer->this_frame_data[oq.ID].Orientation_rms = ((oq.Orientation_rms_u << 3) + oq.Orientation_rms_d);
                    S_Radar_Viewer->this_frame_data[oq.ID].MirrorProb = oq.MirrorProb;
                    S_Radar_Viewer->this_frame_data[oq.ID].MeasState = oq.MeasState;
                    S_Radar_Viewer->this_frame_data[oq.ID].ProbOfExist = oq.ProbOfExist;
                    S_Radar_Viewer->this_frame_data[oq.ID].C = true;
                }
            }
        }
    }
}
void MainWindow::Set_Obj_D(TPCANMsg msg)
{
    Object_Extended oe;
    memcpy(&oe, msg.DATA, sizeof(Object_Extended));

    //qDebug() << "(60D) Obj ID : " << oe.ID;

    if(int(msg.ID) == (0x60D + (N_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(N_Radar_Viewer->first_A)
        {
            if(log_work)
            {
                if(N_Radar_Viewer->startRadar)
                {
                    bool header = false;
                    if(int(last_save_obj.wMinute / 10) != (global_time.wMinute / 10))
                    {
                        last_save_obj = global_time;
                        //log_obj_PATH = log_DIR + "/OBJ/" + last_save_obj.toString("yyyy-MM-dd-HH-mm-ss-zzz") + ".csv";
                        header = true;
                    }
                    QFile file(log_obj_PATH);
                    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                    QTextStream out(&file);

                    if(header)
                        out << "Time, ID, DistLat, DistLong, DIST, VrelLat, VrelLong, VREL, DynProp, RCS, ProbofExist, MirrorProp, ArelLat, ArelLong, Orientation, Class, Length, Width/n";

                    //out << N_Radar_Viewer->this_frame_data[oe.ID].DateTime.toString("yyyy/MM/dd hh:mm:ss.zzz") << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].ID << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].DistLat << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].DistLong << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].Distance << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].VrelLat << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].VrelLong << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].Velocity << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].DynProp << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].RCS << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].ProbOfExist << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].MirrorProb << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].ArelLat << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].ArelLong << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].OrientationAngel << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].Class << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].Length << ",";
                    out << N_Radar_Viewer->this_frame_data[oe.ID].Width << "/n";

                    file.close();
                }
            }

            if(do_kalman)
            {
                for(int i=N_Radar_Viewer->count4Kalman; i<oe.ID; i++)
                {
                    if(N_Radar_Viewer->exist[i])
                    {
                        if(log_work)
                        {
                        }
                        N_Radar_Viewer->Obj_data[i].addLast(N_Radar_Viewer->this_frame_data[i]);
                        N_Radar_Viewer->exist[i] = false;
                    }
                }
            }
            N_Radar_Viewer->count4Kalman = oe.ID + 1;
            N_Radar_Viewer->N_car_now++;

            if(N_Radar_Viewer->exist[oe.ID])
            {
                if(!N_Radar_Viewer->this_frame_data[oe.ID].D)
                {
                    N_Radar_Viewer->this_frame_data[oe.ID].ArelLong = ((((oe.ArelLong_u << 3) + oe.ArelLong_d) * 0.01) - 10);
                    N_Radar_Viewer->this_frame_data[oe.ID].ArelLat = ((((oe.ArelLat_u << 3) + oe.ArelLat_d) * 0.01) - 2.5);
                    N_Radar_Viewer->this_frame_data[oe.ID].Class = oe.Class;
                    N_Radar_Viewer->this_frame_data[oe.ID].OrientationAngel = ((((oe.OrientationAngel_u << 2) + oe.OrientationAngel_d) * 0.4) - 180);
                    N_Radar_Viewer->this_frame_data[oe.ID].Length = (oe.Length * 0.2);
                    N_Radar_Viewer->this_frame_data[oe.ID].Width = (oe.Width * 0.2);
                    N_Radar_Viewer->this_frame_data[oe.ID].D = true;

                    if(log_work)
                    {
                    }
                    N_Radar_Viewer->Obj_data[oe.ID].addLast(N_Radar_Viewer->this_frame_data[oe.ID]);
                    N_Radar_Viewer->exist[oe.ID] = false;
                }
            }
            if(do_kalman)
            {
                if(N_Radar_Viewer->N_car == N_Radar_Viewer->N_car_now)
                {
                    for(int i=oe.ID + 1; i<MAX_OBJ; i++)
                    {
                        if(N_Radar_Viewer->exist[i])
                        {
                            if(log_work)
                            {
                            }
                            N_Radar_Viewer->Obj_data[i].addLast(N_Radar_Viewer->this_frame_data[i]);
                            N_Radar_Viewer->exist[i] = false;
                        }
                    }
                }
            }
        }
    }
    else if(int(msg.ID) == (0x60D + (S_Radar_Viewer->Radar_ID * 0x10)))
    {
        if(S_Radar_Viewer->first_A)
        {
            if(log_work)
            {
                if(S_Radar_Viewer->startRadar)
                {
                    bool header = false;
                    if(int(last_save_obj.wMinute / 10) != (global_time.wMinute / 10))
                    {
                        last_save_obj = global_time;
                        //log_obj_PATH = log_DIR + "/OBJ/" + last_save_obj.toString("yyyy-MM-dd-HH-mm-ss-zzz") + ".csv";
                        header = true;
                    }
                    QFile file(log_obj_PATH);
                    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                    QTextStream out(&file);

                    if(header)
                        out << "Time, ID, DistLat, DistLong, DIST, VrelLat, VrelLong, VREL, DynProp, RCS, ProbofExist, MirrorProp, ArelLat, ArelLong, Orientation, Class, Length, Width/n";

                    //out << S_Radar_Viewer->this_frame_data[oe.ID].DateTime.toString("yyyy/MM/dd hh:mm:ss.zzz") << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].ID << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].DistLat << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].DistLong << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].Distance << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].VrelLat << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].VrelLong << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].Velocity << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].DynProp << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].RCS << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].ProbOfExist << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].MirrorProb << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].ArelLat << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].ArelLong << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].OrientationAngel << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].Class << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].Length << ",";
                    out << S_Radar_Viewer->this_frame_data[oe.ID].Width << "/n";

                    file.close();
                }
            }

            if(do_kalman)
            {
                for(int i=S_Radar_Viewer->count4Kalman; i<oe.ID; i++)
                {
                    if(S_Radar_Viewer->exist[i])
                    {
                        if(log_work)
                        {
                        }
                        S_Radar_Viewer->Obj_data[i].addLast(S_Radar_Viewer->this_frame_data[i]);
                        S_Radar_Viewer->exist[i] = false;
                    }
                }
            }
            S_Radar_Viewer->count4Kalman = oe.ID + 1;
            S_Radar_Viewer->N_car_now++;

            if(S_Radar_Viewer->exist[oe.ID])
            {
                if(!S_Radar_Viewer->this_frame_data[oe.ID].D)
                {
                    S_Radar_Viewer->this_frame_data[oe.ID].ArelLong = ((((oe.ArelLong_u << 3) + oe.ArelLong_d) * 0.01) - 10);
                    S_Radar_Viewer->this_frame_data[oe.ID].ArelLat = ((((oe.ArelLat_u << 3) + oe.ArelLat_d) * 0.01) - 2.5);
                    S_Radar_Viewer->this_frame_data[oe.ID].Class = oe.Class;
                    S_Radar_Viewer->this_frame_data[oe.ID].OrientationAngel = ((((oe.OrientationAngel_u << 2) + oe.OrientationAngel_d) * 0.4) - 180);
                    S_Radar_Viewer->this_frame_data[oe.ID].Length = (oe.Length * 0.2);
                    S_Radar_Viewer->this_frame_data[oe.ID].Width = (oe.Width * 0.2);
                    S_Radar_Viewer->this_frame_data[oe.ID].D = true;

                    if(log_work)
                    {
                    }
                    S_Radar_Viewer->this_frame_data[oe.ID].DateTime = S_Radar_Viewer->A_DateTime;
                    S_Radar_Viewer->Obj_data[oe.ID].addLast(S_Radar_Viewer->this_frame_data[oe.ID]);
                    S_Radar_Viewer->exist[oe.ID] = false;
                }
            }
            if(do_kalman)
            {
                if(S_Radar_Viewer->N_car == S_Radar_Viewer->N_car_now)
                {
                    for(int i=oe.ID + 1; i<MAX_OBJ; i++)
                    {
                        if(S_Radar_Viewer->exist[i])
                        {
                            if(log_work)
                            {
                            }
                            S_Radar_Viewer->Obj_data[i].addLast(S_Radar_Viewer->this_frame_data[i]);
                            S_Radar_Viewer->exist[i] = false;
                        }
                    }
                }
            }
        }
    }
}

bool MainWindow::InitializeValue_Camera()
{
    player = new QMediaPlayer;
    startCamera = false;

    return true;
}
void MainWindow::on_Connectbtn_Camera_clicked()
{
    Connect_Camera();
}
void MainWindow::on_Disconnectbtn_Camera_clicked()
{
    Disconnect_Camera();
}

bool MainWindow::Connect_Camera()
{
    if(!startCamera)
    {
        Connectbtn_Camera->setEnabled(false);


        if(NET_DVR_Init() == false)
            qDebug() << "NET_DVR_Init ERROR";


        NET_DVR_SetConnectTime(2000, 1);
        NET_DVR_SetReconnect(10000, true);

        NET_DVR_DEVICEINFO_V30 DeviceInfo;
        UserID = NET_DVR_Login_V30("183.99.41.239", 625, "admin", "hbrain0372!", &DeviceInfo);
        if(UserID < 0)
        {
            NET_DVR_Cleanup();
            qDebug() << "NET_DVR_Login  ERROR";
            return false;
        }
        else
        {
            player = new QMediaPlayer;
            player->setVideoOutput(Camera_Viewer);
            QUrl url = QUrl("rtsp://admin:hbrain0372!@183.99.41.239");
            requestRtsp = QNetworkRequest(QUrl(url));
            player->setMedia(requestRtsp);
            qDebug() << url;
            player->play();
            Camera_Status->setStyleSheet("background-color: rgb(0, 255, 0);");
        }


        Connectbtn_Camera->setEnabled(false);
        Disconnectbtn_Camera->setEnabled(true);
        startCamera = true;
    }

    return true;
}

bool MainWindow::Disconnect_Camera()
{
    if(startCamera)
    {
        NET_DVR_StopRealPlay(RealPlayHandle);
        RealPlayHandle = -1;
        NET_DVR_Logout(UserID);

        player->stop();

        Camera_Status->setStyleSheet("background-color: rgb(255, 0, 0);");

        Connectbtn_Camera->setEnabled(true);
        Disconnectbtn_Camera->setEnabled(false);
        startCamera = false;
    }

    return true;
}
void MainWindow::on_moveUP_pressed()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, TILT_UP, 0, 5);
}
void MainWindow::on_moveUP_released()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, TILT_UP, 1, 5);
}
void MainWindow::on_moveDOWN_pressed()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, TILT_DOWN, 0, 5);
}
void MainWindow::on_moveDOWN_released()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, TILT_DOWN, 1, 5);
}
void MainWindow::on_moveLEFT_pressed()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, PAN_LEFT, 0, 5);
}
void MainWindow::on_moveLEFT_released()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, PAN_LEFT, 1, 5);
}
void MainWindow::on_moveRIGHT_pressed()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, PAN_RIGHT, 0, 5);
}
void MainWindow::on_moveRIGHT_released()
{
    NET_DVR_PTZControlWithSpeed_Other(UserID, 1, PAN_RIGHT, 1, 5);
}

bool MainWindow::InitializeValue_Socket()
{

}
void MainWindow::on_Connectbtn_Socket_clicked()
{
    Connect_Socket();
}

void MainWindow::on_Disconnectbtn_Socket_clicked()
{
    Disconnect_Socket();
}

bool MainWindow::Connect_Socket()
{
    if(!startSocket)
    {
        m_socketDevice.Open("127.0.0.1", 1234);

        Connectbtn_Socket->setEnabled(false);
        Disconnectbtn_Socket->setEnabled(true);
        startSocket = true;

        Socket_Status->setStyleSheet("background-color: rgb(0, 255, 0);");
    }

    return true;
}
bool MainWindow::Disconnect_Socket()
{
    if(startSocket)
    {


        Connectbtn_Socket->setEnabled(true);
        Disconnectbtn_Socket->setEnabled(false);
        startSocket = false;

        Socket_Status->setStyleSheet("background-color: rgb(255, 0, 0);");
    }

    return true;
}

bool MainWindow::send_Socket_Connection_Check()
{

}
bool MainWindow::InitializeValue_Serial()
{
    startSerial = false;

    s_Port = 4;
    s_Baudrate = 19200;

    N_display_ON = false;
    S_display_ON = false;

    getSerialPort();

    CheckSerialDatatimer = new QTimer(this);
    connect(CheckSerialDatatimer, SIGNAL(timeout()), this, SLOT(ClassifyingEachSerialMessage()));
    check_ack_timer = new QTimer(this);
    connect(check_ack_timer, SIGNAL(timeout()), this, SLOT(check_ACK()));
    check_connect_timer = new QTimer(this);
    connect(check_connect_timer, SIGNAL(timeout()), this, SLOT(check_connect()));
}
void MainWindow::getSerialPort()
{
    HKEY hKey;

    RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), &hKey);

    TCHAR szData[20], szName[100];
    DWORD index = 0, dwSize = 100, dwSize2 = 20, dwType = REG_SZ;
    // m_Combo_CommList.ResetContent();
    memset(szData, 0x00, sizeof(szData));
    memset(szName, 0x00, sizeof(szName));


    //https://msdn.microsoft.com/en-us/library/windows/desktop/ms724865(v=vs.85).aspx
    //hKey - 레지스터키 핸들
    //index - 값을 가져올 인덱스.. 다수의 값이 있을 경우 필요
    //szName - 항목값이 저장될 배열
    //dwSize - 배열의 크기
    while (ERROR_SUCCESS == RegEnumValue(hKey, index, szName, &dwSize, NULL, NULL, NULL, NULL))
    {
        index++;

        //https://msdn.microsoft.com/en-us/library/windows/desktop/ms724911(v=vs.85).aspx
        //szName-레지터스터 항목의 이름
        //dwType-항목의 타입, 여기에서는 널로 끝나는 문자열
        //szData-항목값이 저장될 배열
        //dwSize2-배열의 크기
        RegQueryValueEx(hKey, szName, NULL, &dwType, (LPBYTE)szData, &dwSize2);
        //m_Combo_CommList.AddString(CString(szData));

        int len = wcslen((wchar_t*)szName);
        char* psz = new char[2*len + 1];
        wcstombs(psz, (wchar_t*)szName, 2*len + 1);
        std::string s = psz;
        delete [] psz;

        len = wcslen((wchar_t*)szName);
        char* pszt = new char[2*len + 1];
        wcstombs(pszt, (wchar_t*)szData, 2*len + 1);
        std::string st = pszt;
        delete [] pszt;

        qDebug() << QString::fromStdString(s) << QString::fromStdString(st);

        memset(szData, 0x00, sizeof(szData));
        memset(szName, 0x00, sizeof(szName));
        dwSize = 100;
        dwSize2 = 20;
    }

    //m_Combo_CommList.SetCurSel(0);
    RegCloseKey(hKey);
}
void MainWindow::on_Connectbtn_Serial_clicked()
{
    Connect_Serial();
}

void MainWindow::on_Disconnectbtn_Serial_clicked()
{
    Disconnect_Serial();
}

bool MainWindow::Connect_Serial()
{
    if(!startSerial)
    {
        int res = m_serialDevice.Open(s_Port, s_Baudrate);
        if(res == false)
        {
            qDebug() << "Serial Open ERROR";
            return false;
        }
        else
        {
            CheckSerialDatatimer->start(3);
            check_ack_timer->start(3);
            check_connect_timer->start(10000);

            startSerial = true;
            Serial_Status->setStyleSheet("background-color: rgb(0, 255, 0);");
            pthread_create(&rfThread, nullptr, MainWindow::callreadSerialMessageFunc, this);

            send_danger_level(0, 1);
        }

        Connectbtn_Serial->setEnabled(false);
        Disconnectbtn_Serial->setEnabled(true);
        startSerial = true;
    }

    return true;
}

bool MainWindow::Disconnect_Serial()
{
    if(startSerial)
    {
        startSerial = false;
        pthread_join(rfThread, nullptr);

        Serial_Status->setStyleSheet("background-color: rgb(255, 0, 0);");
        CheckSerialDatatimer->stop();
        check_ack_timer->stop();
        check_connect_timer->stop();

        Connectbtn_Serial->setEnabled(true);
        Disconnectbtn_Serial->setEnabled(false);
    }

    return true;
}

void *MainWindow::callreadSerialMessageFunc(void *func)
{
    (static_cast<MainWindow *>(func))->readSerialMessage();
    return nullptr;
}
void MainWindow::readSerialMessage()
{
    //qDebug() << "readRF";

    while(startSerial)
    {
        char data = m_serialDevice.readOneByte();
        if(data != NULL)
        {
            buffer.push_back(data);
        }

        if(buffer.size() >= 5)
        {
            if(buffer[0] == STX)
            {
                int len = buffer[1];
                if(buffer.size() >= (len + 2))
                {
                    char code = buffer[2];
                    if((code == DANGER_LEVEL_ACK) || (code == CHECK_CONNECTION_ACK))
                    {
                        char msg[32] = {0, };
                        for(int i=0; i<len+2; i++)
                            msg[i] = buffer[i];
                        _msg_t msg_set;
                        memcpy(msg_set.msg, msg, 32);
                        msg_set.len = len+2;
                        recv_buf.push(msg_set);
                        buffer.erase(buffer.begin(), buffer.begin()+len+2);
                    }
                    else
                        buffer.erase(buffer.begin());
                }
            }
            else
                buffer.erase(buffer.begin());


            if(buffer.size() >= 50)
                buffer.erase(buffer.begin());
        }
    }
}

bool MainWindow::send_danger_level(int ID, int danger_level)
{
    char data[32];
    unsigned short checkSum = 0;
    char checkSum_high = 0;
    char checkSum_low = 0;

    sprintf(data, "%c%c%c%c%c", STX, 6, DANGER_LEVEL, ID, danger_level);

    checkSum = calCRC((unsigned char*)data, 5);
    checkSum_high = checkSum>>8;
    checkSum_low = checkSum & 0xFF;

    _msg_t msg_s;
    sprintf(msg_s.msg, "%c%c%c%c%c%c%c%c\n", STX, 6, DANGER_LEVEL, ID, danger_level, checkSum_high, checkSum_low, ETX);
    msg_s.len = 6 + 2;

    if(startSerial)
    {
        m_serialDevice.writeData(msg_s.msg, msg_s.len + 1);

        switch(ID - 1)
        {
        case NORTH:
        {
            gettimeofday(&N_timeSendDanger, nullptr);
            break;
        }

        case SOUTH:
        {
            gettimeofday(&S_timeSendDanger, nullptr);
            break;
        }

        default:
            break;

        }


//        display_ON = false;
//        flicker_timer->stop();
//        switch(danger_level)
//        {
//        case 1:
//        {
//            display_ON = true;
//            showSpeed = true;
//            QPixmap DisplayImg(currentPATH + "/img/Display_ON.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            flicker_timer->start(200);
//            break;
//        }
//        case 2:
//        {
//            showSpeed = true;
//            QPixmap DisplayImg(currentPATH + "/img/Display_ON.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        case 3:
//        {
//            showSpeed = false;
//            QPixmap DisplayImg(currentPATH + "/img/Display_OFF.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        case 4:
//        {
//            showSpeed = false;
//            QPixmap DisplayImg(currentPATH + "/img/Display_OFF.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        case 5:
//        {
//            showSpeed = false;
//            QPixmap DisplayImg(currentPATH + "/img/Display_OFF.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        case 6:
//        {
//            showSpeed = false;
//            QPixmap DisplayImg("/home/pi/image/Display_OFF.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        default:
//        {
//            showSpeed = false;
//            QPixmap DisplayImg("/home/pi/image/Display_OFF.png");
//            ui->AIDisplayImg->setPixmap(DisplayImg);
//            ui->AIDisplayImg->setScaledContents(true);
//            break;
//        }
//        }


        char hex_msg[64] = {0, };
        str2hex(hex_msg, msg_s.msg, msg_s.len);
        if(do_print_text) qDebug("Send Danger Level : %s", hex_msg);
    }
    else
        if(do_print_text) qDebug() << "Send Danger Level Error : Not connected Serial Module";
}

bool MainWindow::send_Serial_Connection_Check(int ID)
{
    char data[32] = {0, };
    unsigned short checkSum = 0;
    char checkSum_high = 0;
    char checkSum_low = 0;

    sprintf(data, "%c%c%c%c", STX, 5, CHECK_CONNECTION, ID);

    checkSum = calCRC((unsigned char*)data, 4);
    checkSum_high = checkSum>>8;
    checkSum_low = checkSum & 0xFF;

    _msg_t msg_s;
    sprintf(msg_s.msg, "%c%c%c%c%c%c%c\n", STX, 5, CHECK_CONNECTION, ID, checkSum_high, checkSum_low, ETX);
    msg_s.len = 5 + 2;

    if(startSerial)
    {
        m_serialDevice.writeData(msg_s.msg, msg_s.len + 1);

        switch(ID - 1)
        {
        case NORTH:
        {
            gettimeofday(&N_timeSendConnect, nullptr);
            break;
        }

        case SOUTH:
        {
            gettimeofday(&S_timeSendConnect, nullptr);
            break;
        }

        default:
            break;

        }

        char hex_msg[64] = {0, };
        str2hex(hex_msg, msg_s.msg, msg_s.len);
        if(do_print_text) qDebug("Send Connect Check : %s", hex_msg);
    }
    else
        if(do_print_text) qDebug() << "Send Connection Check Error : Not connected Serial Module";
}
void MainWindow::check_connect()
{
    if(startSerial)
    {
        N_waitConnect = true;
        N_countConnect = 0;
        S_waitConnect = true;
        S_countConnect = 0;
        PD_waitConnect = true;
        PD_countConnect = 0;

        send_Serial_Connection_Check(NORTH + 1);
        send_Serial_Connection_Check(SOUTH + 1);
        send_Socket_Connection_Check();
    }
}
void MainWindow::ClassifyingEachSerialMessage()
{
    if(!recv_buf.empty())
    {
        _msg_t msg;
        memcpy(&msg, &recv_buf.front(), sizeof(_msg_t));
        recv_buf.pop();

        switch(msg.msg[2])
        {
        case DANGER_LEVEL_ACK:
        {
            char hex_msg[64] = {0, };
            str2hex(hex_msg, msg.msg, msg.len);
            qDebug("DANGER LEVEL ACK : %s\n", hex_msg);

            check_Dabger_Level_ACK(msg);
            break;
        }

        case CHECK_CONNECTION_ACK:
        {
            char hex_msg[64] = {0, };
            str2hex(hex_msg, msg.msg, msg.len);
            qDebug("CHECK CONNECTION ACK : %s\n", hex_msg);

            check_Serial_CONNECT_ACK(msg);
            break;
        }

        default:
            break;
        }
    }
}
bool MainWindow::check_Dabger_Level_ACK(_msg_t msg)
{
    if(startSerial)
    {
        char msg_4_crc[32] = {0, };

        memcrop(msg.msg, 0, msg.len-2, msg_4_crc);

        if(check_CRC16(msg_4_crc))
        {
            switch(msg.msg[3] - 1)
            {
            case NORTH:
            {
                if(msg.msg[4] == ACK)
                {
                    N_waitDanger = false;
                    N_countstatusDanger = 0;
                    return true;
                }
                else
                {
                    usleep(10000);

                    send_danger_level(NORTH + 1, lastDanger);
                }
                break;
            }

            case SOUTH:
            {
                if(msg.msg[4] == ACK)
                {
                    S_waitDanger = false;
                    S_countstatusDanger = 0;
                    return true;
                }
                else
                {
                    usleep(10000);

                    send_danger_level(SOUTH + 1, lastDanger);
                }
                break;
            }

            default:
                break;

            }
        }
    }

    return true;
}
bool MainWindow::check_Serial_CONNECT_ACK(_msg_t msg)
{
    if(startSerial)
    {
        char msg_4_crc[32] = {0, };

        memcrop(msg.msg, 0, msg.len-2, msg_4_crc);

        if(check_CRC16(msg_4_crc))
        {
            switch(msg.msg[3] - 1)
            {
            case NORTH:
            {
                if(msg.msg[4] == ACK)
                {
                    N_waitConnect = false;
                    N_countstatusConnect = 0;
                    return true;
                }
                else
                {
                    usleep(10000);

                    send_Serial_Connection_Check(msg.msg[3]);
                }
                break;
            }

            case SOUTH:
            {
                if(msg.msg[4] == ACK)
                {
                    S_waitConnect = false;
                    S_countstatusConnect = 0;
                    return true;
                }
                else
                {
                    usleep(10000);

                    send_Serial_Connection_Check(msg.msg[3]);
                }
                break;
            }

            default:
                break;
            }
        }
    }
    return true;
}
void MainWindow::check_ACK()
{
//    int i;
//    bool check_waiting_danger = false;
//    bool check_waiting_connect = false;
//    for(i=0; i<slave_num; i++)
//    {
//        if(waitDanger[i])
//            check_waiting_danger = true;
//        if(waitConnect[i])
//            check_waiting_connect = true;
//    }
//    if(check_waiting_danger)
//    {
//        QDateTime now_t = QDateTime::currentDateTime();

//        if(timeSendDanger.secsTo(now_t) >= 1)
//        {
//            for(i=0; i<slave_num; i++)
//                if(waitDanger[i])
//                    countDanger[i]++;

//            bool connection_check = false;

//            for(i=0; i<slave_num; i++)
//            {
//                if(countDanger[i]>=RESEND_TIME)
//                {
//                    connection_check = true;
//                    countstatusDanger[i]++;
//                }
//            }

//            if(connection_check)
//            {
//                memset(waitDanger, false, sizeof(bool) * MAX_SLAVE_NUM);
//                memset(countDanger, 0, sizeof(int) * MAX_SLAVE_NUM);
//            }
//            else
//            {
//                for(int i=1; i<=slave_num; i++)
//                {
//                    if(waitDanger[i-1])
//                    {
//                        Send_danger_level(i, lastDanger);
//                    }
//                }
//                timeSendDanger = QDateTime::currentDateTime();
//            }
//        }
//    }
//    else
//    {
//        memset(waitDanger, false, sizeof(bool) * MAX_SLAVE_NUM);
//        memset(countDanger, 0, sizeof(int) * MAX_SLAVE_NUM);
//    }

//    if(check_waiting_connect)
//    {
//        QDateTime now_t = QDateTime::currentDateTime();

//        if(timeSendConnect.secsTo(now_t) >= 1)
//        {
//            for(i=0; i<slave_num; i++)
//                if(waitConnect[i])
//                    countConnect[i]++;

//            bool connection_check = false;

//            for(i=0; i<slave_num; i++)
//            {
//                if(countConnect[i]>=RESEND_TIME)
//                {
//                    connection_check = true;
//                    countstatusConnect[i]++;
//                }
//            }

//            if(connection_check)
//            {
//                memset(waitConnect, false, sizeof(bool) * MAX_SLAVE_NUM);
//                memset(countConnect, 0, sizeof(int) * MAX_SLAVE_NUM);
//            }
//            else
//            {
//                for(int i=1; i<=slave_num; i++)
//                    if(waitConnect[i-1])
//                        Send_Connection_Check(i);

//                timeSendConnect = QDateTime::currentDateTime();
//            }
//        }
//    }
//    else
//    {
//        memset(waitConnect, false, sizeof(bool) * MAX_SLAVE_NUM);
//        memset(countConnect, 0, sizeof(int) * MAX_SLAVE_NUM);
//    }
//    bool connect_fail = false;
//    for(i=0; i<slave_num; i++)
//        if((countstatusDanger[i] + countstatusConnect[i]) >= 10)
//            connect_fail = true;

//    if(connect_fail)
//        ui->RFConnection->setStyleSheet("background-color: rgb(255, 255, 0);");
//    else
//        ui->RFConnection->setStyleSheet("background-color: rgb(0, 255, 0);");
}

bool MainWindow::check_CRC16(char* msg)
{
    char data[32] = {0, };
    char data_4_crc[32] = {0, };
    char crc_data[3] = {0, };
    int len = msg[1];
    memcpy(data, msg, len+1);
    memcrop(data, 0, len-2, data_4_crc);

    unsigned short crc = calCRC((unsigned char*)data_4_crc, len-1);
    memcrop(data, len-1, len, crc_data);

    char crc_high = crc>>8;
    char crc_low = crc & 0xFF;
    //qDebug("%X %X", crc_high, crc_low);

    if((crc_high == crc_data[0]) && (crc_low == crc_data[1]))
        return true;

    return false;
}
void MainWindow::memcrop(char* in_buff, int s, int e, char* out_buff)
{
    memcpy(out_buff, in_buff+s, e-s+1);
    out_buff[e-s + 1] = '\0';
    return;
}
int MainWindow::hex2dec(char* buff, int s, int e)
{
    char tbuff[10];
    int i, oval;
    for(i=0; i<(e - s + 1); i++)
        tbuff[i] = buff[s + i];
    tbuff[i] = '\0';
    sscanf(tbuff, "%x", &oval);
    return oval;
}
void MainWindow::str2hex(char* buff, char* data, int size)
{
    memset(buff, 0, 64);
    char hexbuff[4] = {0, };
    for(int i=0; i<size; i++)
    {
        char2hex(hexbuff, data[i]);
        buff[(i * 3) + 0] = hexbuff[0];
        buff[(i * 3) + 1] = hexbuff[1];
        buff[(i * 3) + 2] = hexbuff[2];
    }
}
void MainWindow::char2hex(char* out_buff, char in_buff)
{
    sprintf(out_buff, "%02X ", (unsigned char)in_buff);
}

std::tuple<int, int> MainWindow::checkDangerRadar()
{
    float min_dist = 1000;
    bool N_danger = false;
    bool N_in_ROI = false;
    int N_danger_level = NO_CAR;
    bool S_danger = false;
    bool S_in_ROI = false;
    int S_danger_level = NO_CAR;

    int i;
    for(i=0; i<MAX_OBJ; i++)
    {
        if(N_Radar_Viewer->Obj_data[i].getsize() >= 2)
        {
            Obj_inf last_data = N_Radar_Viewer->Obj_data[i].getLast();

            N_in_ROI = true;
            if(last_data.Distance <= min_dist)
            {
                min_dist = last_data.Distance;
                N_danger = last_data.danger;
            }
        }
    }
    if(N_in_ROI)
    {
        if(N_danger)
            N_danger_level = SAFE_CAR;
        else
            N_danger_level = DANGER_CAR;
    }
    else
        N_danger_level = NO_CAR;

    min_dist = 1000;
    for(i=0; i<MAX_OBJ; i++)
    {
        if(S_Radar_Viewer->Obj_data[i].getsize() >= 2)
        {
            Obj_inf last_data = S_Radar_Viewer->Obj_data[i].getLast();

            S_in_ROI = true;
            if(last_data.Distance <= min_dist)
            {
                min_dist = last_data.Distance;
                S_danger = last_data.danger;
            }
        }
    }
    if(S_in_ROI)
    {
        if(S_danger)
            S_danger_level = SAFE_CAR;
        else
            S_danger_level = DANGER_CAR;
    }
    else
        S_danger_level = NO_CAR;

    return {N_danger_level, S_danger_level};
}

std::tuple<int, int> MainWindow::checkDangerPD()
{
    int E_danger_level = SAFE_PD;
    int W_danger_level = SAFE_PD;

    E_danger_level = E_statusPD;
    W_danger_level = W_statusPD;

    return {E_danger_level, W_danger_level};
}

void MainWindow::check_danger()
{
    auto [N_Radar_danger_level, S_Radar_danger_level] = checkDangerRadar();
    auto [E_PD_danger_level, W_PD_danger_level] = checkDangerPD();

    int danger_level = 7;


    if(check_danger_noise)
    {
        timeval now_t;
        gettimeofday(&now_t, nullptr);

        if((now_t.tv_sec - Danger_time.tv_sec) + ((now_t.tv_usec - Danger_time.tv_usec) / 1000000) >= 3)
        {
            check_danger_noise = false;
            return;
        }
    }/*
    if(lastDanger > danger_level)
    {
        lastDanger = danger_level;

        memset(waitDanger, true, sizeof(bool) * MAX_SLAVE_NUM);
        memset(countDanger, 0, sizeof(int) * MAX_SLAVE_NUM);

        Send_danger_level(0, lastDanger);

        if(log_work)
        {
            if(startRadarThread && startSerial)
            {
                bool header = false;
                if(last_save_danger.date().day() != global_time.date().day())
                {
                    last_save_danger = global_time;
                    log_danger_PATH = log_DIR + "/Danger/" + last_save_danger.toString("yyyy-MM-dd-HH-mm-ss-zzz") + ".csv";
                    header = true;
                }
                QFile file(log_danger_PATH);
                file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                QTextStream out(&file);

                if(header)
                    out << "시간, Radar Status,PD Status, Danger Level\n";

                QDateTime now = global_time;
                out << global_time.toString("yyyy/MM/dd hh:mm:ss.zzz") << ",";
                switch(radar_status)
                {
                case NO_CAR:
                    out << "EMPTY" << ",";
                    break;

                case SAFE_CAR:
                    out << "SAFE" << ",";
                    break;

                case DANGER_CAR:
                    out << "DANGER" << ",";
                    break;
                }
                switch(pd_status)
                {
                case SAFE_PD:
                    out << "SAFE" << ",";
                    break;

                case DANGER_PD:
                    out << "DANGER" << ",";
                    break;
                }
                out << lastDanger << "\n";

                file.close();
            }
        }
        check_danger_noise = false;
    }
    else if(lastDanger < danger_level)
    {
        if(!check_danger_noise) Danger_time = QDateTime::currentDateTime();
        check_danger_noise = true;
    }*/
}
void MainWindow::N_flicker_display()
{
    if(N_display_ON)
    {
        QPixmap DisplayImg(currentPATH + "/img/Display_OFF.png");
        N_Display_Status->setPixmap(DisplayImg);
        N_Display_Status->setScaledContents(true);
    }
    else
    {
        QPixmap DisplayImg(currentPATH + "/img/Display_ON.png");
        N_Display_Status->setPixmap(DisplayImg);
        N_Display_Status->setScaledContents(true);
    }
    N_display_ON = !N_display_ON;
}
void MainWindow::S_flicker_display()
{
    if(S_display_ON)
    {
        QPixmap DisplayImg(currentPATH + "/img/Display_OFF.png");
        S_Display_Status->setPixmap(DisplayImg);
        S_Display_Status->setScaledContents(true);
    }
    else
    {
        QPixmap DisplayImg(currentPATH + "/img/Display_ON.png");
        S_Display_Status->setPixmap(DisplayImg);
        S_Display_Status->setScaledContents(true);
    }
    S_display_ON = !S_display_ON;
}

void MainWindow::on_Settingbtn_clicked()
{
    if(page->currentIndex() == 0)
    {
        page->setCurrentIndex(1);
        Settingbtn->setText("Main");
    }
    else
    {
        page->setCurrentIndex(0);
        Settingbtn->setText("Setting");
    }
}

void MainWindow::on_SaveSetting_btn_clicked()
{
    writeSettings();
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if(N_Radar_Viewer->startRadar)
        Disconnect_Radar();
    if(startCamera)
        Disconnect_Camera();
    if(startSocket)
        Disconnect_Socket();
    if(startSerial)
        Disconnect_Serial();

    exit(0);
}
void MainWindow::resizeEvent(QResizeEvent * event)
{
    Camera_Viewer->setMinimumHeight(int(float(Camera_Viewer->geometry().width()) * cameraRatio));
    Camera_Viewer->setMaximumHeight(int(float(Camera_Viewer->geometry().width()) * cameraRatio));

    E_PD_Status->setMinimumHeight(int(float(E_PD_Status->geometry().width()) * PDRatio));
    E_PD_Status->setMaximumHeight(int(float(E_PD_Status->geometry().width()) * PDRatio));
    W_PD_Status->setMinimumHeight(int(float(W_PD_Status->geometry().width()) * PDRatio));
    W_PD_Status->setMaximumHeight(int(float(W_PD_Status->geometry().width()) * PDRatio));
}
