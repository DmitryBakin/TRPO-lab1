#include "FileManager.h"

FileManager::FileManager()
{
    m_timer = new QTimer();

    connect(m_timer, &QTimer::timeout, this, &FileManager::onTimeout);

    connect(m_outputMethod, &IFileLogs::fileCreated, this, &FileManager::onTimeout);
}

FileManager::~FileManager()
{
    m_timer->stop();
    delete m_timer;

    delete m_outputMethod;
}

void FileManager::setOutputMethod(IFileLogs* outputMethod)
{
    if(outputMethod ==  nullptr)
    {
        return;
    }

    delete m_outputMethod;
    m_outputMethod = outputMethod;
}

void FileManager::addFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
    {
        if(!contains(paths[i]))
            m_fileVector.push_back(QFileInfo(paths[i]));
    }
}

void FileManager::removeFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
        for(int j = 0; j < m_fileVector.size(); j++)
            if(contains(paths[i]))
            {
                m_fileVector.remove(j);
                j--;
            }
}

bool FileManager::contains(QString path) const
{
    for(int j = 0; j < m_fileVector.size(); j++)
        if(m_fileVector[j].filePath() == path)
        {
            return 1;
        }
    return 0;
}

QVector<QFileInfo> FileManager::getFileVector()
{
    return m_fileVector;
}

void FileManager::startTimer()
{
    m_timer->start(100);
}

void FileManager::stopTimer()
{
    m_timer->stop();
}

void FileManager::onTimeout()
{
    for(int i = 0; i < m_fileVector.size(); i++)
    {
        m_fileVector[i].refresh();
    }

    m_outputMethod->print(m_fileVector);
}
