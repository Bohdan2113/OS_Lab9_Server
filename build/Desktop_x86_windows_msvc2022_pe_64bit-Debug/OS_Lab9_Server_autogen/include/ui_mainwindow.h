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
    QHBoxLayout *headerCrIdea;
    QSpacerItem *horizontalSpacer_4;
    QLabel *timerCrIdeaLabel;
    QLabel *timeImgCrIdea;
    QWidget *bodyWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *EndSessionButton;
    QWidget *votePage;
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
    QWidget *podiumPage;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_22;
    QLabel *label_22;
    QSpacerItem *verticalSpacer_17;
    QLabel *label_23;
    QLabel *label_24;
    QSpacerItem *verticalSpacer_18;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *verticalLayout_24;
    QSpacerItem *verticalSpacer_19;
    QLabel *label_25;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_25;
    QSpacerItem *verticalSpacer_20;
    QLabel *label_27;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_26;
    QSpacerItem *verticalSpacer_21;
    QLabel *label_29;
    QLabel *label_30;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_14;
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
        homePage->setStyleSheet(QString::fromUtf8("background-image: url(:/image/images/mainPageBackground.png);"));
        verticalLayout_2 = new QVBoxLayout(homePage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(100, 0, 100, 0);
        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_6 = new QLabel(homePage);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/image/images/logo.png);\n"
"\n"
"    font-size: 100px;  "));

        verticalLayout_2->addWidget(label_6);

        label = new QLabel(homePage);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Julius Sans One")});
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));

        verticalLayout_2->addWidget(label);

        topicLineEdit = new QLineEdit(homePage);
        topicLineEdit->setObjectName("topicLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topicLineEdit->sizePolicy().hasHeightForWidth());
        topicLineEdit->setSizePolicy(sizePolicy);
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

        verticalLayout_2->addWidget(topicLineEdit);

        label_9 = new QLabel(homePage);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));

        verticalLayout_2->addWidget(label_9);

        setTimeEdit = new QTimeEdit(homePage);
        setTimeEdit->setObjectName("setTimeEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(setTimeEdit->sizePolicy().hasHeightForWidth());
        setTimeEdit->setSizePolicy(sizePolicy1);
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

        verticalLayout_2->addWidget(setTimeEdit);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        createRoomButton = new QPushButton(homePage);
        createRoomButton->setObjectName("createRoomButton");
        sizePolicy1.setHeightForWidth(createRoomButton->sizePolicy().hasHeightForWidth());
        createRoomButton->setSizePolicy(sizePolicy1);
        createRoomButton->setMinimumSize(QSize(230, 0));
        createRoomButton->setFont(font);
        createRoomButton->setCursor(QCursor(Qt::PointingHandCursor));
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


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 150, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_5);

        stackedWidget->addWidget(homePage);
        hamstersPage = new QWidget();
        hamstersPage->setObjectName("hamstersPage");
        hamstersPage->setStyleSheet(QString::fromUtf8("background-image: url(:/image/images/moneyBackgroung.png);"));
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
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(20, 15, 20, 0);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(16777215, 80));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Julius Sans One")});
        font3.setBold(true);
        font3.setItalic(false);
        label_11->setFont(font3);
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"image: url(:/image/images/logo.png);\n"
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
        horizontalLayout_4->setContentsMargins(-1, 20, 20, 20);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        startSessionPushButton = new QPushButton(widget_2);
        startSessionPushButton->setObjectName("startSessionPushButton");
        sizePolicy1.setHeightForWidth(startSessionPushButton->sizePolicy().hasHeightForWidth());
        startSessionPushButton->setSizePolicy(sizePolicy1);
        startSessionPushButton->setMinimumSize(QSize(230, 0));
        startSessionPushButton->setFont(font);
        startSessionPushButton->setCursor(QCursor(Qt::PointingHandCursor));
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
        createIdeaPage->setStyleSheet(QString::fromUtf8("background-image: url(:/image/images/moneyBackgroung.png);"));
        verticalLayout_7 = new QVBoxLayout(createIdeaPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        headerCrIdea = new QHBoxLayout();
        headerCrIdea->setSpacing(0);
        headerCrIdea->setObjectName("headerCrIdea");
        headerCrIdea->setContentsMargins(0, 20, 20, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerCrIdea->addItem(horizontalSpacer_4);

        timerCrIdeaLabel = new QLabel(createIdeaPage);
        timerCrIdeaLabel->setObjectName("timerCrIdeaLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(timerCrIdeaLabel->sizePolicy().hasHeightForWidth());
        timerCrIdeaLabel->setSizePolicy(sizePolicy2);
        timerCrIdeaLabel->setMinimumSize(QSize(100, 0));
        timerCrIdeaLabel->setFont(font);
        timerCrIdeaLabel->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;"));

        headerCrIdea->addWidget(timerCrIdeaLabel);

        timeImgCrIdea = new QLabel(createIdeaPage);
        timeImgCrIdea->setObjectName("timeImgCrIdea");
        timeImgCrIdea->setMinimumSize(QSize(30, 0));
        timeImgCrIdea->setStyleSheet(QString::fromUtf8("image: url(:/image/images/clock.png);\n"
"background: transparent;\n"
"font-size: 20px;\n"
""));

        headerCrIdea->addWidget(timeImgCrIdea);


        verticalLayout_7->addLayout(headerCrIdea);

        bodyWidget = new QWidget(createIdeaPage);
        bodyWidget->setObjectName("bodyWidget");
        bodyWidget->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        verticalLayout_6 = new QVBoxLayout(bodyWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(20, 0, 20, 0);
        label_2 = new QLabel(bodyWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_2->setMargin(5);

        verticalLayout_6->addWidget(label_2);

        scrollArea = new QScrollArea(bodyWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8); "));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 758, 469));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8); "));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 20, 20, 20);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        EndSessionButton = new QPushButton(bodyWidget);
        EndSessionButton->setObjectName("EndSessionButton");
        sizePolicy1.setHeightForWidth(EndSessionButton->sizePolicy().hasHeightForWidth());
        EndSessionButton->setSizePolicy(sizePolicy1);
        EndSessionButton->setMinimumSize(QSize(230, 0));
        EndSessionButton->setFont(font);
        EndSessionButton->setCursor(QCursor(Qt::PointingHandCursor));
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


        verticalLayout_7->addWidget(bodyWidget);

        stackedWidget->addWidget(createIdeaPage);
        votePage = new QWidget();
        votePage->setObjectName("votePage");
        votePage->setStyleSheet(QString::fromUtf8("background-image: url(:/image/images/moneyBackgroung.png);"));
        verticalLayout_9 = new QVBoxLayout(votePage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 20, 20, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        timeCreateIdeaLabel_2 = new QLabel(votePage);
        timeCreateIdeaLabel_2->setObjectName("timeCreateIdeaLabel_2");
        sizePolicy2.setHeightForWidth(timeCreateIdeaLabel_2->sizePolicy().hasHeightForWidth());
        timeCreateIdeaLabel_2->setSizePolicy(sizePolicy2);
        timeCreateIdeaLabel_2->setMinimumSize(QSize(100, 0));
        timeCreateIdeaLabel_2->setFont(font);
        timeCreateIdeaLabel_2->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
"\n"
""));

        horizontalLayout_7->addWidget(timeCreateIdeaLabel_2);

        label_18 = new QLabel(votePage);
        label_18->setObjectName("label_18");
        label_18->setMinimumSize(QSize(30, 0));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/image/images/clock.png);\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));

        horizontalLayout_7->addWidget(label_18);


        verticalLayout_9->addLayout(horizontalLayout_7);

        widget_4 = new QWidget(votePage);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 50));
        widget_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: transparent;\n"
""));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(20, 0, 20, 0);
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

        verticalSpacer_4 = new QSpacerItem(20, 92, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_9->addWidget(widget_4);

        stackedWidget->addWidget(votePage);
        podiumPage = new QWidget();
        podiumPage->setObjectName("podiumPage");
        podiumPage->setStyleSheet(QString::fromUtf8("background-image: url(:/image/images/moneyBackgroung.png);"));
        verticalLayout_10 = new QVBoxLayout(podiumPage);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalSpacer_22 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_22);

        label_22 = new QLabel(podiumPage);
        label_22->setObjectName("label_22");
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setMinimumSize(QSize(0, 0));
        label_22->setMaximumSize(QSize(16777215, 80));
        label_22->setFont(font3);
        label_22->setAutoFillBackground(false);
        label_22->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"image: url(:/image/images/logo.png);\n"
"font-size: 50px;  \n"
"background: transparent;"));

        verticalLayout_10->addWidget(label_22);

        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_17);

        label_23 = new QLabel(podiumPage);
        label_23->setObjectName("label_23");
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_23->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_23);

        label_24 = new QLabel(podiumPage);
        label_24->setObjectName("label_24");
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 30px;  \n"
"background: transparent;\n"
""));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_24);

        verticalSpacer_18 = new QSpacerItem(20, 2, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_18);

        widget_14 = new QWidget(podiumPage);
        widget_14->setObjectName("widget_14");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_14->sizePolicy().hasHeightForWidth());
        widget_14->setSizePolicy(sizePolicy3);
        widget_14->setMinimumSize(QSize(0, 300));
        widget_14->setStyleSheet(QString::fromUtf8("background: transparent;"));
        horizontalLayout_17 = new QHBoxLayout(widget_14);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_15);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName("verticalLayout_24");
        verticalSpacer_19 = new QSpacerItem(80, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_24->addItem(verticalSpacer_19);

        label_25 = new QLabel(widget_14);
        label_25->setObjectName("label_25");
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMinimumSize(QSize(200, 0));
        label_25->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_25->setWordWrap(true);

        verticalLayout_24->addWidget(label_25);

        label_26 = new QLabel(widget_14);
        label_26->setObjectName("label_26");
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(120, 135));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("image: url(:/image/images/secondPlacePodium.png);"));

        verticalLayout_24->addWidget(label_26);


        horizontalLayout_17->addLayout(verticalLayout_24);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_16);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setObjectName("verticalLayout_25");
        verticalSpacer_20 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_25->addItem(verticalSpacer_20);

        label_27 = new QLabel(widget_14);
        label_27->setObjectName("label_27");
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMinimumSize(QSize(200, 0));
        label_27->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));
        label_27->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_27->setWordWrap(true);

        verticalLayout_25->addWidget(label_27);

        label_28 = new QLabel(widget_14);
        label_28->setObjectName("label_28");
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setMinimumSize(QSize(120, 165));
        label_28->setStyleSheet(QString::fromUtf8("image: url(:/image/images/firstPlacePodium.png);"));

        verticalLayout_25->addWidget(label_28);


        horizontalLayout_17->addLayout(verticalLayout_25);

        horizontalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_17);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName("verticalLayout_26");
        verticalSpacer_21 = new QSpacerItem(80, 110, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_26->addItem(verticalSpacer_21);

        label_29 = new QLabel(widget_14);
        label_29->setObjectName("label_29");
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMinimumSize(QSize(200, 0));
        label_29->setStyleSheet(QString::fromUtf8("font-family: 'Julius Sans One', sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"font-size: 20px;  \n"
"background: transparent;\n"
""));
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_29->setWordWrap(true);

        verticalLayout_26->addWidget(label_29);

        label_30 = new QLabel(widget_14);
        label_30->setObjectName("label_30");
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        label_30->setMinimumSize(QSize(120, 105));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/image/images/thirdPlacePodium.png);\n"
""));

        verticalLayout_26->addWidget(label_30);


        horizontalLayout_17->addLayout(verticalLayout_26);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_18);


        verticalLayout_10->addWidget(widget_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(-1, 20, 20, 20);
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);

        homeButton = new QPushButton(podiumPage);
        homeButton->setObjectName("homeButton");
        sizePolicy1.setHeightForWidth(homeButton->sizePolicy().hasHeightForWidth());
        homeButton->setSizePolicy(sizePolicy1);
        homeButton->setMinimumSize(QSize(150, 0));
        homeButton->setFont(font);
        homeButton->setCursor(QCursor(Qt::PointingHandCursor));
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

        horizontalLayout_15->addWidget(homeButton);


        verticalLayout_10->addLayout(horizontalLayout_15);

        stackedWidget->addWidget(podiumPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


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
        timerCrIdeaLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        timeImgCrIdea->setText(QString());
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
        label_22->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Top 3 ideas:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "How to stay survive?", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "erjteyjety jetyjejet", nullptr));
        label_26->setText(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "dtykfjrtsje\321\203\320\260\320\272\320\277\320\272\320\265\321\200\320\265\320\275\321\200\320\274\320\272\320\260tyjetyj etyjetjyt", nullptr));
        label_28->setText(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "JUICjetj etjertjejrE", nullptr));
        label_30->setText(QString());
        homeButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
