/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *topicLineEdit;
    QLabel *label_9;
    QTimeEdit *setTimeEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createRoomButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *hamstersPage;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLabel *label_3;
    QTableWidget *hamstersTableWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *startSessionPushButton;
    QWidget *createIdeaPage;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *timeCreateIdeaLabel;
    QLabel *label_13;
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
    QSpacerItem *horizontalSpacer_5;
    QLabel *timeCreateIdeaLabel_2;
    QLabel *label_18;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QTableWidget *voteTableWidget;
    QSpacerItem *verticalSpacer_4;
    QWidget *topIdeaPage;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_12;
    QSpacerItem *verticalSpacer;
    QLabel *label_19;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_10;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_15;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_14;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_14;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *homeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 666);
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
        homePage->setStyleSheet(QString::fromUtf8("background-image: url(:/images/mainPageBackground.png);"));
        verticalLayout_2 = new QVBoxLayout(homePage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(homePage);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 600));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(100, 0, 100, 5);
        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/images/logo.png);\n"
"\n"
"    font-size: 100px;  "));

        verticalLayout_3->addWidget(label_6);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Julius Sans One")});
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));

        verticalLayout_3->addWidget(label);

        topicLineEdit = new QLineEdit(widget);
        topicLineEdit->setObjectName("topicLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topicLineEdit->sizePolicy().hasHeightForWidth());
        topicLineEdit->setSizePolicy(sizePolicy1);
        topicLineEdit->setMinimumSize(QSize(300, 0));
        QFont font1;
        font1.setPointSize(20);
        topicLineEdit->setFont(font1);
        topicLineEdit->setTabletTracking(false);
        topicLineEdit->setAutoFillBackground(false);
        topicLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"width: 150px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"height: 50px;  "));

        verticalLayout_3->addWidget(topicLineEdit);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));

        verticalLayout_3->addWidget(label_9);

        setTimeEdit = new QTimeEdit(widget);
        setTimeEdit->setObjectName("setTimeEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(setTimeEdit->sizePolicy().hasHeightForWidth());
        setTimeEdit->setSizePolicy(sizePolicy2);
        setTimeEdit->setMinimumSize(QSize(200, 0));
        QFont font2;
        font2.setPointSize(16);
        setTimeEdit->setFont(font2);
        setTimeEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"width: 100px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;  "));
        setTimeEdit->setWrapping(false);
        setTimeEdit->setFrame(true);
        setTimeEdit->setCurrentSection(QDateTimeEdit::Section::MinuteSection);
        setTimeEdit->setTime(QTime(0, 3, 0));

        verticalLayout_3->addWidget(setTimeEdit);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        createRoomButton = new QPushButton(widget);
        createRoomButton->setObjectName("createRoomButton");
        sizePolicy2.setHeightForWidth(createRoomButton->sizePolicy().hasHeightForWidth());
        createRoomButton->setSizePolicy(sizePolicy2);
        createRoomButton->setMinimumSize(QSize(230, 0));
        createRoomButton->setFont(font);
        createRoomButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        createRoomButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 150px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    border: 1px solid black;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    font-size: 30px;                   /* \320\240\320\276\320\267\320\274\321\226\321\200 \321\210\321\200\320\270\321\204\321\202\321\203 */\n"
"	background: transparent;\n"
" 	background-color: #D9D7D7;         /* \320\232"
                        "\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    width: 150px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    background-color:#EBEBEB  ;         /* \320\232\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"    border: 2px solid white;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    fon"
                        "t-size: 30px;       \n"
"}\n"
""));

        horizontalLayout_2->addWidget(createRoomButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 150, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_5);


        verticalLayout_2->addWidget(widget);

        stackedWidget->addWidget(homePage);
        hamstersPage = new QWidget();
        hamstersPage->setObjectName("hamstersPage");
        hamstersPage->setStyleSheet(QString::fromUtf8("background-image: url(:/images/moneyBackgroung.png);"));
        verticalLayout_4 = new QVBoxLayout(hamstersPage);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(hamstersPage);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"\n"
""));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(20, 20, 20, 20);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(16777215, 80));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Julius Sans One")});
        font3.setBold(true);
        font3.setItalic(false);
        label_11->setFont(font3);
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"image: url(:/images/logo.png);\n"
"font-size: 50px;  \n"
"background: transparent;"));

        verticalLayout_5->addWidget(label_11);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));

        verticalLayout_5->addWidget(label_3);

        hamstersTableWidget = new QTableWidget(widget_2);
        if (hamstersTableWidget->columnCount() < 2)
            hamstersTableWidget->setColumnCount(2);
        if (hamstersTableWidget->rowCount() < 5)
            hamstersTableWidget->setRowCount(5);
        hamstersTableWidget->setObjectName("hamstersTableWidget");
        hamstersTableWidget->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        hamstersTableWidget->setShowGrid(true);
        hamstersTableWidget->setRowCount(5);
        hamstersTableWidget->setColumnCount(2);

        verticalLayout_5->addWidget(hamstersTableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        startSessionPushButton = new QPushButton(widget_2);
        startSessionPushButton->setObjectName("startSessionPushButton");
        sizePolicy2.setHeightForWidth(startSessionPushButton->sizePolicy().hasHeightForWidth());
        startSessionPushButton->setSizePolicy(sizePolicy2);
        startSessionPushButton->setMinimumSize(QSize(230, 0));
        startSessionPushButton->setFont(font);
        startSessionPushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        startSessionPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 105px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    border: 1px solid black;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    font-size: 30px;                   /* \320\240\320\276\320\267\320\274\321\226\321\200 \321\210\321\200\320\270\321\204\321\202\321\203 */\n"
"	background: transparent;\n"
" 	background-color: #D9D7D7;         /* \320\232"
                        "\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    width: 105px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    background-color:#EBEBEB  ;         /* \320\232\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"    border: 2px solid white;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    fon"
                        "t-size: 30px;       \n"
"}\n"
""));

        horizontalLayout_4->addWidget(startSessionPushButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(widget_2);

        stackedWidget->addWidget(hamstersPage);
        createIdeaPage = new QWidget();
        createIdeaPage->setObjectName("createIdeaPage");
        createIdeaPage->setStyleSheet(QString::fromUtf8("background-image: url(:/images/moneyBackgroung.png);"));
        verticalLayout_7 = new QVBoxLayout(createIdeaPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 15);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(20, 20, 15, 10);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        timeCreateIdeaLabel = new QLabel(createIdeaPage);
        timeCreateIdeaLabel->setObjectName("timeCreateIdeaLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(timeCreateIdeaLabel->sizePolicy().hasHeightForWidth());
        timeCreateIdeaLabel->setSizePolicy(sizePolicy3);
        timeCreateIdeaLabel->setMinimumSize(QSize(60, 0));
        timeCreateIdeaLabel->setFont(font);
        timeCreateIdeaLabel->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;"));

        horizontalLayout_5->addWidget(timeCreateIdeaLabel);

        label_13 = new QLabel(createIdeaPage);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(30, 0));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/images/clock.png);\n"
"background: transparent;\n"
"font-size: 20px;\n"
""));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout_7->addLayout(horizontalLayout_5);

        widget_3 = new QWidget(createIdeaPage);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(20, -1, 20, 15);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_2->setMargin(5);

        verticalLayout_6->addWidget(label_2);

        scrollArea = new QScrollArea(widget_3);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8); "));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 758, 459));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8); "));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        EndSessionButton = new QPushButton(widget_3);
        EndSessionButton->setObjectName("EndSessionButton");
        sizePolicy2.setHeightForWidth(EndSessionButton->sizePolicy().hasHeightForWidth());
        EndSessionButton->setSizePolicy(sizePolicy2);
        EndSessionButton->setMinimumSize(QSize(230, 0));
        EndSessionButton->setFont(font);
        EndSessionButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        EndSessionButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        EndSessionButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 105px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    border: 1px solid black;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    font-size: 30px;                   /* \320\240\320\276\320\267\320\274\321\226\321\200 \321\210\321\200\320\270\321\204\321\202\321\203 */\n"
"	background: transparent;\n"
" 	background-color: #D9D7D7;         /* \320\232"
                        "\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    width: 105px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    background-color:#EBEBEB  ;         /* \320\232\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"    border: 2px solid white;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    fon"
                        "t-size: 30px;       \n"
"}\n"
""));

        horizontalLayout_6->addWidget(EndSessionButton);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_7->addWidget(widget_3);

        stackedWidget->addWidget(createIdeaPage);
        voteIdeaPage = new QWidget();
        voteIdeaPage->setObjectName("voteIdeaPage");
        voteIdeaPage->setStyleSheet(QString::fromUtf8("background-image: url(:/images/moneyBackgroung.png);"));
        verticalLayout_9 = new QVBoxLayout(voteIdeaPage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(7, 10, 7, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(11, 15, 15, 11);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        timeCreateIdeaLabel_2 = new QLabel(voteIdeaPage);
        timeCreateIdeaLabel_2->setObjectName("timeCreateIdeaLabel_2");
        sizePolicy3.setHeightForWidth(timeCreateIdeaLabel_2->sizePolicy().hasHeightForWidth());
        timeCreateIdeaLabel_2->setSizePolicy(sizePolicy3);
        timeCreateIdeaLabel_2->setMinimumSize(QSize(100, 0));
        timeCreateIdeaLabel_2->setFont(font);
        timeCreateIdeaLabel_2->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
"\n"
""));

        horizontalLayout_7->addWidget(timeCreateIdeaLabel_2);

        label_18 = new QLabel(voteIdeaPage);
        label_18->setObjectName("label_18");
        label_18->setMinimumSize(QSize(30, 0));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/images/clock.png);\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));

        horizontalLayout_7->addWidget(label_18);


        verticalLayout_9->addLayout(horizontalLayout_7);

        widget_4 = new QWidget(voteIdeaPage);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 50));
        widget_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: transparent;\n"
""));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_16 = new QLabel(widget_4);
        label_16->setObjectName("label_16");
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_16->setMargin(5);

        verticalLayout_8->addWidget(label_16);

        voteTableWidget = new QTableWidget(widget_4);
        if (voteTableWidget->columnCount() < 3)
            voteTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        voteTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        voteTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        voteTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (voteTableWidget->rowCount() < 5)
            voteTableWidget->setRowCount(5);
        voteTableWidget->setObjectName("voteTableWidget");
        voteTableWidget->setFont(font2);
        voteTableWidget->setAutoFillBackground(false);
        voteTableWidget->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"background-color: rgba(255, 255, 255, 0.8); "));
        voteTableWidget->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        voteTableWidget->setRowCount(5);
        voteTableWidget->setColumnCount(3);
        voteTableWidget->horizontalHeader()->setVisible(true);
        voteTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        voteTableWidget->horizontalHeader()->setMinimumSectionSize(60);
        voteTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_8->addWidget(voteTableWidget);

        verticalSpacer_4 = new QSpacerItem(20, 73, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_9->addWidget(widget_4);

        stackedWidget->addWidget(voteIdeaPage);
        topIdeaPage = new QWidget();
        topIdeaPage->setObjectName("topIdeaPage");
        topIdeaPage->setStyleSheet(QString::fromUtf8("background-image: url(:/images/moneyBackgroung.png);"));
        verticalLayout_11 = new QVBoxLayout(topIdeaPage);
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(20, 0, -1, -1);
        widget_7 = new QWidget(topIdeaPage);
        widget_7->setObjectName("widget_7");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy4);
        widget_7->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        verticalLayout_12 = new QVBoxLayout(widget_7);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_12 = new QLabel(widget_7);
        label_12->setObjectName("label_12");
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setMaximumSize(QSize(16777215, 80));
        label_12->setFont(font3);
        label_12->setAutoFillBackground(false);
        label_12->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"image: url(:/images/logo.png);\n"
"font-size: 50px;  \n"
"background: transparent;"));

        verticalLayout_12->addWidget(label_12);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_12->addItem(verticalSpacer);

        label_19 = new QLabel(widget_7);
        label_19->setObjectName("label_19");
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(label_19);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(label_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_6);

        widget_5 = new QWidget(widget_7);
        widget_5->setObjectName("widget_5");
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(0, 300));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalSpacer_7 = new QSpacerItem(80, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_15->addItem(verticalSpacer_7);

        label_10 = new QLabel(widget_5);
        label_10->setObjectName("label_10");
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(200, 0));
        label_10->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_10->setWordWrap(true);

        verticalLayout_15->addWidget(label_10);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(120, 135));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/images/secondPlacePodium.png);"));

        verticalLayout_15->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_15);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_13->addItem(verticalSpacer_8);

        label_15 = new QLabel(widget_5);
        label_15->setObjectName("label_15");
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(200, 0));
        label_15->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15->setWordWrap(true);

        verticalLayout_13->addWidget(label_15);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName("label_7");
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(120, 165));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/images/firstPlacePodium.png);"));

        verticalLayout_13->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_13);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalSpacer_9 = new QSpacerItem(80, 110, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_14->addItem(verticalSpacer_9);

        label_14 = new QLabel(widget_5);
        label_14->setObjectName("label_14");
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(200, 0));
        label_14->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_14->setWordWrap(true);

        verticalLayout_14->addWidget(label_14);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(120, 105));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/images/thirdPlacePodium.png);\n"
""));

        verticalLayout_14->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_12->addWidget(widget_5);


        horizontalLayout_8->addWidget(widget_7);


        verticalLayout_11->addLayout(horizontalLayout_8);

        widget_6 = new QWidget(topIdeaPage);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        verticalLayout_10 = new QVBoxLayout(widget_6);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        homeButton = new QPushButton(widget_6);
        homeButton->setObjectName("homeButton");
        sizePolicy2.setHeightForWidth(homeButton->sizePolicy().hasHeightForWidth());
        homeButton->setSizePolicy(sizePolicy2);
        homeButton->setMinimumSize(QSize(150, 0));
        homeButton->setFont(font);
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 150px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    border: 1px solid black;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    font-size: 30px;                   /* \320\240\320\276\320\267\320\274\321\226\321\200 \321\210\321\200\320\270\321\204\321\202\321\203 */\n"
"	background: transparent;\n"
" 	background-color: #D9D7D7;         /* \320\232"
                        "\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    width: 150px;                      /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    height: 50px;                      /* \320\222\320\270\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    background-color:#EBEBEB  ;         /* \320\232\320\276\320\273\321\226\321\200 \321\204\320\276\320\275\321\203 */\n"
"    border: 2px solid white;           /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\207\320\276\321\200\320\275\320\270\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 */\n"
"    border-radius: 20px;               /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\217 \320\272\321\200\320\260\321\227\320\262 */\n"
"    font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    fon"
                        "t-size: 30px;       \n"
"}\n"
""));

        horizontalLayout_9->addWidget(homeButton);


        verticalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_11->addWidget(widget_6);

        stackedWidget->addWidget(topIdeaPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Topic:</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        topicLineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Time:</span></p></body></html>", nullptr));
        setTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        createRoomButton->setText(QCoreApplication::translate("MainWindow", "Create room", nullptr));
        label_11->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>     Participants:</p></body></html>", nullptr));
        startSessionPushButton->setText(QCoreApplication::translate("MainWindow", "Start session", nullptr));
        timeCreateIdeaLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_13->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Ideas:", nullptr));
        EndSessionButton->setText(QCoreApplication::translate("MainWindow", "End session", nullptr));
        timeCreateIdeaLabel_2->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_18->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Votes:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = voteTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = voteTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Idea", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = voteTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Votes", nullptr));
        label_12->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Top 3 ideas:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "How to stay survive?", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "erjteyjety jetyjejet", nullptr));
        label_5->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "dtykfjrtsje\321\203\320\260\320\272\320\277\320\272\320\265\321\200\320\265\320\275\321\200\320\274\320\272\320\260tyjetyj etyjetjyt", nullptr));
        label_7->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "JUICjetj etjertjejrE", nullptr));
        label_4->setText(QString());
        homeButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
