#include "main.h"

char *get_location(char *command){
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    struct stat buffer;

    path = getenv("PATH");

    if (path){
        /* duplicate path string and free up memory for strdup */ 
        path_copy = strdup(path);
        /* lenght of commands passed */
        command_length = strlen(command);

        /* to get all available directories and path variables */
        path_token = strtok(path_copy, ":");

        while(path_token != NULL){
            /* for legth of the directory */
            directory_length = strlen(path_token);
            /* memory allocation to store directory and command name */
            file_path = malloc(command_length + directory_length + 2);
            /* build a path for command by copying and concatenate to it */
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            /* test if path exists or not or test for next directory */
            if (stat(file_path, &buffer) == 0){
                /* 0 if successfull if file_path valid*/

                /* free up allocated memory before returning your file_path */
                free(path_copy);

                return (file_path);
            }
            else{
     		/* to free up file_path memory and check another one */
                free(file_path);
                path_token = strtok(NULL, ":");

            }

        }

        /* if file_path does not exist return NULL but free path_copy memory */ 
        free(path_copy);

        /* If unsuccessfull check if command is a file_path*/
        if (stat(command, &buffer) == 0)
        {
            return (command);
        }


        return (NULL);

    }


    return (NULL);
}
