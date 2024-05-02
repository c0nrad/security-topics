#include <seccomp.h>

#include <cstdlib>
#include <iostream>

int main() {
    std::cout << "Start: cout" << std::endl;
    system("echo 'Start: system'");

    // SECCOMP
    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_KILL);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
    seccomp_load(ctx);

    std::cout << "End: cout" << std::endl;
    system("echo 'End: system'");

    return 0;
}
