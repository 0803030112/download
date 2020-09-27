#include "getjson.h"
#include <QJsonParseError>

GetJson::GetJson()
{
    get_json();
}

void GetJson::get_json()
{
    QNetworkAccessManager *json_manager = new QNetworkAccessManager;
    QObject::connect(json_manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(OnReplyFinshed(QNetworkReply*)));
    QUrl url("http://softmall.gps.67n.com/softlist.json");
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    json_manager->get(request);
}

void GetJson::OnReplyFinshed(QNetworkReply* reply)
{
    QByteArray baData;
    //获取响应的信息，状态码为200表示正常
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(reply->error() == QNetworkReply::NoError && statusCode == 200)
    {
        baData = reply->readAll();
    }

    reply->deleteLater();

    agrument_process(baData);
}

void GetJson::agrument_process(const QByteArray& json)
{
    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(json, &error);

    if(QJsonParseError::NoError == error.error)
    {
        //map
        QVariantMap map = document.toVariant().toMap();

        m_main_window = new MainWindow();
        m_main_window->init(map);
        m_main_window->show();

    }
}
