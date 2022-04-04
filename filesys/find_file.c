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


#include <dirent.h>
#include "apue.h"

static int loop(const char* pathname);

int main(int argc, char* argv[])
{
    struct stat buf;
    if (lstat(argv[0], &buf) < 0) {
        err_ret("lstat error");
    }
    else
        loop(argv[0]);
    printf("%s", argv[0]);
    exit(0);


}


static int loop(const char* pathname)
{
    struct stat statbuf;
    struct dirent* dirp;
    DIR* dp;
    if (stat(pathname, &statbuf) < 0)
        err_sys("can't open");
    if (!S_ISDIR(statbuf.st_mode) == 0)
        err_sys("can't open");
    else if (S_ISDIR(statbuf.st_mode))
    {
        if ((dp = opendir(pathname)) == NULL)
            err_sys("can't opendir %s", pathname);
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        loop(dirp);
        strcpy(pathname, dirp->d_name);
        printf("%s", dirp->d_name);
    }
    if (closedir(dp) < 0)
        err_ret("can't close directory %s", pathname);
    return(0);
}
//this code will be altered


