#include <stdio.h>
#include <sys/auxv.h>
#include <sys/time.h>
#include <time.h>

int main() {
    void *vdso = (void *)getauxval(AT_SYSINFO_EHDR);
    void *vvar = vdso - 0x4000;

    printf("currentime: %ld\n", time(NULL));
    printf("vvar: %p\n", vvar);

    for (int i = 0; i < 0x1000; i += 8) {
        unsigned long v = *(unsigned long *)(vvar + i);
        printf("%p: %lx %ld\n", vvar + i, v, v);
    }
}