#ifndef CBUSINESSLOGIC_H
#define CBUSINESSLOGIC_H

#include <QObject>
#include <QRegExp>

class CBusinessLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged);
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged);
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged);
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged);
    Q_PROPERTY(bool checkBox READ checkBox WRITE setCheckBox NOTIFY checkBoxChanged);
    Q_PROPERTY(bool enabledSignUp READ enabledSignUp NOTIFY enabledSignUpChanged);
    Q_PROPERTY(bool emailValid READ emailValid WRITE setEmailValid NOTIFY emailValidChanged);

public:
    explicit CBusinessLogic(QObject *parent = nullptr);

    QString firstName();
    QString lastName();
    QString email();
    QString password();
    QString country();
    bool checkBox();
    bool enabledSignUp();
    bool emailValid();

    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setEmail(QString email);
    void setPassword(QString passwrod);
    void setCountry(QString countryCode);
    void setCheckBox(bool checkbox);
    void setEmailValid(bool emailValid);

    void checkEmail();

private:
    QString _firstName;
    QString _lastName;
    QString _email;
    QString _password;
    QString _country;
    bool _checkbox;

    bool _enabledSignUp;
    bool _emailValid;

signals:
    void firstNameChanged();
    void lastNameChanged();
    void emailChanged();
    void countryChanged();
    void checkBoxChanged();
    void enabledSignUpChanged();
    void emailValidChanged();
    void passwordChanged();

    void resetSignUp();

public slots:
    void checkCorrectly();
    void reset();
};

#endif // CBUSINESSLOGIC_H
