#pragma once

#include <iostream>
#include <ctime>

time_t get_time_from_user() {
    time_t time = 0;
    struct tm timer = *localtime(&time);
    {
        int year = 0;
        while (year < 1000) {
            std::cout << "Enter year (4 digits): ";
            std::cin >> year;
        }
        timer.tm_year = year - 1900;
    }
    {
        int month = 0;
        while (month < 1 || month > 12) {
            std::cout << "Enter month (1-12): ";
            std::cin >> month;
        }
        timer.tm_mon = month + 1;
    }
    {
        int day = 0;
        while (day < 1 || day > 31) {
            std::cout << "Enter day (1-31): ";
            std::cin >> day;
        }
        timer.tm_mday = day;
    }
    {
        int hour = -1;
        while (hour < 0 || hour > 23) {
            std::cout << "Enter hour (0-23): ";
            std::cin >> hour;
        }
        timer.tm_hour = hour;
    }
    {
        int minute = -1;
        while (minute < 0 || minute > 59) {
            std::cout << "Enter minute (0-59): ";
            std::cin >> minute;
        }
        timer.tm_min = minute;
    }
    timer.tm_sec = 0;

    time = timelocal(&timer);

    return time;
}
