/**
 * @file L1F20ASCS0028_ADP41_Task6.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C program that lists all the processes owned by you and associated with your terminal.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
/**
 * @file L1F20ASCS0028_ADP41_Task6.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C program that lists all the processes owned by you and associated with your terminal.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright sipakhti (c) 2022
 * 
 */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

    execlp("ps", "ps","-u", NULL);

    return 0;
}