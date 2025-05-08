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






void delete_task_by_id(Task* tasks, int* task_count, int id_to_delete)
{
    if (*task_count == 0)
    {
        printf("No task to delete.\n");
        return;
    }

    int index = find_task_by_id(tasks,*task_count,id_to_delete);
    if (index == -1)
    {
        printf("Task could not be found.\n");
        return;
    }

    for (int i = index; i < *task_count - 1; i++)
    {
        tasks[i] = tasks[i+1];
    }
    
    *task_count = *task_count - 1;
}

int find_task_by_id(Task* tasks, int task_count, int id)
{
    
    for (int i = 0 ; i < task_count; i++)
    {
        if (tasks[i].id == id)
        {
                return i;
        }
    }
    return -1;
}



void load_tasks_from_file(const char *filename, Task **tasks, int *task_count, int *capacity, int *current_id)
{
    FILE *csv = fopen(filename,"r");

    if (csv == NULL)
    {
        printf("Could not load the file %s\n",filename);
        return;
    }

    char line[256];
    
    // on ignore la première ligne.
    fgets(line,256,csv);

    while (fgets(line,256,csv) != NULL)
    {
        line[strcspn(line,"\n")] = '\0';
        
        Task task;
        char description[DESCRIPTION_MAX];
        char date[DATE_MAX];
        int priority;
        int status;

        strcpy(description,strtok(line,";"));
        strcpy(date,strtok(NULL,";"));
        priority = atoi(strtok(NULL,";"));
        status = atoi(strtok(NULL,";"));

        if (*task_count == *capacity)
        {   
            // ici on utilise cap pour ne pas changer capacity si l'allocation fail.
            int cap = *capacity * 2;
            Task *tmp = realloc(*tasks,sizeof(Task) * cap);

            if (tmp == NULL)
            {
                printf("Could not reallocate memory for tasks.\n");
                fclose(csv);
                return;
            }

            *tasks = tmp;
            *capacity = cap;

        }

        task.id = *current_id;
        strcpy(task.description,description);
        strcpy(task.date,date);
        task.priority = priority;
        task.status = status;

        (*tasks)[*task_count] = task;

        *task_count = *task_count + 1;
        *current_id = *current_id + 1;

        printf("Task with id %d has been added to the task manager.\n",task.id);

    }

    fclose(csv);
}
