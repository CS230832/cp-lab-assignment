#pragma once

#include <string>

enum class TaskStatus {
    completed = 0,
    incomplete = 1,
};

class Task {
private:
    std::string description;
    time_t due_time;
    TaskStatus status;
public:
    Task(const char* description, time_t due_time) {
        this->description = description;
        this->due_time = due_time;
        this->status = TaskStatus::incomplete;
    }

    void set_status(TaskStatus status) {
        this->status = status;
    }

    const std::string get_status() {
        switch (this->status) {
        case TaskStatus::completed:
            return "completed";
        case TaskStatus::incomplete:
            return "incomplete";
        default:
            return "should never reaches here!";
        }
    }

    const std::string get_description() {
        return this->description;
    }

    const time_t get_due_time() {
        return this->due_time;
    }

    static Task get_from_user() {
        std::string description{};
        std::cout << "Enter task description: ";
        std::cin >> description;
        std::cin.clear();
        return Task(description.c_str(), get_time_from_user());
    }
};