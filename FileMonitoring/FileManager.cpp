#include "FileManager.h"


void FileManager::addFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
    {
        if(!containts(paths[i]))
            m_fileVector.push_back(File(paths[i]));
    }
}

void FileManager::removeFiles(QStringList paths)
{
    for(int i = 0; i < paths.size(); i++)
        for(int j = 0; j < m_fileVector.size(); j++)
            if(containts(paths[i]))
            {
                m_fileVector.remove(j);
                j--;
            }
}

bool FileManager::containts(QString path)
{
    for(int j = 0; j < m_fileVector.size(); j++)
        if(m_fileVector[j].filePath() == path)
        {
            return 1;
        }
    return 0;
}
