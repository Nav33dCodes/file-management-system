#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <windows.h>
#include <stdint.h>

#define COLOR_CYAN     "\033[1;36m"
#define COLOR_YELLOW   "\033[1;33m"
#define COLOR_GREEN    "\033[1;32m"
#define COLOR_RED      "\033[1;31m"
#define COLOR_MAGENTA  "\033[1;35m"
#define COLOR_BLUE     "\033[1;34m"
#define COLOR_RESET    "\033[0m"

// Prototypes
void menu();
void file_ops_submenu();
void create_file();
void write_file();
void read_file();
void delete_file();
void show_metadata();
void generate_cv();
void rename_file();
void copy_file();
void move_file();
void list_directory();
void search_file();
void encrypt_decrypt_file();

void clear_console();
void pause_console();
void print_header(const char* title);
void get_string(const char* prompt, char* buffer, size_t size);
void format_size(double size, char* result, size_t max_len);

int main() {
    // Enable ANSI colors and UTF-8 output on Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    char inputBuffer[100];
    do {
        clear_console();
        menu();
        printf("\n  " COLOR_CYAN "╭─" COLOR_RESET " Enter your choice: " COLOR_CYAN);
        
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) break;
        if (sscanf(inputBuffer, "%d", &choice) != 1) choice = -1;
        printf(COLOR_RESET);

        switch (choice) {
            case 1: create_file(); break;
            case 2: write_file(); break;
            case 3: read_file(); break;
            case 4: file_ops_submenu(); break;
            case 5: show_metadata(); break;
            case 6: list_directory(); break;
            case 7: search_file(); break;
            case 8: encrypt_decrypt_file(); break;
            case 9: generate_cv(); break;
            case 10:
                printf("\n  " COLOR_GREEN "Goodbye! Thank you for using FILE MANAGEMENT SYSTEM.\n" COLOR_RESET);
                exit(0);
            default:
                printf("\n  " COLOR_RED "Invalid Choice! Please enter a number between 1 and 10.\n" COLOR_RESET);
                pause_console();
        }
    } while (1);

    return 0;
}

void clear_console() {
    system("cls");
}

void pause_console() {
    printf("\n  " COLOR_CYAN "Press Enter to continue..." COLOR_RESET);
    char buf[10];
    fgets(buf, sizeof(buf), stdin);
}

void print_header(const char* title) {
    printf("\n");
    printf(COLOR_MAGENTA "  ╔════════════════════════════════════════════════════════════╗\n");
    int padding = (60 - strlen(title)) / 2;
    int extra = (60 - strlen(title)) % 2;
    printf("  ║" COLOR_BLUE "%*s%s%*s" COLOR_MAGENTA "║\n", padding, "", title, padding + extra, "");
    printf("  ╚════════════════════════════════════════════════════════════╝\n" COLOR_RESET);
    printf("\n");
}

void get_string(const char* prompt, char* buffer, size_t size) {
    printf("  " COLOR_YELLOW "» " COLOR_RESET "%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
}

void format_size(double size, char* result, size_t max_len) {
    int i = 0;
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    while (size >= 1024 && i < 4) {
        size /= 1024;
        i++;
    }
    snprintf(result, max_len, "%.2f %s", size, units[i]);
}

void menu() {
    printf("\n");
    /* Retained only as a reference for the original banner artwork. */
    if (0) {
    printf(COLOR_CYAN "  ███████╗██╗██╗     ███████╗███████╗ ██████╗ ██████╗  ██████╗ ███████╗\n");
    printf("  ██╔════╝██║██║     ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝ ██╔════╝\n");
    printf("  █████╗  ██║██║     █████╗  █████╗  ██║   ██║██████╔╝██║  ███╗█████╗  \n");
    printf("  ██╔══╝  ██║██║     ██╔══╝  ██╔══╝  ██║   ██║██╔══██╗██║   ██║██╔══╝  \n");
    printf("  ██║     ██║███████╗███████╗██║     ╚██████╔╝██║  ██║╚██████╔╝███████╗\n");
    printf("  ╚═╝     ╚═╝╚══════╝╚══════╝╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚══════╝\n" COLOR_RESET);

    }

    print_header("FILE MANAGEMENT SYSTEM");
    
    printf("  " COLOR_YELLOW "[ 1 ]" COLOR_RESET " Create a File\n");
    printf("  " COLOR_YELLOW "[ 2 ]" COLOR_RESET " Write to a File\n");
    printf("  " COLOR_YELLOW "[ 3 ]" COLOR_RESET " Read from a File\n");
    printf("  " COLOR_YELLOW "[ 4 ]" COLOR_RESET " Advanced File Operations (Copy, Move, Rename, Delete)\n");
    printf("  " COLOR_YELLOW "[ 5 ]" COLOR_RESET " View File Metadata\n");
    printf("  " COLOR_YELLOW "[ 6 ]" COLOR_RESET " List Directory Contents\n");
    printf("  " COLOR_YELLOW "[ 7 ]" COLOR_RESET " Search for a File\n");
    printf("  " COLOR_YELLOW "[ 8 ]" COLOR_RESET " Encrypt / Decrypt File (XOR)\n");
    printf("  " COLOR_YELLOW "[ 9 ]" COLOR_RESET " Generate Your Resume\n");
    printf("  " COLOR_YELLOW "[ 10]" COLOR_RESET " Exit\n");
}

void file_ops_submenu() {
    int choice;
    char inputBuffer[100];
    do {
        clear_console();
        print_header("ADVANCED FILE OPERATIONS");
        printf("  " COLOR_YELLOW "[ 1 ]" COLOR_RESET " Copy File\n");
        printf("  " COLOR_YELLOW "[ 2 ]" COLOR_RESET " Move File\n");
        printf("  " COLOR_YELLOW "[ 3 ]" COLOR_RESET " Rename File\n");
        printf("  " COLOR_YELLOW "[ 4 ]" COLOR_RESET " Delete File\n");
        printf("  " COLOR_YELLOW "[ 5 ]" COLOR_RESET " Back to Main Menu\n");
        
        printf("\n  " COLOR_CYAN "╭─" COLOR_RESET " Enter your choice: " COLOR_CYAN);
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) break;
        if (sscanf(inputBuffer, "%d", &choice) != 1) choice = -1;
        printf(COLOR_RESET);

        switch (choice) {
            case 1: copy_file(); break;
            case 2: move_file(); break;
            case 3: rename_file(); break;
            case 4: delete_file(); break;
            case 5: return;
            default:
                printf("\n  " COLOR_RED "Invalid Choice! Please enter a number between 1 and 5.\n" COLOR_RESET);
                pause_console();
        }
    } while (1);
}

void create_file() {
    char path[512];
    FILE *fp;

    print_header("CREATE FILE");
    get_string("Enter File Name or Path to Create: ", path, sizeof(path));

    fp = fopen(path, "w");
    if (fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot create file! Check permissions or path.\n" COLOR_RESET);
        pause_console();
        return;
    }
    printf("\n  " COLOR_GREEN "File created successfully at: %s\n" COLOR_RESET, path);
    fclose(fp);
    pause_console();
}

void write_file() {
    char path[512], content[2048];
    FILE *fp;

    print_header("WRITE TO FILE");
    get_string("Enter File Name or Path to Write To: ", path, sizeof(path));

    fp = fopen(path, "a");
    if (fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot open file! Ensure it exists.\n" COLOR_RESET);
        pause_console();
        return;
    }
    get_string("Enter Content to Write:\n  " COLOR_YELLOW "» " COLOR_RESET, content, sizeof(content));

    fprintf(fp, "%s\n", content);
    printf("\n  " COLOR_GREEN "Content written successfully.\n" COLOR_RESET);
    fclose(fp);
    pause_console();
}

void read_file() {
    char path[512], buffer[1024];
    FILE *fp;

    print_header("READ FILE");
    get_string("Enter File Name or Path to Read: ", path, sizeof(path));

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("\n  " COLOR_RED "Error: File not found or access denied!\n" COLOR_RESET);
        pause_console();
        return;
    }
    printf("\n  " COLOR_CYAN "Contents of '%s':\n" COLOR_RESET, path);
    printf("  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("  %s", buffer);
    }
    printf("\n  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    
    fclose(fp);
    pause_console();
}

void delete_file() {
    char path[512];

    print_header("DELETE FILE");
    get_string("Enter File Name or Path to Delete: ", path, sizeof(path));

    if (remove(path) == 0)
        printf("\n  " COLOR_GREEN "File '%s' deleted successfully.\n" COLOR_RESET, path);
    else
        printf("\n  " COLOR_RED "Error: Cannot delete file. It may not exist or is in use.\n" COLOR_RESET);
    pause_console();
}

void show_metadata() {
    char path[512];
    struct stat st;

    print_header("FILE METADATA");
    get_string("Enter File Name or Path for Metadata: ", path, sizeof(path));

    if (stat(path, &st) == 0) {
        char size_str[32];
        format_size((double)st.st_size, size_str, sizeof(size_str));
        
        printf("\n  " COLOR_CYAN "====== Metadata for '%s' ======\n" COLOR_RESET, path);
        printf("  " COLOR_YELLOW "Size     :" COLOR_RESET " %s (%ld bytes)\n", size_str, (long)st.st_size);
        printf("  " COLOR_YELLOW "Created  :" COLOR_RESET " %s", ctime(&st.st_ctime));
        printf("  " COLOR_YELLOW "Modified :" COLOR_RESET " %s", ctime(&st.st_mtime));
        printf("  " COLOR_YELLOW "Accessed :" COLOR_RESET " %s", ctime(&st.st_atime));
    } else {
        printf("\n  " COLOR_RED "Error: Cannot access metadata. File might not exist.\n" COLOR_RESET);
    }
    pause_console();
}

void generate_cv() {
    char path[512];
    char name[128], email[128], phone[64], address[256], edu[512], exp[512], skills[512];
    FILE *fp;

    print_header("GENERATE CV");
    get_string("Enter CV File Name to Save As (e.g., resume.txt): ", path, sizeof(path));

    fp = fopen(path, "w");
    if (fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot create CV file!\n" COLOR_RESET);
        pause_console();
        return;
    }

    get_string("Enter Full Name: ", name, sizeof(name));
    get_string("Enter Email: ", email, sizeof(email));
    get_string("Enter Phone: ", phone, sizeof(phone));
    get_string("Enter Address: ", address, sizeof(address));
    get_string("Enter Education: ", edu, sizeof(edu));
    get_string("Enter Experience: ", exp, sizeof(exp));
    get_string("Enter Skills: ", skills, sizeof(skills));

    fprintf(fp, "============================================================\n");
    fprintf(fp, "                       CURRICULUM VITAE\n");
    fprintf(fp, "============================================================\n\n");
    fprintf(fp, "[ PERSONAL INFORMATION ]\n");
    fprintf(fp, "Name      : %s\n", name);
    fprintf(fp, "Email     : %s\n", email);
    fprintf(fp, "Phone     : %s\n", phone);
    fprintf(fp, "Address   : %s\n\n", address);
    fprintf(fp, "[ EDUCATION ]\n%s\n\n", edu);
    fprintf(fp, "[ EXPERIENCE ]\n%s\n\n", exp);
    fprintf(fp, "[ SKILLS ]\n%s\n\n", skills);
    fprintf(fp, "============================================================\n");

    printf("\n  " COLOR_GREEN "CV elegantly generated and saved successfully at '%s'.\n" COLOR_RESET, path);
    fclose(fp);
    pause_console();
}

void rename_file() {
    char oldname[512], newname[512];

    print_header("RENAME FILE");
    get_string("Enter Current File Name or Path: ", oldname, sizeof(oldname));
    get_string("Enter New File Name or Path: ", newname, sizeof(newname));

    if (rename(oldname, newname) == 0)
        printf("\n  " COLOR_GREEN "File renamed successfully.\n" COLOR_RESET);
    else
        printf("\n  " COLOR_RED "Error: Could not rename file.\n" COLOR_RESET);
    pause_console();
}

void copy_file() {
    char src[512], dest[512];
    char buffer[4096];
    size_t bytesRead;
    FILE *src_fp, *dest_fp;

    print_header("COPY FILE");
    get_string("Enter Source File Name or Path: ", src, sizeof(src));
    get_string("Enter Destination File Name or Path: ", dest, sizeof(dest));

    src_fp = fopen(src, "rb"); 
    if (src_fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot open source file!\n" COLOR_RESET);
        pause_console();
        return;
    }
    
    dest_fp = fopen(dest, "wb");
    if (dest_fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot open destination file!\n" COLOR_RESET);
        fclose(src_fp);
        pause_console();
        return;
    }
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytesRead, dest_fp);
    }

    printf("\n  " COLOR_GREEN "File copied successfully!\n" COLOR_RESET);
    fclose(src_fp);
    fclose(dest_fp);
    pause_console();
}

void move_file() {
    char src[512], dest[512];

    print_header("MOVE FILE");
    get_string("Enter File Name or Path to Move: ", src, sizeof(src));
    get_string("Enter New File Name or Path in Destination: ", dest, sizeof(dest));

    if (rename(src, dest) == 0)
        printf("\n  " COLOR_GREEN "File moved successfully!\n" COLOR_RESET);
    else
        printf("\n  " COLOR_RED "Error: File could not be moved!\n" COLOR_RESET);
    pause_console();
}

void list_directory() {
    char path[512], searchPath[516];
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    print_header("LIST DIRECTORY");
    get_string("Enter Directory Path (e.g., C:\\ or . for current): ", path, sizeof(path));
    
    snprintf(searchPath, sizeof(searchPath), "%s\\*.*", path);
    if ((hFind = FindFirstFile(searchPath, &fdFile)) == INVALID_HANDLE_VALUE) {
        printf("\n  " COLOR_RED "Error: Directory not found or access denied.\n" COLOR_RESET);
        pause_console();
        return;
    }

    printf("\n  " COLOR_CYAN "Contents of '%s':\n" COLOR_RESET, path);
    printf("  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    
    do {
        if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0) {
            if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                printf("  " COLOR_BLUE "[DIR] " COLOR_RESET " %s\n", fdFile.cFileName);
            } else {
                char size_str[32];
                ULARGE_INTEGER fileSize;
                fileSize.LowPart = fdFile.nFileSizeLow;
                fileSize.HighPart = fdFile.nFileSizeHigh;
                format_size((double)fileSize.QuadPart, size_str, sizeof(size_str));
                
                printf("  " COLOR_GREEN "[FILE]" COLOR_RESET " %-30s | %s\n", fdFile.cFileName, size_str);
            }
        }
    } while (FindNextFile(hFind, &fdFile));
    
    FindClose(hFind);
    printf("  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    pause_console();
}

void search_file() {
    char path[512], keyword[256], searchPath[516];
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    int foundCount = 0;

    print_header("SEARCH FILE");
    get_string("Enter Directory Path to Search In: ", path, sizeof(path));
    get_string("Enter Keyword to Search For: ", keyword, sizeof(keyword));

    snprintf(searchPath, sizeof(searchPath), "%s\\*.*", path);
    if ((hFind = FindFirstFile(searchPath, &fdFile)) == INVALID_HANDLE_VALUE) {
        printf("\n  " COLOR_RED "Error: Directory not found or access denied.\n" COLOR_RESET);
        pause_console();
        return;
    }

    printf("\n  " COLOR_CYAN "Search Results for '%s' in '%s':\n" COLOR_RESET, keyword, path);
    printf("  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    
    do {
        if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0) {
            char lowerFileName[512], lowerKeyword[256];
            strncpy(lowerFileName, fdFile.cFileName, sizeof(lowerFileName));
            strncpy(lowerKeyword, keyword, sizeof(lowerKeyword));
            _strlwr(lowerFileName);
            _strlwr(lowerKeyword);

            if (strstr(lowerFileName, lowerKeyword) != NULL) {
                if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    printf("  " COLOR_BLUE "[DIR] " COLOR_RESET " %s\n", fdFile.cFileName);
                } else {
                    printf("  " COLOR_GREEN "[FILE]" COLOR_RESET " %s\n", fdFile.cFileName);
                }
                foundCount++;
            }
        }
    } while (FindNextFile(hFind, &fdFile));
    
    FindClose(hFind);
    if (foundCount == 0) {
        printf("  " COLOR_YELLOW "No matching files found.\n" COLOR_RESET);
    }
    printf("  " COLOR_MAGENTA "────────────────────────────────────────────────────────────\n" COLOR_RESET);
    pause_console();
}

void encrypt_decrypt_file() {
    char src[512], dest[512], key[128];
    FILE *src_fp, *dest_fp;
    size_t bytesRead;
    char buffer[4096];

    print_header("ENCRYPT / DECRYPT FILE (XOR)");
    printf("  " COLOR_YELLOW "Note:" COLOR_RESET " XOR cipher is symmetric. Encrypting an encrypted file decrypts it.\n\n");
    
    get_string("Enter Source File Path: ", src, sizeof(src));
    get_string("Enter Destination File Path: ", dest, sizeof(dest));
    get_string("Enter Encryption Key (Password): ", key, sizeof(key));

    size_t key_len = strlen(key);
    if (key_len == 0) {
        printf("\n  " COLOR_RED "Error: Key cannot be empty!\n" COLOR_RESET);
        pause_console();
        return;
    }

    src_fp = fopen(src, "rb");
    if (src_fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot open source file!\n" COLOR_RESET);
        pause_console();
        return;
    }
    
    dest_fp = fopen(dest, "wb");
    if (dest_fp == NULL) {
        printf("\n  " COLOR_RED "Error: Cannot open destination file!\n" COLOR_RESET);
        fclose(src_fp);
        pause_console();
        return;
    }
    
    size_t key_index = 0;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[key_index % key_len];
            key_index++;
        }
        fwrite(buffer, 1, bytesRead, dest_fp);
    }

    printf("\n  " COLOR_GREEN "File processed successfully and saved to '%s'!\n" COLOR_RESET, dest);
    fclose(src_fp);
    fclose(dest_fp);
    pause_console();
}
