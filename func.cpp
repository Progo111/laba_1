#include "header.h"

int Intenger(const char *arr) {// Делает строку int
    int res = static_cast<int>(arr[0]) % 48;
    for (int i = 1; arr[i] != '\0'; ++i) {
        res = res * 10 + (static_cast<int>(arr[i]) % 48);
    }
    return res;
}


char *element(const char *arr, int &i) {
    static bool flag = true;
    int cnt = i;
    char *res = new char[0];
    while (arr[i] == ' ') {
        i++;
    }
    int j = 0;
    if (arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/' && arr[i] != '(' && arr[i] != ')') {
        while (arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/' && arr[i] != '(' &&
               arr[i] != ')' && arr[i] != '\0' && arr[i] != ' ') {
            res[j] = arr[i];
            ++j;
            ++i;
        }
        if (flag) {
            i = cnt;
            flag = false;
        } else { flag = true; }
        return res;
    }
    res[j] = arr[i];
    i++;
    if (flag) {
        i = cnt;
        flag = false;
    } else {
        flag = true;
    }
    return res;
}

int isSign(char *arr) {//Приоритет знаков
    if (strcmp(arr, "+") == 0) {
        return 1;
    } else if (strcmp(arr, "-") == 0) {
        return -1;
    } else if (strcmp(arr, "*") == 0) {
        return 2;
    } else if (strcmp(arr, "/") == 0) {
        return -2;
    } else if (strcmp(arr, "(") == 0) {
        return 3;
    } else if (strcmp(arr, ")") == 0) {
        return -3;
    }
    return 0;
}

bool isChar(char *arr) {
    if (strcmp(arr, "A") < 0) {
        return false;
    }
    return true;
}

int Direct(char *arr, int &counter) {
    int i = 0;
    int *number = new int[0];
    int *sign = new int[0];
    int number_index = -1;
    int sign_index = -1;
    bool flag_1 = false;
    while (strcmp(element(arr, counter), "\0") != 0) {
        i++;
        char *used = element(arr, counter);
        if (isChar(used)) {
            std::cerr << "ERROR_input_char";
            return EXIT_FAILURE;
        } else if (isSign(used) == 0) {
            number_index++;
            number[number_index] = Intenger(used);
            flag_1 = false;
        } else if (sign_index == -1) {
            sign_index++;
            sign[sign_index] = isSign(used);

            if (isSign(used) == 3) {
                flag_1 = true;
            } else if (isSign(used) == -3) {
                std::cerr << "ERROR";
                return EXIT_FAILURE;

            }
        } else if (isSign(used) == 3) {
            sign_index++;
            sign[sign_index] = isSign(used);

            flag_1 = true;
        } else if (sign[sign_index] == 3) {
            if (!flag_1) {
                sign_index++;
                sign[sign_index] = isSign(used);
            } else {
                if (isSign(used) == 1) {
                    number_index++;
                    number[number_index] = 0;
                    sign_index++;
                    sign[sign_index] = isSign(used);
                } else if (isSign(used) == -1) {
                    number_index++;
                    number[number_index] = 0;
                    sign_index++;
                    sign[sign_index] = isSign(used);
                } else {
                    std::cerr << "ERROR";
                    return EXIT_FAILURE;
                }
            }
        } else if (isSign(used) == -3) {
            int exRes = 0;
            while (sign[sign_index] != 3) {
                if (sign[sign_index] == 2) {
                    exRes = number[number_index - 1] * number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == -2) {
                    exRes = number[number_index - 1] / number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == 1) {
                    exRes = number[number_index - 1] + number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == -1) {
                    exRes = number[number_index - 1] - number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                }
                if (sign[sign_index] == 3) {
                    break;
                }
            }
            sign_index--;
        } else {
            if (abs(isSign(used)) > abs(sign[sign_index])) {
                sign_index++;
                sign[sign_index] = isSign(used);
            } else {
                int exRes = 0;
                while (abs(sign[sign_index]) >= abs(isSign(used)) && sign_index != -1 && abs(sign[sign_index]) != 3) {
                    //cout<<i<<std::endl;
                    if (sign[sign_index] == 2) {
                        exRes = number[number_index - 1] * number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == -2) {
                        exRes = number[number_index - 1] / number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == 1) {
                        exRes = number[number_index - 1] + number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == -1) {
                        exRes = number[number_index - 1] - number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    }
                }
                sign_index++;
                sign[sign_index] = isSign(used);
            }
        }
    }
    while (sign_index != -1) {
        int exRes = 0;
        if (sign[sign_index] == 2) {
            exRes = number[number_index - 1] * number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == -2) {
            exRes = number[number_index - 1] / number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == 1) {
            exRes = number[number_index - 1] + number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == -1) {
            exRes = number[number_index - 1] - number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        }
    }
    return number[number_index];
}

int postFix(char *arr, int &counter) {
    int i = -1;
    int *number = new int[0];
    int *sign = new int[0];
    int number_index = -1;
    int sign_index = -1;
    bool flag_1 = false;
    while (strcmp(element(arr, counter), "\0") != 0) {
        i++;
        char *used = element(arr, counter);
        if (isChar(used)) {
            std::cerr << "ERROR_input_char";
            return EXIT_FAILURE;
        } else if (isSign(used) == 0) {
            number_index++;
            number[number_index] = Intenger(used);
            flag_1 = false;
        } else if (sign_index == -1) {
            sign_index++;
            sign[sign_index] = isSign(used);
            if (isSign(used) == 3) {
                flag_1 = true;
                std::cerr << "ERROR";
                return EXIT_FAILURE;
            } else if (isSign(used) == -3) {
                std::cerr << "ERROR";
                return EXIT_FAILURE;

            }
        } else if (isSign(used) == 3) {
            sign_index++;
            flag_1 = true;
            sign[sign_index] = isSign(used);
        } else if (sign[sign_index] == 3) {
            if (!flag_1) {
                sign_index++;
                sign[sign_index] = isSign(used);
            } else {
                if (isSign(used) == 1) {
                    number_index++;
                    number[number_index] = 0;
                    sign_index++;
                    sign[sign_index] = isSign(used);
                } else if (isSign(used) == -1) {
                    number_index++;
                    number[number_index] = 0;
                    sign_index++;
                    sign[sign_index] = isSign(used);
                } else {
                    std::cerr << "ERROR";
                    return EXIT_FAILURE;
                }
            }
        } else if (isSign(used) == -3) {
            int exRes = 0;
            while (sign[sign_index] != 3) {
                if (sign[sign_index] == 2) {
                    exRes = number[number_index - 1] * number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == -2) {
                    exRes = number[number_index - 1] / number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == 1) {
                    exRes = number[number_index - 1] + number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                } else if (sign[sign_index] == -1) {
                    exRes = number[number_index - 1] - number[number_index];
                    sign_index--;
                    number_index--;
                    number[number_index] = exRes;
                }
                if (sign[sign_index] == 3) {
                    break;
                }
            }
            sign_index--;
        } else {
            if (abs(isSign(used)) > abs(sign[sign_index])) {
                sign_index++;
                sign[sign_index] = isSign(used);
            } else {
                int exRes = 0;
                while (abs(sign[sign_index]) >= abs(isSign(used)) && sign_index != -1) {
                    if (sign[sign_index] == 2) {
                        exRes = number[number_index - 1] * number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == -2) {
                        exRes = number[number_index - 1] / number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == 1) {
                        exRes = number[number_index - 1] + number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    } else if (sign[sign_index] == -1) {
                        exRes = number[number_index - 1] - number[number_index];
                        sign_index--;
                        number_index--;
                        number[number_index] = exRes;
                    }
                }
                sign_index++;
                sign[sign_index] = isSign(used);
            }
        }
    }
    while (sign_index != -1) {
        int exRes = 0;
        if (sign[sign_index] == 2) {
            exRes = number[number_index - 1] * number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == -2) {
            exRes = number[number_index - 1] / number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == 1) {
            exRes = number[number_index - 1] + number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        } else if (sign[sign_index] == -1) {
            exRes = number[number_index - 1] - number[number_index];
            sign_index--;
            number_index--;
            number[number_index] = exRes;
        }
    }
    return number[number_index];
}
