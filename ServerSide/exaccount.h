#ifndef EXACCOUNT_H
#define EXACCOUNT_H
#include <QString>

class ExAccount{
    // make this fileds public on purpose
public:
    ExAccount();
    QString username;
    QString password;
    QString startShare;     // the start point when the user's willing to share
    QString endShare;       // the end point when the user refuse to share
    double leftAtMost;      // because left flow can't be more than this
    double shareRate;       // the share rate determines whether the user can still fetch shared flow
    double totalShare;      // record of the amount flow the user has shared
    double shareFlow;       // amount of flow the user want to share during a specific time
    double totolFetchedFlow;    // the amount of total flow the user has fetched so far
    double fetchedFlow;         // fetched how much this time
    double credit;              // like login as others but force to close the application
    bool valid;                 // is the password (still) match the username
};

#endif // EXACCOUNT_H
