#include STM32_HAL_H

#include "common.h"
#include "display.h"
#include "rng.h"

void __attribute__((noreturn)) __fatal_error(const char *expr, const char *msg, const char *file, int line, const char *func) {
    display_orientation(0);
    display_backlight(255);
    display_print_color(COLOR_WHITE, COLOR_RED128);
    display_printf("\nFATAL ERROR:\n");
    if (expr) {
        display_printf("expr: %s\n", expr);
    }
    if (msg) {
        display_printf("msg : %s\n", msg);
    }
    if (file) {
        display_printf("file: %s:%d\n", file, line);
    }
    if (func) {
        display_printf("func: %s\n", func);
    }
#ifdef GITREV
#define XSTR(s) STR(s)
#define STR(s) #s
    display_printf("rev : %s\n", XSTR(GITREV));
#endif
    shutdown();
    for (;;);
}

uint32_t __stack_chk_guard = 0;

void __attribute__((noreturn)) __stack_chk_fail(void)
{
    ensure(secfalse, "Stack smashing detected");
}

#ifndef NDEBUG
void __assert_func(const char *file, int line, const char *func, const char *expr) {
    __fatal_error(expr, "assert failed", file, line, func);
}
#endif

void hal_delay(uint32_t ms)
{
    HAL_Delay(ms);
}
