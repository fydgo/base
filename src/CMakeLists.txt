file(GLOB SRC CONFIGURE_DEPENDS 
        "*.cpp"
        "*.h"
)

add_library(base STATIC ${SRC})