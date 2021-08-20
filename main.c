#include "shell.h"

/**char * my_strtok(char *buffer, const char *delimiter){
	
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
}*/

char **tokenizer(char *buffer, char *delimiter){
	char **token = NULL;
	size_t i = 0;
	unsigned int count = 1;

	if (buffer == NULL){
		return (NULL);
	}

	token = malloc(sizeof(char *) *count);

	if (token == NULL){
		return (NULL);
	}

	if (*buffer == '\n' || *buffer == ' ' && *(buffer + 1) == '\0'){
		return (NULL);
	}

	while ((token[i] = my_strtok(buffer,delimiter)) != NULL){
		i++;
		if (i >= count){
			token = realloc(token, sizeof(char *) * (i + 1));
			if (token == NULL){
				return (NULL);
			}
			buffer = NULL;
		}
		return (token);
	}
}

int main (void){

    char buffer[] = "azucar limon";
    char *delimiter = " ";
    char **array;
    
	array = tokenizer(buffer, delimiter);
    
	while(*array != NULL)
    {
        printf("%s\n",*array);
        array++;
    }
    return(0);
}
