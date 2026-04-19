#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <iostream>

#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString appDir = QCoreApplication::applicationDirPath();

    QDir projectDir(appDir);
    projectDir.cdUp();
    projectDir.cdUp();
    projectDir.cdUp();

    QString filePath = projectDir.absolutePath() + "/input.txt";

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

    //instance.setOutputMethod(new PrintInfoToOtherFile());

    return a.exec();
}
