#if !defined TODO
#define TODO
typedef enum  Status {ONGOING, COMPLETED} Status;

typedef struct Task
{
   char* tasks;
   Status takes;   

}Task;
typedef struct todoList
{
    Task* task;
    int cur;
    int size;
}todoList;

int Delete(todoList *todos, int index);
void destroylist(todoList *todos);
int write_to_file(const todoList *todos,const char *fn);
void print_list(const todoList *todos);
int insert(todoList *todos, const char *desc);
int complete(todoList *todos, int index);
#endif