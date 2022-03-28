#pragma once

#define ESC(x) "\x1b[" #x
#define RESET   ESC(0m)
#define BKGRND  ESC(30;1m) // CONSOLE BACKGROUND - was BLACK
#define BLACK   ESC(31;1m) // BLACK - was RED
#define WHITE   ESC(32;1m) // WHITE - was GREEN
#define BLUE    ESC(33;1m) // BLUE - was YELLOW
#define RED     ESC(34;1m) // RED - was BLUE
#define YELLOW  ESC(35;1m) // GRAY1 - was MAGENTA
#define GREEN   ESC(36;1m) // GRAY2 - was CYAN
#define CYAN    ESC(37;1m) // GRAY3 - was WHITE

void console_init(void);

__attribute__((format(printf,1,2)))
void console_set_status(const char *fmt, ...);

__attribute__((format(printf,1,2)))
void console_print(const char *fmt, ...);

__attribute__((format(printf,1,2)))
void debug_print(const char *fmt, ...);

void console_render(void);
