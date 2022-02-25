struct stat;
struct rtcdate;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int add(void);
int waitpid(int, int*, int);
int exitS(int) __attribute__((noreturn)); //part a
int waitS(int*);                          //part b
int waitpid(int, int*, int);              //part c
int debug(void);                              //part e
int set_prior(int);                  //Lab2
int getprior(void);                       //Lab2
int set_aging(int);                       //Lab2
int tw_time(void);                        //Lab2
int output_flag(int);                     //Lab2
int donate(int);                          //Lab2

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
