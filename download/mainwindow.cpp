#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QNetworkAccessManager>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new DownloadManager;
    QObject::connect(manager, SIGNAL(finished()), this, SLOT(download_finihsed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::download(const QUrl& url)
{ 
    manager->append(url);
}

void MainWindow::init(const QVariantMap& map)
{
    if(map.contains("msg"))
    {
        this->setWindowTitle(map["msg"].toString());
    }
    if(map.contains("data"))
    {
        QList<QVariant> list = map["data"].toList();
        foreach(QVariant item, list)
        {
            QVariantMap map = item.toMap();
            QString software_addr = map["download_url"].toString();
            QString software_name = map["good_name"].toString();
            ui->comboBox_softlist->addItem(software_name);
            m_download_list.insert(software_name, QUrl(software_addr));

        }
    }

}

void MainWindow::get_json()
{
    QNetworkAccessManager *json_manager = new QNetworkAccessManager(this);
    QObject::connect(json_manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(OnReplyFinshed(QNetworkReply*)));
    QUrl url("http://softmall.gps.67n.com/softlist.json");
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    json_manager->get(request);
}

void MainWindow::download_finihsed()
{
    qDebug("download_finihsed");
}

void MainWindow::OnReplyFinshed(QNetworkReply* reply)
{
    //获取响应的信息，状态码为200表示正常
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(reply->error() == QNetworkReply::NoError && statusCode == 200)
    {
        QByteArray baData = reply->readAll();
        qDebug() << baData;
    }

    reply->deleteLater();
}

void MainWindow::on_pushButton_clicked()
{
    download(m_download_list[ui->comboBox_softlist->currentText()]);
}

