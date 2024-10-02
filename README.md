# cxx-bazel-template

Bazel test compiling C++ "Hello World" and google test suite

## Initialize

Build the docker image by running the following inside the root dir of the repo:

~~~bash

docker compose up -d

~~~

Jump into the container by running:

~~~bash
docker exec -it bazel-test bash
~~~

## Building

Compile the hello_world program by running the following command on the /workspace

~~~bash

bazel build //main:hello_world

~~~

## Running

Run the hello_world program by running the following command on the /workspace

~~~bash
./bazel-bin/main/hello_world
~~~

## License

MIT
