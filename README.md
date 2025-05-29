Compiling the project

Require : CMAKE

```bash
cmake -B build
cmake --build build
```

Then run the game 

```
./build/game_of_life --input testcase/test.txt --iterations 20 --all
```