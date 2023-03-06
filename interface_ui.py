# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'interface.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1873, 852)
        MainWindow.setStyleSheet("background-color: rgb(17, 17, 17);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.widget = AnalogueGauageWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(130, 100, 411, 401))
        self.widget.setObjectName("widget")
        self.lcd = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcd.setGeometry(QtCore.QRect(260, 550, 141, 41))
        self.lcd.setObjectName("lcd")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(40, 550, 211, 41))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label.setFont(font)
        self.label.setStyleSheet("background color: rgb(170, 255, 0)")
        self.label.setObjectName("label")
        self.Range3 = QtWidgets.QPushButton(self.centralwidget)
        self.Range3.setGeometry(QtCore.QRect(1390, 200, 131, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.Range3.setFont(font)
        self.Range3.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.Range3.setObjectName("Range3")
        self.Range1 = QtWidgets.QPushButton(self.centralwidget)
        self.Range1.setGeometry(QtCore.QRect(1390, 60, 131, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.Range1.setFont(font)
        self.Range1.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.Range1.setObjectName("Range1")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setGeometry(QtCore.QRect(1200, 200, 141, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(1200, 60, 111, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.Range2 = QtWidgets.QPushButton(self.centralwidget)
        self.Range2.setGeometry(QtCore.QRect(1390, 130, 131, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.Range2.setFont(font)
        self.Range2.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.Range2.setObjectName("Range2")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(1200, 130, 111, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.NCC = QtWidgets.QPushButton(self.centralwidget)
        self.NCC.setGeometry(QtCore.QRect(1670, 600, 161, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.NCC.setFont(font)
        self.NCC.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.NCC.setObjectName("NCC")
        self.accel = QtWidgets.QPushButton(self.centralwidget)
        self.accel.setGeometry(QtCore.QRect(1670, 340, 161, 61))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.accel.setFont(font)
        self.accel.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.accel.setObjectName("accel")
        self.decl = QtWidgets.QPushButton(self.centralwidget)
        self.decl.setGeometry(QtCore.QRect(1670, 430, 161, 61))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.decl.setFont(font)
        self.decl.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.decl.setObjectName("decl")
        self.stop = QtWidgets.QPushButton(self.centralwidget)
        self.stop.setGeometry(QtCore.QRect(1670, 770, 161, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.stop.setFont(font)
        self.stop.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.stop.setObjectName("stop")
        self.CC = QtWidgets.QPushButton(self.centralwidget)
        self.CC.setGeometry(QtCore.QRect(1670, 690, 161, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.CC.setFont(font)
        self.CC.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.CC.setObjectName("CC")
        self.ACC = QtWidgets.QPushButton(self.centralwidget)
        self.ACC.setGeometry(QtCore.QRect(1670, 520, 161, 51))
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.ACC.setFont(font)
        self.ACC.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.ACC.setObjectName("ACC")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(650, 740, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(920, 510, 151, 61))
        self.lineEdit.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.lineEdit.setObjectName("lineEdit")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(650, 620, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(640, 510, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(620, 60, 551, 51))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(920, 610, 151, 61))
        self.lineEdit_2.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(920, 730, 151, 61))
        self.lineEdit_3.setStyleSheet("background:rgb(0, 0, 255);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"color: white")
        self.lineEdit_3.setObjectName("lineEdit_3")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ffffff;\">Current Speed</span></p></body></html>"))
        self.Range3.setText(_translate("MainWindow", "Far"))
        self.Range1.setText(_translate("MainWindow", "Close"))
        self.label_8.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#ffffff;\">90 : 120</span></p></body></html>"))
        self.label_6.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#ffffff;\">30 : 60</span></p></body></html>"))
        self.Range2.setText(_translate("MainWindow", "Medium"))
        self.label_7.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ffffff;\">60 : 90</span></p></body></html>"))
        self.NCC.setText(_translate("MainWindow", "NCC on"))
        self.accel.setText(_translate("MainWindow", "Accelerate"))
        self.decl.setText(_translate("MainWindow", "Decelerate"))
        self.stop.setText(_translate("MainWindow", "Stop"))
        self.CC.setText(_translate("MainWindow", "CC off"))
        self.ACC.setText(_translate("MainWindow", "ACC on"))
        self.label_5.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">CC State</span></p></body></html>"))
        self.label_4.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">CC mode</span></p></body></html>"))
        self.label_3.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Current Distance</span></p></body></html>"))
        self.label_9.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">please select perfered Distance Range in Acc mode:</span></p></body></html>"))
        self.lineEdit_3.setText(_translate("MainWindow", "CC Off"))
from AnalogueGauageWidget import AnalogueGauageWidget
