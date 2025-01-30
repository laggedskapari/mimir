#include <ftw.h>
#include <stdio.h>
#include <string.h>

#define TREEWALK(userArgs) (strcmp(userArg, "-ls") == 0)
#define TREEWALK_FILEEXT(userArg) (strcmp(userArg, "-ext") == 0)
#define TREEWALK_FILECOUNT(userArg) (strcmp(userArg, "-fc") == 0)
#define TREEWALK_DIRCOUNT(userArg) (strcmp(userArg, "-dc") == 0)
#define TREEWALK_FILESIZE(userArg) (strcmp(userArg, "-fs") == 0)
#define TREEWALK_DIRCOPY(userArg) (strcmp(userArg, "-cp") == 0)
#define TREEWALK_MOVEDIR(userArg) (strcmp(userArg, "-mv") == 0)
#define TREEWALK_DELFILEEXT(userArg) (strcmp(userArg, "-del") == 0)

const char *targetExtension = NULL;

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
  int count = 0;
  if (typeFlag == FTW_F) {
    ++count;
  }
  return count;
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
    if (strlen(argv[3]) > 0) {
      int result = nftw(argv[3], fileCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
      printf("Total Files: %d", result);
    } else {
      int result = nftw(".", fileCountCallback, 20, flag);
      if (result < 0) {
        perror("nftw");
        return 1;
      }
      printf("Total Files: %d", result);
    }
    return 0;
  }
}
