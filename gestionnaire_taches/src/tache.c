#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_task(Task** tasks, int* task_count, int* capacity, int* current_id)
{
    // Local variables for clarity
    int i = *task_count;
    int cap = *capacity;
    int id = *current_id;
    Task *tab = *tasks;

    // Reallocate memory if the current number of tasks reaches capacity
    if (i == cap)
    {
        cap *= 2;
        Task *tmp = realloc(tab, cap * sizeof(Task));
        if (tmp == NULL)
        {
            printf("Couldn't reallocate memory for the task list.\n");
            return;
        }

        tab = tmp;
        *tasks = tab;
        *capacity = cap;
    }

    // Prompt the user for task information
    Task task;
    char desc_input[DESCRIPTION_MAX];
    char date_input[DATE_MAX];
    int priority;
    int status;

    printf("Description of the task?\n");
    fgets(desc_input,DESCRIPTION_MAX,stdin);
    desc_input[strcspn(desc_input,"\n")] = '\0';

    printf("Date?\n");
    fgets(date_input,DATE_MAX,stdin);
    date_input[strcspn(date_input,"\n")] = '\0';

    printf("Priority task? from 1 (low) to 3 (high)\n");
    scanf("%d",&priority);
    getchar();

    printf("Task's status? 0 = todo, 1 = in progress, 2 = done\n");
    scanf("%d",&status);
    getchar();

    task.id = id;
    strcpy(task.description,desc_input);
    strcpy(task.date,date_input);
    task.priority = priority;
    task.status = status;


   tab[i] = task;

   *tasks = tab;
   *current_id = *current_id + 1;
   *task_count = *task_count + 1;

}

void display_tasks(Task* tasks, int task_count)
{

    printf("=== Task List === \n\n");
    for (int i = 0; i < task_count; i++)
    {
        Task task = tasks[i];
        char *priority_str = (task.priority == 1) ? "Low" : (task.priority == 2) ? "Medium" : "High";
        char *status_str = (task.status == 0) ? "To do" : (task.status == 1) ? "In progress..." : "Done";

        printf("Id : %d\n",task.id);
        printf("Description : %s\n",task.description);
        printf("Date : %s\n",task.date);
        printf("Priority : %s\n",priority_str);
        printf("Status : %s\n\n",status_str);
    }
}
