#include <QObject>


class File
{
public:
    File();
    File(QString fileName);

    bool exists();
    qint64 size();


private:

    bool m_exists = 0;
    qint64 m_size = 0;
};
