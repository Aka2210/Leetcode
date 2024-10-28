#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../include/command.h"
#include "../include/builtin.h"

// ======================= requirement 2.3 =======================
/**
 * @brief 
 * Redirect command's stdin and stdout to the specified file descriptor
 * If you want to implement ( < , > ), use "in_file" and "out_file" included the cmd_node structure
 * If you want to implement ( | ), use "in" and "out" included the cmd_node structure.
 *
 * @param p cmd_node structure
 * 
 */
void redirection(struct cmd_node *p){
	if(p->in_file != NULL)
	{
		int file = open(p->in_file, O_RDONLY);
		if(file < 0)
		{
			perror("file open failed");
			_exit(-1);
		}
		dup2(file, p->in);
		close(file);
	}
	
	if(p->out_file != NULL)
	{
		int file = open(p->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(file < 0)
		{
			perror("file open failed");
			_exit(-1);
		}
		dup2(file, p->out);
		close(file);
	}

	if(p->in != STDIN_FILENO)
	{
		dup2(p->in, STDIN_FILENO);
	}

	if(p->out != STDOUT_FILENO)
	{
		dup2(p->out, STDOUT_FILENO);
	}
}
// ===============================================================

// ======================= requirement 2.2 =======================
/**
 * @brief 
 * Execute external command
 * The external command is mainly divided into the following two steps:
 * 1. Call "fork()" to create child process
 * 2. Call "execvp()" to execute the corresponding executable file
 * @param p cmd_node structure
 * @return int 
 * Return execution status
 */
int spawn_proc(struct cmd_node *p)
{
	int status;
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
		exit(-1);
	}
	else if(pid == 0)
	{
		redirection(p);
		execvp(p->args[0], p->args);
		_exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
  	return 1;
}
// ===============================================================


// ======================= requirement 2.4 =======================
/**
 * @brief 
 * Use "pipe()" to create a communication bridge between processes
 * Call "spawn_proc()" in order according to the number of cmd_node
 * @param cmd Command structure  
 * @return int
 * Return execution status 
 */
int fork_cmd_node(struct cmd *cmd)
{
	int *pipe_prv = NULL;
	while(cmd->head != NULL)
	{
		if(pipe_prv != NULL)
		{
			close(pipe_prv[0]);
			close(pipe_prv[1]);
		}

		if(cmd->head->next != NULL)
		{
			int pipe_fd[2];
			pipe(pipe_fd);
			cmd->head->out = pipe_fd[1];
			cmd->head->next->in = pipe_fd[0];
			pipe_prv = pipe_fd[0];
			pipe_prv = pipe_fd[1];
		}
		spawn_proc(cmd->head);
		cmd->head = cmd->head->next;
	}
	close(pipe_prv[0]);
	close(pipe_prv[1]);
	return 1;
}
// ===============================================================


void shell()
{
	while (1) {
		printf(">>> $ ");
		char *buffer = read_line();
		if (buffer == NULL)
			continue;

		struct cmd *cmd = split_line(buffer);
		
		int status = -1;
		// only a single command
		struct cmd_node *temp = cmd->head;
		
		if(temp->next == NULL){
			status = searchBuiltInCommand(temp);
			if (status != -1){
				int in = dup(STDIN_FILENO), out = dup(STDOUT_FILENO);
				if( in == -1 | out == -1)
					perror("dup");
				redirection(temp);
				status = execBuiltInCommand(status,temp);

				// recover shell stdin and stdout
				if (temp->in_file)  dup2(in, 0);
				if (temp->out_file){
					dup2(out, 1);
				}
				close(in);
				close(out);
			}
			else{
				//external command
				status = spawn_proc(cmd->head);
			}
		}
		// There are multiple commands ( | )
		else{
			
			status = fork_cmd_node(cmd);
		}
		// free space
		while (cmd->head) {
			
			struct cmd_node *temp = cmd->head;
      		cmd->head = cmd->head->next;
			free(temp->args);
   	    	free(temp);
   		}
		free(cmd);
		free(buffer);
		
		if (status == 0)
			break;
	}
}
