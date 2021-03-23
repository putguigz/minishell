# minishellrose

expected commands:

export (sans arg) -> "declre -x var" affichage var alpha

## gpetit 
- [ ] pwd
- [ ] env
- [ ] cd
- [ ] echo
- [ ] unset
- [ ] exit

## ndemont 
- [ ] export 

allowed functions:

printf
malloc
free
write
open
read
close

fork -- create a new process

wait -- wait for process termination

witpid

wait3 -- wait for process termination

wait4 -- wait for process termination

signal -- simplified software signal facilities

kill -- terminate or signal a process

exit

getcwd -- get working directory pathname

chdir

stat -- display file status

lstat -- get file status

fstat -- get file status

execve -- execute a file

dup -- duplicate an existing file descriptor

dup2 -- duplicate an existing file descriptor

pipe - Postfix delivery to external command

opendir -- directory operations

readdir -- directory operations

closedir -- directory operations

strerror -- system error messages

errno -- introduction to system calls and error numbers

isatty -- get name of associated terminal (tty) from file descriptor

ttyname -- get name of associated terminal (tty) from file descriptor

ttyslot -- get name of associated terminal (tty) from file descriptor

ioctl -- control device

getenv -- environment variable functions

tcsetattr -- manipulating the termios structure

tcgetattr -- manipulating the termios structure

tgetent - direct curses interface to the terminfo capability database

tgetflag - direct curses interface to the terminfo capability database

tgetnum - direct curses interface to the terminfo capability database

tgetstr - direct curses interface to the terminfo capability database

tgoto - direct curses interface to the terminfo capability database

tputs - direct curses interface to the terminfo capability database

## List data

- [ ] struct gloabale avec tout 
- [ ] liste chainees de commandes (termcap)
- [ ] struct par commande 
- [ ] arbre binaire de commandes relatives a la ligne
- [ ] le current path (cd)
- [ ] le retour de la derniere commande ($?)
