#include <avr/io.h>
#include "simple_io.h"
#include "test.h"

static void initUart(uint32_t baud_rate);
static writeChar(char c);

int main(int argc, char **argv)
{
    initUart(38400);
    IO_printLine("hello");
    TEST_runTests();
    IO_printLine("bye");
    while (1) {
    }
    return 0;
}

static void initUart(uint32_t baud_rate)
{
    uint16_t ubbr = F_CPU / 16UL / baud_rate - 1;
    UBRR0H = (uint8_t) (ubbr>>8);
    UBRR0L = (uint8_t) ubbr;
    UCSR0A = 0;
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02);
    UCSR0C = ((0<<UMSEL01) | (0<<UMSEL00) |
              (0<<UPM01) | (0<<UPM00) |
              (0<<USBS0) |
              (1<<UCSZ01) | (1<<UCSZ00) |
              (0<<UCPOL0));
}

void IO_printLine(const char *line)
{
    const char *p;
    for (p = line; *p != '\0'; p++) {
        writeChar(*p);
    }
    writeChar('\r');
    writeChar('\n');
}

static writeChar(char c)
{
    UDR0 = c;
    while (!(UCSR0A & (1<<TXC0))) {
    }
    UCSR0A |= (1<<TXC0);
}
