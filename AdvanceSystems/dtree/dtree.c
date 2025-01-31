#include <fcntl.h>
#include <ftw.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define TREEWALK(userArgs) (strcmp(userArg, "-ls") == 0)
#define TREEWALK_FILEEXT(userArg) (strcmp(userArg, "-ext") == 0)
#define TREEWALK_FILECOUNT(userArg) (strcmp(userArg, "-fc") == 0)
#define TREEWALK_DIRCOUNT(userArg) (strcmp(userArg, "-dc") == 0)
#define TREEWALK_FILESIZE(userArg) (strcmp(userArg, "-fs") == 0)
#define TREEWALK_DIRCOPY(userArg) (strcmp(userArg, "-cp") == 0)
#define TREEWALK_MOVEDIR(userArg) (strcmp(userArg, "-mv") == 0)
#define TREEWALK_DELFILEEXT(userArg) (strcmp(userArg, "-del") == 0)

#define BUFFER_SIZE 8192

const char *targetExtension = NULL;
static int fileCount = 0;
static int directoryCount = 0;
static const char *destinationDirectory = NULL;
static char destinationPath[4096];

static void makeDirectories(const char *dir) {
  char tmp[2096];
  char *p = NULL;
  size_t len;

  snprintf(tmp, sizeof(tmp), "%s", dir);

  len = strlen(tmp);
  if (tmp[len - 1] == '/')
    tmp[len - 1] = 0;

  for (p = tmp + 1; *p; p++) {
    if (*p == '/') {
      *p = 0;
      mkdir(tmp, 0755);
      *p = '/';
    }
  }
  mkdir(tmp, 0755);
}
static int copyFile(const char *source, const char *destination) {
  char buffer[BUFFER_SIZE];
  int sourcefd, destinationfd;
  size_t readBytes;

  sourcefd = open(source, O_RDONLY);
  if (sourcefd == -1) {
    perror("Error: opening sourse file");
    return -1;
  }

  char *destinationDirectoryName = dirname(strdup(destination));
  makeDirectories(destinationDirectoryName);
  free(destinationDirectoryName);

  destinationfd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (destinationfd == -1) {
    printf("Error: failed to open destination file");
    close(sourcefd);
    return -1;
  }

  while ((readBytes = read(sourcefd, buffer, BUFFER_SIZE)) > 0) {
    if (write(destinationfd, buffer, readBytes) != readBytes) {
      perror("Error: failed to write into destination file");
      close(sourcefd);
      close(destinationfd);
      return -1;
    }
  }
  close(sourcefd);
  close(destinationfd);

  return 0;
}

static int treeWalkCallback(const char *filePath, const struct stat *sb,
                            int typeFlag, struct FTW *buff) {
  printf("%s - ", filePath);

  switch (typeFlag) {
  case FTW_D:
    printf("[directory]\n");
    break;
  case FTW_F:
    printf("[file]\n");
    break;
  case FTW_SL:
    printf("[symbolic]\n");
    break;
  default:
    printf("[other]\n");
    break;
  }
  return 0;
}

static int fileHasExtention(const char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename)
    return 0;
  return strcmp(dot, targetExtension) == 0;
}

static int fileExtCallback(const char *filePath, const struct stat *sb,
                           int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_F) {
    if (fileHasExtention(filePath)) {
      printf("%s\n", filePath);
    }
  }
  return 0;
}

static int fileCountCallback(const char *filePath, const struct stat *sb,
                             int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_F)
    ++fileCount;
  return 0;
}

static int directoryCountCallback(const char *filePath, const struct stat *sb,
                                  int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_D)
    ++directoryCount;
  return 0;
}

static int fileSizeCallback(const char *filePath, const struct stat *sb,
                            int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_F) {
    printf("[%llu B] - %s\n", (unsigned long long)sb->st_size, filePath);
  }
  return 0;
}

static int copyFileCallback(const char *filePath, const struct stat *sb,
                            int typeFlag, struct FTW *buff) {
  char relPath[4096];
  strcpy(relPath, filePath);

  snprintf(destinationPath, sizeof(destinationPath), "%s/%s",
           destinationDirectory, basename(relPath));
  if (typeFlag == FTW_F) {
    if (fileHasExtention(filePath)) {
      printf("copying %s to %s\n", filePath, destinationPath);
      if (copyFile(filePath, destinationPath) == 0) {
        printf("File copied successfully\n");
      } else {
        printf("Error: failed to copy file\n");
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int flag = FTW_PHYS;
  if (argc < 2) {
    printf("Error: not enough argumen\n");
    return 0;
  };

  if (strcmp(argv[1], "dtree") != 0) {
    printf("Error: %s is not found or valid command\n", argv[1]);
    return 0;
  }

  char const *userArg = argv[2];
  if (TREEWALK(userArg)) {
    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], treeWalkCallback, 20, flag);
      if (result != 0) {
        perror("nftw");
        return 1;
      }
    } else {
      int result = nftw(".", treeWalkCallback, 20, flag);
      if (result != 0) {
        perror("nftw");
        return 1;
      }
    }
    return 0;
  }
  if (TREEWALK_FILEEXT(userArg)) {

    if (argc < 4) {
      printf("Error: extention argument missing\n");
      return 1;
    }

    targetExtension = argv[4];

    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], fileExtCallback, 20, flag);
      if (result != 0) {
        perror("nftw");
        return 1;
      }
    } else {
      int result = nftw(".", fileExtCallback, 20, flag);
      if (result != 0) {
        perror("nftw");
        return 1;
      }
    }
    return 0;
  }

  if (TREEWALK_FILECOUNT(userArg)) {
    fileCount = 0;
    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], fileCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
      printf("Total Files: %d\n", fileCount);
    } else {
      int result = nftw(".", fileCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
      printf("Total Files: %d\n", fileCount);
    }
    return 0;
  }

  if (TREEWALK_DIRCOUNT(userArg)) {
    directoryCount = 0;
    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], directoryCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
      printf("Total Directories: %d\n", directoryCount);
    } else {
      int result = nftw(".", directoryCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
    }
    return 0;
  }

  if (TREEWALK_FILESIZE(userArg)) {
    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], fileSizeCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
    } else {
      int result = nftw(".", fileSizeCallback, 20, flag);
      if (result != 0) {
        perror("nftw");
        return 1;
      }
    }
    return 0;
  }
}
