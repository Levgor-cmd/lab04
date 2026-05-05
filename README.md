## Отчёт к лабораторной работе 03

### После ознакомления с учебным материалом приступим к выполнению инструкций учебного материала:


https://gist.github.com/Levgor-cmd/38665c48e45a1b457d9d50e8cc95d530
```bash

lev@debian:~$ export GITHUB_USERNAME=Levgor-cmd
lev@debian:~$ cd ${GITHUB_USERNAME}/workspace
lev@debian:~/Levgor-cmd/workspace$ pushd .
~/Levgor-cmd/workspace ~/Levgor-cmd/workspace
lev@debian:~/Levgor-cmd/workspace$ source scripts/activate

lev@debian:~/Levgor-cmd/workspace$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
Клонирование в «projects/lab03»...
remote: Enumerating objects: 15, done.
remote: Counting objects: 100% (15/15), done.
remote: Compressing objects: 100% (10/10), done.
remote: Total 15 (delta 1), reused 15 (delta 1), pack-reused 0 (from 0)
Получение объектов: 100% (15/15), готово.
Определение изменений: 100% (1/1), готово.

lev@debian:~/Levgor-cmd/workspace$ cd projects/lab03
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git remote remove origin
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git


lev@debian:~/Levgor-cmd/workspace/projects/lab03$ g++ -std=c++11 -I./include -c sources/print.cpp
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ls print.o
print.o
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ nm print.o | grep print
0000000000000000 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ar rvs print.a print.o
ar: создаётся print.a
a - print.o
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ file print.a
print.a: current ar archive
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ g++ -std=c++11 -I./include -c examples/example1.cpp
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ls example1.o
example1.o
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ g++ example1.o print.a -o example1
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ./example1 && echo
Hello

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ g++ -std=c++11 -I./include -c examples/example2.cpp
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ nm example2.o
0000000000000000 V DW.ref.__gxx_personality_v0
                 U __gxx_personality_v0
0000000000000000 T main
                 U _Unwind_Resume
                 U _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED2Ev
0000000000000000 n _ZNSt15__new_allocatorIcED5Ev
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                 U _ZSt21ios_base_library_initv
0000000000000000 r _ZStL19piecewise_construct
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ g++ example2.o print.a -o example2
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ./example2
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat log.txt && echo
hello

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf example1.o example2.o print.o
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf print.a
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf example1 example2
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf log.txt

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.4)
project(print)
EOF
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake -H. -B_build
CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (1.9s)
-- Generating done (0.0s)
-- Build files have been written to: /home/lev/Levgor-cmd/workspace/projects/lab03/_build
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build
[ 50%] Building CXX object CMakeFiles/print.dir/sources/print.cpp.o
[100%] Linking CXX static library libprint.a
[100%] Built target print


lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build
CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/lev/Levgor-cmd/workspace/projects/lab03/_build
[ 33%] Built target print
[ 50%] Building CXX object CMakeFiles/example1.dir/examples/example1.cpp.o
[ 66%] Linking CXX executable example1
[ 66%] Built target example1
[ 83%] Building CXX object CMakeFiles/example2.dir/examples/example2.cpp.o
[100%] Linking CXX executable example2
[100%] Built target example2


lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build --target print
[100%] Built target print

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build --target example1
[ 50%] Built target print
[100%] Built target example1

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build --target example2
[ 50%] Built target print
[100%] Built target example2

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ ls -la _build/libprint.a
-rw-rw-r-- 1 lev lev 1730 мая  5 12:23 _build/libprint.a

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ _build/example1 && echo
Hello

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ _build/example2
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat log.txt && echo
hello

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf log.txt

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git clone https://github.com/tp-labs/lab03 tmp
Клонирование в «tmp»...
remote: Enumerating objects: 91, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 91 (delta 23), reused 21 (delta 21), pack-reused 61 (from 1)
Получение объектов: 100% (91/91), 1.02 МиБ | 1.39 МиБ/с, готово.
Определение изменений: 100% (41/41), готово.
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ mv -f tmp/CMakeLists.txt .
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ rm -rf tmp

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cat CMakeLists.txt
cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)

project(print)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

target_include_directories(print PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} print)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS print
    EXPORT print-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT print-config DESTINATION cmake)

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/lev/Levgor-cmd/workspace/projects/lab03/_build

lev@debian:~/Levgor-cmd/workspace/projects/lab03$ cmake --build _build --target install
[100%] Built target print
Install the project...
-- Install configuration: ""
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/lib/libprint.a
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/include
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/include/print.h
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/include/print.hpp
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/cmake/print-config.cmake
-- Installing: /home/lev/Levgor-cmd/workspace/projects/lab03/_install/cmake/print-config-noconfig.cmake


lev@debian:~/Levgor-cmd/workspace/projects/lab03$ tree _install
_install
├── cmake
│   ├── print-config.cmake
│   └── print-config-noconfig.cmake
├── include
│   ├── print.h
│   └── print.hpp
└── lib
    └── libprint.a

4 directories, 5 files


lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git add CMakeLists.txt
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git commit -m"added CMakeLists.txt"
[main 9c95911] added CMakeLists.txt
 1 file changed, 36 insertions(+)
 create mode 100644 CMakeLists.txt
lev@debian:~/Levgor-cmd/workspace/projects/lab03$ git push origin main
Username for 'https://github.com': Levgor-cmd
Password for 'https://%D0%94Levgor-cmd@github.com':
Перечисление объектов: 18, готово.
Подсчет объектов: 100% (18/18), готово.
При сжатии изменений используется до 6 потоков
Сжатие объектов: 100% (13/13), готово.
Запись объектов: 100% (18/18), 2.70 КиБ | 691.00 КиБ/с, готово.
Total 18 (delta 2), reused 14 (delta 1), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), done.
To https://github.com/Levgor-cmd/lab03.git
 * [new branch]      main -> main
 
```

### CMake закоммичен на данный репозиторий
