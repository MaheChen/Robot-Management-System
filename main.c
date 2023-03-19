#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROBOTS 10

struct Robot {
    int id;
    char name[50];
    int battery_level;
    int is_active;
};

struct Robot robots[MAX_ROBOTS];
int num_robots = 0;

void create_robot(char* name, int battery_level) {
    if (num_robots == MAX_ROBOTS) {
        printf("Maximum number of robots reached!\n");
        return;
    }

    struct Robot new_robot;
    new_robot.id = num_robots;
    strcpy(new_robot.name, name);
    new_robot.battery_level = battery_level;
    new_robot.is_active = 1;

    robots[num_robots++] = new_robot;

    printf("Robot created successfully!\n");
}

void delete_robot(int id) {
    if (id < 0 || id >= num_robots) {
        printf("Invalid robot ID!\n");
        return;
    }

    robots[id].is_active = 0;
    printf("Robot deleted successfully!\n");
}

void display_robot(int id) {
    if (id < 0 || id >= num_robots) {
        printf("Invalid robot ID!\n");
        return;
    }

    struct Robot robot = robots[id];

    printf("Robot ID: %d\n", robot.id);
    printf("Robot Name: %s\n", robot.name);
    printf("Battery Level: %d\n", robot.battery_level);
    printf("Is Active: %s\n", robot.is_active ? "Yes" : "No");
}

void display_all_robots() {
    if (num_robots == 0) {
        printf("No robots found!\n");
        return;
    }

    printf("List of Robots:\n");

    for (int i = 0; i < num_robots; i++) {
        struct Robot robot = robots[i];

        printf("Robot ID: %d\n", robot.id);
        printf("Robot Name: %s\n", robot.name);
        printf("Battery Level: %d\n", robot.battery_level);
        printf("Is Active: %s\n", robot.is_active ? "Yes" : "No");
        printf("\n");
    }
}

int main() {
    int choice;
    char name[50];
    int battery_level;
    int id;

    while (1) {
        printf("*********** Robot Management System ***********\n");
        printf("1. Create Robot\n");
        printf("2. Delete Robot\n");
        printf("3. Display Robot\n");
        printf("4. Display All Robots\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter robot name: ");
                scanf("%s", name);
                printf("Enter battery level: ");
                scanf("%d", &battery_level);
                create_robot(name, battery_level);
                break;

            case 2:
                printf("Enter robot ID: ");
                scanf("%d", &id);
                delete_robot(id);
                break;

            case 3:
                printf("Enter robot ID: ");
                scanf("%d", &id);
                display_robot(id);
                break;

            case 4:
                display_all_robots();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0
