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
    CountdownTimer(int minutes, int seconds, QLabel* label, std::function<void()> callback);
    ~CountdownTimer();

private slots:
    void updateTime();

private:
    void updateDisplay();

    std::function<void()> onCompleteCallback;
    int minutes;
    int seconds;
    QLabel* timeLabel;
    QTimer* timer;
};

#endif // COUNTDOWNTIMER_H
