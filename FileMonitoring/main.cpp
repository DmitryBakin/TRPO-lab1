#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <iostream>

#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filePath = "C:/TRPO-lab1/FileMonitoring/input.txt";

    QFile inputFile(filePath);

    QString fileNames;

    if (inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream input(&inputFile);

        fileNames = input.readAll();
    }

    QStringList list = fileNames.split(",");

    FileManager& instance = FileManager::Instance();

    instance.addFiles(list);

    return a.exec();
}
