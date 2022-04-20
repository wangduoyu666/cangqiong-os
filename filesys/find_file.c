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

2022.4.20
/*
#include "apue.h"
#include <dirent.h>
#include <stdbool.h>

static int dopath(char*);

int main(int argc, char argv[])
{
    const char* path;
    if (argc != 2)
        path = "/etc";
    else
        path = argv[1];
    printf("Directory scan of %s\n", path);
    dopath(path);
    return 0;
}

static int dopath(char* dirpath)
{
    struct dirent* dirp;
    DIR* dp;
    if ((dp = opendir(dirpath)) == NULL) {
        err_sys("can't open:%s\n", dirpath);
        return;
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s/%s\n", dirpath, dirp->d_name);
        }
    closedir(dp);
    return 0;
}

// void loop(int v)
//{
//    char *p;
//    struct stat *statbuf;
//    if(p=S_ISDIR(statbuf->st_mode)<0)
//    v=0;
//    else
//    for(v=1; v<strlen(p); v++)
//    {
//       dopath(p);
//     }
//     return;
//}

*/
// only one level, but I will keep trying


