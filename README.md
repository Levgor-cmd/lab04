[![CMake CI](https://github.com/Levgor-cmd/lab04/actions/workflows/ci.yml/badge.svg)](https://github.com/Levgor-cmd/lab04/actions/workflows/ci.yml)
## Отчёт к лабораторной работе 04

### После ознакомления с учебным материалом приступим к выполнению инструкций учебного материала, адаптированным под github actions:

```bash
lev@debian:~/Levgor-cmd/workspace/projects/lab04$ export GITHUB_USERNAME=Levgor-cmd
lev@debian:~/Levgor-cmd/workspace/projects/lab04$ cd ~/${GITHUB_USERNAME}/workspace
lev@debian:~/Levgor-cmd/workspace$ git clone https://github.com/${GITHUB_USERNAME}/lab03 projects/lab04
fatal: целевой путь «projects/lab04» уже существует и не является пустым каталогом.
lev@debian:~/Levgor-cmd/workspace$ cd projects/lab04
lev@debian:~/Levgor-cmd/workspace/projects/lab04$ git remote remove origin
lev@debian:~/Levgor-cmd/workspace/projects/lab04$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04.git
lev@debian:~/Levgor-cmd/workspace/projects/lab04$ git remote -v
origin  https://github.com/Levgor-cmd/lab04.git (fetch)
origin  https://github.com/Levgor-cmd/lab04.git (push)


lev@debian:~/Levgor-cmd/workspace/projects/lab04$ cat > .github/workflows/ci.yml << 'EOF'
name: CMake CI

on:
  push:
    branches: [ master, main ]
  pull_request:
    branches: [ master, main ]

jobs:
  build:
    runs-on: ubuntu-latest
    
    steps:
    - name: Checkout code
      uses: actions/checkout@v4
    
    - name: Install CMake
      run: |
        sudo apt-get update
        sudo apt-get install -y cmake cmake-data
    
    - name: Configure CMake
      run: cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
    
    - name: Build
      run: cmake --build _build
    
    - name: Install
      run: cmake --build _build --target install
EOF

```

### Файл был добавлен в репозиторий и запушен. В результате выполнения CI сборка прошла успешно. В данный README добавлен бейдж (см. начало)

### Создаём новый токен с правами workflow и repo, после чего коммитим изменения и пушим


