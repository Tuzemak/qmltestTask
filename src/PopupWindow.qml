import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: popupWindow
    property string firstName: ""
    property string lastName: ""
    property string country: ""
    property string email: ""
    property string password: ""

    signal signUpAgain

    modality: Qt.WindowModal;

    Column
    {
        Text
        {
            text: "First name:" + firstName
        }
        Text
        {
            text: "Last name:" + lastName
        }
        Text
        {
            text: "Country:" + country
        }
        Text
        {
            text: "Email:" + email
        }
        Text
        {
            text: "Password:" + firstName
        }
        Row
        {
            spacing: 10
            Button {
                id: signUpAgainButton
                text: qsTr("Sign Up Again")
                onClicked: {signUpAgain(); popupWindow.close()}
            }
            Button {
                id: closeButton
                text: qsTr("Close")
                onClicked: {popupWindow.close()}
            }
        }
    }
}
