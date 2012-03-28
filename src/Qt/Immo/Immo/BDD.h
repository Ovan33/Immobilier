#ifndef CONNEXIONSQL_H
#define CONNEXIONSQL_H

#include <QtSql>

class BDD
{
private:
    QSqlDatabase db;

public:
    BDD(QString, QString, QString, QString);
    bool testConnection();

};

#endif // CONNEXIONSQL_H
