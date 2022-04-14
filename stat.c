#include <stdio.h>
#include <sys/stat.h>
// #include <sys/sysmacros.h>


// https://man7.org/linux/man-pages/man2/lstat.2.html
// https://linuxhint.com/stat-system-call-linux/
int main( int argc, char *argv[] )  {
  struct stat info;
  stat(argv[1], &info);

  printf("Information about file at path: %s\n\n", argv[1]);
  // https://man7.org/linux/man-pages/man3/major.3.html
  printf("1. st_dev: %d. Describes the device on which the file resides.\n", info.st_dev);
  printf("2. st_ino: %d. Inode number. It is the serial number of file, unique for each file.\n", info.st_ino);
  printf("3. st_mode: %d. Contains the file type and mode\n",info.st_mode);

  // https://man7.org/linux/man-pages/man7/inode.7.html
  switch (info.st_mode & S_IFMT){
    case S_IFSOCK:
      printf("The file type is socket\n");
      break;
    case S_IFLNK:
      printf("The file type is symbolic link\n");
      break;
    case S_IFREG:
      printf("The file type is regular file\n");
      break;
    case S_IFBLK:
      printf("The file type is block device\n");
      break;
    case S_IFDIR:
      printf("The file type is directory\n");
      break;
    case S_IFCHR:
      printf("The file type is character device\n");
      break;
    case S_IFIFO:
      printf("The file type is FIFO\n");
      break;
    default:
      printf("The file type is unkowon\n");
  }
  return 0;
}