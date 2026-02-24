#include "File.h"
#include <QFileInfo>

File::File() {}

File::File(QString fileName)
{
    QFileInfo fileInfo(fileName);

    m_exists = fileInfo.exists();

    if(m_exists)
        m_size = fileInfo.size();
    else
        m_size = 0;

}


bool File::exists()
{
    return m_exists;
}

qint64 File::size()
{
    return m_size;
}
