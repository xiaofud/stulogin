#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class Account{
public:
    Account(const QString &user, const QString &passwd);
    QString username;
    QString password;
    double leftFlowMax;     // becuase the value can't be more than this
    bool valid;             // determine whether the passwd is correct
    bool hasBeenUsed;
};

#endif // ACCOUNT_H
