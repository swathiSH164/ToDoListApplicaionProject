import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import QtMultimedia 5.15
Button {
    text: "Activate Alarm"
    onClicked: {
        modellist.targetdate();
    }


MediaPlayer {
    id: alarmPlayer
    source: "qrc:/Image/clock-alarm-8761.mp3"
}

Timer {
    id: alarmTimer
    interval: 5000
    running: false

    onTriggered: {
        stopAlarm();
    }
}

property bool isAlarmActivated: false

function startAlarm() {
    if (!isAlarmActivated) {
        console.log("Alarm is active!");
        alarmPlayer.play();
        alarmTimer.running = true;
        isAlarmActivated = true;
    }
}

function stopAlarm() {
    console.log("Alarm stopped!");
    alarmPlayer.stop();
    alarmTimer.running = false;
}

Connections {
    target: modellist

    onAlarmActivated: {
        //startAlarm();
        console.log("Alarm Activated!");
    }
}
}
