#ifndef EXACCOUNT_H
#define EXACCOUNT_H
#include <QString>
#include <QList>
#include <QStringList>

const double INITIAL_CREDIT = 100;

//QString ServerWidget::FIELDS = "(username, password, start_time, end_time, left_at_most, share_rate, total_share, share_this_time, total_fetch, "
//                               "fetch_this_time, credit, valid)";

class ExAccount{
    // make this fileds public on purpose
public:
    ExAccount();
    ExAccount(const QString &user, const QString &passwd,
              long st_share = 0, long end_share=0, double left_at_most=0, double share_rate=0, double total_share=0,
              double share_flow=0, double total_fetched=0, double fetched_flow=0, double credit_=INITIAL_CREDIT, int valid=1);
    QString toInsertStr() const ;

    QString username;
    QString password;
    long startShare;     // the start point when the user's willing to share
    long endShare;       // the end point when the user refuse to share
    double leftAtMost;      // because left flow can't be more than this
    double shareRate;       // the share rate determines whether the user can still fetch shared flow
    double totalShare;      // record of the amount flow the user has shared
    double shareFlow;       // amount of flow the user want to share during a specific time
    double totolFetchedFlow;    // the amount of total flow the user has fetched so far
    double fetchedFlow;         // fetched how much this time
    double credit;              // like login as others but force to close the application
    int valid;                 // is the password (still) match the username
    QList<QString> strFields;
    QList<double> numberFields;


private:
    void toStrFileds() ;
    void toNumFields() ;




};

#endif // EXACCOUNT_H
