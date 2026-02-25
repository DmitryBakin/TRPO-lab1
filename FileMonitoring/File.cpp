#include "File.h"
#include <QFileInfo>

File::File() {}

File::File(QString filePath)
{
    QFileInfo fileInfo(filePath);

    m_filePath = filePath;

    m_exists = fileInfo.exists();

    if(m_exists)
        m_size = fileInfo.size();
    else
        m_size = 0;
}

bool File::isChanged()
{
    QFileInfo fileInfo(m_filePath);

    if(fileInfo.exists() == m_exists && fileInfo.size() == m_size)
        return 0;
    else
        return 1;
}

bool File::exists()
{
    return m_exists;
}

int File::size()
{
    return m_size;
}
