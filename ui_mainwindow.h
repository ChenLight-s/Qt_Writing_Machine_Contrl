/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionwriter;
    QAction *actioncarve;
    QAction *actionjiandanhuitu;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QTextEdit *recvTextEdit;
    QLabel *label_2;
    QTextEdit *sendTextEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *clearButton;
    QPushButton *clearSend;
    QPushButton *sendButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *portNameBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QComboBox *baudrateBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *dataBitsBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *ParityBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *stopBitsBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *searchButton;
    QPushButton *openButton;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *bujinshezhi;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QTextEdit *Contrl_Step;
    QLabel *label_10;
    QTextEdit *Run_Speed;
    QGroupBox *bujinshezhi_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Yup;
    QHBoxLayout *horizontalLayout;
    QPushButton *Xdown;
    QPushButton *Xup;
    QPushButton *Ydown;
    QVBoxLayout *verticalLayout;
    QPushButton *Set_Origin_Button;
    QPushButton *To_Origin_Button;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *Contrl_Step_luobi;
    QPushButton *luobi;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *Contrl_Step_luobi_2;
    QPushButton *luobi_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1202, 918);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAnimated(true);
        actionwriter = new QAction(MainWindow);
        actionwriter->setObjectName(QString::fromUtf8("actionwriter"));
        actioncarve = new QAction(MainWindow);
        actioncarve->setObjectName(QString::fromUtf8("actioncarve"));
        actionjiandanhuitu = new QAction(MainWindow);
        actionjiandanhuitu->setObjectName(QString::fromUtf8("actionjiandanhuitu"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);

        recvTextEdit = new QTextEdit(centralWidget);
        recvTextEdit->setObjectName(QString::fromUtf8("recvTextEdit"));

        verticalLayout_6->addWidget(recvTextEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        sendTextEdit = new QTextEdit(centralWidget);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));

        verticalLayout_6->addWidget(sendTextEdit);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(0, 39));

        horizontalLayout_9->addWidget(clearButton);

        clearSend = new QPushButton(centralWidget);
        clearSend->setObjectName(QString::fromUtf8("clearSend"));
        clearSend->setMinimumSize(QSize(0, 39));

        horizontalLayout_9->addWidget(clearSend);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMinimumSize(QSize(0, 39));

        horizontalLayout_9->addWidget(sendButton);


        verticalLayout_6->addLayout(horizontalLayout_9);


        gridLayout_5->addLayout(verticalLayout_6, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 592));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_3);

        portNameBox = new QComboBox(scrollAreaWidgetContents);
        portNameBox->setObjectName(QString::fromUtf8("portNameBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(portNameBox->sizePolicy().hasHeightForWidth());
        portNameBox->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(portNameBox);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_4);

        baudrateBox = new QComboBox(scrollAreaWidgetContents);
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));
        sizePolicy2.setHeightForWidth(baudrateBox->sizePolicy().hasHeightForWidth());
        baudrateBox->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(baudrateBox);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_5);

        dataBitsBox = new QComboBox(scrollAreaWidgetContents);
        dataBitsBox->addItem(QString());
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));
        sizePolicy2.setHeightForWidth(dataBitsBox->sizePolicy().hasHeightForWidth());
        dataBitsBox->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(dataBitsBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_6);

        ParityBox = new QComboBox(scrollAreaWidgetContents);
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));
        sizePolicy2.setHeightForWidth(ParityBox->sizePolicy().hasHeightForWidth());
        ParityBox->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(ParityBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_7);

        stopBitsBox = new QComboBox(scrollAreaWidgetContents);
        stopBitsBox->addItem(QString());
        stopBitsBox->addItem(QString());
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));
        sizePolicy2.setHeightForWidth(stopBitsBox->sizePolicy().hasHeightForWidth());
        stopBitsBox->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(stopBitsBox);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        searchButton = new QPushButton(scrollAreaWidgetContents);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        sizePolicy2.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy2);
        searchButton->setMinimumSize(QSize(0, 39));

        horizontalLayout_3->addWidget(searchButton);

        openButton = new QPushButton(scrollAreaWidgetContents);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        sizePolicy2.setHeightForWidth(openButton->sizePolicy().hasHeightForWidth());
        openButton->setSizePolicy(sizePolicy2);
        openButton->setMinimumSize(QSize(0, 39));

        horizontalLayout_3->addWidget(openButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        bujinshezhi = new QGroupBox(centralWidget);
        bujinshezhi->setObjectName(QString::fromUtf8("bujinshezhi"));
        bujinshezhi->setEnabled(true);
        sizePolicy2.setHeightForWidth(bujinshezhi->sizePolicy().hasHeightForWidth());
        bujinshezhi->setSizePolicy(sizePolicy2);
        bujinshezhi->setMinimumSize(QSize(111, 141));
        gridLayout = new QGridLayout(bujinshezhi);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(bujinshezhi);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_9);

        Contrl_Step = new QTextEdit(bujinshezhi);
        Contrl_Step->setObjectName(QString::fromUtf8("Contrl_Step"));
        sizePolicy2.setHeightForWidth(Contrl_Step->sizePolicy().hasHeightForWidth());
        Contrl_Step->setSizePolicy(sizePolicy2);
        Contrl_Step->setMinimumSize(QSize(50, 30));

        verticalLayout_3->addWidget(Contrl_Step);

        label_10 = new QLabel(bujinshezhi);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_10);

        Run_Speed = new QTextEdit(bujinshezhi);
        Run_Speed->setObjectName(QString::fromUtf8("Run_Speed"));
        sizePolicy2.setHeightForWidth(Run_Speed->sizePolicy().hasHeightForWidth());
        Run_Speed->setSizePolicy(sizePolicy2);
        Run_Speed->setMinimumSize(QSize(50, 30));

        verticalLayout_3->addWidget(Run_Speed);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_12->addWidget(bujinshezhi);

        bujinshezhi_2 = new QGroupBox(centralWidget);
        bujinshezhi_2->setObjectName(QString::fromUtf8("bujinshezhi_2"));
        sizePolicy2.setHeightForWidth(bujinshezhi_2->sizePolicy().hasHeightForWidth());
        bujinshezhi_2->setSizePolicy(sizePolicy2);
        bujinshezhi_2->setMinimumSize(QSize(111, 141));
        gridLayout_2 = new QGridLayout(bujinshezhi_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Yup = new QPushButton(bujinshezhi_2);
        Yup->setObjectName(QString::fromUtf8("Yup"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Yup->sizePolicy().hasHeightForWidth());
        Yup->setSizePolicy(sizePolicy3);
        Yup->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(Yup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Xdown = new QPushButton(bujinshezhi_2);
        Xdown->setObjectName(QString::fromUtf8("Xdown"));
        Xdown->setMinimumSize(QSize(0, 39));

        horizontalLayout->addWidget(Xdown);

        Xup = new QPushButton(bujinshezhi_2);
        Xup->setObjectName(QString::fromUtf8("Xup"));
        Xup->setMinimumSize(QSize(0, 39));

        horizontalLayout->addWidget(Xup);


        verticalLayout_2->addLayout(horizontalLayout);

        Ydown = new QPushButton(bujinshezhi_2);
        Ydown->setObjectName(QString::fromUtf8("Ydown"));
        Ydown->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(Ydown);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Set_Origin_Button = new QPushButton(bujinshezhi_2);
        Set_Origin_Button->setObjectName(QString::fromUtf8("Set_Origin_Button"));
        sizePolicy2.setHeightForWidth(Set_Origin_Button->sizePolicy().hasHeightForWidth());
        Set_Origin_Button->setSizePolicy(sizePolicy2);
        Set_Origin_Button->setMinimumSize(QSize(135, 39));

        verticalLayout->addWidget(Set_Origin_Button);

        To_Origin_Button = new QPushButton(bujinshezhi_2);
        To_Origin_Button->setObjectName(QString::fromUtf8("To_Origin_Button"));
        sizePolicy2.setHeightForWidth(To_Origin_Button->sizePolicy().hasHeightForWidth());
        To_Origin_Button->setSizePolicy(sizePolicy2);
        To_Origin_Button->setMinimumSize(QSize(135, 39));

        verticalLayout->addWidget(To_Origin_Button);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        Contrl_Step_luobi = new QTextEdit(bujinshezhi_2);
        Contrl_Step_luobi->setObjectName(QString::fromUtf8("Contrl_Step_luobi"));
        sizePolicy2.setHeightForWidth(Contrl_Step_luobi->sizePolicy().hasHeightForWidth());
        Contrl_Step_luobi->setSizePolicy(sizePolicy2);
        Contrl_Step_luobi->setMinimumSize(QSize(45, 30));

        horizontalLayout_10->addWidget(Contrl_Step_luobi);

        luobi = new QPushButton(bujinshezhi_2);
        luobi->setObjectName(QString::fromUtf8("luobi"));
        sizePolicy2.setHeightForWidth(luobi->sizePolicy().hasHeightForWidth());
        luobi->setSizePolicy(sizePolicy2);
        luobi->setMinimumSize(QSize(0, 30));

        horizontalLayout_10->addWidget(luobi);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        Contrl_Step_luobi_2 = new QTextEdit(bujinshezhi_2);
        Contrl_Step_luobi_2->setObjectName(QString::fromUtf8("Contrl_Step_luobi_2"));
        sizePolicy2.setHeightForWidth(Contrl_Step_luobi_2->sizePolicy().hasHeightForWidth());
        Contrl_Step_luobi_2->setSizePolicy(sizePolicy2);
        Contrl_Step_luobi_2->setMinimumSize(QSize(50, 30));

        horizontalLayout_11->addWidget(Contrl_Step_luobi_2);

        luobi_2 = new QPushButton(bujinshezhi_2);
        luobi_2->setObjectName(QString::fromUtf8("luobi_2"));
        sizePolicy2.setHeightForWidth(luobi_2->sizePolicy().hasHeightForWidth());
        luobi_2->setSizePolicy(sizePolicy2);
        luobi_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_11->addWidget(luobi_2);


        verticalLayout_7->addLayout(horizontalLayout_11);


        verticalLayout->addLayout(verticalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        horizontalLayout_12->addWidget(bujinshezhi_2);


        gridLayout_5->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionwriter);
        menu->addAction(actioncarve);
        menu_2->addAction(actionjiandanhuitu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\275\257\344\273\266", nullptr));
        actionwriter->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\255\227\346\234\272", nullptr));
        actionwriter->setIconText(QCoreApplication::translate("MainWindow", "\345\206\231\345\255\227\346\234\272", nullptr));
        actioncarve->setText(QCoreApplication::translate("MainWindow", "\351\233\225\345\210\273\346\234\272", nullptr));
        actionjiandanhuitu->setText(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225\347\273\230\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        clearSend->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        baudrateBox->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        baudrateBox->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        baudrateBox->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        baudrateBox->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudrateBox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        dataBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        ParityBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stopBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopBitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        bujinshezhi->setTitle(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#000000;\">\346\255\245\350\277\233\350\267\235\347\246\273</span></p></body></html>", nullptr));
        Contrl_Step->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.0</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">\350\241\214\350\277\233\351\200\237\345\272\246</span></p></body></html>", nullptr));
        Run_Speed->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1000.0</p></body></html>", nullptr));
        bujinshezhi_2->setTitle(QString());
        Yup->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        Xdown->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        Xup->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        Ydown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        Set_Origin_Button->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\216\237\347\202\271", nullptr));
        To_Origin_Button->setText(QCoreApplication::translate("MainWindow", "\345\233\236\345\275\222\345\216\237\347\202\271", nullptr));
        Contrl_Step_luobi->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.0</p></body></html>", nullptr));
        luobi->setText(QCoreApplication::translate("MainWindow", "\350\220\275\347\254\224", nullptr));
        Contrl_Step_luobi_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.0</p></body></html>", nullptr));
        luobi_2->setText(QCoreApplication::translate("MainWindow", "\350\220\275\347\254\224", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225\345\233\276\345\275\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
