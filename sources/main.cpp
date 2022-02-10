#include <iostream>
#include "Application.hpp"
#include <core/span.hpp>

int StraitXMain(Span<const char *> args) {
    Application::Get().Run();
    return 777;
}
