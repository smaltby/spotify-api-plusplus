file(GLOB_RECURSE SPOTIFY_SRC_H
        "*.h"
        )

file(GLOB_RECURSE SPOTIFY_SRC_CPP
        "*.cpp"
        )

set(SPOTIFY_SRC ${SPOTIFY_SRC_H} ${SPOTIFY_SRC_CPP})

add_library(spotify-plusplus SHARED ${SPOTIFY_SRC})
target_link_libraries(spotify-plusplus ${LIBS})

install(TARGETS spotify-plusplus DESTINATION bin)
install(FILES ${SPOTIFY_SRC_H} DESTINATION include)