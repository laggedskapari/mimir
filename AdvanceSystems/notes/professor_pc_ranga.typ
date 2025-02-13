#set text(
  font: "Berkeley Mono",
  size: 14pt,
)

#set page(
  paper: "a4"
)

= Advance Systems Programming
#emph[Lecture notes from] *Prof. PC Ranga*


== Lecture: 0
+ *Kernel*
  - It is the core of the unix OS.
  - It directly interact with the hardware and provide service to the applications.
  - *System calls* are used to interact with kernel in order to request service.
  - *Libraries* of common functions are built on top of the systems call interface, but application are free to use both.
  - *Shell* is a special application that provides an interface for running other applications.
  - #emph[*Note*: No application can directly interact with the kernel. (NO BYPASSING THE SYSTEM CALLS)]
    - *Linux* is the kernel for the GNU OS.

+ *Shells*
  - It is a command-line interpreter that reads user input and executes commands.
  - The user interact with shell is normally via a *terminal* or somtimes from a file called #emph[*shell script*].
  - *COMMON SHELLS*:
    + Bourne shell - * /bin/sh *
    + Bourne-again shell - * /bin/bash *
    + C shell - * /bin/csh *
    + Korn shell - * /bin/ksh *
    + TENEX C shell - * /bin/tcsh *
    + Z shell - * /bin/zsh *
  - *COMMON COMMANDS AND VARIABLES*
    + * \$SHELL * - hold the name of current shell.
    + * uname -a * - gives you the linux version.
+ *File System*
  - Unix file system is a hierarchical arrangement of directories and files.
  - Everything starts from the directory called *root*, whose name is *'/'*.
  - *Unix* treats everything as a file, even the directories are files which contains directory entries i.e * filename, structure information about attributes of files and other directories*.
  - *Attributes* of a file:
    + File Name
    + Size
    + File Type (File or Directory)
    + Owner
    + Permissions 
    + Last Modification
  - []*`stat()`* in C returns all the information containing attributes of the file.
  - *Home directory* is denoted by `~` symbol.
+ *Filename* 
  - The only 2 characters that are forbidden in a filename are the '/' and the #underline[NULL] character.
  - Filenames are *Case-Sensitive*.
  - * / * - seprates filenames that form a pathname.
  - *NULL* - terminates a pathname.
  - * POSIX * recommends restricting filenames to consist of the following characters: letter (a-z, A-Z), numbers (0-9), period (.), dash (-), and underscore \_ .
  - *. (dot) and .. (dot-dot)* automatically get created in every directory.
  - *. (dot)* - refers to the current working directory.
  - *.. (dot-dot)* - refers to the parent of the current working directorty.
+ *Pathname*
  - A sequence of one or more filename seprated by slashed and optionally starting with a slash forms a pathname. *(e.g /mimir/AdvanceSystems)*
  - *Absolute pathname* - begins with a '/' *(eg. /home/bin/zsh)*
  - *Relative pathname* - file relative to the current working directory. *(eg. ../mimir/AdvanceSystems)*
  - * / *  - is special case for  absolute pathname that has no file component.
+ *Input and Output* (IO)
  - 3 Files - *Standard Input, Standard Output and Standard Error*
  - All shell open 3 file descriptor whenever a new routine or program runs.
    + *Standard Input*: File descriptor No. 0
    + *Standard Output*: File descriptor No. 1
    + *Standard Error*: File descriptor No. 2
  - Most shell provide a way to redirect any or all of these 3 descriptors to any file. *(eg. `ls > listing.txt`)*
  - *>* : output redirection
  - *<* : input redirection
  - *>>* : output concatenation
#set raw(
  theme: "Gruvbox-N.tmTheme",
  block: true,
  
)

```zsh
$ ls -l > output.txt # output of ls is stored in output.txt
$ sort < output.txt # content of output.txt goes into sort routine and gets sorted.
$ echo $SHELL >> output.txt # append current shell to end of the output.txt file.
```
+ *Pipes*
  - Its is a way to redirect output of a program to a input of another program.
  ```shell
  ls -l | grep .c | wc -w # ls gives all the file, then grep .c filter out all the C files and finally we get the word count.
  ```
+ *Processes and Process IDs*
  - an execution instance of a program is called a process.
  - Some OS call them #emph[task].
  - UNIX system guarantees that every process has a unique numeric identifier called Process ID. The process ID is a non -ve integer.
  - Every process has a process ID, parent process ID and group ID.
  - #emph[*NOTE*]: *swapper* and *sched* has a process ID of 0.

== Lecture: 1
+ *Introduction*
  - Pointers are crucial to C, and they are mainly used to:
    + provide the way by which function can modify their calling arguments.
    + Support dynamic allocation of memory.
    + Refer to a large data structure in a simple manner.
    + Support data structure like linked lists.
+ *Pointers are Addresses*
  - A pointer is a variable whose value is a memory addresses.
  - A pointer variable similar to other variables.
  - A pointer variable store address of another variable.
  - `base type *pointerName`
  - *'\*'* - is used to dereference or declare a pointer.
  - *&* - is used to access memory location.
+ *NULL*
  - It used to indicate that pointer is not pointing to any valid data.
  - *NULL* is defined in *`stdlib.h`*
  - *NULL* is used to indicate a failure operation.
+ *Pointer Arithmetic*
  - When a pointer is incremented (or decremented). It will points to memory location of next element of its base type.
  - ```C ptr + 1 = 204 //ptr is int and int is 4 bytes```
+ *Pointers and Array*
  - The name of the array is the address of the array's first element.
  - e.g `int arr[3];` reserves 3 consecutive unit of memory, each block of size 4.
  - Pointers and array are interchangeable.
  - *Limitations of Pointer arithmetic*
    + \*, / and % can't be used with pointers.
    + 2 pointers *cannot* be added together.
    + Only *integer offsets* can be added to or subtracted from a pointer.
    + A pointer p1 can be subtracted from p2. The result is an integer, the number of elements between p1 and p2.
+ *Generic Pointers*
  - A pointer variable defined as *void* is a generic pointer variable. (It can point to any type)
  - *Advantage*: not type casting is required.
  - You can't dereference a generic pointer.
+ *Dynamic Memory Allocation*
  - *Static allocation*: a variable's memory is allocated and persists throughout the entire life of the program. This is the case of global variable.
  - *Automatic allocation*: when a local variable are declared *inside a function*, the space for these variable is allocated when the function is called (starts) and is freed when the function terminates. This is also the case of parametric variables.
  - *Dynamic allocation*: allow a program at the execution time to allocate memory *when needed* and free it when no longer needed.
    + *Advantage*: it is often impossible to know, prior to the execution time, the size of memory needed in many cases. (e.g. The size of an array based on any size n)
  - Most common used functions for managing dynamic memory are:
    + *`void* malloc(int size)`*: to allocate a block (number of bytes) of memory of a given *size* and returns a pointer to this newly allocated block.
    + *`void free(void *ptr)`*: to free previously allocated block of memory. 
  - #emph[*CODE*]
```C
#include <stdio.h>

int main(void) {
  int num = 100;
  int *b;

  b = &num;
  printf("*b: %d\n", *b); // 100

  int **c;
  c = &b;
  printf("**c: %d\n", **c); // 100

  int ***d;
  d = &c;
  printf("***d: %d\n", ***d); // 100
}



#include <stdio.h>

int main() {
  int n1 = 10, n2;
  int *ptr;

  ptr = &n1;
  n2 = *ptr;
  printf("n1: %d  n2: %d  *ptr: %d\n", n1, n2,
         *ptr); // n1: 10  n2: 10  *ptr: 10
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int *createArray(size_t size) {
  int *ptr = malloc(sizeof(int));
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  return ptr;
}

int main() {
  int *arr = createArray(1000);
  if (arr == NULL) {
    return 1;
  }

  free(arr);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int *createArray(size_t size) {
  int *ptr = malloc(sizeof(int));
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  return ptr;
}

int main() {
  int *arr = createArray(1000);
  if (arr == NULL) {
    return 1;
  }

  free(arr);
  return 0;
}
```

== Lecture 2
+ *File IOs*
  - File descriptors are used by kernel to address a open file. *(NON -VE)*
  - *1, 2 and 3* are reserved and are assigned to standard IO and error.
  - UNIX has declared the reserved one with a symbolic constant, defined in `<unistd.h>` for these values are:
    + *STDIN_FILENO*: Standart Input - 0
    + *STDOUT_FILENO*: Standard Output - 1
    + *STDERR_FILENO*: Standard Error - 2
  - User processes can only get file descriptors > 2.
  - File descriptor range from 0 through `OPEN_MAX` (a symbolic constant i.e defined by the OS).
  - They are unbuffered cause they come under system calls.

+ *`open()`*
  - File is created and open by it. (Created only when file doesn't alreadt exists)
  - *Function*:
  - ```C
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int open(const char *pathname, int oflag, mode_t mode);
```
  - *`pathname`*: absolute or relative.
  - *`oflag`*: formed by bitwise OR `|` constants. (e.g. O_RDONLY, O_WRONLY, etc)
  - *`mode_t`*: only used when creating file.
  - When creating a file, `mode_t` goes through a default umask (#emph[file permisson = asked file permission - umask]). (e.g. 0777 - 0022 = 0755)
  - 

+ *`read()`*
  - Data is read from an open file.
  - *Function*
```C
#include<unistd.h>
ssize_t read(int filedes, void *buff, size_t nbytes);
```
  - *`filedes`*: file descriptor.
  - *`*buff\`* : buffer to store output.
  - *`size_t`* : size of the output.
  - returns: number of bytes read, 0 if end of file, -1 on error.
  - also read the UTF character.
+ *`write()`*
  - Data is written to an open file with write function.
  - *Function*:
```C
#include<unistd.h>

ssize_t write(int filedes, const void *buff, size_t nbytes)
```
+ *`close()`*
  - free the file descriptor.
  - returns 0 when OK and -1 otherwise. (e.g. -1 if already closed and try to close again)
+  *`lseek()`*
  - It is used to change the file offset.
  - *Function*: 
```C
#include<sys/types.h>
#include<unistd.h>

off_t lseek(int filedes, off_t offset, int whence);
```
  - returns new file offset if OK, -1 on error.
  - by default it is intialized to 0, when a file is opened, unless O_APPEND is specified.
  - *`SEEK_SET`*: offset is set to #emph[offset] bytes from the beginning of the file.
  - *`SEEK_CUR`*: offset is set to current value + #emph[offset]. (#emph[offset] can be +ve and -ve)
  - *`SEEK_END`*: offset is set to the size of the file plus the #emph[offset]. (The #emph[offset] can be +ve or -ve)
  - *#emph[NOTE]*: UTF characters are included and have a size of 8 bits. (UTF character is can also be changed to \n)

== Lecture 3
+ *Unix Process*
  - Unix is a multi-user and multitasking OS.
  - Users can run their programs concurrently and shared hardware resources.
  - An *user can run multiple programs* and task concurrently.
  - It appears that execution is done in parallel, however in reality OS switches between mutliple users and process rapidly in an interleaved manner.
  - *Unix Processes*:
    + Any routine is a process.
    + ex.c (Program) > ex (executable) > ./ex (process).
  - Every process in UNIX has: 
    + PID
    + Some code
    + Some data
    + Stack
    + env
  - Unix start as a single process, called *init*, and it has a PID 1.
  - The only way to create a new process in Unix, is to duplicate an existing one.
  - The process init is the ancestor of all subsequent processes.
  - Process *init* never dies.
  - The *spawning* of new process is done with 2 *system calls*.
    + *`fork()`*: duplicated the called process.
    + *`exex()`*: replaces the called process by a new one.
#image("Screenshot 2025-02-12 at 9.00.30 PM.png", width: 100%, height: 50%)
+ *`fork()`*
  - It is used to create new child process.
  - *Function*:
```C
#include<sys/types.h>
#include<unistd.h>

pid_t fork(void);
```
  - returns 0 in child, PID of child in parent, -1 on error.
  - is called *once*, but returns *twice*.
  - The reason for returning 0 in child because child can do `getppid();` to get parent PID;
  - The reason for returning child PID in parent because child can have more `fork();` to create more child.
  - File descriptors are inherited, therefore *parent* and *child* have same file descriptors.
  - *`fork();`* performs in cocurrency.
  - Execution resumes at the line after the `fork()` statement in both *parent* and *child*.
  - *Parent* and *Child* have different scope that means same variable can different values in execution.
  - *Usage*:
    + A process wants to execute another program.
    + A program needs to execute subtask. (e.g. Server/sockets)
  - $ "Total Process" = 2^n - 1 $
