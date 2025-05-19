#include "globalValue.h"



QString staticVal::Account = "null";
QString staticVal:: Password= "null";


void staticVal::setAccount(const QString &value) { Account = value; }
void staticVal::setPassword(const QString& value) { Password = value; }


QString staticVal::getAccount() { return Account; }
QString staticVal::getPassword() { return Password; }
