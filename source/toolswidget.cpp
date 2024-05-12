#include "toolswidget.h"
#include "ui_toolswidget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
#include <QJsonParseError>
#include <QXmlStreamReader>
#include "utils.h"
#include <QGraphicsDropShadowEffect>
toolswidget::toolswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊

    ui->widget_left->setGraphicsEffect(effect);
    //QAction *action = new QAction(this);
    //action->setIcon(QIcon(":/lib/soucuo.png").pixmap(QSize(50, 50)));
    //ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
}

toolswidget::toolswidget(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(connectType - 1);
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊

    ui->widget_left->setGraphicsEffect(effect);
}

toolswidget::~toolswidget()
{
    delete ui;
}

// void toolswidget::on_textEdit_json_source_textChanged()
// {
//     ui->textEdit_json_target->clear();
//     utils_parsingJsonInfo(ui->textEdit_json_target, ui->plainTextEdit_json_source->toPlainText());
// }

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

void toolswidget::on_plainTextEdit_json_source_textChanged()
{
    ui->textEdit_json_target->clear();
    utils_parsingJsonInfo(ui->textEdit_json_target, ui->plainTextEdit_json_source->toPlainText());
}
