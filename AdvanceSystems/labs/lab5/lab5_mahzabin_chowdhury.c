#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd;
  char buff1[50];

  // Set file creation mask to ensure proper access permissions
  // The resulting permissions will be 0755
  umask(0022);

  // Initialize file descriptor and establish file with read/write access
  fd = open("lab5.txt", O_CREAT | O_RDWR, 0777);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }

  // Insert the opening message into the file
  const char *initial_text = "Welcome to COMP 8567, University of Windsor";
  write(fd, initial_text, strlen(initial_text));

  // Position file pointer at the start of the phrase "University of Windsor"
  lseek(fd, strlen("Welcome to COMP 8567, "), SEEK_SET);

  // Store "University of Windsor" in temporary storage buff1
  read(fd, buff1, strlen("University of Windsor"));
  buff1[strlen("University of Windsor")] = '\0';

  // Return pointer position to end of "Welcome to COMP 8567,"
  lseek(fd, strlen("Welcome to COMP 8567,"), SEEK_SET);

  // Insert new text segment "School of Computer Science," after the course
  // reference
  const char *add_text = " School of Computer Science,";
  write(fd, add_text, strlen(add_text));

  // Append the previously stored university name after the school reference
  write(fd, " ", 1); // Include spacing for readability
  write(fd, buff1, strlen(buff1));

  // Add hyphen to separate course code components
  lseek(fd, strlen("Welcome to COMP"), SEEK_SET);
  write(fd, "-", 1);

  // Advance file position 12 characters beyond current end
  lseek(fd, 12, SEEK_END);

  // Append semester designation at file's end
  const char *winter_text = "Winter 2025";
  write(fd, winter_text, strlen(winter_text));

  // Save changes and release file handle
  close(fd);

  // Access file again to handle null character conversion
  fd = open("lab5.txt", O_RDWR);
  if (fd == -1) {
    perror("Error reopening file");
    return 1;
  }

  // Transfer entire file contents to memory
  char buffer[1024];
  int bytes_read = read(fd, buffer, sizeof(buffer));

  // Convert all null characters to spaces
  for (int i = 0; i < bytes_read; i++) {
    if (buffer[i] == '\0') {
      buffer[i] = ' ';
    }
  }

  // Save updated content back to file
  lseek(fd, 0, SEEK_SET);
  write(fd, buffer, bytes_read);

  // Finalize changes and close file
  close(fd);

  return 0;
}
