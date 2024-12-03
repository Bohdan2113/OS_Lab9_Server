/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *topicLineEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_9;
    QTimeEdit *setTimeEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createRoomButton;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QWidget *hamstersPage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QTableWidget *hamstersTableWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *startSessionPushButton;
    QWidget *createIdeaPage;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *timeCreateIdeaLabel;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *EndSessionButton;
    QWidget *voteIdeaPage;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *timeCreateIdeaLabel_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *voteTableWidget;
    QWidget *topIdeaPage;
    QPushButton *homeButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1057, 707);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        homePage = new QWidget();
        homePage->setObjectName("homePage");
        homePage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(homePage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 0, -1, -1);
        label_8 = new QLabel(homePage);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMaximumSize(QSize(50, 50));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.jpg")));
        label_8->setScaledContents(true);

        horizontalLayout->addWidget(label_8);

        label_6 = new QLabel(homePage);
        label_6->setObjectName("label_6");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(330, 80));
        label_6->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        label_6->setFont(font);
        label_6->setAutoFillBackground(false);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"    stop:0 rgba(255, 255, 255, 255), \n"
"    stop:0.8 rgba(192, 192, 192, 255), \n"
"    stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout);

        widget = new QWidget(homePage);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(500, 600));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 95, 70);\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(100, -1, 100, -1);
        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label);

        topicLineEdit = new QLineEdit(widget);
        topicLineEdit->setObjectName("topicLineEdit");
        sizePolicy1.setHeightForWidth(topicLineEdit->sizePolicy().hasHeightForWidth());
        topicLineEdit->setSizePolicy(sizePolicy1);
        topicLineEdit->setMinimumSize(QSize(300, 0));
        QFont font2;
        font2.setPointSize(20);
        topicLineEdit->setFont(font2);
        topicLineEdit->setTabletTracking(false);
        topicLineEdit->setAutoFillBackground(false);
        topicLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(topicLineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_9);

        setTimeEdit = new QTimeEdit(widget);
        setTimeEdit->setObjectName("setTimeEdit");
        sizePolicy.setHeightForWidth(setTimeEdit->sizePolicy().hasHeightForWidth());
        setTimeEdit->setSizePolicy(sizePolicy);
        setTimeEdit->setMinimumSize(QSize(200, 0));
        QFont font3;
        font3.setPointSize(16);
        setTimeEdit->setFont(font3);
        setTimeEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        setTimeEdit->setWrapping(false);
        setTimeEdit->setFrame(true);
        setTimeEdit->setCurrentSection(QDateTimeEdit::Section::MinuteSection);
        setTimeEdit->setTime(QTime(0, 3, 0));

        verticalLayout_3->addWidget(setTimeEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        createRoomButton = new QPushButton(widget);
        createRoomButton->setObjectName("createRoomButton");
        sizePolicy.setHeightForWidth(createRoomButton->sizePolicy().hasHeightForWidth());
        createRoomButton->setSizePolicy(sizePolicy);
        createRoomButton->setMinimumSize(QSize(230, 0));
        createRoomButton->setFont(font1);
        createRoomButton->setCursor(QCursor(Qt::PointingHandCursor));
        createRoomButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(createRoomButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 70, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        verticalLayout_2->addWidget(widget);

        stackedWidget->addWidget(homePage);
        hamstersPage = new QWidget();
        hamstersPage->setObjectName("hamstersPage");
        verticalLayout_4 = new QVBoxLayout(hamstersPage);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(20, 0, -1, -1);
        label_10 = new QLabel(hamstersPage);
        label_10->setObjectName("label_10");
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(50, 50));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.jpg")));
        label_10->setScaledContents(true);

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(hamstersPage);
        label_11->setObjectName("label_11");
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(330, 80));
        label_11->setMaximumSize(QSize(16777215, 80));
        label_11->setFont(font);
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"    stop:0 rgba(255, 255, 255, 255), \n"
"    stop:0.8 rgba(192, 192, 192, 255), \n"
"    stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout_3->addWidget(label_11);


        verticalLayout_4->addLayout(horizontalLayout_3);

        widget_2 = new QWidget(hamstersPage);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 95, 70);"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(label_3);

        hamstersTableWidget = new QTableWidget(widget_2);
        if (hamstersTableWidget->columnCount() < 2)
            hamstersTableWidget->setColumnCount(2);
        if (hamstersTableWidget->rowCount() < 5)
            hamstersTableWidget->setRowCount(5);
        hamstersTableWidget->setObjectName("hamstersTableWidget");
        hamstersTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        hamstersTableWidget->setShowGrid(true);
        hamstersTableWidget->setRowCount(5);
        hamstersTableWidget->setColumnCount(2);

        verticalLayout_5->addWidget(hamstersTableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 60, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        startSessionPushButton = new QPushButton(widget_2);
        startSessionPushButton->setObjectName("startSessionPushButton");
        sizePolicy.setHeightForWidth(startSessionPushButton->sizePolicy().hasHeightForWidth());
        startSessionPushButton->setSizePolicy(sizePolicy);
        startSessionPushButton->setMinimumSize(QSize(230, 0));
        startSessionPushButton->setFont(font1);
        startSessionPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        startSessionPushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(startSessionPushButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(widget_2);

        stackedWidget->addWidget(hamstersPage);
        createIdeaPage = new QWidget();
        createIdeaPage->setObjectName("createIdeaPage");
        verticalLayout_7 = new QVBoxLayout(createIdeaPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(20, 0, -1, -1);
        label_12 = new QLabel(createIdeaPage);
        label_12->setObjectName("label_12");
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMaximumSize(QSize(50, 50));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.jpg")));
        label_12->setScaledContents(true);

        horizontalLayout_5->addWidget(label_12);

        label_13 = new QLabel(createIdeaPage);
        label_13->setObjectName("label_13");
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(330, 80));
        label_13->setMaximumSize(QSize(16777215, 80));
        label_13->setFont(font);
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"    stop:0 rgba(255, 255, 255, 255), \n"
"    stop:0.8 rgba(192, 192, 192, 255), \n"
"    stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout_5->addWidget(label_13);

        timeCreateIdeaLabel = new QLabel(createIdeaPage);
        timeCreateIdeaLabel->setObjectName("timeCreateIdeaLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(timeCreateIdeaLabel->sizePolicy().hasHeightForWidth());
        timeCreateIdeaLabel->setSizePolicy(sizePolicy3);
        timeCreateIdeaLabel->setMinimumSize(QSize(100, 0));
        timeCreateIdeaLabel->setFont(font3);
        timeCreateIdeaLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(timeCreateIdeaLabel);


        verticalLayout_7->addLayout(horizontalLayout_5);

        widget_3 = new QWidget(createIdeaPage);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 95, 70);"));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_6->addWidget(label_2);

        scrollArea = new QScrollArea(widget_3);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1033, 496));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, -1, 60, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        EndSessionButton = new QPushButton(widget_3);
        EndSessionButton->setObjectName("EndSessionButton");
        sizePolicy.setHeightForWidth(EndSessionButton->sizePolicy().hasHeightForWidth());
        EndSessionButton->setSizePolicy(sizePolicy);
        EndSessionButton->setMinimumSize(QSize(230, 0));
        EndSessionButton->setFont(font1);
        EndSessionButton->setCursor(QCursor(Qt::PointingHandCursor));
        EndSessionButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(EndSessionButton);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_7->addWidget(widget_3);

        stackedWidget->addWidget(createIdeaPage);
        voteIdeaPage = new QWidget();
        voteIdeaPage->setObjectName("voteIdeaPage");
        verticalLayout_9 = new QVBoxLayout(voteIdeaPage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(20, 0, -1, -1);
        label_14 = new QLabel(voteIdeaPage);
        label_14->setObjectName("label_14");
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMaximumSize(QSize(50, 50));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.jpg")));
        label_14->setScaledContents(true);

        horizontalLayout_7->addWidget(label_14);

        label_15 = new QLabel(voteIdeaPage);
        label_15->setObjectName("label_15");
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(330, 80));
        label_15->setMaximumSize(QSize(16777215, 80));
        label_15->setFont(font);
        label_15->setAutoFillBackground(false);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"    stop:0 rgba(255, 255, 255, 255), \n"
"    stop:0.8 rgba(192, 192, 192, 255), \n"
"    stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout_7->addWidget(label_15);

        timeCreateIdeaLabel_2 = new QLabel(voteIdeaPage);
        timeCreateIdeaLabel_2->setObjectName("timeCreateIdeaLabel_2");
        sizePolicy3.setHeightForWidth(timeCreateIdeaLabel_2->sizePolicy().hasHeightForWidth());
        timeCreateIdeaLabel_2->setSizePolicy(sizePolicy3);
        timeCreateIdeaLabel_2->setMinimumSize(QSize(100, 0));
        timeCreateIdeaLabel_2->setFont(font3);
        timeCreateIdeaLabel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(timeCreateIdeaLabel_2);


        verticalLayout_9->addLayout(horizontalLayout_7);

        widget_4 = new QWidget(voteIdeaPage);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 95, 70);"));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        voteTableWidget = new QTableWidget(widget_4);
        voteTableWidget->setObjectName("voteTableWidget");
        voteTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(voteTableWidget);


        verticalLayout_9->addWidget(widget_4);

        stackedWidget->addWidget(voteIdeaPage);
        topIdeaPage = new QWidget();
        topIdeaPage->setObjectName("topIdeaPage");
        homeButton = new QPushButton(topIdeaPage);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(760, 530, 211, 45));
        sizePolicy.setHeightForWidth(homeButton->sizePolicy().hasHeightForWidth());
        homeButton->setSizePolicy(sizePolicy);
        homeButton->setMinimumSize(QSize(150, 0));
        homeButton->setFont(font3);
        homeButton->setCursor(QCursor(Qt::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(topIdeaPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 270, 121, 41));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(topIdeaPage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(490, 180, 121, 41));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(topIdeaPage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(680, 360, 121, 41));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(topIdeaPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "  Boardhangsters", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Topic:</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        topicLineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Time:</span></p></body></html>", nullptr));
        setTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        createRoomButton->setText(QCoreApplication::translate("MainWindow", "Create room", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "  Boardhangsters", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>     Participants:</p></body></html>", nullptr));
        startSessionPushButton->setText(QCoreApplication::translate("MainWindow", "Start session", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "  Boardhangsters", nullptr));
        timeCreateIdeaLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ideas:", nullptr));
        EndSessionButton->setText(QCoreApplication::translate("MainWindow", "End session", nullptr));
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "  Boardhangsters", nullptr));
        timeCreateIdeaLabel_2->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        homeButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
