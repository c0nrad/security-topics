#include <stdio.h>
#include <sys/auxv.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <time.h>

int main() {
    void *vdso = (void *)getauxval(AT_SYSINFO_EHDR);
    void *vvar = vdso - 0x4000;

    printf("currentime: %ld\n", time(NULL));
    printf("vvar: %p\n", vvar);

    int result = mprotect(vvar, 0x4000, PROT_READ | PROT_WRITE);
    if (result == -1) {
        perror("mprotect");
        return 1;
    }

    int offsets[3] = {0xa0, 0xf0, 0x150};

    for (int i = 0; i < sizeof(offsets) / sizeof(offsets[0]); i++) {
        unsigned long *v = (unsigned long *)(vvar + offsets[i]);
        *v = 0xdeadbeef;
        printf("%p: %lx %ld\n", v, *v, *v);
    }
}