/**
 * Assignment 2: Simple UNIX Shell
 * @file prog.cpp
 * @author Denay Stokely
 * @brief A simple UNIX shell supporting: 
 *              - Command execution
 *              - Background execution (&)
 *              - Command history (!!)
 *              - Input redirection (<) 
 *              - Output redirection (>) 
 *              - Single pipe(|)
 */

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

#define MAX_LINE 80 //Maximum length of a command

// Store last command for history
char last_command[MAX_LINE] = "";

/**
 * Parse command into args separated by space
 * 
 * splits the input string by spaces and stores tokens in args[]. 
 * The argument list is terminated with NULL as required by execvp().
 * 
 * @param command Input command string
 * @param args Array of argument pointers
 * @return int Number of arguments parsed 
 */
int parse_command(char command[], char *args[])
{
    int i = 0;
    char *token = strtok(command, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL; // execvp requires NULL termination
    return i;
}

/**
 *@brief Main shell loop
 */
int main()
{
    char command[MAX_LINE]; //User input buffer
    char *args[MAX_LINE / 2 + 1]; // Parsed arguments

    while (true)
    {
        printf("osh> ");
        fflush(stdout);

//Read user input 
        if (fgets(command, MAX_LINE, stdin) == NULL)
            break;

        // Remove newline
        command[strcspn(command, "\n")] = '\0';

        // ---------------- HISTORY (!!) ----------------
        if (strcmp(command, "!!") == 0)
        {
            if (strlen(last_command) == 0)
            {
                cout << "No command history found." << endl;
                continue;
            }
            else
            {
                cout << last_command << endl;
                strcpy(command, last_command);
            }
        }
        else
        {
            if (strlen(command) > 0)
                strcpy(last_command, command);
        }

//Built-in exit command
        if (strcmp(command, "exit") == 0)
            break;

        // ---------------- HANDLE & WITHOUT SPACE ----------------
        int background = 0;
        int len = strlen(command);
        if (len > 0 && command[len - 1] == '&')
        {
            background = 1;
            command[len - 1] = '\0';
        }

        // ---------------- HANDLE PIPE ----------------
        char *pipe_pos = strchr(command, '|');
        if (pipe_pos != NULL)
        {
            *pipe_pos = '\0'; //Split command into two parts
            char *cmd1 = command;
            char *cmd2 = pipe_pos + 1;

            int fd[2];
            pipe(fd);

            pid_t pid1 = fork();

            //First child: executes left command
            if (pid1 == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);

                char *args1[MAX_LINE / 2 + 1];
                parse_command(cmd1, args1);
                execvp(args1[0], args1);
                cout << "Command not found" << endl;
                exit(1);
            }

            pid_t pid2 = fork();

            //Second child: executes right command
            if (pid2 == 0)
            {
                dup2(fd[0], STDIN_FILENO);
                close(fd[1]);
                close(fd[0]);

                char *args2[MAX_LINE / 2 + 1];
                parse_command(cmd2, args2);
                execvp(args2[0], args2);
                cout << "Command not found" << endl;
                exit(1);
            }

//Parent closes pipe and waits 
            close(fd[0]);
            close(fd[1]);

            wait(NULL);
            wait(NULL);
            continue;
        }

        // ---------------- REDIRECTION ----------------
        char *input_file = NULL;
        char *output_file = NULL;

        char *in_pos = strchr(command, '<');
        char *out_pos = strchr(command, '>');

        if (in_pos != NULL)
        {
            *in_pos = '\0';
            input_file = strtok(in_pos + 1, " ");
        }

        if (out_pos != NULL)
        {
            *out_pos = '\0';
            output_file = strtok(out_pos + 1, " ");
        }

//Parse command after removing redirection symbols 
        parse_command(command, args);
        if (args[0] == NULL)
            continue;

        // ---------------- FORK ----------------
        pid_t pid = fork();

        if (pid == 0) //Child process
        {
            // Input redirection
            if (input_file != NULL)
            {
                int fd = open(input_file, O_RDONLY);
                if (fd < 0)
                {
                    cout << "Command not found" << endl;
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }

            // Output redirection
            if (output_file != NULL)
            {
                int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }

            execvp(args[0], args);

            //Only executes if execvp fails 
            cout << "Command not found" << endl;
            exit(1);
        }
        else   //Parent process
        {
            if (!background)
                wait(NULL);   //Wait for foreground process
        }
    }

    return 0;
}
