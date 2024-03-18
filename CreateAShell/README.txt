Group Members:
Siddhi Shinde
Peyton Malueax

Submission Contents:
Main.c: Source code for the shell program.
README.txt: This file.


Compilation Instructions:
Compile the shell program using the provided source code with the following command:
	gcc main.c -o project1

Execution Instructions:
	*Run the compiled shell program using the following command:
	gcc main.c -o project1 followed by: ./project1

Built-in Commands:
	*exit: Terminate the shell process.
	*cd [PATH]: Change the present working directory.
	*showpid: Show the last 5 child process IDs created by the shell.

NOTE:
	OMS Folder is temporary folder to test cd command.

Challenges Encountered:
	*Probelems Running Program with MakeFile:
		Runs perfectly fine with: gcc main.c -o project1 followed by ./project1
		When we run with the makefile we get hard to understand warnings.

	*Ensuring proper handling of command execution and built-in commands.
	*Managing the child process ID history for showpid.

Sources Used:
	*Standard C library documentation.
	*Ubuntu, libraries for POSIX functions
	*Online resources for understanding fork(), execvp(), and waitpid() usage.
