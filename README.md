# Holberton Shell (hsh)

## NAME
	hsh - holberton simple shell, a simple UNIX command language interpreter

## DESCRIPTION

The *hsh* is a simple UNIX command language interpreter that executes commands read from standard input. The shell works in interactive and non interactive mode just as well. Examples of how both of these modes work are included in the *USAGE* section.

When a command is called on the *hsh*, the program will first check for it's existance in the current directory (or in the specified pathname). If a regular, executable file is found, the program will call the *fork()* syscall, and the newly created child process will call *execve* and execute the passed command on the child process, while the parent process waits for its completion. If a something else than a regular file is found (for example: a directory, or a symbolic link), the program will print to standard error that the passed command is not a regular file, and prompt the user for a new input.

If the command isn't an existing pathname and can't be found, the program will search for the command in all of the directories listed in the environment variable **PATH**. If a regular, executable file is found, just as before, the program calls *fork()* and executes the command in the shild process while the parent waits for completion. If a non regular file is found, the program will print an according message to standard error, and prompt the user for a new input.

Some of the commands do not call *execve* and instead are built-ins. Examples of this are: the *env* command, which prints out the environment (same as *printenv*) and the *exit [status]* which exits the shell with an exit status inseted by the user, or 0 if no exit status is specified.  

To exit the shell in interactive mode, two main options are available: (1) type `exit [status]` (+ Carriage Return) when prompted for an input, or (2) type `Ctrl + D`, which signifies an End of File (*EOF*). The shell **is** case sensitive (meaning that `EXIT` will be unrecognized, and won't exit the shell), but any spaces or tabs inserted before or after the typed command won't be registered. In interactive mode, the `Ctrl + C` input from the user sends a SIGINT signal which terminates a child process if one is executing, but it won't exit the shell.


## INSTALLATION

To run the *hsh* on your console, simply *clone* or *fork* the repository. The `Makefile` in the repository contains the recommened compiler and flags used in compilation. To compile the program, simply type `make` in the command line. Once compiled, the shell can be run in interactive mode by running `./hsh`, or non interactively by running `echo "*command*" | ./hsh`. If additional scrutiny is desired, the command `make run` will run the created executable with `valgrind` to detect memory leaks and aditional errors. 


## USAGE AND EXAMPLES

#### Interactive Mode Example

	# ./hsh
	$ qwerty
	./hsh: 1: qwerty: not found
	$ pwd
	/holbertonschool-simple_shell
	$ which ls
	/usr/bin/ls
	$ ls
	env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c
	$ exit 98
	# echo $?
	98 

#### Non-interactive Mode Example

	# echo "qwerty" | ./hsh
	./hsh: 1: qwerty: not found
	# echo "pwd" | ./hsh
	/holbertonschool-simple_shell
	# echo "which ls" | ././hsh
	/usr/bin/ls
	# echo "ls" | ./hsh
	env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c


## UNAVAILABLE OPTIONS AND SHORTCOMINGS

Unlike the *sh* shell, or more advanced shells (like *ash*, *zsh* or *bash*), the *hsh* doesn't support pipes, special characters (like wildcards, $$ or $?), I/O redirection and other advanced features. The *hsh* can't recieve it's input from other files, and doesn't accept the options that the regular *sh* does (such as -c or -s, for example).

The `hsh` doesn't keep track of the history of commands, and (when used in interactive mode) it can't be navigated using the arrows.
