#include "FileManager.h"

FileManager::FileManager()
    : m_timer(new QTimer()), m_outputMethod(new PrintInfoToConsole())
{
    connect(m_timer, &QTimer::timeout, this, &FileManager::onTimeout);
    connect(this, &FileManager::onFileCreated, m_outputMethod, &IFileLogs::print);
    connect(this, &FileManager::onFileRemoved, m_outputMethod, &IFileLogs::print);
    connect(this, &FileManager::onFileChanged, m_outputMethod, &IFileLogs::print);

    m_timer->start(100);
}
FileManager::~FileManager()
{
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
        m_timer = nullptr;
    }
    delete m_outputMethod;
}

void FileManager::setOutputMethod(IFileLogs* outputMethod)
{
    if(outputMethod == nullptr)
    {
        return;
    }

    disconnect(this, &FileManager::onFileCreated, m_outputMethod, &IFileLogs::print);
    disconnect(this, &FileManager::onFileRemoved, m_outputMethod, &IFileLogs::print);
    disconnect(this, &FileManager::onFileChanged, m_outputMethod, &IFileLogs::print);

    delete m_outputMethod;
    m_outputMethod = outputMethod;

    connect(this, &FileManager::onFileCreated, m_outputMethod, &IFileLogs::print);
    connect(this, &FileManager::onFileRemoved, m_outputMethod, &IFileLogs::print);
    connect(this, &FileManager::onFileChanged, m_outputMethod, &IFileLogs::print);
}

void FileManager::addFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
    {
        QString path = paths[i];
        if(path.isEmpty())
            continue;

        if(!contains(path))
        {
            QFileInfo newFile(path);
            m_fileVector.push_back(newFile);

            QPair<int, bool> currentState(newFile.size(), newFile.exists());
            m_vectorOldStates.push_back(currentState);
        }
    }
}

void FileManager::removeFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
        for(int j = 0; j < m_fileVector.size(); j++)
            if(m_fileVector[j].filePath() == paths[i])
            {
                m_fileVector.remove(j);
                m_vectorOldStates.remove(j);
                j--;
            }
}

bool FileManager::contains(const QString& path) const
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

void FileManager::onTimeout()
{
    for(int i = 0; i < m_fileVector.size(); i++)
    {
        m_fileVector[i].refresh();

        QPair<int, bool> currState(m_fileVector[i].size(), m_fileVector[i].exists());

        if(currState.second == 1 && m_vectorOldStates[i].second == 0)
        {
            m_vectorOldStates[i].second = 1;

            emit onFileCreated(m_fileVector[i]);
        }
        else if(currState.second == 0 && m_vectorOldStates[i].second == 1)
        {
            m_vectorOldStates[i].second = 0;

            emit onFileRemoved(m_fileVector[i]);
        }
        else if(currState.first != m_vectorOldStates[i].first && currState.second == 1)
        {
            m_vectorOldStates[i].first = currState.first;

            emit onFileChanged(m_fileVector[i]);
        }
    }

}
