#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "downloadmanager.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init(const QVariantMap& map);
    void download(const QUrl& url);

private slots:
    void download_finihsed(void);
    void OnReplyFinshed(QNetworkReply*);

    void on_pushButton_clicked();

private:
    void get_json();

private:
    Ui::MainWindow *ui;

    DownloadManager* manager = nullptr;
    QMap<QString, QUrl> m_download_list;

};
#endif // MAINWINDOW_H
