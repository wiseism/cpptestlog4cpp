# README

g++ -o log4cppapp src/main.cpp -L/usr/local/Cellar/log4cpp/1.1.3/lib -llog4cpp

g++ -o log4cppapp src/main.cpp $(pkg-config --cflags --libs log4cpp)


gcc -std=c11 src/mac_s.c -o mac_s
clang -std=c11 src/mac_s.c -o mac_s

https://www.apiref.com/cpp-zh/cpp/string/byte/strtok.html
https://www.apiref.com/cpp-zh/c/string/byte/strtok.html

mac系统
string.h文件只有strtok_r，没有strtok_s

## ubuntu

sudo apt install liblog4cpp5-dev -y
dpkg -L liblog4cpp5-dev


```shell
dpkg -L liblog4cpp5-dev
/.
/usr
/usr/bin
/usr/bin/log4cpp-config
/usr/include
/usr/include/log4cpp
/usr/include/log4cpp/AbortAppender.hh
/usr/include/log4cpp/Appender.hh
/usr/include/log4cpp/AppenderSkeleton.hh
/usr/include/log4cpp/AppendersFactory.hh
/usr/include/log4cpp/BasicConfigurator.hh
/usr/include/log4cpp/BasicLayout.hh
/usr/include/log4cpp/BufferingAppender.hh
/usr/include/log4cpp/Category.hh
/usr/include/log4cpp/CategoryStream.hh
/usr/include/log4cpp/Configurator.hh
/usr/include/log4cpp/DailyRollingFileAppender.hh
/usr/include/log4cpp/Export.hh
/usr/include/log4cpp/FactoryParams.hh
/usr/include/log4cpp/FileAppender.hh
/usr/include/log4cpp/Filter.hh
/usr/include/log4cpp/FixedContextCategory.hh
/usr/include/log4cpp/HierarchyMaintainer.hh
/usr/include/log4cpp/IdsaAppender.hh
/usr/include/log4cpp/Layout.hh
/usr/include/log4cpp/LayoutAppender.hh
/usr/include/log4cpp/LayoutsFactory.hh
/usr/include/log4cpp/LevelEvaluator.hh
/usr/include/log4cpp/LoggingEvent.hh
/usr/include/log4cpp/Manipulator.hh
/usr/include/log4cpp/NDC.hh
/usr/include/log4cpp/NTEventLogAppender.hh
/usr/include/log4cpp/OstreamAppender.hh
/usr/include/log4cpp/PassThroughLayout.hh
/usr/include/log4cpp/PatternLayout.hh
/usr/include/log4cpp/Portability.hh
/usr/include/log4cpp/Priority.hh
/usr/include/log4cpp/PropertyConfigurator.hh
/usr/include/log4cpp/RemoteSyslogAppender.hh
/usr/include/log4cpp/RollingFileAppender.hh
/usr/include/log4cpp/SimpleConfigurator.hh
/usr/include/log4cpp/SimpleLayout.hh
/usr/include/log4cpp/StringQueueAppender.hh
/usr/include/log4cpp/SyslogAppender.hh
/usr/include/log4cpp/TimeStamp.hh
/usr/include/log4cpp/TriggeringEventEvaluator.hh
/usr/include/log4cpp/TriggeringEventEvaluatorFactory.hh
/usr/include/log4cpp/Win32DebugAppender.hh
/usr/include/log4cpp/config-MinGW32.h
/usr/include/log4cpp/config-openvms.h
/usr/include/log4cpp/config-win32.h
/usr/include/log4cpp/config.h
/usr/include/log4cpp/convenience.h
/usr/include/log4cpp/threading
/usr/include/log4cpp/threading/BoostThreads.hh
/usr/include/log4cpp/threading/DummyThreads.hh
/usr/include/log4cpp/threading/MSThreads.hh
/usr/include/log4cpp/threading/OmniThreads.hh
/usr/include/log4cpp/threading/PThreads.hh
/usr/include/log4cpp/threading/Threading.hh
/usr/lib
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/liblog4cpp.a
/usr/lib/x86_64-linux-gnu/pkgconfig
/usr/lib/x86_64-linux-gnu/pkgconfig/log4cpp.pc
/usr/share
/usr/share/aclocal
/usr/share/aclocal/log4cpp.m4
/usr/share/doc
/usr/share/doc/liblog4cpp5-dev
/usr/share/doc/liblog4cpp5-dev/copyright
/usr/share/man
/usr/share/man/man1
/usr/share/man/man1/log4cpp-config.1.gz
/usr/lib/x86_64-linux-gnu/liblog4cpp.so
/usr/share/doc/liblog4cpp5-dev/changelog.Debian.gz
```

这样安装的log4cpp不支持cmake，
sudo apt-get install libpthread-stubs0-dev -y
dpkg -L libpthread-stubs0-dev

```shell
dpkg -L libpthread-stubs0-dev
/.
/usr
/usr/lib
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/pkgconfig
/usr/lib/x86_64-linux-gnu/pkgconfig/pthread-stubs.pc
/usr/share
/usr/share/doc
/usr/share/doc/libpthread-stubs0-dev
/usr/share/doc/libpthread-stubs0-dev/README
/usr/share/doc/libpthread-stubs0-dev/changelog.Debian.gz
/usr/share/doc/libpthread-stubs0-dev/copyright
```

g++ -o log4cpp_main src/log4cpp_main.cpp -llog4cpp -lpthread


./log4cpp_main
./log4cpp_main: symbol lookup error: /usr/local/lib/liblog4cpp.so.5: undefined symbol: pthread_key_create
wdidada@DESKTOP-DAF8ST0:~/tmp/cpptestlog4cpp$ nm /usr/lib/x86_64-linux-gnu/liblog4cpp.a | grep pthread_key_create
nm: IdsaAppender.o: no symbols
U pthread_key_create
nm: Win32DebugAppender.o: no symbols
nm: NTEventLogAppender.o: no symbols
nm: DllMain.o: no symbols
nm: DummyThreads.o: no symbols
nm: MSThreads.o: no symbols
nm: OmniThreads.o: no symbols
nm: PortabilityImpl.o: no symbols
nm: SmtpAppender.o: no symbols
wdidada@DESKTOP-DAF8ST0:~/tmp/cpptestlog4cpp$ ldd /usr/local/lib/liblog4cpp.so.5
linux-vdso.so.1 (0x00007ffca23d3000)
libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fdf62f98000)
libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fdf62e49000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fdf62c57000)
libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fdf62c32000)
/lib64/ld-linux-x86-64.so.2 (0x00007fdf63246000)
