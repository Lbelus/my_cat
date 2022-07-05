/*
    /\                                                                                                                                            \
(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)
    \/''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''/
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                               ....                                          |
    |                                                                                             .'' .'''                                        |
    |                                                              .                             .'   :                                           |
    |                    .                .                        \\                          .:    :                                            |
    |                    :"-.          .-";                         \\                        _:    :       ..----.._                             |
    |                    |:`.`.__..__.'.';|                          \\                    .:::.....:::.. .'         ''.                          |
    |                    || :-"      "-; ||                           \\                 .'  #-. .-######'     #        '.                        |
    |                    :;              :;                            \\                 '.##'/ ' ################       :                       |
    |                    /  .==.    .==.  \                             \\                  #####################         :                       |
    |                   :      _.--._      ;                             \\               ..##.-.#### .''''###'.._        :                       |
    |                   ; .--.' `--' `.--. :                              \\             :--:########:            '.    .' :                      |
    |                  :   __;`      ':__   ;                              \\..__...--.. :--:#######.'   '.         '.     :                      |
    |                  ;  '  '-._:;_.-'  '  :                              :     :  : : '':'-:'':'::        .         '.  .'                      |
    |                  '.       `--'       .'                              '---'''..: :    ':    '..'''.      '.        :'                        |
    |                   ."-._          _.-".                                  \\  :: : :     '      ''''''.     '.      .:                        |
    |                 .'     ""------""     `.                                 \\ ::  : :     '            '.      '      :                       |
    |                /`-                    -'\                                 \\::   : :           ....' ..:       '     '.                     |
    |               /`-                      -'\                                 \\::  : :    .....####\\ .~~.:.             :                    |
    |              :`-   .'              `.   -';                                 \\':.:.:.:'#########.===. ~ |.'-.   . '''.. :                   |
    |              ;    /                  \    :                                  \\    .'  ########## \ \ _.' '. '-.       '''.                 |
    |             :    :                    ;    ;                                 :\\  :     ########   \ \      '.  '-.        :                |
    |             ;    ;                    :    :                                :  \\'    '   #### :    \ \      :.    '-.      :               |
    |             ':_:.'                    '.;_;'                               :  .'\\   :'  :     :     \ \       :      '-.    :              |
    |                :_                      _;                                 : .'  .\\  '  :      :     :\ \       :        '.   :             |
    |                ; "-._                -" :`-.     _.._                     ::   :  \\'  :.      :     : \ \      :          '. :             |
    |                :_          ()          _;   "--::__. `.                   ::. :    \\  : :      :    ;  \ \     :           '.:             |
    |                 \"-                  -"/`._           :                    : ':    '\\ :  :     :     :  \:\     :        ..'               |
    |                .-"-.                 -"-.  ""--..____.'                       :    ' \\ :        :     ;  \|      :   .'''                  |
    |               /         .__  __.         \                                    '.   '  \\:                         :.''                      |
    |              : / ,       / "" \       . \ ;                                    .:..... \\:       :            ..''                          |
    |               "-:___..--"      "--..___;-"                                    '._____|'.\\......'''''''.:..'''                              |
    |                                                                                          \\                                                 |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                                                                                                                             |
    |                                    ███╗   ███╗██╗   ██╗     ██████╗ █████╗ ████████╗                                                        |
    |                                    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██╔══██╗╚══██╔══╝                                                        |
    |                                    ██╔████╔██║ ╚████╔╝     ██║     ███████║   ██║                                                           |
    |                                    ██║╚██╔╝██║  ╚██╔╝      ██║     ██╔══██║   ██║                                                           | 
    |                                    ██║ ╚═╝ ██║   ██║       ╚██████╗██║  ██║   ██║                                                           |
    |                                    ╚═╝     ╚═╝   ╚═╝        ╚═════╝╚═╝  ╚═╝   ╚═╝                                                           |
    |                                                                                                                                             |          
    /\''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\    
(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)
    \/____________________________________________________________________________________________________________________________________________/


*/



#include <unistd.h>
#include<fcntl.h> 

// /*
// */

#define SIZE 512



void read_on(char** argv, int fd, int write_fd){
    int file_input = 0;
    char file_buffer[SIZE]; 
    while((file_input = read(fd,file_buffer,SIZE))){
        write(write_fd, file_buffer, file_input);
    }

    close(fd);
}
    
void write_user_input(char** argv, int fd, int write_fd){
    int User_input=0;
    char User_buffer[SIZE];
    User_input = read(1, User_buffer, SIZE);
    write(fd, User_buffer, User_input); 
    close(fd);
}

void copy_on_file(char** argv, int fd, int write_fd){
    int size_block= 0;
    int size_fd = 0;
    int initial_size = 0;
    char file_RDON_buffer[SIZE];

    while((size_block = read(fd, file_RDON_buffer, SIZE))){
        size_fd = size_fd +size_block;   
    };

    char file_RnW_buffer[size_fd];

    while((initial_size = read(write_fd,file_RnW_buffer,size_fd))){
        write(write_fd, file_RnW_buffer, size_fd);
    }

    close(fd);
    close(write_fd);
}

void copy_to_previous_file(char** argv, int fd, int write_fd, int write_last_fd){
    int size_block= 0;
    int size_fd = 0;
    int initial_size = 0;
    char file_RDON_buffer[SIZE];

    while((size_block = read(fd, file_RDON_buffer, SIZE))){
        size_fd = size_fd +size_block;   
    };

    char file_RnW_buffer[size_fd];

    while((initial_size = read(write_fd,file_RnW_buffer,size_fd))){
        write(write_last_fd, file_RnW_buffer, size_fd);
    }

    close(fd);
    close(write_fd);
    close(write_last_fd);
}


int main(int argc, char** argv){
    int fd = 0, i = 0, write_fd = 0, write_last_fd = 0, ref= 0 ;
    for(int y = 2; y < argc; y++){
        i++;
        if(argv[i][0] == '-'){
            for(int x = 1; argv[i][x] != '\0'; x++ ){
                char flag = argv[i][x];
                switch(flag){
                case 'r': // output file on STDOUT;
                    fd = open(argv[y], O_RDONLY);
                    write_fd = 1;
                    read_on(argv, fd, write_fd); 
                break;
                case 'w': // Write on file from STDIN. Can append to an existing file or create a new one.
                    fd = open(argv[y], O_RDWR | O_APPEND | O_CREAT, 0644);
                    write_fd = fd;
                    write_user_input(argv, fd, write_fd);
                break;
                case 'c': // copy from file descriptor to the same file. 
                    fd = open(argv[y], O_RDONLY);
                    write_fd = open(argv[y], O_RDWR | O_APPEND | O_CREAT, 0644);
                    copy_on_file(argv, fd, write_fd);
                break;
                case 'p': // copy from file descriptor to the another file. Can append to an existing file or create a new one.
                    fd = open(argv[y+1], O_RDONLY);
                    write_fd = open(argv[y+1], O_RDWR | O_APPEND | O_CREAT, 0644);
                    write_last_fd = open(argv[y], O_RDWR | O_APPEND | O_CREAT, 0644);
                    copy_to_previous_file(argv, fd, write_fd, write_last_fd);
                break;
                case 'f': // copy from as many file descriptor as you like to the another file. Can append to an existing file or create a new one.
                    ref = y;
                    while(y < argc-1){
                        y++;
                        fd = open(argv[y], O_RDONLY);
                        write_fd = open(argv[y], O_RDONLY);
                        write_last_fd = open(argv[ref], O_RDWR | O_APPEND | O_CREAT, 0644);
                        copy_to_previous_file(argv, fd, write_fd, write_last_fd);
                    }
                break;
                }
            }
        }
    }
    return 0;
} 


/*


copy from begining of file but not to end
    int User_input;
    int file_input;
    char User_buffer[SIZE];
    char buffer[SIZE];
    User_input = read(fd, buffer, SIZE);
    
    while((file_input = read(write_fd,User_buffer,SIZE))){
        write(write_fd, User_buffer, User_input);
    }
    
    write(write_fd, User_buffer, User_input); 
     //Copy file : write(fd, buffer, size); // write on stdout : write(1, "\n blah \n", 10);// write on file : write(fd, "\n blah \n", 10); // char str1[4]; // Write from stdin to files : // write from sdtin to stdout: char str1[4]; fgets (str1, 60, stdin); write(1, str1, 3); 
    close(fd);

*/

/* make gig blank files.

#include <stdio.h>
#include <unistd.h>
#include<fcntl.h> 



#define SIZE 512

void copy_on_file(char** argv, int y, int fd, int write_fd){
    int User_input;
    int file_input;
    char User_buffer[SIZE];
    char buffer[SIZE];
    User_input = read(fd, buffer, SIZE);
    
    while((file_input = read(fd,User_buffer,SIZE))){
        write(write_fd, User_buffer, User_input);
    }
    
    write(fd, User_buffer, User_input); 
     //Copy file : write(fd, buffer, size); // write on stdout : write(1, "\n blah \n", 10);// write on file : write(fd, "\n blah \n", 10); // char str1[4]; // Write from stdin to files : // write from sdtin to stdout: char str1[4]; fgets (str1, 60, stdin); write(1, str1, 3); 
    close(fd);
    }


int main(int argc, char** argv){
    int fd = 0, i = 0, write_fd = 0;
    for(int y = 2; y < argc; y++){
        i++;
        if(argv[i][0] == '-'){
            for(int x = 1; argv[i][x] != '\0'; x++ ){
                char flag = argv[i][x];
                switch(flag){
                case 'c':
                    fd = open(argv[y], O_RDONLY);
                    write_fd = open(argv[y], O_RDWR | O_APPEND | O_CREAT, 0644);
                    copy_on_file(argv, y, fd, write_fd);
                break;
                }
            }
        }
    }
    return 0;
} 



    */