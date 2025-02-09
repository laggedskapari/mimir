#define _XOPEN_SOURCE 500
#define _GNU_SOURCE
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
static const char *sourceBase = NULL;

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
  ssize_t readBytes;

  // Create destination directories
  char *destCopy = strdup(destination);
  if (!destCopy) {
    perror("Memory allocation failed");
    return -1;
  }
  char *dirPath = dirname(destCopy);
  makeDirectories(dirPath);
  free(destCopy); // Free after using dirname

  // Open source file
  sourcefd = open(source, O_RDONLY);
  if (sourcefd == -1) {
    perror("Error: opening source file");
    return -1;
  }

  // Open destination file
  destinationfd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (destinationfd == -1) {
    perror("Error: failed to open destination file");
    close(sourcefd);
    return -1;
  }

  // Copy file contents
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

static int fileHasExtention(const char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename)
    return 0;
  return strcmp(dot, targetExtension) == 0;
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
  // Calculate relative path from source base
  const char *relativePath = filePath + strlen(sourceBase);
  if (*relativePath == '/')
    relativePath++; // Skip leading slash

  // Construct full destination path
  snprintf(destinationPath, sizeof(destinationPath), "%s/%s",
           destinationDirectory, relativePath);

  if (typeFlag == FTW_D) {
    // Create directory in destination
    makeDirectories(destinationPath);
    printf("Creating directory: %s\n", destinationPath);
  } else if (typeFlag == FTW_F) {
    // If extension is specified, check if file should be excluded
    if (targetExtension != NULL) {
      if (fileHasExtention(filePath)) {
        printf("Skipping file (excluded extension): %s\n", filePath);
        return 0;
      }
    }

    printf("Copying file: %s to %s\n", filePath, destinationPath);
    if (copyFile(filePath, destinationPath) == 0) {
      printf("File copied successfully\n");
    } else {
      printf("Error: failed to copy file\n");
    }
  }
  return 0;
}

static int moveFileCallback(const char *filePath, const struct stat *sb,
                            int typeFlag, struct FTW *buff) {
  // Calculate relative path correctly
  const char *relativePath = filePath;
  if (strncmp(filePath, sourceBase, strlen(sourceBase)) == 0) {
    relativePath = filePath + strlen(sourceBase);
    while (*relativePath == '/')
      relativePath++; // Skip extra slashes
  }

  // Construct destination path
  snprintf(destinationPath, sizeof(destinationPath), "%s/%s",
           destinationDirectory, relativePath);

  if (typeFlag == FTW_D) {
    // Create directory in destination
    makeDirectories(destinationPath);
    printf("Creating directory: %s\n", destinationPath);
  } else if (typeFlag == FTW_F) {
    printf("Moving file: %s -> %s\n", filePath, destinationPath);

    // First try to copy the file
    if (copyFile(filePath, destinationPath) == 0) {
      // Only delete source file if copy was successful
      if (unlink(filePath) == 0) {
        printf("Successfully moved: %s\n", filePath);
      } else {
        perror("Warning: Could not delete source file");
        return 1; // Signal error but continue
      }
    } else {
      printf("Error: Failed to move %s\n", filePath);
      return 1;
    }
  }
  return 0;
}

static int deleteDirectoryCallback(const char *filePath, const struct stat *sb,
                                   int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_DP) { // Only process directories after their contents
    if (rmdir(filePath) == 0) {
      printf("Removed directory: %s\n", filePath);
    } else {
      perror("Warning: Could not remove directory");
      return 1; // Signal error but continue
    }
  }
  return 0;
}

static int deleteFileCallback(const char *filePath, const struct stat *sb,
                              int typeFlag, struct FTW *buff) {
  if (typeFlag == FTW_F) {
    if (fileHasExtention(filePath)) {
      printf("Deleting: %s\n", filePath);
      if (unlink(filePath) == 0) {
        printf("Successfully deleted: %s\n", filePath);
      } else {
        perror("Error deleting file");
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int flag = FTW_PHYS;
  int result;

  // Basic argument validation
  if (argc < 2) {
    fprintf(stderr, "Usage: dtree <command> [arguments]\n");
    fprintf(stderr, "Commands: -ls, -ext, -fc, -dc, -fs, -cp, -mv, -del\n");
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "dtree") != 0) {
    fprintf(stderr, "Error: Program must be invoked as 'dtree'\n");
    return EXIT_FAILURE;
  }

  if (argc < 3) {
    fprintf(stderr, "Error: No command specified\n");
    return EXIT_FAILURE;
  }

  const char *userArg = argv[2];
  const char *directory = (argc > 3 && strlen(argv[3]) > 0) ? argv[3] : ".";

  // List files and directories
  if (TREEWALK(userArg)) {
    result = nftw(directory, treeWalkCallback, 20, flag);
    if (result != 0) {
      perror("Error traversing directory");
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  // Find files by extension
  if (TREEWALK_FILEEXT(userArg)) {
    if (argc < 5) {
      fprintf(stderr, "Usage: dtree -ext <directory> <extension>\n");
      return EXIT_FAILURE;
    }
    targetExtension = argv[4];
    if (targetExtension[0] != '.') {
      fprintf(stderr, "Error: Extension must start with '.'\n");
      return EXIT_FAILURE;
    }

    result = nftw(directory, fileExtCallback, 20, flag);
    if (result != 0) {
      perror("Error searching for files");
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  // Count files
  if (TREEWALK_FILECOUNT(userArg)) {
    fileCount = 0;
    result = nftw(directory, fileCountCallback, 20, flag);
    if (result != 0) {
      perror("Error counting files");
      return EXIT_FAILURE;
    }
    printf("Total Files: %d\n", fileCount);
    return EXIT_SUCCESS;
  }

  // Count directories
  if (TREEWALK_DIRCOUNT(userArg)) {
    directoryCount = 0;
    result = nftw(directory, directoryCountCallback, 20, flag);
    if (result != 0) {
      perror("Error counting directories");
      return EXIT_FAILURE;
    }
    printf("Total Directories: %d\n", directoryCount);
    return EXIT_SUCCESS;
  }

  // Show file sizes
  if (TREEWALK_FILESIZE(userArg)) {
    result = nftw(directory, fileSizeCallback, 20, flag);
    if (result != 0) {
      perror("Error getting file sizes");
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  // Copy directory
  if (TREEWALK_DIRCOPY(userArg)) {
    if (argc < 5) {
      fprintf(stderr, "Usage: dtree -cp <source> <destination> [extension]\n");
      return EXIT_FAILURE;
    }

    sourceBase = argv[3];
    destinationDirectory = argv[4];
    targetExtension = (argc > 5) ? argv[5] : NULL;

    struct stat st;
    if (stat(sourceBase, &st) != 0) {
      perror("Error: Source directory does not exist");
      return EXIT_FAILURE;
    }
    if (!S_ISDIR(st.st_mode)) {
      fprintf(stderr, "Error: Source must be a directory\n");
      return EXIT_FAILURE;
    }

    printf("Copying from %s to %s...\n", sourceBase, destinationDirectory);
    result = nftw(sourceBase, copyFileCallback, 20, flag);
    if (result != 0) {
      perror("Error during copy operation");
      return EXIT_FAILURE;
    }
    printf("Copy operation completed successfully\n");
    return EXIT_SUCCESS;
  }

  // Move directory
  if (TREEWALK_MOVEDIR(userArg)) {
    if (argc < 5) {
      fprintf(stderr, "Usage: dtree -mv <source> <destination>\n");
      return EXIT_FAILURE;
    }

    sourceBase = argv[3];
    destinationDirectory = argv[4];

    // Remove trailing slashes from paths
    char *temp = strdup(sourceBase);
    size_t len = strlen(temp);
    while (len > 1 && temp[len - 1] == '/') {
      temp[len - 1] = '\0';
      len--;
    }
    sourceBase = temp;

    // Check if source exists and is a directory
    struct stat st;
    if (stat(sourceBase, &st) != 0) {
      free(temp);
      perror("Error: Source directory does not exist");
      return EXIT_FAILURE;
    }
    if (!S_ISDIR(st.st_mode)) {
      free(temp);
      fprintf(stderr, "Error: Source must be a directory\n");
      return EXIT_FAILURE;
    }

    printf("Moving files from %s to %s\n", sourceBase, destinationDirectory);

    // First move all files and create directories
    int result = nftw(sourceBase, moveFileCallback, 20, FTW_PHYS);
    if (result != 0) {
      free(temp);
      perror("Error during move operation");
      return EXIT_FAILURE;
    }

    // Then delete the source directories
    printf("Cleaning up source directories...\n");
    result =
        nftw(sourceBase, deleteDirectoryCallback, 20, FTW_PHYS | FTW_DEPTH);
    if (result != 0) {
      free(temp);
      perror("Error during cleanup");
      return EXIT_FAILURE;
    }

    free(temp);
    printf("Move operation completed successfully\n");
    return EXIT_SUCCESS;
  }
  // Delete files by extension
  if (TREEWALK_DELFILEEXT(userArg)) {
    if (argc < 5) {
      fprintf(stderr, "Usage: dtree -del <directory> <extension>\n");
      return EXIT_FAILURE;
    }

    targetExtension = argv[4];
    if (targetExtension[0] != '.') {
      fprintf(stderr, "Error: Extension must start with '.'\n");
      return EXIT_FAILURE;
    }

    struct stat st;
    if (stat(directory, &st) != 0) {
      perror("Error: Directory does not exist");
      return EXIT_FAILURE;
    }
    if (!S_ISDIR(st.st_mode)) {
      fprintf(stderr, "Error: Path must be a directory\n");
      return EXIT_FAILURE;
    }

    printf("Deleting all %s files in %s...\n", targetExtension, directory);
    result = nftw(directory, deleteFileCallback, 20, flag);
    if (result != 0) {
      perror("Error during delete operation");
      return EXIT_FAILURE;
    }

    printf("Delete operation completed successfully\n");
    return EXIT_SUCCESS;
  }

  fprintf(stderr, "Error: Unknown command '%s'\n", userArg);
  return EXIT_FAILURE;
}
