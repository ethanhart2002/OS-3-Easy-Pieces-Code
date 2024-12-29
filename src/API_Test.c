#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>


int fork_test() {
  int x = 0;
  int f = fork();
  if (f == 0) {
    int *newX = &x + 1;
    printf("Ah. You just got forked. Here's x addy + 1: %p \n", newX);
    return 0;
  } else {
    printf("Parent Type Beat. X: %d \n", x);
    return 0;
  }
  return 0;

}

int open_test() {
  int fd = open("./lala.txt", O_RDWR, O_TRUNC);
  if (fd < 0) {
    printf("Error opening file.");
  } else {
    int f = fork();
    if (f==0) {
      char* message1 = "Forkd!!!\n";
      write(fd, message1, strlen(message1));
      close(fd);
    } else {
      
      char* message2 = "This is your father.\n";
      write(fd, message2, strlen(message2));
      close(fd);
    }
  }
  return 0;
}

int fork_test_two() {
    int f = fork();
    if (f == 0) {
      printf("Hopefully I printed first.... \n");
    } else {
      printf("I better be printed second. \n");
    }
    return 0;
}

int main() {
  //int openTest = open_test();
  //int forkTest = fork_test();
  int forkTestTwo = fork_test_two();
  return 0;
}


  
