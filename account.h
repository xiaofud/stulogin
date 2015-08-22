#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class Account{
public:
    Account(const QString &user, const QString &passwd);
    QString username;
    QString password;
    bool hasBeenUsed;
};

#endif // ACCOUNT_H
