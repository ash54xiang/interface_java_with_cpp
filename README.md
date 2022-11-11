# Interfacing Java with Cpp

- The motivation of this project is to create a linkage between Java app with Cpp interfacing some of the legacy Cpp static libraries.

## 2 Types of Libraries in CPP:
1. Static Library
    - also known as Archives.
    - It is a library that becomes a part of the executable which references it.
    - On Windows, it has extension of ".lib", on Linux, it is ".a" (or archive).
    - Advantage:
        - don't have to distribute the static library along with the executables because the contents of the library are a part of the applications and there is no need to give it separately.
    - Disadvantage:
        - the executable can become bulky and too much space is wasted as the library is part of the executable.
        - if the static library changes, then the executable referencing it needs to be updated as well. 
        
2. Dynamic Library
    - also known as "Shared library"
    - On Windows, it has extension of ".dll", on Linux, it is ".so" (shared object).
    - It consists of routines that are loaded into the app at run time. When an application references a dynamic library, the library does not become a part of the app, but it remains as a separate unit.
    - Advantages:
        - One copy of the library can be shared by many apps, saving space.
        - It is a separate unit, the app executable does not change when the dynamic library changes.
    - Disadvantage:
        - it requires a separate program to load and reference the library which can be cumbersome. To solve this problem, we use the "import library" routine.
            - **import library** is a mechanism that loads and uses dynamic library automatically into the program. On Windows, the import library keeps a small static library (.lib) having the same name as the .dll file and is linked to the program at compile time.
            - Once this is done, the dynamic library is used as if it was a static library. 

## WebSocket Comes into Place:
- when we would like to establish a connection between two parties, WebSocket could be one of the way to do it other than HTTP.
- WebSocket is an API which provides the services to open a two-way interactive communication session between clients and a server over TCP connection.
- Uniques:
    - **Bidirectional**: It allows full duplex communication between client and a server.
    - **Persistent**: It allows persistent client-server connection rather than establishing and terminating the connection for each client request and server response.
    - **Low Latency**: Persistent connection between the server and client greatly reduces the data size of each message by only sending all subsequent messages including only the relevant information.
    - **Security**: WSS (Websockets over SSL/TLS) is encrypted, thus it protects user against man-in-the-middle attack.

    | --------      | WebSocket      | HTTP                       |
    | --------      | ---------      | -----------                |
    | Duplex        | Full Duplex    | Half Duplex                |
    | Msg Patten    | Bi-directional | Request-Response           |
    | Overhead      | Small overhead | Relatively large overhead  |
