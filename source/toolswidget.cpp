#include "toolswidget.h"
#include "ui_toolswidget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
#include <QJsonParseError>
#include <QXmlStreamReader>
toolswidget::toolswidget(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(connectType - 1);
}

toolswidget::~toolswidget()
{
    delete ui;
}

void toolswidget::on_textEdit_json_source_textChanged()
{
    QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(ui->textEdit_json_source->toPlainText().toUtf8(), &error);
        if (error.error == QJsonParseError::NoError && !jsonDoc.isNull()) {
            // 格式化为可读的字符串
            QString formattedJson = jsonDoc.toJson(QJsonDocument::Indented);
            ui->textEdit_json_target->setPlainText(formattedJson);
        }
}

void formatXml(const QString& xmlData) {
    QXmlStreamReader xmlReader(xmlData);
    QString result;
    int indentLevel = 0;

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement) {
            result.append(QString(indentLevel * 4, ' ') + "<" + xmlReader.name().toString());

            QXmlStreamAttributes attributes = xmlReader.attributes();
            for (const QXmlStreamAttribute& attribute : attributes) {
                result.append(" " + attribute.name().toString() + "=\"" + attribute.value().toString() + "\"");
            }

            if (xmlReader.isEndElement() && xmlReader.isWhitespace()) {
                result.append("/>\n");
            } else {
                result.append(">\n");
                indentLevel++;
            }
        } else if (token == QXmlStreamReader::Characters && !xmlReader.isWhitespace()) {
            result.append(QString((indentLevel + 1) * 4, ' ') + xmlReader.text().toString().trimmed() + "\n");
        } else if (token == QXmlStreamReader::EndElement) {
            indentLevel--;
            result.append(QString(indentLevel * 4, ' ') + "</" + xmlReader.name().toString() + ">\n");
        }
    }

    if (xmlReader.hasError()) {
        // 解析XML时发生错误处理
        result.append("XML parsing error: " + xmlReader.errorString() + "\n");
    }

    qDebug().noquote() << result;
}


void toolswidget::on_textEdit_xml_source_textChanged()
{
    //QString xmlData = "<sites><site><name>RUNOOB</name><url>www.runoob.com</url></site></sites>";

    //QXmlStreamReader xmlReader(ui->textEdit_xml_source->toPlainText());
    formatXml(ui->textEdit_xml_source->toPlainText());

}
