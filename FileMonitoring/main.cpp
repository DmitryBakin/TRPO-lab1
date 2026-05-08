#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <iostream>

#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer *timer = new QTimer(&a);
    timer->setInterval(100);

    QObject::connect(timer, &QTimer::timeout, &a, []()
     {
        static bool initialStatePrinted = false;

        QString appDir = QCoreApplication::applicationDirPath();

        QDir projectDir(appDir);
        projectDir.cdUp();
        projectDir.cdUp();


        QString filePath = projectDir.absolutePath() + "/input.txt";
        QFile inputFile(filePath);

        if (inputFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&inputFile);
            QString fileNames = stream.readAll();
            inputFile.close();

            QStringList list = fileNames.split(",");
            FileManager& instance = FileManager::Instance();
            instance.clear();
            instance.addFiles(list);
        }
        FileManager& instance = FileManager::Instance();
        QVector<QFileInfo> currStates = instance.getFileVector();

        if(!initialStatePrinted)
        {
            for(int i = 0; i < currStates.size(); i++)
                qDebug() << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
                        << "Path:" << currStates[i].filePath()
                        << "Exists:" << currStates[i].exists()
                        << "Size:" << currStates[i].size();
            initialStatePrinted = true;
        }
    });

    timer->start();

    return a.exec();
}
