import QtQml 2.12
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.testtask.CountriesListModel 1.0
import com.testtask.BusinessLogic 1.0

Window {


    property color accentColorLight: "black"
    property color backgroundColorLigth: "white"
    property color foregroundColorLight: "silver"

    property color accentColorDark: "white"
    property color backgroundColorDark: "dimgray"
    property color foregroundColorDark: "black"

    property color accentColor: accentColorLight
    property color backgroundColor: backgroundColorLigth
    property color foregroundColor: foregroundColorLight

    CountriesListModel
    {
        id: countrieModel
        onModelError: {console.log(msg)}
    }
    BusinessLogic
    {
        id: businessLogic
    }

    PopupWindow
    {
        id: popupWindow;
        firstName: businessLogic.firstName
        lastName: businessLogic.lastName
        country: businessLogic.country
        email: businessLogic.email
        password: businessLogic.password
        onSignUpAgain:{ businessLogic.reset()}
    }

    id: signUpWindow
    visible: true
    width: 640
    height: 480
    minimumHeight: 300
    minimumWidth: 200
    maximumHeight: 800
    maximumWidth: 600
    title: qsTr("Sign Upzz")
    color: backgroundColor
    modality: Qt.WindowModal;
    ParallelAnimation
    {
        property color destinationAccent : "black"
        property color destinationForeground : "black"
        property color destinationBackground : "black"

        id: onThemeAnim
        ColorAnimation {
            target: signUpWindow
            properties: "accentColor"
            from: signUpWindow.accentColor
            to: onThemeAnim.destinationAccent
            duration: 200
        }
        ColorAnimation {
            target: signUpWindow
            properties: "foregroundColor"
            from: signUpWindow.foregroundColor
            to: onThemeAnim.destinationForeground
            duration: 200
        }
        ColorAnimation {
            target: signUpWindow
            properties: "backgroundColor"
            from: signUpWindow.backgroundColor
            to: onThemeAnim.destinationBackground
            duration: 200
        }
    }


    Column {
        id: row
        x:0
        y:0
        height: parent.height
        width: parent.width
        leftPadding: 12;
        rightPadding: 12;
        spacing: 10
        Switch {
            id: themeSwitch
            anchors.right: parent.right
            anchors.rightMargin: 12
            onClicked: {
                if (!themeSwitch.checked)
                {
                    onThemeAnim.destinationAccent = accentColorLight
                    onThemeAnim.destinationForeground = foregroundColorLight
                    onThemeAnim.destinationBackground = backgroundColorLigth
                }
                else
                {
                    onThemeAnim.destinationAccent = accentColorDark
                    onThemeAnim.destinationForeground = foregroundColorDark
                    onThemeAnim.destinationBackground = backgroundColorDark
                }
                onThemeAnim.running = true;
            }
        }

        Text {
            id: titleText
            width: 83
            height: 47
            text: qsTr("Sign Up")
            font.pixelSize: 36
            color: accentColor
        }

        Text {
            id: descriptionText
            text: qsTr("Please fill in this form to create an account")
            font.pixelSize: 12
            color: accentColor
        }

        Flow {
            id: firstLatNameFlow
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.left: parent.left
            anchors.leftMargin: 12
            TextField {
                id: firstNameField
                width: (signUpWindow.width > 400)?((signUpWindow.width - row.leftPadding - row.rightPadding) / 2):200
                placeholderText: "FirstName"
                text: businessLogic.firstName
                color: accentColor
                background: Rectangle {color: foregroundColor; border.color: parent.focus?"mediumblue":"gray" }
                onTextEdited: {businessLogic.firstName = text}
            }

            TextField {
                id: lastNameField
                width: firstNameField.width
                placeholderText: "LastName"
                text: businessLogic.lastName
                color: accentColor
                background: Rectangle {color: foregroundColor; border.color: parent.focus?"mediumblue":"gray" }
                onTextEdited: {businessLogic.lastName = text}
            }

        }

        ComboBox {
            id: countryField
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.leftMargin: 12
            model: countrieModel
            textRole: "display"
            editText: businessLogic.country
            anchors.left: parent.left
            background: Rectangle {color: foregroundColor; border.color: parent.focus?"mediumblue":"gray" }
            onActivated: { businessLogic.country = editText;}
        }

        TextField {
            id: emailField
            anchors.left: parent.left
            placeholderText: "Email"
            text: businessLogic.email
            color: businessLogic.emailValid?accentColor:"red"
            anchors.leftMargin: 12
            anchors.right: parent.right
            anchors.rightMargin: 12
            background: Rectangle {color: foregroundColor; border.color: parent.focus?"mediumblue":"gray" }
            onTextEdited: {businessLogic.email = text}
        }

        TextField {
            id: passwordField
            anchors.left: parent.left
            placeholderText: "Password"
            echoMode: "Password"
            text: businessLogic.password
            passwordCharacter: "*"
            color: accentColor
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.leftMargin: 12
            background: Rectangle {color: foregroundColor; border.color: parent.focus?"mediumblue":"gray" }
            onTextEdited: {businessLogic.password = text}
        }

        CheckBox {            
            id: checkBox
            anchors.left: parent.left
            text: qsTr("I accept the Terms of use")
            checked: businessLogic.checkBox
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.leftMargin: 12
            onCheckedChanged: {businessLogic.checkBox = checked}
        }

        Button {
            id: button
            enabled: businessLogic.enabledSignUp
            text: qsTr("Sign Up")
            onClicked: {console.log(businessLogic.firstName);
                        console.log(businessLogic.lastName);
                        console.log(businessLogic.country);
                        console.log(businessLogic.email);
                        console.log(businessLogic.password);
                        popupWindow.show()}
        }
    }
}
