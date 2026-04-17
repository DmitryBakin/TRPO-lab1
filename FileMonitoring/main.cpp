#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile inputFile("C:/TRPO-lab1-development/FileMonitoring/input.txt");

    QString fileNames;

    if (inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream input(&inputFile);

        fileNames = input.readAll();
    }

    QStringList list = fileNames.split(",");

    FileManager& instance = FileManager::Instance();

    instance.addFiles(list);

    instance.startTimer();

    return a.exec();
}
