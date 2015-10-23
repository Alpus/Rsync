#include "Classes/FileManager.cpp"
#include "Hashers/md5.h"

int main() {
    char * file_name = "Resources/input";
    FileManager file(file_name, 0x100);
    MD5_CTX *md5_result;
    MD5_Init(md5_result);
    MD5_Update(md5_result, file.get_next_page(), 0x100);
    unsigned char* string_md5;
    MD5_Final(string_md5, md5_result);
    std::cout << string_md5;
    return 0;
}