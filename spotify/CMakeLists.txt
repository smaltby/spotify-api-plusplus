file(GLOB_RECURSE SPOTIFY_SRC
        "*.h"
        "*.cpp"
        )

add_library(spotify-plusplus SHARED ${SPOTIFY_SRC})
target_link_libraries(spotify-plusplus ${LIBS})