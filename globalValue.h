#ifndef GLOBALVALUE_H
#define GLOBALVALUE_H

#include<QString>

class staticVal
{
public:
    staticVal();

    static void setAccount(const QString &value);
    static QString getAccount();

    static void setPassword(const QString& value);
    static QString getPassword();

private:
    static QString Account;
    static QString Password;
};

#endif // GLOBALVALUE_H
