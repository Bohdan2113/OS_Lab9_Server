#include "countdowntimer.h"

CountdownTimer::CountdownTimer(int minutes, int seconds, QLabel* label, QWidget* nextPage, QStackedWidget* stackedWidget)
    : minutes(minutes), seconds(seconds), timeLabel(label), nextPage(nextPage), stackedWidget(stackedWidget)
{
    // Ініціалізація таймера
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CountdownTimer::updateTime);
    timer->start(1000); // Таймер працює кожну секунду

    updateDisplay();
}

CountdownTimer::~CountdownTimer()
{
    delete timer; // Звільняємо таймер
    timer = nullptr;
}

void CountdownTimer::updateTime() {
    if (seconds == 0) {
        if (minutes == 0) {
            timer->stop(); // Зупиняємо таймер
            delete timer; // Звільняємо таймер
            timer = nullptr;
            stackedWidget->setCurrentWidget(nextPage);
            return;
        } else {
            minutes--;
            seconds = 59;
        }
    } else {
        seconds--;
    }
    updateDisplay();
}

void CountdownTimer::updateDisplay() {
    timeLabel->setText(QString("%1:%2")
                           .arg(minutes, 2, 10, QChar('0'))
                           .arg(seconds, 2, 10, QChar('0')));
}
