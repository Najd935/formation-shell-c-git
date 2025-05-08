#ifndef TASK_H
#define TASK_H

#define DESCRIPTION_MAX 100
#define DATE_MAX 11  // format: dd/mm/yyyy

typedef struct {
    int id;
    char description[DESCRIPTION_MAX];
    char date[DATE_MAX];
    int priority;   // from 1 (low) to 3 (high)
    int status;     // 0 = todo, 1 = in progress, 2 = done (example)
} Task;

void add_task(Task** tasks, int* task_count, int* capacity, int* current_id);
void display_tasks(Task* tasks, int task_count);
void delete_task_by_id(Task* tasks, int* task_count, int id_to_delete);


#endif