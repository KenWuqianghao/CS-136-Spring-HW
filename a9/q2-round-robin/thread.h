#include <stdbool.h>

// thread represents a thread
struct thread;

// thread_create(id, name, cpu_time) returns a new thread with a given id and
//   name, as well as the cpu_time required to complete the thread.
// requries: id must be non-negative
//           cpu_time must be positive
// effects:  allocates memory; client must call thread_destroy
// time:     O(n), where n is the length of name
struct thread *thread_create(int id, const char *name, int cpu_time);

// thread_destroy(thrd) releases all resources used by thrd.
// effects: invalidates thrd
// time:    O(1)
void thread_destroy(struct thread *thrd);

// thread_make() returns a new thread with all information read from console.
//   The format is ID NAME CPUTIME (<int>, <string>, <int>). ID must be non-
//   negative, length of NAME must not exceed 99 characters, and CPUTIME must
//   be positive.
// example: 1 bash 450
//          136 seashell 990
// effects: allocates memory; client must call thread_destroy
// time:    O(n), where n is the length of name
struct thread *thread_make(void);

// thread_exec(thrd, cpu_time) reduces the remaining required CPU time of thrd
//   by cpu_time or to 0. The function returns true if thrd has finished, and
//   false otherwise.
// requires: cpu_time must be positive
// effects:  mutates thrd
// time:     O(1)
bool thread_exec(struct thread *thrd, int cpu_time);

// thread_id_get(thrd) returns the id of thrd.
// time: O(1)
int thread_id_get(const struct thread *thrd);

// thread_print(thrd) prints all information of thrd to the console.
// effects: writes to console
// time:    O(n), where n is the length of the name of thrd
void thread_print(const struct thread *thrd);
