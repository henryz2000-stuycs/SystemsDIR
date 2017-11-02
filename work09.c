#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

unsigned long get_size(struct dirent *entry){
  struct stat sb;
  stat(entry->d_name, &sb);
  //printf("%s", entry->d_name);
  return sb.st_size;
}

char * get_directories(struct dirent *entry){
  if (entry->d_type == DT_DIR){
    return entry->d_name;
  }
  return "\n";
}

char * get_files(struct dirent *entry){
  if (entry->d_type == DT_REG){
    return entry->d_name;
  }
  return "\n";
}

int main(){
  DIR * dir = opendir(".");
  struct dirent *entry = readdir(dir);
  
  printf("Statistics for directory: .\n");
  printf("Total Directory Size: %lu Bytes\n", get_size(entry));
  printf("Directories:\n");
  while (entry){
    printf("%s", get_directories(entry));
    if (get_directories(entry) != "\n"){
      entry = readdir(dir);
    }
  }
  printf("Regular files:\n");
  while(entry){
    printf("%s", get_files(entry));
    if (get_files(entry) != "\n"){
      entry = readdir(dir);
    }
  }
  
  closedir(dir);
}
