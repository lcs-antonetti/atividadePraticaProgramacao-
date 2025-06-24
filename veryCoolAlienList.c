#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

typedef struct 
{
	int id;
	char titulo[100];
	char descricao[200];
	char data[11];
	int prioridade;
	int status;
} Tarefa;

Tarefa tasks[TAM];

const char *filename = "tasks.txt";

void show_alien();
void enterClear(char *string);
void loadlist(int *taskNum);
int verifyId(Tarefa tasks[], int taskNum, int id);
void addtask(int *taskNum);
void list_tasks(int taskNum);
void search_task(int taskNum);
void Edit_task(int taskNum);
void Delete_task(int *taskNum);
void pending_tasks(int taskNum);
void Sort_tasks(int taskNum);
int compare_data(const void *a, const void *b);
void savefile(int taskNum);

int main() 
{
    srand(time(NULL));

    int taskNum = 0;
    loadlist(&taskNum);

    int opcao = 0;
    while (opcao != 8) 
    {
        show_alien();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) 
        {
            case 1:
                addtask(&taskNum);
                break;
            case 2:
                list_tasks(taskNum);
                break;
            case 3:
                search_task(taskNum);
                break;
            case 4:
                Sort_tasks(taskNum);
                break;
            case 5:
                Edit_task(taskNum);
                break;
            case 6:
                Delete_task(&taskNum);
                break;
            case 7:
                pending_tasks(taskNum);
                break;
            case 8:
                savefile(taskNum);
                printf("Saving...\n");
                break;
            default:
                printf("Choose a valid option.\n");
        }
        
        if (opcao != 8)
        {
            printf("\nPress enter to continue...");
            getchar();
            system("clear");
        }
    }
    return 0;
}

void show_alien()
{
    printf("\033[32m     _                      _______                      _                   __________________   __________________\n");
    printf("  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_            .-/|                  \\ /                  |\\-.\n");
    printf(" dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb           ||||      TASK         |      LIST         ||||\n");
    printf(" V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V           ||||                   |                   ||||\n");
    printf("          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'                    ||||  1.add task       |  6.delete task    ||||\n");
    printf("           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'                     ||||  2.list tasks     |  7.pending tasks  ||||\n");
    printf("      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __                ||||  3.search task    |  8.save and leave ||||\n");
    printf("    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.              ||||  4.sort list      |                   ||||\n");
    printf(" _,dP~  `YMba_      OOb  \033[31m<0>\033[32m `OOO'  \033[31m<0>\033[32m dOO      _aMMP'  ~Yb._           ||||  5.edit task      |  \033[31m WHAT WILL THE\033[32m   ||||\n");
    printf("             `YMMMM\\`OO       OOO     oOOO'/MMMMP'                       ||||                   |  \033[31m ALIEN DO NEXT?\033[32m  ||||\n");
    printf("     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.              ||||__________________ | __________________||||\n");
    printf("   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.            ||/===================\\|/===================\\||\n");
    printf("  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.           `--------------------~___~-------------------''\n");
    printf("  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM\n");
    printf("  YMb           ~YMMMM\\`OOOOI`````IOOOOO'/MMMMP~           dMP\n");
    printf("   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n");
    printf("     `'                  `OObNNNNNdOO'                   `'\n");
    printf("                           `~OOOOO~'  \033[0m\n");
}

void enterClear(char *string)
{
    string[strcspn(string, "\n")] = '\0';
}

void loadlist(int *taskNum)
{
    FILE *file = fopen(filename, "r");
    if (!file) return;
    while (fscanf(file, "%d;%99[^;];%199[^;];%10[^;];%d;%d\n", &tasks[*taskNum].id, tasks[*taskNum].titulo, tasks[*taskNum].descricao, tasks[*taskNum].data, &tasks[*taskNum].prioridade, &tasks[*taskNum].status) == 6)
    {
        (*taskNum)++;
    }
    fclose(file);
}

int verifyId(Tarefa tasks[], int taskNum, int id) 
{
    for (int i = 0; i < taskNum; i++) 
    {
        if (tasks[i].id == id)
            return 1;
    }
    return 0;
}

void addtask(int *taskNum)
{
    if (*taskNum >= TAM) 
    {
        printf("\033[31mYOU CANT ADD MORE TASKS, THE ALIEN WILL NOT LET YOU!\033[32m\n");
        return;
    }

    int newID;
    do {
        newID = rand() % 1000;
    } while (verifyId(tasks, *taskNum, newID));

    tasks[*taskNum].id = newID;
    printf("ID: %03d\n", tasks[*taskNum].id);

    printf("Title: ");
    fgets(tasks[*taskNum].titulo, 100, stdin); enterClear(tasks[*taskNum].titulo);

    printf("Description: ");
    fgets(tasks[*taskNum].descricao, 200, stdin); enterClear(tasks[*taskNum].descricao);

    printf("Date (DD/MM/AAAA): ");
    fgets(tasks[*taskNum].data, 11, stdin); enterClear(tasks[*taskNum].data);

    printf("Priority (1-5): ");
    scanf("%d", &tasks[*taskNum].prioridade);
    getchar();

    printf("Status (0 = pendente, 1 = concluida): ");
    scanf("%d", &tasks[*taskNum].status);
    getchar();

    printf("Task added!\n");
    (*taskNum)++;
}

void list_tasks(int taskNum) 
{
    for (int i = 0; i < taskNum; i++) 
    {
        printf("\nID: %d\nTitle: %s\nDescription: %s\nDate: %s\nPriority: %d\nStatus: %s\n", tasks[i].id, tasks[i].titulo, tasks[i].descricao, tasks[i].data, tasks[i].prioridade, tasks[i].status ? "Concluida" : "Pendente");
    }
}

void search_task(int taskNum)
{
    int option;
    char answer[200];

    printf("\nSearch for: 1-ID 2-Date 3-Title 4-Priority 5-Status: ");
    scanf("%d", &option);
    getchar();
    printf("Write the value: ");
    fgets(answer, 200, stdin); enterClear(answer);

    for (int i = 0; i < taskNum; i++) 
    {
        int match = 0;
        switch(option) 
        {
            case 1: if (tasks[i].id == atoi(answer)) match = 1; break;
            case 2: if (strcmp(tasks[i].data, answer) == 0) match = 1; break;
            case 3: if (strstr(tasks[i].titulo, answer)) match = 1; break;
            case 4: if (tasks[i].prioridade == atoi(answer)) match = 1; break;
            case 5: if (tasks[i].status == atoi(answer)) match = 1; break;
        }
        if (match)
        {
            printf("\nID: %d\nTitle: %s\nDescription: %s\nDate: %s\nPriority: %d\nStatus: %s\n", tasks[i].id, tasks[i].titulo, tasks[i].descricao, tasks[i].data, tasks[i].prioridade, tasks[i].status ? "Done" : "Pending");
        }
    }
}

void Edit_task(int taskNum) 
{
    int id;
    printf("Task ID: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < taskNum; i++) 
    {
        if (tasks[i].id == id)
        {
            printf("Title: "); fgets(tasks[i].titulo, 100, stdin); enterClear(tasks[i].titulo);
            printf("Description: "); fgets(tasks[i].descricao, 200, stdin); enterClear(tasks[i].descricao);
            printf("date: "); fgets(tasks[i].data, 11, stdin); enterClear(tasks[i].data);
            printf("Priority: "); scanf("%d", &tasks[i].prioridade); getchar();
            printf("status: "); scanf("%d", &tasks[i].status); getchar();
            printf("task added!\n");
            return;
        }
    }
    printf("could not find the task ID.\n");
}

void Delete_task(int *taskNum) 
{
    int id;
    printf("Task ID: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < *taskNum; i++)
    {
        if (tasks[i].id == id)
        {
            for (int j = i; j < *taskNum - 1; j++) 
            {
                tasks[j] = tasks[j + 1];
            }
            (*taskNum)--;
            printf("Task deleted.\n");
            return;
        }
    }
    printf("Could not find the task ID.\n");
}

void pending_tasks(int taskNum)
{
    printf("\n=== Tasks to be done ===\n");
    for (int i = 0; i < taskNum; i++) 
    {
        if (tasks[i].status == 0)
        {
            printf("ID: %d - %s (Date: %s, Priority: %d)\n", tasks[i].id, tasks[i].titulo, tasks[i].data, tasks[i].prioridade);
        }
    }
}

void Sort_tasks(int taskNum) 
{
    qsort(tasks, taskNum, sizeof(Tarefa), compare_data);
    printf("Sorted by date.\n");
}

int compare_data(const void *a, const void *b)
{
    const Tarefa *t1 = (const Tarefa *)a;
    const Tarefa *t2 = (const Tarefa *)b;

    int day1, month1, year1;
    int day2, month2, year2;

    sscanf(t1->data, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(t2->data, "%d/%d/%d", &day2, &month2, &year2);

    if (year1 != year2 ) return year1 - year2;
    if (month1 != month2) return month1 - month2;
    return day1 - day2;
}

void savefile(int taskNum)
{
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < taskNum; i++)
    {
        fprintf(file, "%d;%s;%s;%s;%d;%d\n", tasks[i].id, tasks[i].titulo, tasks[i].descricao, tasks[i].data, tasks[i].prioridade, tasks[i].status);
    }
    fclose(file);
}