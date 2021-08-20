#include "shell.h"

char * my_strtok(char *buffer, const char *delimiter){
	
	static char *keep = NULL;
	char *put = NULL;
    char *str = NULL;
    
    if (buffer == NULL){
        buffer = keep;
    }
    buffer = buffer;

    if (*buffer != '\0'){
        put = buffer;
        if (!*put){
            keep = '\0';
        }
        else{
            str = put;
            while (*put != *delimiter && *put != '\0'){
                put++;
            }
            if (*put != '\0'){
                *put = '\0';
                put ++;
            }
            keep = put;
        }
    }
    return (str);
}
