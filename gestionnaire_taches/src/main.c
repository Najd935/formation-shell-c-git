#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "menu.h"

#define FILENAME "data/taches.txt"

int main()
{
    int capacity = 2;
    int task_count = 0;
    int current_id = 1;

    Task *tasks = malloc(capacity * sizeof(Task));
    if (tasks == NULL)
    {
        printf("Failed to initialize the task list.\n");
        printf("Exiting program.\n");
        return 1;
    }

    int choice;
    do
    {
        display_menu();
        scanf("%d",&choice);
        getchar();

        switch (choice)
        {
        case 1:
            add_task(&tasks,&task_count,&capacity,&current_id);
            break;
        case 2:
            display_tasks(tasks,task_count);
            break;
        case 3 :
        {
            printf("Select an id : ");
            int to_delete;
            scanf("%d",&to_delete);
            delete_task_by_id(tasks,&task_count,to_delete);
            break;
        }
        case 4 :
            load_tasks_from_file(FILENAME,&tasks,&task_count,&capacity,&current_id);
            break;
        case 5 :
            save_tasks_to_file(FILENAME,tasks,task_count);
            break;
        case 0:
            printf("Bye !\n");
            break;
        default:
            printf("Invalid input\n");
            
        }

    } while (choice != 0);

    // You can later add a menu loop here
    // display_menu();
    // read input and call add_task(), display_tasks(), etc.

    free(tasks); // Don't forget to free the memory when done

    return 0;
}
