#include "exaccount.h"

ExAccount::ExAccount(){
    toStrFileds();
    toNumFields();
}

ExAccount::ExAccount(const QString &user, const QString &passwd, long st_share, long end_share, double left_at_most, double share_rate, double total_share, double share_flow, double total_fetched, double fetched_flow, double credit_, int valid_) : username(user), password(passwd), startShare(st_share),
    endShare(end_share), leftAtMost(left_at_most), shareRate(share_rate), totalShare(total_share), shareFlow(share_flow), totolFetchedFlow(total_fetched),
    fetchedFlow(fetched_flow), credit(credit_), valid(valid_)
{
    toStrFileds();
    toNumFields();
}

void ExAccount::toStrFileds(){
    strFields.clear();
    strFields << username << password;
}

void ExAccount::toNumFields(){
    numberFields.clear();
    numberFields << startShare << endShare << leftAtMost << shareRate << totalShare << shareFlow << totolFetchedFlow << fetchedFlow << credit << valid;
}

QString addQuotes(const QString &str){
    return "'" + str + "'";
}

QString ExAccount::toInsertStr() const{
    QString insertStatement;
    for(int i = 0 ; i < strFields.size() ; ++i)
        insertStatement += addQuotes( strFields[i] ) + ",";


    for(int i = 0 ; i < numberFields.size() ; ++i){
        if (i != numberFields.size() - 1){
            insertStatement += addQuotes(QString::number(numberFields[i])) + ",";
        }else{
            insertStatement += addQuotes(QString::number(numberFields[i]));
        }
    }

    return insertStatement;

}
