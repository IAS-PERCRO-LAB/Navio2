#include <Navio2/Led_Navio2.h>
#ifdef NAVIO1
#include <Navio+/Led_Navio.h>
#endif
#include <Common/Util.h>
#include <unistd.h>
#include <memory>


std::unique_ptr<Led> get_led() {
#ifdef NAVIO1
    if (get_navio_version() == NAVIO2) {
#endif
        auto ptr = std::unique_ptr<Led>{new Led_Navio2()};
        return ptr;
#ifdef NAVIO1
    } else {
        auto ptr = std::unique_ptr<Led>{new Led_Navio()};
        return ptr;
    }
#endif
}

int main(int argc, char *argv[]) {

    if (check_apm()) {
        return 1;
    }

    if (getuid()) {
        fprintf(stderr, "Not root. Please launch like this: sudo %s\n", argv[0]);
    }


    auto led = get_led();
    if (!led->initialize())
        return EXIT_FAILURE;

    while (true) {
        led->setColor(Colors::Green);
        printf("LED is green\n");
        sleep(1);

        led->setColor(Colors::Cyan);
        printf("LED is cyan\n");
        sleep(1);

        led->setColor(Colors::Blue);
        printf("LED is blue\n");
        sleep(1);

        led->setColor(Colors::Magenta);
        printf("LED is magenta\n");
        sleep(1);

        led->setColor(Colors::Red);
        printf("LED is red\n");
        sleep(1);

        led->setColor(Colors::Yellow);
        printf("LED is yellow\n");
        sleep(1);
    }

    return 0;
}
