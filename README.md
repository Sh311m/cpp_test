**Dependency:**  
Cmake >= 3.0.0  
Clang >= 8.0  
GTest >= 1.8.1  

```bash

mkdir build && cd build
cmake -G "Unix Makefiles" ..
make all
```

You will receive 3 binary: 
* practice - CLI wrapper for target function (pass input string as CLI argument)
* practice_test - wrapper for GTest (no additional args to run)
* practice_fuzzer - wrapper for fuzz-testing target function (you may add options for libfuzzer, for example `only_ascii=1`)
