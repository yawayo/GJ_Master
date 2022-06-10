#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSpacerItem>
#include <QTableView>
#include <QComboBox>
#include <QCheckBox>

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>
#include <QNetworkRequest>

#include <QMessageBox>

#include <QSettings>

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include <QDialog>
#include <QSlider>
#include <QFormLayout>

#include <QApplication>

#include <QTimer>
#include <QPixmap>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QSettings>
#include <QRect>

#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#include <cody_Msg_Format.h>
#include <drawradarinfo.h>

#include <HCNetSDK.h>

#include <socketclass.h>
#include <serialclass.h>

#define N_OF_RADAR 2
#define NORTH 0
#define SOUTH 1

#define KEEP_SEC 3

class MainWindow : public QMainWindow
{
    Q_OBJECT

    // main Layout
    QVBoxLayout* main_layout;


    // Button & Logo
    QHBoxLayout* button_layout;

    QGroupBox* radarGroup;
    QPushButton* Connectbtn_Radar;
    QPushButton* Disconnectbtn_Radar;

    QGroupBox* cameraGroup;
    QPushButton* Connectbtn_Camera;
    QPushButton* Disconnectbtn_Camera;

    QGroupBox* socketGroup;
    QPushButton* Connectbtn_Socket;
    QPushButton* Disconnectbtn_Socket;

    QGroupBox* serialGroup;
    QPushButton* Connectbtn_Serial;
    QPushButton* Disconnectbtn_Serial;

    QGroupBox* settingGroup;
    QPushButton* Settingbtn;

    QSpacerItem* button_layout_spacer;

    QLabel* Logo;


    // Main Panel
    QStackedWidget* page;


    // Main page
    QWidget* main_page;
    QHBoxLayout* main_page_layout;


    // Show North Info
    QVBoxLayout* main_page_layout1;
    QTableView* N_Radar_Table;
    DrawRadarInfo* N_Radar_Viewer;
    QHBoxLayout* main_page_layout1_1;
    QLabel* N_Display_Status;


    // Show Camera & Show PD Info
    QVBoxLayout* main_page_layout2;
    QLabel* E_PD_Status;

    QVBoxLayout* main_page_layout2_1;
    QVideoWidget* Camera_Viewer;
    QHBoxLayout* main_page_layout2_1_1;
    QSpacerItem* main_page_layout2_1_1_spacer;
    QVBoxLayout* main_page_layout2_1_1_1;
    QVBoxLayout* main_page_layout2_1_1_2;
    QVBoxLayout* main_page_layout2_1_1_3;
    QPushButton* move_UP;
    QPushButton* move_DOWN;
    QPushButton* move_LEFT;
    QPushButton* move_RIGHT;

    QLabel* W_PD_Status;
    float PDRatio = 294.0 / 440.0;
    float cameraRatio = 1080.0 / 1920.0;



    // Show South Info
    QVBoxLayout* main_page_layout3;
    QHBoxLayout* main_page_layout3_1;
    QLabel* S_Display_Status;
    DrawRadarInfo* S_Radar_Viewer;
    QTableView* S_Radar_Table;


    // Radar Setting page
    QWidget* radarSetting_page;
    QHBoxLayout* radarSetting_page_layout;

    // Radar Setting
    QVBoxLayout* radarSetting_layout;

    QHBoxLayout* radar_title_layout;
    QLabel* radar_title;
    QSpacerItem* radar_title_spacer;
    QPushButton* writebtn_radarSetting;

    QHBoxLayout* radarSetting_value_layout;

    QVBoxLayout* read_radarSetting_layout;

    QHBoxLayout* read_NVMReadStatus_layout;
    QHBoxLayout* read_NVMWriteStatus_layout;
    QHBoxLayout* read_MaxDistanceCfg_layout;
    QHBoxLayout* read_PersistentError_layout;
    QHBoxLayout* read_Interference_layout;
    QHBoxLayout* read_TemperatureError_layout;
    QHBoxLayout* read_TemporaryError_layout;
    QHBoxLayout* read_VoltageError_layout;
    QHBoxLayout* read_SensorID_layout;
    QHBoxLayout* read_SortIndex_layout;
    QHBoxLayout* read_RadarPowerCfg_layout;
    QHBoxLayout* read_CtrlRelayCfg_layout;
    QHBoxLayout* read_OutputTypeCfg_layout;
    QHBoxLayout* read_SendQualityCfg_layout;
    QHBoxLayout* read_SendExtInfoCfg_layout;
    QHBoxLayout* read_MotionRxState_layout;
    QHBoxLayout* read_RCSThreshold_layout;
    QHBoxLayout* read_InvalidClusters_layout;

    QLabel* read_NVMReadStatus_label;
    QLabel* read_NVMWriteStatus_label;
    QLabel* read_MaxDistanceCfg_label;
    QLabel* read_PersistentError_label;
    QLabel* read_Interference_label;
    QLabel* read_TemperatureError_label;
    QLabel* read_TemporaryError_label;
    QLabel* read_VoltageError_label;
    QLabel* read_SensorID_label;
    QLabel* read_SortIndex_label;
    QLabel* read_RadarPowerCfg_label;
    QLabel* read_CtrlRelayCfg_label;
    QLabel* read_OutputTypeCfg_label;
    QLabel* read_SendQualityCfg_label;
    QLabel* read_SendExtInfoCfg_label;
    QLabel* read_MotionRxState_label;
    QLabel* read_RCSThreshold_label;
    QLabel* read_InvalidClusters_label;

    QLabel* read_NVMReadStatus_value;
    QLabel* read_NVMWriteStatus_value;
    QLabel* read_MaxDistanceCfg_value;
    QLabel* read_PersistentError_value;
    QLabel* read_Interference_value;
    QLabel* read_TemperatureError_value;
    QLabel* read_TemporaryError_value;
    QLabel* read_VoltageError_value;
    QLabel* read_SensorID_value;
    QLabel* read_SortIndex_value;
    QLabel* read_RadarPowerCfg_value;
    QLabel* read_CtrlRelayCfg_value;
    QLabel* read_OutputTypeCfg_value;
    QLabel* read_SendQualityCfg_value;
    QLabel* read_SendExtInfoCfg_value;
    QLabel* read_MotionRxState_value;
    QLabel* read_RCSThreshold_value;
    QLabel* read_InvalidClusters_value;

    QVBoxLayout* write_radarSetting_layout;

    QHBoxLayout* write_MaxDistance_layout;
    QHBoxLayout* write_SensorID_layout;
    QHBoxLayout* write_OutputType_layout;
    QHBoxLayout* write_RadarPower_layout;
    QHBoxLayout* write_CtrlRelay_layout;
    QHBoxLayout* write_SendQuality_layout;
    QHBoxLayout* write_SendExtInfo_layout;
    QHBoxLayout* write_SortIndex_layout;
    QHBoxLayout* write_StoreInNVM_layout;
    QHBoxLayout* write_RCSThreshold_layout;
    QHBoxLayout* write_InvalidClusters_layout;

    QCheckBox* write_MaxDistance_label;
    QCheckBox* write_SensorID_label;
    QCheckBox* write_OutputType_label;
    QCheckBox* write_RadarPower_label;
    QCheckBox* write_CtrlRelay_label;
    QCheckBox* write_SendQuality_label;
    QCheckBox* write_SendExtInfo_label;
    QCheckBox* write_SortIndex_label;
    QCheckBox* write_StoreInNVM_label;
    QCheckBox* write_RCSThreshold_label;
    QCheckBox* write_InvalidClusters_label;

    QLineEdit* write_MaxDistance_value;
    QComboBox* write_SensorID_value;
    QComboBox* write_OutputType_value;
    QComboBox* write_RadarPower_value;
    QComboBox* write_CtrlRelay_value;
    QComboBox* write_SendQuality_value;
    QComboBox* write_SendExtInfo_value;
    QComboBox* write_SortIndex_value;
    QComboBox* write_StoreInNVM_value;
    QComboBox* write_RCSThreshold_value;
    QComboBox* write_InvalidClusters_value;


    // Filter Setting
    QVBoxLayout* filterSetting_layout;

    QHBoxLayout* filter_title_layout;
    QLabel* filter_title;
    QSpacerItem* filter_title_spacer;
    QPushButton* writebtn_filterSetting;

    QHBoxLayout* filterSetting_value_layout;

    QVBoxLayout* read_filterSetting_layout;

    QHBoxLayout* read_MinMax_layout;
    QHBoxLayout* read_NofObj_layout;
    QHBoxLayout* read_Distance_layout;
    QHBoxLayout* read_Azimuth_layout;
    QHBoxLayout* read_VrelOncome_layout;
    QHBoxLayout* read_VrelDepart_layout;
    QHBoxLayout* read_RCS_layout;
    QHBoxLayout* read_Lifetime_layout;
    QHBoxLayout* read_Size_layout;
    QHBoxLayout* read_ProbExists_layout;
    QHBoxLayout* read_Y_layout;
    QHBoxLayout* read_X_layout;
    QHBoxLayout* read_VYRightLeft_layout;
    QHBoxLayout* read_VXOncome_layout;
    QHBoxLayout* read_VYLeftRight_layout;
    QHBoxLayout* read_VXDepart_layout;

    QLabel* read_Empty_label;
    QLabel* read_Min_label;
    QLabel* read_Max_label;

    QLabel* read_NofObj_label;
    QLabel* read_Distance_label;
    QLabel* read_Azimuth_label;
    QLabel* read_VrelOncome_label;
    QLabel* read_VrelDepart_label;
    QLabel* read_RCS_label;
    QLabel* read_Lifetime_label;
    QLabel* read_Size_label;
    QLabel* read_ProbExists_label;
    QLabel* read_Y_label;
    QLabel* read_X_label;
    QLabel* read_VYRightLeft_label;
    QLabel* read_VXOncome_label;
    QLabel* read_VYLeftRight_label;
    QLabel* read_VXDepart_label;

    QLabel* read_NofObj_min;
    QLabel* read_Distance_min;
    QLabel* read_Azimuth_min;
    QLabel* read_VrelOncome_min;
    QLabel* read_VrelDepart_min;
    QLabel* read_RCS_min;
    QLabel* read_Lifetime_min;
    QLabel* read_Size_min;
    QLabel* read_ProbExists_min;
    QLabel* read_Y_min;
    QLabel* read_X_min;
    QLabel* read_VYRightLeft_min;
    QLabel* read_VXOncome_min;
    QLabel* read_VYLeftRight_min;
    QLabel* read_VXDepart_min;

    QLabel* read_NofObj_max;
    QLabel* read_Distance_max;
    QLabel* read_Azimuth_max;
    QLabel* read_VrelOncome_max;
    QLabel* read_VrelDepart_max;
    QLabel* read_RCS_max;
    QLabel* read_Lifetime_max;
    QLabel* read_Size_max;
    QLabel* read_ProbExists_max;
    QLabel* read_Y_max;
    QLabel* read_X_max;
    QLabel* read_VYRightLeft_max;
    QLabel* read_VXOncome_max;
    QLabel* read_VYLeftRight_max;
    QLabel* read_VXDepart_max;

    QVBoxLayout* write_filterSetting_layout;

    QHBoxLayout* write_MinMaxActive_layout;
    QHBoxLayout* write_NofObj_layout;
    QHBoxLayout* write_Distance_layout;
    QHBoxLayout* write_Azimuth_layout;
    QHBoxLayout* write_VrelOncome_layout;
    QHBoxLayout* write_VrelDepart_layout;
    QHBoxLayout* write_RCS_layout;
    QHBoxLayout* write_Lifetime_layout;
    QHBoxLayout* write_Size_layout;
    QHBoxLayout* write_ProbExists_layout;
    QHBoxLayout* write_Y_layout;
    QHBoxLayout* write_X_layout;
    QHBoxLayout* write_VYRightLeft_layout;
    QHBoxLayout* write_VXOncome_layout;
    QHBoxLayout* write_VYLeftRight_layout;
    QHBoxLayout* write_VXDepart_layout;

    QLabel* write_Empty_label;
    QLabel* write_Min_label;
    QLabel* write_Max_label;
    QLabel* write_Active_label;

    QCheckBox* write_NofObj_valid;
    QCheckBox* write_Distance_valid;
    QCheckBox* write_Azimuth_valid;
    QCheckBox* write_VrelOncome_valid;
    QCheckBox* write_VrelDepart_valid;
    QCheckBox* write_RCS_valid;
    QCheckBox* write_Lifetime_valid;
    QCheckBox* write_Size_valid;
    QCheckBox* write_ProbExists_valid;
    QCheckBox* write_Y_valid;
    QCheckBox* write_X_valid;
    QCheckBox* write_VYRightLeft_valid;
    QCheckBox* write_VXOncome_valid;
    QCheckBox* write_VYLeftRight_valid;
    QCheckBox* write_VXDepart_valid;

    QLineEdit* write_NofObj_min;
    QLineEdit* write_Distance_min;
    QLineEdit* write_Azimuth_min;
    QLineEdit* write_VrelOncome_min;
    QLineEdit* write_VrelDepart_min;
    QLineEdit* write_RCS_min;
    QLineEdit* write_Lifetime_min;
    QLineEdit* write_Size_min;
    QComboBox* write_ProbExists_min;
    QLineEdit* write_Y_min;
    QLineEdit* write_X_min;
    QLineEdit* write_VYRightLeft_min;
    QLineEdit* write_VXOncome_min;
    QLineEdit* write_VYLeftRight_min;
    QLineEdit* write_VXDepart_min;

    QLineEdit* write_NofObj_max;
    QLineEdit* write_Distance_max;
    QLineEdit* write_Azimuth_max;
    QLineEdit* write_VrelOncome_max;
    QLineEdit* write_VrelDepart_max;
    QLineEdit* write_RCS_max;
    QLineEdit* write_Lifetime_max;
    QLineEdit* write_Size_max;
    QComboBox* write_ProbExists_max;
    QLineEdit* write_Y_max;
    QLineEdit* write_X_max;
    QLineEdit* write_VYRightLeft_max;
    QLineEdit* write_VXOncome_max;
    QLineEdit* write_VYLeftRight_max;
    QLineEdit* write_VXDepart_max;

    QCheckBox* write_NofObj_active;
    QCheckBox* write_Distance_active;
    QCheckBox* write_Azimuth_active;
    QCheckBox* write_VrelOncome_active;
    QCheckBox* write_VrelDepart_active;
    QCheckBox* write_RCS_active;
    QCheckBox* write_Lifetime_active;
    QCheckBox* write_Size_active;
    QCheckBox* write_ProbExists_active;
    QCheckBox* write_Y_active;
    QCheckBox* write_X_active;
    QCheckBox* write_VYRightLeft_active;
    QCheckBox* write_VXOncome_active;
    QCheckBox* write_VYLeftRight_active;
    QCheckBox* write_VXDepart_active;


    // Show Status Bar
    QHBoxLayout* statusBar_layout;
    QLabel* realTime;
    QSpacerItem* statusBar_layout_spacer;
    QHBoxLayout* status_layout;
    QLabel* N_Radar_Status;
    QLabel* S_Radar_Status;
    QLabel* E_Camera_Status;
    QLabel* W_Camera_Status;
    QLabel* N_Serial_Status;
    QLabel* S_Serial_Status;


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createUI();

    QSettings m_settings;
    void writeSettings();
    void readSettings();

    QTimer* timer;
    SYSTEMTIME global_time;
    QString currentPATH;

    void initValue();
    void read_Setting_ini(QString path);
    void storage_make_empty();


    //Radar Parameter
    // - PCAN Parameter

    // - Radar Thread Parameter
    pthread_t thread_radar[N_OF_RADAR];

    // - Kalman Parameter
    const float A[16] = {1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1};
    const float H[8] = {1, 0, 0, 0,
                        0, 1, 0, 0};


    //Radar Function
    // - Init Radar Parameter Function
    bool InitializeValue_Radar();
    bool read_CarLane_ini(QString N_path, QString S_path);

    // - Radar Connection Function
    bool Connect_Radar();
    bool Disconnect_Radar();

    // - Radar Thread Function
    static void* N_callreadCANMessageFunc(void *func);
    static void* S_callreadCANMessageFunc(void *func);
    void readCANMessage(int Way);

    // - Msg Function
    void ClassifyingEachCANMessage(TPCANMsg msg);

    void Set_Obj_A(TPCANMsg msg);
    void Set_Obj_B(TPCANMsg msg);
    void Set_Obj_C(TPCANMsg msg);
    void Set_Obj_D(TPCANMsg msg);

    void Set_RadarCfg(TPCANMsg msg);
    void Set_FilterCfg(TPCANMsg msg);

    void Set_NofObj();
    void Set_Distance();
    void Set_Azimuth();
    void Set_VrelOncome();
    void Set_VrelDepart();
    void Set_RCS();
    void Set_Lifetime();
    void Set_Size();
    void Set_ProbExists();
    void Set_Y();
    void Set_X();
    void Set_VYRightLeft();
    void Set_VXOncome();
    void Set_VYLeftRight();
    void Set_VXDepart();


    //Camera Parameter
    // - Camera Parameter
    QString cameraIP;
    QString cameraPort;
    QString cameraID;
    QString cameraPW;

    LONG UserID;

    NET_DVR_PREVIEWINFO structPlayInfo = {0, };
    LONG RealPlayHandle;

    QMediaPlayer *player;
    QNetworkRequest requestRtsp;

    bool startCamera;

    //Camera Function
    // - Init Camera Parameter Function
    bool InitializeValue_Camera();

    // - Camera Connection Function
    bool Connect_Camera();
    bool Disconnect_Camera();


    //Serial Parameter
    // - Serial Parameter
    bool startSocket;

    SocketClass m_Socket;


    // - Init Socket Parameter Function
    bool InitializeValue_Socket();

    // - Socket Connection Function
    bool Connect_Socket();
    bool Disconnect_Socket();


    //Serial Parameter
    // - Serial Parameter
    bool startSerial;

    SerialClass m_Serial;


    // - Init Socket Parameter Function
    bool InitializeValue_Serial();

    // - Socket Connection Function
    bool Connect_Serial();
    bool Disconnect_Serial();


    //Test
    // - Test
    bool do_print_text;
    bool do_kalman;
    bool do_print_table;

    // - Log
    bool log_work = false;
    QString log_DIR;
    QString log_obj_PATH;
    QString log_traffic_PATH;
    void make_log_path();
    SYSTEMTIME last_save_obj;
    SYSTEMTIME last_save_traffic;



protected:
    virtual void closeEvent(QCloseEvent*);
    virtual void resizeEvent(QResizeEvent*);

private slots:

    void readTime();

    void on_Connectbtn_Radar_clicked();
    void on_Disconnectbtn_Radar_clicked();

    void on_Connectbtn_Camera_clicked();
    void on_Disconnectbtn_Camera_clicked();

    void on_Connectbtn_Socket_clicked();
    void on_Disconnectbtn_Socket_clicked();

    void on_Connectbtn_Serial_clicked();
    void on_Disconnectbtn_Serial_clicked();

    void on_Settingbtn_clicked();

    void on_SaveSetting_btn_clicked();

    void on_moveUP_pressed();
    void on_moveUP_released();
    void on_moveDOWN_pressed();
    void on_moveDOWN_released();
    void on_moveLEFT_pressed();
    void on_moveLEFT_released();
    void on_moveRIGHT_pressed();
    void on_moveRIGHT_released();


};

#endif // MAINWINDOW_H
