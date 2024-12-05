#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QApplication>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QTimer>

class CountdownTimer : public QWidget {
    Q_OBJECT

public:
    CountdownTimer(int minutes, int seconds, QLabel* label, QWidget* nextPage, QStackedWidget* stackedWidget);
    ~CountdownTimer();

private slots:
    void updateTime();

private:
    void updateDisplay();

    int minutes;
    int seconds;
    QLabel* timeLabel;
    QTimer* timer;
    QWidget* nextPage;
    QStackedWidget* stackedWidget;
};

#endif // COUNTDOWNTIMER_H
