
#include "header.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Enter the \"--forward\" or \"--reverse\"flag first. And if you want to read from the file \"--file\"."<<"\n";
        return EXIT_FAILURE;
    } else if (strcmp(argv[1], "--forward") == 0) {
        char *arr = new char[200];
        int counter = 0;
        if (argc > 3 && strcmp(argv[2], "--file") == 0) {
            std::ifstream file(argv[3]);
            if (file.is_open()) {
                char f = file.get();
                for (int i = 0; !file.eof(); i++) {//считываем строку
                    arr[i] = f;
                    f = file.get();
                }
                cout << "Answer: " << Direct(arr, counter) << std::endl;
                file.close();
            } else {
                cout << "ERROR: file is not open" << std::endl;
                file.close();
            }
        } else if (argc == 2) {
            cout << "Enter an expression. For example \"5 + 5 * 100\"" << "\n";
            int a = getchar();
            char S = a;
            for (int i = 0; a != '\n'; i++) {//считываем строку
                arr[i] = S;
                a = getchar();
                S = a;
            }
            cout << "Answer: " << Direct(arr, counter) << std::endl;
        }
        delete[] arr;
        return 0;
    } else if (strcmp(argv[1], "--reverse") == 0) {
        char *arr = new char[200];
        int counter = 0;
        if (argc > 3 && strcmp(argv[2], "--file") == 0) {
            std::ifstream file(argv[3]);
            if (file.is_open()) {
                char f = file.get();
                for (int i = 0; !file.eof(); i++) {//считываем строку
                    arr[i] = f;
                    f = file.get();
                }
                cout << "Answer: " << postFix(arr, counter) << std::endl;
                file.close();
            } else {
                cout << "ERROR: file is not open" << std::endl;
                file.close();
            }
        } else if (argc == 2) {
            cout << "Enter an expression. For example \"1 2 + 4 × 3 +\"" << "\n";
            int a = getchar();
            char S = a;
            for (int i = 0; a != '\n'; i++) {//считываем строку
                arr[i] = S;
                a = getchar();
                S = a;
            }
            cout << "Answer: " << postFix(arr, counter) << std::endl;
        }
        delete[] arr;
        return 0;
    } else {
        std::cerr << "Enter the \"--forward\" or \"--reverse\"flag first. And if you want to read from the file \"--file\"."<<"\n";
        return EXIT_FAILURE;
    }
}
