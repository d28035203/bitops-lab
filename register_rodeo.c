/* register-rodeo — bit-level drills (set/clear/toggle/popcount/print) */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static void print_bits(uint32_t x) {
    for (int i = 31; i >= 0; i--) {
        putchar((x >> i) & 1U ? '1' : '0');
        if (i % 8 == 0 && i) putchar(' ');
    }
    printf("  (0x%08X / %u)\n", x, x);
}

static uint32_t set_bit(uint32_t x, unsigned b) { return x | (1U << b); }
static uint32_t clear_bit(uint32_t x, unsigned b) { return x & ~(1U << b); }
static uint32_t toggle_bit(uint32_t x, unsigned b) { return x ^ (1U << b); }
static int get_bit(uint32_t x, unsigned b) { return (int)((x >> b) & 1U); }

static int popcount(uint32_t x) {
    int n = 0;
    while (x) { n += x & 1U; x >>= 1; }
    return n;
}

static void usage(const char *argv0) {
    fprintf(stderr,
        "usage:\n"
        "  %s show <n>\n"
        "  %s set <n> <bit>\n"
        "  %s clear <n> <bit>\n"
        "  %s toggle <n> <bit>\n"
        "  %s get <n> <bit>\n"
        "  %s popcount <n>\n"
        "  %s demo\n",
        argv0, argv0, argv0, argv0, argv0, argv0, argv0);
}

int main(int argc, char **argv) {
    if (argc < 2) { usage(argv[0]); return 2; }
    const char *cmd = argv[1];

    if (strcmp(cmd, "demo") == 0) {
        uint32_t x = 0;
        x = set_bit(x, 0);
        x = set_bit(x, 3);
        x = set_bit(x, 7);
        printf("after set 0,3,7: "); print_bits(x);
        x = toggle_bit(x, 3);
        printf("toggle 3:        "); print_bits(x);
        x = clear_bit(x, 0);
        printf("clear 0:         "); print_bits(x);
        printf("popcount: %d\n", popcount(x));
        return 0;
    }

    if (argc < 3) { usage(argv[0]); return 2; }
    uint32_t n = (uint32_t)strtoul(argv[2], NULL, 0);

    if (strcmp(cmd, "show") == 0) {
        print_bits(n);
        return 0;
    }
    if (strcmp(cmd, "popcount") == 0) {
        printf("%d\n", popcount(n));
        return 0;
    }
    if (argc < 4) { usage(argv[0]); return 2; }
    unsigned b = (unsigned)strtoul(argv[3], NULL, 0);
    if (b > 31) { fprintf(stderr, "bit must be 0..31\n"); return 2; }

    if (strcmp(cmd, "set") == 0) { print_bits(set_bit(n, b)); return 0; }
    if (strcmp(cmd, "clear") == 0) { print_bits(clear_bit(n, b)); return 0; }
    if (strcmp(cmd, "toggle") == 0) { print_bits(toggle_bit(n, b)); return 0; }
    if (strcmp(cmd, "get") == 0) { printf("%d\n", get_bit(n, b)); return 0; }

    usage(argv[0]);
    return 2;
}
