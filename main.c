#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <direct.h>
#include <windows.h>


const char* get_file_category(const char *filename) {
    const char *dot = strrchr(filename, '.');

    if (dot == NULL) {
        return "Others";
    }

    if (stricmp(dot, ".pdf") == 0 || stricmp(dot, ".docx") == 0 || stricmp(dot, ".txt") == 0 || stricmp(dot, ".xlsx") == 0) {
        return "Documents";
    }
    if (stricmp(dot, ".jpg") == 0 || stricmp(dot, ".jpeg") == 0 || stricmp(dot, ".png") == 0 || stricmp(dot, ".gif") == 0) {
        return "Images";
    }
    if (stricmp(dot, ".mp3") == 0 || stricmp(dot, ".wav") == 0 || stricmp(dot, ".m4a") == 0) {
        return "Music";
    }
    if (stricmp(dot, ".mp4") == 0 || stricmp(dot, ".mkv") == 0 || stricmp(dot, ".avi") == 0) {
        return "Videos";
    }
    if (stricmp(dot, ".exe") == 0 || stricmp(dot, ".msi") == 0) {
        return "Programs";
    }
    if (stricmp(dot, ".zip") == 0 || stricmp(dot, ".rar") == 0 || stricmp(dot, ".7z") == 0) {
        return "Archives";
    }

    return "Others";
}

void organize_folder(const char *target_dir) {
    DIR *dir = opendir(target_dir);
    struct dirent *entry;

    if (dir == NULL) {
        printf("Could not open the folder: %s\n", target_dir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        const char *category = get_file_category(entry->d_name);

        char dest_folder[1024];
        snprintf(dest_folder, sizeof(dest_folder), "%s/%s", target_dir, category);

        _mkdir(dest_folder);

        char old_path[1024];
        char new_path[1024];
        snprintf(old_path, sizeof(old_path), "%s/%s", target_dir, entry->d_name);
        snprintf(new_path, sizeof(new_path), "%s/%s", dest_folder, entry->d_name);

        if (rename(old_path, new_path) == 0) {
            printf("[SUCCESS] Moved: %s -> %s/\n", entry->d_name, category);
        }
    }

    closedir(dir);
}

int main() {
    char target_path[1024];

    printf("==================================================\n");
    printf("           SMART FILE ORGANIZER START             \n");
    printf("==================================================\n");

    printf("Enter the full path of the folder to organize:\n");
    printf("Example: C:\\Users\\YourName\\Downloads\n\nEnter the path here: ");

    if (fgets(target_path, sizeof(target_path), stdin) != NULL) {
        target_path[strcspn(target_path, "\n")] = '\0';
    }


    int len = strlen(target_path);
    if (target_path[0] == '"' && target_path[len - 1] == '"') {

        memmove(target_path, target_path + 1, len - 2);
        target_path[len - 2] = '\0';
    }


    printf("\nSTEP 1:Running immediate folder cleanup...\n");
    organize_folder(target_path);
    printf("Immediate cleanup finished successfully!\n");

    printf("\nSTEP 2 : Entering Smart Background Mode.\n");
    printf("The program will now stay open and check for new files periodically.\n");
    printf("Keep this window open to maintain automation.\n\n");

    while (1) {
        int wait_time = 10000;

        printf("Sleeping for a bit... checking folder again soon.\n");
        Sleep(wait_time);

        printf("\nSMART RUN: Scanning for newly added files...\n");
        organize_folder(target_path);
        printf("SMART RUN: Scan finished.\n\n");
    }

    return 0;
}
