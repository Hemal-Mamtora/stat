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
  printf("1. st_dev: %ld. Describes the device on which the file resides.\n", info.st_dev);
  printf("2. st_ino: %ld. Inode number. It is the serial number of file, unique for each file.\n", info.st_ino);
  printf("3. st_mode: %d. Contains the file type and mode: ",info.st_mode);

  // https://man7.org/linux/man-pages/man7/inode.7.html
  switch (info.st_mode & S_IFMT){
    case S_IFSOCK:
      printf("The file type is socket.\n");
      break;
    case S_IFLNK:
      printf("The file type is symbolic link.\n");
      break;
    case S_IFREG:
      printf("The file type is regular file.\n");
      break;
    case S_IFBLK:
      printf("The file type is block device.\n");
      break;
    case S_IFDIR:
      printf("The file type is directory.\n");
      break;
    case S_IFCHR:
      printf("The file type is character device.\n");
      break;
    case S_IFIFO:
      printf("The file type is FIFO.\n");
      break;
    default:
      printf("The file type is unknown.\n");
  }

  printf("4. st_link: %ld. Number of hard links to the file\n", info.st_nlink);

  printf("5. st_uid: %d. User ID of the owner of the file\n", info.st_uid);
  printf("6. st_gid: %d. Group ID of the owner of the file\n", info.st_gid);
  
  printf("7. st_rdev: %ld. Device type, for special file inode\n", info.st_rdev);

  if (info.st_mode & S_IFMT == S_IFLNK){
    // symbolic link
    printf("8. st_size: %ld. Size of the symbolic link path name (without terminating null byte).\n", info.st_size);
  } else{
    printf("8. st_size: %ld. Size of the file in bytes.\n", info.st_size);
  }

  printf("9. st_blksize: %ld. \"preferred\" block size.\n", info.st_blksize);

  printf("10. st_blocks: %ld. Number of blocks allocated to the file, in 512-byte units.\n", info.st_blocks);

  printf("11. st_atime: %ld. Time last accessed.\n", info.st_atime);
  printf("12. st_mtime: %ld. Time last modified.\n", info.st_mtime);
  printf("13. st_ctime: %ld. Time last changed.\n", info.st_ctime);

  printf("\n");
  printf("Access permissions: 0 == no, 1 == yes:\n");
  printf("Does owner have read or write or execute permission? %d\n", (info.st_mode & S_IRWXU) != 0);
  printf("Does owner have read permission? %d\n", (info.st_mode & S_IRUSR) != 0);
  printf("Does owner have write permission? %d\n", (info.st_mode & S_IWUSR) != 0);
  printf("Does owner have execute permission? %d\n", (info.st_mode & S_IXUSR) != 0);

  printf("Does group have read or write or execute permission? %d\n", (info.st_mode & S_IRWXG) != 0);
  printf("Does group have read permission? %d\n", (info.st_mode & S_IRGRP)!= 0);
  printf("Does group have write permission? %d\n", (info.st_mode & S_IWGRP)!= 0);
  printf("Does group have execute permission? %d\n", (info.st_mode & S_IXGRP)!= 0);
  
  
  printf("Do others have read or write or execute permission? %d\n", (info.st_mode & S_IRWXO)!= 0);
  printf("Do others have read permission? %d\n", (info.st_mode & S_IROTH)!= 0);
  printf("Do others have write permission? %d\n", (info.st_mode & S_IWOTH)!= 0);
  printf("Do others have execute permission? %d\n", (info.st_mode & S_IXOTH)!= 0);
  printf("\n");

  return 0;
}