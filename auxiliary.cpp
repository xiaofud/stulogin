#include "auxiliary.h"
#include <QString>
Auxiliary::Auxiliary(){

}


double Auxiliary::setDecimalBit(double number, int bits){
    //  1.234 len = 5 bits = 2 [0, 4) bits = 3 [0, 5)
    if (bits < 0)
        return number;
    QString numStr = QString::number(number);
    int len = numStr.length();
    int dotIndex = numStr.indexOf('.');     // 1
    int deciBits = len - dotIndex - 1;
    if (deciBits <= bits)   // don't need to change
        return number;

    numStr = numStr.mid(0, dotIndex + bits + 1);    // the last char doesn't count
    return numStr.toDouble();
}
