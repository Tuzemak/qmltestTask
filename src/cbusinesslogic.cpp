#include "cbusinesslogic.h"

CBusinessLogic::CBusinessLogic(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(firstNameChanged()), this, SLOT(checkCorrectly()));
    connect(this, SIGNAL(countryChanged()), this, SLOT(checkCorrectly()));
    connect(this, SIGNAL(emailChanged()), this, SLOT(checkCorrectly()));
    connect(this, SIGNAL(passwordChanged()), this, SLOT(checkCorrectly()));
    connect(this, SIGNAL(checkBoxChanged()), this, SLOT(checkCorrectly()));
}

QString CBusinessLogic::firstName()
{
    return _firstName;
}

QString CBusinessLogic::lastName()
{
    return _lastName;
}

QString CBusinessLogic::email()
{
    return _email;
}

QString CBusinessLogic::password()
{
    return _password;
}

QString CBusinessLogic::country()
{
    return _country;
}

bool CBusinessLogic::checkBox()
{
    return _checkbox;
}

bool CBusinessLogic::enabledSignUp()
{
    return _enabledSignUp;
}

bool CBusinessLogic::emailValid()
{
    return _emailValid;
}

void CBusinessLogic::setFirstName(QString firstName)
{
    _firstName = firstName;
    emit firstNameChanged();
}

void CBusinessLogic::setLastName(QString lastName)
{
    _lastName = lastName;
    emit lastNameChanged();
}

void CBusinessLogic::setEmail(QString email)
{
    _email = email;
    checkEmail();
    emit emailChanged();
}

void CBusinessLogic::setCountry(QString country)
{
    _country = country;
    emit countryChanged();
}

void CBusinessLogic::setPassword(QString password)
{
    _password = password;
    emit passwordChanged();
}

void CBusinessLogic::setCheckBox(bool checkBox)
{
    _checkbox = checkBox;
    emit checkBoxChanged();
}

void CBusinessLogic::setEmailValid(bool emailValid)
{
    _emailValid = emailValid;
    emit emailValidChanged();
}

void CBusinessLogic::checkEmail()
{
    QRegExp _regExpr("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    setEmailValid(_regExpr.exactMatch(_email));
}

void CBusinessLogic::checkCorrectly()
{
     if (_firstName != QString("") &&
         _email != QString("") &&
         _password != QString("") &&
         _emailValid == true &&
         _checkbox == true )
     {
     _enabledSignUp = true;
     }
     else
     {
     _enabledSignUp = false;
     }
     emit enabledSignUpChanged();
}

void CBusinessLogic::reset()
{
    setFirstName("");
    setLastName("");
    setCountry("");
    setEmail("");
    setPassword("");
    setCheckBox(false);
}
