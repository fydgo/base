file(GLOB SRC CONFIGURE_DEPENDS 
        "*.cpp"
        "*.h"
)

# My understanding: to set lib for configuration type of project details.
add_library(base STATIC ${SRC})