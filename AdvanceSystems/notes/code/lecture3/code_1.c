#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  int fileDescriptor = open("check.txt", O_CREAT | O_RDWR, 0777);
  printf("File Descriptor: %d\n", fileDescriptor); // FD = 3

  char *writeBuff = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20";
  long int byteWritten;

  byteWritten = write(fileDescriptor, writeBuff, strlen(writeBuff));
  printf(
      "Buffer: %s\n",
      writeBuff); // Buffer: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  printf("Byte Written: %ld\n", byteWritten); // Byte Written: 50
  close(fileDescriptor);

  fileDescriptor = open("check.txt", O_CREAT | O_RDWR, 0777);

  char *buff1[100];
  long int byteRead;

  byteRead = read(fileDescriptor, buff1, 100);

  printf("Bytes read: %ld\n", byteRead); // Bytes read: 50
  printf("Buffer: %s\n",
         buff1); // Buffer: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

  close(fileDescriptor);

  // --------------------------------------------------------------------

  fileDescriptor = open("check.txt", O_CREAT | O_RDWR, 0777);
  char *buff2[100];
  int offset;
  offset = lseek(fileDescriptor, 10, SEEK_SET);
  char *writeBuff2 = "Bald Headed Demon";
  byteWritten = write(fileDescriptor, writeBuff2, strlen(writeBuff2)); // 17
  printf("Offset: %d\n", offset);
  printf("Byte Written: %ld\n", byteWritten);
  // Offset: 10
  // Byte Written: 17
  // 1 2 3 4 5 Bald Headed Demon13 14 15 16 17 18 19 20

  offset = lseek(fileDescriptor, 10, SEEK_CUR); // SEEK_CUR = 27
  printf("Offset: %d\n", offset);
  char *writeBuff3 = "D";
  byteWritten = write(fileDescriptor, writeBuff3, strlen(writeBuff3));
  printf("Byte Written: %ld\n", byteWritten);
  // Offset: 37
  // Byte Written: 1
  // 1 2 3 4 5 Bald Headed Demon13 14 15 1D 17 18 19 20

  offset = lseek(fileDescriptor, 0, SEEK_CUR);
  printf("Offset: %d\n", offset);
  // Offset: 38

  offset = lseek(fileDescriptor, -100, SEEK_CUR);
  printf("Offset: %d\n", offset);
  // Offset: -1 (offset don't move cause we can't go back 100 bytes from 38)

  offset = lseek(fileDescriptor, 100, SEEK_END); // SEEK_END = 50
  printf("Offset: %d\n", offset);
  byteWritten = write(fileDescriptor, writeBuff3, strlen(writeBuff3));
  printf("Byte Written: %ld\n", byteWritten);
  // Offset: 150
  // Byte Written: 1
  // 1 2 3 4 5 Bald Headed Demon13 14 15 1D 17 18 19 20<HOLE OF 100>D

  offset = lseek(fileDescriptor, 100, SEEK_END); // SEEK_END = 151
  printf("Offset: %d\n", offset);
  byteWritten = write(fileDescriptor, writeBuff3, strlen(writeBuff3));
  printf("Byte Written: %ld\n", byteWritten);
  // Offset: 251
  // Byte Written: 1
  // 1 2 3 4 5 Bald Headed Demon13 14 15 1D 17 18 19 20<HOLE OF 100>D<HOLE OF
  // 100>D

  offset = lseek(fileDescriptor, 0, SEEK_CUR);
  printf("Offset: %d\n", offset);
  // Offset: 252

  close(fileDescriptor);

  return 0;
}
