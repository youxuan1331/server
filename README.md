# co_http

基于 C++17 回调函数的异步 HTTP 服务器。

编译和运行：

```bash 
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --target chat_server
cd build
./chat_server
```

> 编译环境是 GCC 9.3.0 和 Ubuntu 20.04 LTS。

然后，访问 https://127.0.0.1:8080 就能访问聊天界面了。
