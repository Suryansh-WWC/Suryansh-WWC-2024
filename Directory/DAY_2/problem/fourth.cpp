#include <iostream>
#include <string>
#include <thread>
#include <chrono>

struct Task {
    int id;
    int priority;
    int executionTime;
    int period;
    Task* next;

    Task(int id, int priority, int executionTime, int period = 0)
        : id(id), priority(priority), executionTime(executionTime), period(period), next(nullptr) {}
};

class TaskScheduler {
    Task* head;

public:
    TaskScheduler() : head(nullptr) {}

    void insertTask(int id, int priority, int executionTime, int period = 0) {
        Task* newTask = new Task(id, priority, executionTime, period);
        if (!head || priority > head->priority) {
            newTask->next = head;
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next && temp->next->priority >= priority)
                temp = temp->next;
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }

    void executeTasks() {
        while (head) {
            Task* current = head;
            head = head->next;
            std::cout << "Executing Task ID: " << current->id << " with priority: " << current->priority << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(current->executionTime));

            if (current->period > 0) {
                insertTask(current->id, current->priority, current->executionTime, current->period);
                std::this_thread::sleep_for(std::chrono::seconds(current->period));
            } else {
                delete current;
            }
        }
    }

    void displayTasks() {
        Task* temp = head;
        std::cout << "Current Task Queue:\n";
        while (temp) {
            std::cout << "Task ID: " << temp->id << ", Priority: " << temp->priority << ", Execution Time: " << temp->executionTime << std::endl;
            temp = temp->next;
        }
    }

    ~TaskScheduler() {
        while (head) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.insertTask(1, 3, 2);
    scheduler.insertTask(2, 1, 1);
    scheduler.insertTask(3, 2, 3, 5);
    scheduler.insertTask(4, 4, 2);

    scheduler.displayTasks();

    std::thread executionThread(&TaskScheduler::executeTasks, &scheduler);
    executionThread.join();

    scheduler.displayTasks();

    return 0;
}
