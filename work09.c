#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

unsigned long get_size(){
  DIR * dir = opendir(".");
  struct dirent *entry = readdir(dir);
  unsigned long ans = 0;
  struct stat sb;
  
  while (entry){
    if (entry->d_type == DT_REG){
      stat(entry->d_name, &sb);
      //printf("%s\n", entry->d_name);
      ans += sb.st_size;
    }
    entry = readdir(dir);
  }
  
  closedir(dir);

  return ans;
}

void get_directories(){
  DIR * dir = opendir(".");
  struct dirent *entry = readdir(dir);

  while (entry){
    if (entry->d_type == DT_DIR){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(dir);
  }

  closedir(dir);
}

void get_files(){
  DIR * dir = opendir(".");
  struct dirent *entry = readdir(dir);

  while (entry){
    if (entry->d_type == DT_REG){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(dir);
  }

  closedir(dir);
}

int main(){
    
  printf("Statistics for directory: .\n");
  printf("Total Directory Size: %lu Bytes\n", get_size());
  printf("Directories:\n");
  get_directories();
  printf("Regular files:\n");
  get_files();
    
}
