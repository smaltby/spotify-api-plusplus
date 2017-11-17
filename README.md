# spotify-api-plusplus

A C++ wrapper for the Spotify Web API.

## Building

First, install necessary dependencies, if you don't already have them.

    sudo apt-get install cmake
    sudo apt-get install libcurl4-openssl-dev

Clone the repository

    git clone https://github.com/smaltby/spotify-api-plusplus.git

Initialize submodules

    cd spotify-api-plusplus
    git submodule update --init --recursive

And finally, build using CMake

    mkdir build
    cd build
    cmake ..
    make

## Testing

Running the unit tests for spotify-api-plusplus is a bit more complex,
because you'll need a client id, client secret, and refresh token. The
first two can be gotten by registering an application with Spotify
[here](https://developer.spotify.com/my-applications/).

The refresh token requires a Spotify Premium Account. Follow
[this](https://developer.spotify.com/web-api/authorization-guide/#authorization-code-flow)
guide up to step 5 to acquire a refresh token. Use the following scope

    scope=user-read-private%20user-read-email%20playlist-read-private%20playlist-read-collaborative%20playlist-modify-public%20playlist-modify-private%20user-follow-modify%20user-follow-read%20user-library-read%20user-library-modify%20user-read-private%20user-read-birthdate%20user-read-email%20user-top-read%20ugc-image-upload%20user-read-playback-state%20user-modify-playback-state%20user-read-currently-playing%20user-read-recently-played

Once acquired, the refresh token should work indefinetely for running the
test cases for this library.

Create 3 files under the root of the project, client_id.txt, client_secret.txt,
and refresh_token.txt, containing the values you acquired previously. The
test cases should be able to use them to sucessfully authenticate with Spotify
and make calls to the API.

To run the test cases, simply use

    make test

after going through the steps to build the library.