#ifndef GETJSON_H
#define GETJSON_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "mainwindow.h"

class GetJson: public QObject
{
    Q_OBJECT

public:
    GetJson();

private:
    void get_json();
    void agrument_process(const QByteArray& json);

private slots:
    void OnReplyFinshed(QNetworkReply*);

private:
    QMap<QString, QUrl> m_software_list;
    QString m_window_name;

    MainWindow* m_main_window = nullptr;
};

#endif // GETJSON_H
