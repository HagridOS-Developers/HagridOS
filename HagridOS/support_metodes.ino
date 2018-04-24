void clear_input_buffer() {
  for (int i = 0; i < 59; i++) {
    input[i] = '\0';
  }
  pos = 0;
}

void kbsplit(char input[70])
{
    int a = 0;
    tmpE[a] = strtok(input, " ");
    a++;
    for (int i = 0; i <= 3; i++)
    {
        tmpE[a] = strtok(NULL, " ");
        a++;
    }
}


int compare(char* input[2])
{
    int tmpC =0;
    int tmpB = 0;
    tmpC = 0;
    do
    {
        tmpB = strcasecmp(commands[tmpC], input[0]);
        if (tmpB == 0)
        {
            break;
        }
        tmpC++;
    }
    while (tmpC < command_count);
    return tmpC;
}
