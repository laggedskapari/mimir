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
  - *`stat()`* in C returns all the information containing attributes of the file.
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
)

```zsh
$ ls -l > output.txt # output of ls is stored in output.txt
$ sort < output.txt # content of output.txt goes into sort routine and gets sorted.
$ echo $SHELL >> output.txt # append current shell to end of the output.txt file.
```
