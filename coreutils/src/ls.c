#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define PATHNAME_LIMIT 1024

int main(int argc, char *argv[]) {
    char path[1024];
    DIR *dp;
    struct dirent *dirp;

    if (argc < 2) {
        strcpy(path, ".");

    } else {
        if (strlen(argv[1]) > PATHNAME_LIMIT) {
            printf("path name too long\n");
            return 1;
        }

        strcpy(path, argv[1]);
    }

    if ((dp = opendir(path)) == NULL) {
        printf("can't open directory\n");
        return 1;
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    return 0;
}
