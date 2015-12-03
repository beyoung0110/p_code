int main ()
{
    pid_t child;
    if( (child = fork()) == -1)
    {
        printf("Fork Error: %s.\n", strerror(errno));
        exit(1);
    }
    else if(child > 0)
    {
        if(kill(getppid(), SIGTRRM) == -1)
        {
            printf("Kill Parent Error: %s.\n", strerror(errno));
            exit(1);
        }
        int mailfd;
        while(1)
        {
            if((mailfd = open(MAIL, O_RDONLY)) != -1)
            {
                fprintf(stderr, "%s", "\007");
                close(mailfd);
            }
            sleep(SLEEP_TIME);
        }
    }
}
