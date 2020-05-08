#include <iostream>

#define OK 0
#define ERROR 1

int process_input(const char *workers_path, const char *map_path);

int process_workers_file(const char *workers_path);

int process_map_file(const char *map_path);


int main(int argc, char *argv[]) {
    const char *workers_path = argv[1], *map_path = argv[2];

    if (process_input(workers_path, map_path) == ERROR) return ERROR;

    return OK;
}

int process_input(const char *workers_path, const char *map_path) {
    if (process_workers_file(workers_path) == ERROR) return ERROR;
    if (process_map_file(map_path) == ERROR) return ERROR;

    return OK;
}

int process_workers_file(const char *workers_path) {
    return OK;
}

int process_map_file(const char *map_path) {
    return OK;
}
