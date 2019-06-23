## Introduce
1. NativeLib.java, 简单展示怎样从native拿值。
2. [NativeHelloALib.java,libasimple] :构建一个hello简单的.a静态库，且将.a和所需头文件导出到 project/export/libahello 目录中
3. [NativeHelloSoLib.java,libsosimple] :构建一个hello简单的.so动态库，且将.so和所需头文件导出到 project/export/libsohello 目录中
3. NativeJsonSoLib :构建一个 jsoncpp.so动态库，且将.so和所需头文件导出到 project/export/libsojsoncpp 目录中,展示了怎么读取设置原生People类

## 注意点
- 当链接so动态库时 必须设置so库路径让gradle将需要的库打到apk中，若不需要动态库，则将以下命令注释

## Tools
- To install `readelf, objdump`

## Thanks to 
- [CMake 官方文档](https://cmake.org/cmake/help/v3.0/index.html)
- [Android NDK开发 JNI操作java构造方法，普通方法，静态方法(七)](https://www.cnblogs.com/mingfeng002/p/6600731.html)
- [关于在Android中使用CMake你所需要了解的一切（二）](https://juejin.im/post/5bb0276be51d450ea52fdb54)