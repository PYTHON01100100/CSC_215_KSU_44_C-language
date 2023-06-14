#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

int insert(todoList *todos, const char *desc) {
    if (todos->cur >= todos->size) {
        // Allocate a new array with double the size of the current array
        Task *new_tasks = (Task*) malloc(todos->size * 2 * sizeof(Task));
        if (new_tasks == NULL) {
            return 0;
        }
        // Copy the existing tasks to the new array
        for (int i = 0; i < todos->cur; i++) {
            new_tasks[i] = todos->task[i];
        }
        // Free the old array and update the todoList struct
        free(todos->task);
        todos->task = new_tasks;
        todos->size *= 2;
    }
    todos->task[todos->cur].tasks = strdup(desc);
    todos->task[todos->cur].takes = ONGOING;
    todos->cur++;
    return 1;
}

int complete(todoList *todos, int index) {
    if (index < 0 || index >= todos->cur) {
        return 0;
    }
    todos->task[index].takes = COMPLETED;
    return 1;
}

int Delete(todoList *todos, int index) {
    if (index < 0 || index >= todos->cur) {
        return 0;
    }
    free(todos->task[index].tasks);
    for (int i = index; i < todos->cur - 1; i++) {
        todos->task[i] = todos->task[i + 1];
    }
    todos->cur--;
    return 1;
}

void destroylist(todoList *todos) {
    for (int i = 0; i < todos->cur; i++) {
        free(todos->task[i].tasks);
    }
    free(todos->task);
    free(todos);
}

int write_to_file(const todoList *todos, const char *fn) {
    FILE *fp = fopen(fn, "w");
    if (fp == NULL) {
        return 0;
    }
    for (int i = 0; i < todos->cur; i++) {
        switch (todos->task[i].takes) {
            case ONGOING:
                fprintf(fp, "ONGOING\t%s\n", todos->task[i].tasks);
                break;
            case COMPLETED:
                fprintf(fp, "COMPLETED\t%s\n", todos->task[i].tasks);
                break;
        }
    }
    fclose(fp);
    return 1;
}

void print_list(const todoList *todos) {
    for (int i = 0; i < todos->cur; i++) {
               printf("%s\t%s\n", (todos->task[i].takes == ONGOING) ? "ONGOING" : "COMPLETED", todos->task[i].tasks);
    }
}