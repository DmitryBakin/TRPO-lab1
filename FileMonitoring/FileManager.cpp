#include "FileManager.h"

FileManager::FileManager()
{}

FileManager::FileManager(std::vector<QString> fileNames)
{
    for(int i = 0; i < fileNames.size(); i++)
    {
        m_fileVector.push_back(File(fileNames[0]));
    }
}
