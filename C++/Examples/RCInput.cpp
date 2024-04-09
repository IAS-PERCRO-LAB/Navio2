#include <unistd.h>
#include <cstdio>

#include <Navio2/RCInput_Navio2.h>
#ifdef NAVIO1
#include <Navio+/RCInput_Navio.h>
#endif
#include <Common/Util.h>
#include <memory>
#include <cstdlib>

#define READ_FAILED (-1)

std::unique_ptr<RCInput> get_rcin() {
#ifdef NAVIO1
    if (get_navio_version() == NAVIO2) {
#endif
        auto ptr = std::unique_ptr<RCInput>{new RCInput_Navio2()};
        return ptr;
#ifdef NAVIO1
    } else {
        auto ptr = std::unique_ptr<RCInput>{new RCInput_Navio()};
        return ptr;
    }
#endif
}


int main(int argc, char *argv[]) {
    if (check_apm()) {
        return 1;
    }

    auto rcin = get_rcin();

    rcin->initialize();

    while (true) {
        int period = rcin->read(2);
        if (period == READ_FAILED)
            return EXIT_FAILURE;
        printf("%d\n", period);

        sleep(1);
    }
}
