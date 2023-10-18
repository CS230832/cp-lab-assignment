#include <iostream>
#include <string>
#include "mytime.hpp"
#include "task.hpp"
#include "manager.hpp"

const char* operations = "Operations:\tadd - to add a new task;\n\tremove - to remove a task;\n\tset - to set task status;\n\tall - to see all tasks;\n\tquit - to exit the application.\n";

int main() {
    TaskManager manager{};

    std::string op{};

    while (true) {
        std::cout << operations << "Enter operation: ";
        std::cin >> op;

        if (op == "quit")
            break;
        else if (op == "add")
            manager.add_task(Task::get_from_user());
        else if (op == "remove") {
            unsigned int index = 0;
            while (index > manager.get_tasks().size()) {
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
            }
            manager.remove_task(index);
        } else if (op == "set") {
            unsigned int index = 0;
            std::string status{};
            do {
                std::cout << "Enter task index to set the status: ";
                std::cin >> index;
            }
            while (index >= manager.get_tasks().size());
             
            while (status != "completed" && status != "incomplete") {
                std::cout << "Please enter either completed or incomplete: ";
                std::cin >> status;
            }
            if (status == "completed")
                manager.set_task_status(index, TaskStatus::completed);
            else
                manager.set_task_status(index, TaskStatus::incomplete);
        } else if (op == "all") {
            auto tasks = manager.get_tasks();
            for (unsigned int i = 0; i < tasks.size(); i++) {
                time_t due_time = tasks[i].get_due_time();
                std::cout << i << " - " << tasks[i].get_description() << "; status: " << tasks[i].get_status() << "; due time: " << asctime(localtime(&due_time));
            }
        } else {
            std::cout << "There is no such operation as '" << op << "';";
        }

        std::cout << std::endl << "----------------------------------------------------------------" << std::endl << std::endl;
    }

    return 0;
}