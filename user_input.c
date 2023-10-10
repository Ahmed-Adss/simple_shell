char *user_input (void)
{
        char *command = NULL;
        size_t length = 0;
        ssize_t get_line;

        get_line = getline(&command, &length, stdin)
        if (get_line == -1)
        {
                if (feof(stdin))
                {
                        free (command);
                        exit (EXIT_SUCCESS);
                }else {
                        free (command);
                        exit (EXIT_FAILURE);
                }
        }
        return (command);
}

