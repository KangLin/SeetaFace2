#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this->setCentralWidget(&m_Display);
    
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        qDebug() << "Camer name:" << cameraInfo.deviceName();
    }
    
    m_pCamera = new QCamera(QCameraInfo::availableCameras().at(0));
    m_pCamera->setViewfinder(&m_CaptureFrame);
    
    bool check = connect(&m_CaptureFrame, SIGNAL(sigCaptureFrame(const QVideoFrame &)),
                         &m_Display, SLOT(slotDisplay(const QVideoFrame &)));
    Q_ASSERT(check);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStart_triggered()
{
    m_pCamera->start();
}

void MainWindow::on_actionStop_triggered()
{
    m_pCamera->stop();
}
