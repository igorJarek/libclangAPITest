#include <CodeRenderWindow.h>
#include <SourceCodeBlock.h>
#include <App.h>

#include <QPainter>
#include <QTextDocument>

CodeRenderWindow::CodeRenderWindow(App& app, QWidget *parent) :
    m_app(app), QWidget(parent)
{

}

void CodeRenderWindow::paintEvent(QPaintEvent * /* event */)
{
    QPainter     painter(this);
    QFont        font("arial", 10, 10);
    QFontMetrics fontMetrics(font);

    painter.setFont(font);
    painter.fillRect(QRect(0, 0, 3200, 3200), Qt::black);

    const QVector<QSharedPointer<SourceCodeBlock>>& sourceCodeBlocks = m_app.getSourceCodeBlocks();
    if(sourceCodeBlocks.size())
    {
        for(QSharedPointer<SourceCodeBlock> sourceCodeBlock : sourceCodeBlocks)
        {
            painter.translate(20, 20);
            sourceCodeBlock->draw(painter, fontMetrics);
            break;
        }
    }

    painter.end();
}

void CodeRenderWindow::wheelEvent(QWheelEvent * event)
{
    
}

/*
* QFontMetrics
* QTextDocument
* 
* 
* int id = QFontDatabase::addApplicationFont(":/fonts/monospace.ttf");
QString family = QFontDatabase::applicationFontFamilies(id).at(0);
QFont monospace(family);
*/