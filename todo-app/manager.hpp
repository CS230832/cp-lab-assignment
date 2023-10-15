#pragma once

#include <string>
#include <vector>
#include "task.hpp"

class TaskManager {
private:
    std::vector<Task> tasks{};
public:
    TaskManager() {};

    void add_task(Task task) {
        if (tasks.data() == nullptr)
            tasks.push_back(task);
        else {
            unsigned int index = 0;
            while (task.get_due_time() < tasks[index].get_due_time())
                index++;
            tasks.insert(tasks.begin() + index, task);
        } 
    }

    void set_task_status(unsigned int index, TaskStatus status) {
        tasks[index].set_status(status);
    }

    void remove_task(unsigned int index) {
        tasks.erase(tasks.begin() + index);
    }

    const std::vector<Task> get_tasks() {
        return tasks;
    }
};