#include <QObject>


class File
{
public:
    File();
    File(QString filePath);

    bool isChanged();

    void update();

    QString filePath();
    bool exists();
    int size();



private:

    QString m_filePath;

    bool m_exists = 0;
    int m_size = 0;
};
