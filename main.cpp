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

    QVector<QFileInfo> currStates = instance.getFileVector();

    for(int i = 0; i < currStates.size(); i++)
        qDebug()
            << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
            << " Path:" << currStates[i].filePath()
            << " Exists:" << currStates[i].exists()
            << " Size:" << currStates[i].size();

    //instance.setOutputMethod(new PrintInfoToOtherFile());

    return a.exec();
}
