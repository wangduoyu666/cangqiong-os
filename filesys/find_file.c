/*
#include "apue.h"
#include <dirent.h>
#define NAME_MAX 400

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        err_sys("%s [dir...]\n", argv[0]);
    if (argc == 1)
        dopath(".");
    else
        for (argv++; *argv; argv++)
            dopath(*argv);
    exit(0);
}

static char* fullpath;
static size_t pathlen;

static int dopath(const char *dirpath)
{
    struct dirent* dirp;
    DIR* dp;
    char* pathname;
    int n;
    fullpath = path_alloc(&pathlen);
    if (pathlen <= strlen(pathname)) {
        pathlen = strlen(pathname) * 2;
        if ((fullpath = realloc(fullpath, pathlen)) == NULL)
            err_sys("realloc failed");
        strcpy(fullpath, pathname);
    }
    n = strlen(fullpath);
    if (n + NAME_MAX + 2 > pathlen) {
        pathlen *= 2;
        if ((fullpath = realloc(fullpath, pathlen)) == NULL)
            err_sys("realloc failed");
    }
    fullpath[n++] = '/';
    fullpath[n] = 0;
    if ((dp = opendir(fullpath)) == NULL)
        err_sys("can't opendir");
    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(&fullpath[n], dirp->d_name);
        printf("%s", dirp->d_name);
    }
    fullpath[n - 1] = 0;
    if (closedir(dp) < 0)
        err_ret("can't close directory %s", fullpath);
    return (0);
}
*/


#include "apue.h"
#include <dirent.h>
#define MAX 30

int main(int argc, char argv[]) {
        if(argc!=2)
        loop(argv[0], 0);
        exit(0);
}



void dopath(char* pathname) {
        struct stat statbuf;
        struct dirent* dirp;
        DIR* dp;
        if (lstat(pathname, &statbuf) < 0) {
                err_sys("lstat error");
        }
        if ((dp = opendir(pathname)) == NULL)
                err_sys("can't opendir");
        while ((dirp = readdir(dp)) != NULL) {
                if (strcmp(dirp->d_name, ".") == 0 ||
                        strcmp(dirp->d_name, "..") == 0)
                        continue;
                printf("%s%s/\n",pathname,dirp->d_name);
        }
        chdir("dirp->d_name");
        closedir(dp);
        return;
}

void loop(char* n, int x) {
        char* path;
        for (x = 0; x < MAX; x++) {
                dopath(path);
                printf("%s", n);
                return;
        }
}

//alter
