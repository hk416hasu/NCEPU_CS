int printf(const char *format, ...);
int (*output)(const char *format, ...)  = printf; // a func-ptr called "output" to printf()

void func_1 (int num) {
    (*output)("%d\n", ++num);
}

int main() {
    (*output)("byebye world\n");
    void (*func_1_ptr)(int) = func_1;
    (*func_1_ptr)(10);


    return 0;
}
