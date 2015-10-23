#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>

class FileManager {
    void *data;
    char *pathname;
    int descriptor;
    size_t page_size;
    off_t off;

    bool get_descriptor(char *pathname) {
        descriptor = open(pathname, O_RDONLY);
        return descriptor != -1;
    }
public:
    FileManager(char *pathname = "Resources/input", size_t page_size = 0x100): off(0),
                                                                               data(NULL),
                                                                               pathname(pathname),
                                                                               page_size(page_size) {
        FileManager();
        if (!get_descriptor) {
            std::cerr << "Bad file" << std::endl;
            return;
        }
    }

    void *get_next_page () {
        if ((data = mmap(NULL, page_size, PROT_READ, MAP_SHARED, descriptor, off))
            == MAP_FAILED) {
            std::cerr << "Fail" << std::endl;
            return data;
        }
        off += page_size;
    }
};