#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
    time_t creationTime;
};

struct TaskHistory {
    int taskId;
    string description;
    time_t modificationTime;
};

class TaskManager {
private:
    vector<Task> tasks;
    vector<TaskHistory> taskHistory;
    int taskIdCounter = 1;

public:

    void addTask(const string& description) {
        Task newTask;
        newTask.id = taskIdCounter++;
        newTask.description = description;
        newTask.completed = false;
        newTask.creationTime = time(nullptr);
        tasks.push_back(newTask);

        TaskHistory history;
        history.taskId = newTask.id;
        history.description = "Task added: " + description;
        history.modificationTime = newTask.creationTime;
        taskHistory.push_back(history);

        cout << "Task added successfully!" << endl;
    }

    void editTask(int taskId, const string& newDescription) {
        for (auto& task : tasks) {
            if (task.id == taskId) {

                TaskHistory history;
                history.taskId = taskId;
                history.description = "Task edited: " + task.description + " -> " + newDescription;
                history.modificationTime = time(nullptr);
                taskHistory.push_back(history);

                task.description = newDescription;
                cout << "Task edited successfully!" << endl;
                return;
            }
        }
        cout << "Task not found!" << endl;
    }

    void completeTask(int taskId) {
        for (auto& task : tasks) {
            if (task.id == taskId) {

                TaskHistory history;
                history.taskId = taskId;
                history.description = "Task completed: " + task.description;
                history.modificationTime = time(nullptr);
                taskHistory.push_back(history);

                task.completed = true;
                cout << "Task marked as completed successfully!" << endl;
                return;
            }
        }
        cout << "Task not found!" << endl;
    }

    void displayTasks() {
        cout << "Task List:" << endl;
        for (const auto& task : tasks) {
            cout << "ID: " << task.id << ", Description: " << task.description << ", Completed: " << (task.completed ? "Yes" : "No") << endl;
        }
    }

    void displayTaskHistory() {
        cout << "Task History:" << endl;
        for (const auto& history : taskHistory) {
            cout << "Task ID: " << history.taskId << ", Description: " << history.description << ", Time: " << ctime(&history.modificationTime);
        }
    }
};

int main() {
    TaskManager taskManager;

    taskManager.addTask("Complete project");
    taskManager.addTask("Prepare presentation");

    taskManager.displayTasks();

    taskManager.editTask(1, "Complete project by Friday");
    taskManager.completeTask(2);

    taskManager.displayTasks();

    taskManager.displayTaskHistory();

    return 0;
}
