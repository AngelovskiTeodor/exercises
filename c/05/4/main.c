#include <stdio.h>

void m() {
    printf_s("m");
}

void c() {
    printf_s("c");
}

void d() {
    printf_s("d");
}

void l() {
    printf_s("l");
}

void x() {
    printf_s("x");
}

void v() {
    printf_s("v");
}

void i() {
    printf_s("i");
}

int main()
{
    int num;
    printf_s("");
    scanf_s("%d", &num);

    do {
        if (num >= 1000) {
            m();
            num -= 1000;
            continue;
        }

        if (num >= 900) {
            c();m();
            num -= 900;
            continue;
        }

        if (num >= 500) {
            d();
            num -= 500;
            continue;
        }

        if (num >= 400) {
            c();d();
            num -= 400;
            continue;
        }

        if (num >= 100) {
            c();
            num -= 100;
            continue;
        }

        if (num >= 90) {
            x();c();
            num -= 90;
            continue;
        }

        if (num >= 50) {
            l();
            num -= 50;
            continue;
        }

        if (num >= 40) {
            x();l();
            num -= 40;
            continue;
        }

        if (num >= 10) {
            x();
            num -= 10;
            continue;
        }

        if (num >= 9) {
            i();x();
            num -= 9;
            continue;
        }

        if (num >= 5) {
            v();
            num -= 5;
            continue;
        }

        if (num >= 4) {
            i();v();
            num -= 4;
            continue;
        }

        if (num >= 1) {
            i();
            num -= 1;
            continue;
        }

    } while (num > 0);

    return 0;
}
